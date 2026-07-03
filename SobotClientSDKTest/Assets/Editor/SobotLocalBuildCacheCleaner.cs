using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using UnityEditor;
using UnityEngine;

public static class SobotLocalBuildCacheCleaner
{
    private static readonly string[] IosIl2CppCachePaths =
    {
        "Library/Il2cppBuildCache/iOS",
        "Temp/StagingArea"
    };

    private static readonly string[] AndroidIl2CppCachePaths =
    {
        "Library/Il2cppBuildCache",
        "Library/Bee",
        "Temp/StagingArea",
        "Temp/il2cppOutput",
        "Temp/gradleOut",
        "builder/Android"
    };

    private static readonly string[] UnityBuildCachePaths =
    {
        "Library/Il2cppBuildCache",
        "Library/Bee",
        "Library/BuildPlayerData",
        "Library/BuildCache",
        "Temp/StagingArea"
    };

    private static readonly string[] IosExportedBuildPaths =
    {
        "builder/iOS/iOSnew",
        "builder/iOSnew"
    };

    private static readonly string[] GeneratedBuildOutputPaths =
    {
        "builder/iOS/iOSnew",
        "builder/iOSnew",
        "builder/iOS",
        "builder/Android"
    };

    [MenuItem("Sobot/Clean Local Build Cache/iOS IL2CPP Cache")]
    public static void CleanIosIl2CppCache()
    {
        CleanCachePaths("iOS IL2CPP", IosIl2CppCachePaths);
    }

    [MenuItem("Sobot/Clean Local Build Cache/Android IL2CPP Cache")]
    public static void CleanAndroidIl2CppCache()
    {
        CleanCachePaths("Android IL2CPP", AndroidIl2CppCachePaths);
    }

    [MenuItem("Sobot/Clean Local Build Cache/Unity Build Cache")]
    public static void CleanUnityBuildCache()
    {
        CleanCachePaths("Unity build", UnityBuildCachePaths);
    }

    [MenuItem("Sobot/Clean Local Build Cache/iOS Exported Build Outputs")]
    public static void CleanIosExportedBuildOutputs()
    {
        CleanCachePaths("iOS exported build", IosExportedBuildPaths);
    }

    [MenuItem("Sobot/Clean Local Build Cache/Generated Build Outputs")]
    public static void CleanGeneratedBuildOutputs()
    {
        CleanCachePaths("generated build output", GeneratedBuildOutputPaths);
    }

    [MenuItem("Sobot/Clean Local Build Cache/Scan Absolute Paths")]
    public static void ScanAbsolutePaths()
    {
        string projectRoot = GetProjectRoot();
        string[] scanRoots =
        {
            "Library/Il2cppBuildCache",
            "Library/Bee",
            "Temp/StagingArea",
            "builder/iOS",
            "builder/iOSnew",
            "builder/Android"
        };

        StringBuilder report = new StringBuilder();
        report.AppendLine("[SobotBuild] Absolute path scan:");

        foreach (string relativePath in scanRoots)
        {
            string fullPath = Path.Combine(projectRoot, relativePath);
            if (!Directory.Exists(fullPath)) continue;

            foreach (string file in EnumerateFilesSafe(fullPath))
            {
                string text = ReadTextSafe(file);
                if (string.IsNullOrEmpty(text)) continue;

                if (text.Contains("/Users/") || text.Contains("/home/") || ContainsWindowsAbsolutePath(text))
                {
                    report.AppendLine(GetRelativePath(projectRoot, file));
                }
            }
        }

        Debug.Log(report.ToString());
    }

    private static void CleanCachePaths(string name, string[] relativePaths)
    {
        string projectRoot = GetProjectRoot();
        List<string> existingPaths = new List<string>();

        foreach (string relativePath in relativePaths)
        {
            string fullPath = Path.Combine(projectRoot, relativePath);
            if (Directory.Exists(fullPath) || File.Exists(fullPath))
            {
                existingPaths.Add(relativePath);
            }
        }

        if (existingPaths.Count == 0)
        {
            Debug.Log($"[SobotBuild] No {name} cache found.");
            return;
        }

        string message = "Will remove local generated cache folders:\n\n" + string.Join("\n", existingPaths);
        if (!EditorUtility.DisplayDialog("Clean Local Build Cache", message, "Clean", "Cancel"))
        {
            return;
        }

        foreach (string relativePath in existingPaths)
        {
            string fullPath = Path.Combine(projectRoot, relativePath);
            if (!IsPathUnderProject(projectRoot, fullPath))
            {
                Debug.LogWarning($"[SobotBuild] Skip unsafe path outside project: {fullPath}");
                continue;
            }

            DeleteIfExists(fullPath);
            Debug.Log($"[SobotBuild] Removed {relativePath}");
        }

        AssetDatabase.Refresh();
        Debug.Log($"[SobotBuild] {name} cache cleaned.");
    }

    private static string GetProjectRoot()
    {
        return Directory.GetParent(Application.dataPath).FullName;
    }

    private static bool IsPathUnderProject(string projectRoot, string path)
    {
        string root = Path.GetFullPath(projectRoot).TrimEnd(Path.DirectorySeparatorChar, Path.AltDirectorySeparatorChar);
        string target = Path.GetFullPath(path);
        return target.Equals(root, StringComparison.Ordinal) ||
               target.StartsWith(root + Path.DirectorySeparatorChar, StringComparison.Ordinal) ||
               target.StartsWith(root + Path.AltDirectorySeparatorChar, StringComparison.Ordinal);
    }

    private static void DeleteIfExists(string path)
    {
        if (Directory.Exists(path))
        {
            Directory.Delete(path, true);
            return;
        }

        if (File.Exists(path))
        {
            File.Delete(path);
        }
    }

    private static IEnumerable<string> EnumerateFilesSafe(string root)
    {
        Queue<string> pending = new Queue<string>();
        pending.Enqueue(root);

        while (pending.Count > 0)
        {
            string current = pending.Dequeue();

            string[] files;
            try
            {
                files = Directory.GetFiles(current);
            }
            catch
            {
                continue;
            }

            foreach (string file in files)
            {
                yield return file;
            }

            string[] dirs;
            try
            {
                dirs = Directory.GetDirectories(current);
            }
            catch
            {
                continue;
            }

            foreach (string dir in dirs)
            {
                pending.Enqueue(dir);
            }
        }
    }

    private static string ReadTextSafe(string path)
    {
        try
        {
            FileInfo info = new FileInfo(path);
            if (info.Length > 1024 * 1024) return string.Empty;
            return File.ReadAllText(path);
        }
        catch
        {
            return string.Empty;
        }
    }

    private static bool ContainsWindowsAbsolutePath(string text)
    {
        for (int i = 0; i + 2 < text.Length; i++)
        {
            if (char.IsLetter(text[i]) && text[i + 1] == ':' && (text[i + 2] == '\\' || text[i + 2] == '/'))
            {
                return true;
            }
        }

        return false;
    }

    private static string GetRelativePath(string root, string path)
    {
        Uri rootUri = new Uri(AppendDirectorySeparatorChar(root));
        Uri pathUri = new Uri(path);
        return Uri.UnescapeDataString(rootUri.MakeRelativeUri(pathUri).ToString()).Replace('/', Path.DirectorySeparatorChar);
    }

    private static string AppendDirectorySeparatorChar(string path)
    {
        if (path.EndsWith(Path.DirectorySeparatorChar.ToString()) || path.EndsWith(Path.AltDirectorySeparatorChar.ToString()))
        {
            return path;
        }

        return path + Path.DirectorySeparatorChar;
    }
}
