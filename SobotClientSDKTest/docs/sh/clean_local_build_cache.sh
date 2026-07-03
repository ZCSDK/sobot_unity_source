#!/usr/bin/env bash

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd -P)"
PROJECT_ROOT=""
PROFILE="unity-ios"
DRY_RUN=0
FORCE=0

usage() {
  cat <<'EOF'
Usage:
  clean_local_build_cache.sh [project_root] [--profile unity-ios|unity-android|unity|mobile|node|scan|all] [--dry-run] [--force]

Profiles:
  unity-ios  Clean Unity iOS IL2CPP caches and exported iOS build outputs. Default.
  unity-android Clean Unity Android IL2CPP/Bee caches and exported Android build outputs.
  unity      Clean common Unity local build caches.
  mobile     Clean Unity iOS + local Gradle/Xcode cache folders.
  node       Clean common frontend package manager cache folders inside the project.
  scan       Scan generated cache folders for absolute paths without deleting files.
  all        Clean all recognized local generated cache folders.

Notes:
  - The script derives paths from the project root and never uses a hard-coded user/device path.
  - Close Unity/Xcode before cleaning. Use --dry-run first when applying it to a new project.
EOF
}

find_project_root() {
  local current="$1"

  while [ "$current" != "/" ]; do
    if [ -d "$current/Assets" ] && [ -d "$current/ProjectSettings" ]; then
      printf '%s\n' "$current"
      return 0
    fi

    if [ -d "$current/.git" ] || [ -f "$current/package.json" ] || [ -f "$current/settings.gradle" ] || [ -f "$current/Podfile" ]; then
      printf '%s\n' "$current"
      return 0
    fi

    current="$(dirname "$current")"
  done

  return 1
}

while [ "$#" -gt 0 ]; do
  case "$1" in
    --profile)
      shift
      PROFILE="${1:-}"
      ;;
    --profile=*)
      PROFILE="${1#*=}"
      ;;
    --dry-run)
      DRY_RUN=1
      ;;
    --force)
      FORCE=1
      ;;
    -h|--help)
      usage
      exit 0
      ;;
    *)
      PROJECT_ROOT="$1"
      ;;
  esac
  shift
done

if [ -z "$PROJECT_ROOT" ]; then
  PROJECT_ROOT="$(find_project_root "$SCRIPT_DIR" || true)"
fi

if [ -z "$PROJECT_ROOT" ] || [ ! -d "$PROJECT_ROOT" ]; then
  echo "[cache-clean] Project root was not found. Pass it explicitly as the first argument." >&2
  exit 1
fi

PROJECT_ROOT="$(cd "$PROJECT_ROOT" && pwd -P)"

declare -a TARGETS
TARGETS=()

add_target() {
  TARGETS+=("$1")
}

add_unity_ios_targets() {
  add_target "Library/Il2cppBuildCache/iOS"
  add_target "Temp/StagingArea"
}

add_unity_android_targets() {
  add_target "Library/Il2cppBuildCache"
  add_target "Library/Bee"
  add_target "Temp/StagingArea"
  add_target "Temp/il2cppOutput"
  add_target "Temp/gradleOut"
  add_target "builder/Android"
}

add_ios_export_targets() {
  add_target "builder/iOS/iOSnew"
  add_target "builder/iOSnew"
}

add_generated_build_targets() {
  add_target "builder/iOS/iOSnew"
  add_target "builder/iOSnew"
  add_target "builder/iOS"
  add_target "builder/Android"
}

add_unity_targets() {
  add_target "Library/Il2cppBuildCache"
  add_target "Library/Bee"
  add_target "Library/BuildPlayerData"
  add_target "Library/BuildCache"
  add_target "Temp/StagingArea"
}

add_gradle_targets() {
  add_target ".gradle"
  add_target "launcher/build"
  add_target "unityLibrary/build"
  add_target "app/build"
}

add_xcode_targets() {
  add_target "DerivedData"
  add_target "ios/DerivedData"
}

add_node_targets() {
  add_target "node_modules/.cache"
  add_target ".next/cache"
  add_target ".turbo"
  add_target ".vite"
  add_target ".parcel-cache"
}

case "$PROFILE" in
  unity-ios)
    add_unity_ios_targets
    add_ios_export_targets
    ;;
  unity-android)
    add_unity_android_targets
    ;;
  unity)
    add_unity_targets
    ;;
  mobile)
    add_unity_ios_targets
    add_generated_build_targets
    add_gradle_targets
    add_xcode_targets
    ;;
  node)
    add_node_targets
    ;;
  all)
    add_unity_targets
    add_generated_build_targets
    add_gradle_targets
    add_xcode_targets
    add_node_targets
    ;;
  scan)
    ;;
  *)
    echo "[cache-clean] Unknown profile: $PROFILE" >&2
    usage
    exit 1
    ;;
esac

is_under_project() {
  local path="$1"
  case "$path" in
    "$PROJECT_ROOT"|"$PROJECT_ROOT"/*) return 0 ;;
    *) return 1 ;;
  esac
}

absolute_target_path() {
  local rel="$1"
  local target="$PROJECT_ROOT/$rel"
  local parent
  parent="$(dirname "$target")"

  if [ -d "$parent" ]; then
    printf '%s/%s\n' "$(cd "$parent" && pwd -P)" "$(basename "$target")"
  else
    printf '%s\n' "$target"
  fi
}

clean_target() {
  local rel="$1"
  local target
  target="$(absolute_target_path "$rel")"

  if ! is_under_project "$target"; then
    echo "[cache-clean] Skip unsafe path outside project: $target" >&2
    return 0
  fi

  if [ ! -e "$target" ] && [ ! -L "$target" ]; then
    echo "[cache-clean] Skip missing: $rel"
    return 0
  fi

  if [ "$DRY_RUN" -eq 1 ]; then
    echo "[cache-clean] Would remove: $rel"
    return 0
  fi

  rm -rf "$target"
  echo "[cache-clean] Removed: $rel"
}

scan_absolute_paths() {
  local scan_roots=(
    "Library/Il2cppBuildCache"
    "Library/Bee"
    "Temp/StagingArea"
    "builder/iOS"
    "builder/iOSnew"
    "builder/Android"
    ".gradle"
    "DerivedData"
    "ios/DerivedData"
    "node_modules/.cache"
    ".next/cache"
    ".turbo"
    ".vite"
    ".parcel-cache"
  )

  echo "[cache-clean] Scanning generated caches under: $PROJECT_ROOT"
  for rel in "${scan_roots[@]}"; do
    local target="$PROJECT_ROOT/$rel"
    if [ -e "$target" ] || [ -L "$target" ]; then
      echo "[cache-clean] Scan: $rel"
      grep -RInIE '(/Users/|/home/|[A-Za-z]:\\)' "$target" 2>/dev/null | sed -n '1,120p' || true
    fi
  done
}

echo "[cache-clean] Project root: $PROJECT_ROOT"
echo "[cache-clean] Profile: $PROFILE"

if [ "$PROFILE" = "scan" ]; then
  scan_absolute_paths
  exit 0
fi

if [ "$DRY_RUN" -eq 0 ] && [ "$FORCE" -eq 0 ] && [ -f "$PROJECT_ROOT/Temp/UnityLockfile" ]; then
  echo "[cache-clean] Unity appears to be open: Temp/UnityLockfile exists." >&2
  echo "[cache-clean] Close Unity and rerun, or pass --force if you know no build/import is running." >&2
  exit 2
fi

for rel in "${TARGETS[@]}"; do
  clean_target "$rel"
done

echo "[cache-clean] Done."
