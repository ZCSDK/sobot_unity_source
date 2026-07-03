// Assets/Editor/SobotPostProcessBuild.cs
// 构建后处理：
//   iOS  - 确保 SobotKit.bundle 被正确添加到 Xcode 工程的 Copy Bundle Resources
//   Android - 自动向导出的 Gradle 工程注入智齿 SDK 依赖

#if UNITY_ANDROID
using System.IO;
using UnityEditor;
using UnityEditor.Android;
using UnityEngine;

/// <summary>
/// Android 导出后自动向 unityLibrary/build.gradle 注入智齿 SDK 依赖
/// </summary>
public class SobotAndroidPostProcess : IPostGenerateGradleAndroidProject
{
    // 回调优先级，数字越小越早执行
    public int callbackOrder => 99;

    public void OnPostGenerateGradleAndroidProject(string gradleProjectPath)
    {
        // gradleProjectPath 指向 unityLibrary 目录
        string rootPath = Path.GetDirectoryName(gradleProjectPath);
        PatchSettingsGradle(rootPath);
        PatchRootBuildGradle(rootPath);

        string buildGradlePath = Path.Combine(gradleProjectPath, "build.gradle");

        if (!File.Exists(buildGradlePath))
        {
            Debug.LogWarning($"[SobotBuild] build.gradle not found at {buildGradlePath}");
            return;
        }

        string content = File.ReadAllText(buildGradlePath);

        // 避免重复注入
        if (content.Contains("com.sobot.chat:client"))
        {
            Debug.Log("[SobotBuild] Sobot dependencies already injected, skipping.");
            return;
        }

        // 需要注入的依赖
        string sobotDeps =
            "\n    // ===== Sobot SDK (auto-injected by SobotPostProcessBuild) =====\n" +
            "    implementation 'com.sobot.chat:client:+'\n" +
            "    implementation 'com.squareup.okhttp3:okhttp:4.4.0'\n" +
            "    implementation 'androidx.appcompat:appcompat:1.0.0'\n" +
            "    implementation 'androidx.recyclerview:recyclerview:1.0.0'\n" +
            "    // implementation 'com.nostra13.universalimageloader:universal-image-loader:1.9.5'\n" +
            "    // implementation 'com.squareup.picasso:picasso:2.71828'\n" +
            "    // implementation 'com.facebook.fresco:fresco:2.6.0'\n" +
            "    implementation 'com.github.bumptech.glide:glide:4.9.0'\n" +
            "    // ================================================================\n";

        // 在 dependencies { 块的末尾 } 前插入
        int depsIndex = content.LastIndexOf("dependencies {");
        if (depsIndex == -1)
        {
            Debug.LogWarning("[SobotBuild] Could not find 'dependencies {' block in build.gradle");
            return;
        }

        // 找到对应的闭合括号
        int braceDepth = 0;
        int insertPos = -1;
        for (int i = depsIndex; i < content.Length; i++)
        {
            if (content[i] == '{') braceDepth++;
            else if (content[i] == '}')
            {
                braceDepth--;
                if (braceDepth == 0)
                {
                    insertPos = i;
                    break;
                }
            }
        }

        if (insertPos == -1)
        {
            Debug.LogWarning("[SobotBuild] Could not find closing brace of dependencies block");
            return;
        }

        content = content.Insert(insertPos, sobotDeps);
        File.WriteAllText(buildGradlePath, content);
        Debug.Log("[SobotBuild] Sobot dependencies injected into unityLibrary/build.gradle");
    }

    /// <summary>
    /// 确保 settings.gradle 的插件仓库和依赖仓库优先包含国内 Maven 镜像。
    /// Android Gradle Plugin 在项目配置阶段解析，必须写入 pluginManagement.repositories。
    /// </summary>
    private void PatchSettingsGradle(string rootPath)
    {
        string settingsPath = Path.Combine(rootPath, "settings.gradle");
        if (!File.Exists(settingsPath))
        {
            Debug.LogWarning($"[SobotBuild] settings.gradle not found at {settingsPath}");
            return;
        }

        string content = RemoveAliyunMirrorLines(File.ReadAllText(settingsPath));

        string pluginMirrorBlock =
            "        maven { url 'https://maven.aliyun.com/repository/gradle-plugin' }\n" +
            "        maven { url 'https://maven.aliyun.com/repository/google' }\n" +
            "        maven { url 'https://maven.aliyun.com/repository/central' }\n" +
            "        maven { url 'https://maven.aliyun.com/repository/public' }\n";

        string dependencyMirrorBlock =
            "        maven { url 'https://maven.aliyun.com/repository/google' }\n" +
            "        maven { url 'https://maven.aliyun.com/repository/central' }\n" +
            "        maven { url 'https://maven.aliyun.com/repository/public' }\n";

        content = InsertRepositoryBlock(content, "pluginManagement", pluginMirrorBlock);
        content = InsertRepositoryBlock(content, "dependencyResolutionManagement", dependencyMirrorBlock);

        File.WriteAllText(settingsPath, content);
        Debug.Log("[SobotBuild] Maven mirrors refreshed in settings.gradle");
    }

    private string RemoveAliyunMirrorLines(string content)
    {
        return content
            .Replace("        maven { url 'https://maven.aliyun.com/repository/google' }\n", string.Empty)
            .Replace("        maven { url 'https://maven.aliyun.com/repository/gradle-plugin' }\n", string.Empty)
            .Replace("        maven { url 'https://maven.aliyun.com/repository/central' }\n", string.Empty)
            .Replace("        maven { url 'https://maven.aliyun.com/repository/public' }\n", string.Empty);
    }

    private string InsertRepositoryBlock(string content, string parentBlockName, string block)
    {
        int parentIndex = content.IndexOf(parentBlockName);
        if (parentIndex == -1) return content;

        int repositoriesIndex = content.IndexOf("repositories {", parentIndex);
        if (repositoriesIndex == -1) return content;

        int insertPos = content.IndexOf('\n', repositoriesIndex);
        if (insertPos == -1) return content;

        return content.Insert(insertPos + 1, block);
    }

    /// <summary>
    /// 兼容旧版 Gradle 模板：确保根 build.gradle 的 allprojects.repositories 包含 mavenCentral()
    /// </summary>
    private void PatchRootBuildGradle(string rootPath)
    {
        string rootGradlePath = Path.Combine(rootPath, "build.gradle");
        if (!File.Exists(rootGradlePath)) return;

        string content = File.ReadAllText(rootGradlePath);
        if (content.Contains("mavenCentral()"))
        {
            Debug.Log("[SobotBuild] mavenCentral() already present in root build.gradle");
            return;
        }

        // 在 google() 后插入 mavenCentral()
        if (!content.Contains("google()"))
        {
            Debug.Log("[SobotBuild] Root build.gradle has no google() repository, skipping mavenCentral() patch.");
            return;
        }

        content = content.Replace("google()", "google()\n        mavenCentral()");
        File.WriteAllText(rootGradlePath, content);
        Debug.Log("[SobotBuild] mavenCentral() added to root build.gradle");
    }
}
#endif

#if UNITY_IOS
using System.IO;
using UnityEditor;
using UnityEditor.Callbacks;
using UnityEditor.iOS.Xcode;
using UnityEngine;

public class SobotPostProcessBuild
{
    private const string BundleAssetRelativePath = "Plugins/Sobot/iOS/frameworks/SobotKit.bundle";
    private const string BundleXcodeRelativePath = "Frameworks/Plugins/Sobot/iOS/frameworks/SobotKit.bundle";
    private const string LegacyBundleXcodeRelativePath = "Frameworks/Plugins/iOS/frameworks/SobotKit.bundle";

    [PostProcessBuild(100)]
    public static void OnPostProcessBuild(BuildTarget target, string buildPath)
    {
        if (target != BuildTarget.iOS) return;

        string pbxPath = PBXProject.GetPBXProjectPath(buildPath);
        PBXProject project = new PBXProject();
        project.ReadFromFile(pbxPath);

        // Unity 2019.3+ 使用 GetUnityFrameworkTargetGuid，旧版用 TargetGuidByName
#if UNITY_2019_3_OR_NEWER
        string targetGuid = project.GetUnityMainTargetGuid();
        string frameworkTargetGuid = project.GetUnityFrameworkTargetGuid();
#else
        string targetGuid = project.TargetGuidByName(PBXProject.GetUnityTargetName());
        string frameworkTargetGuid = targetGuid;
#endif

        project.AddFrameworkToProject(frameworkTargetGuid, "UserNotifications.framework", false);

        RemoveLegacyBundleReference(project, targetGuid, buildPath);
        EnsureSobotKitBundle(project, targetGuid, buildPath);

        // 写回 pbxproj
        project.WriteToFile(pbxPath);

        // 修改 Info.plist：添加必要权限
        PatchInfoPlist(buildPath);
    }

    private static void EnsureSobotKitBundle(PBXProject project, string targetGuid, string buildPath)
    {
        string bundleSrcPath = Path.Combine(Application.dataPath, BundleAssetRelativePath);
        string bundleDstPath = Path.Combine(buildPath, BundleXcodeRelativePath);

        if (!Directory.Exists(bundleDstPath))
        {
            if (!Directory.Exists(bundleSrcPath))
            {
                Debug.LogWarning($"[SobotBuild] SobotKit.bundle not found at {bundleSrcPath}");
                return;
            }

            CopyDirectory(bundleSrcPath, bundleDstPath);
            Debug.Log($"[SobotBuild] Copied SobotKit.bundle to {bundleDstPath}");
        }

        string fileGuid = project.FindFileGuidByProjectPath(BundleXcodeRelativePath);
        if (string.IsNullOrEmpty(fileGuid))
        {
            fileGuid = project.AddFile(BundleXcodeRelativePath, BundleXcodeRelativePath, PBXSourceTree.Source);
        }

        project.RemoveFileFromBuild(targetGuid, fileGuid);
        project.AddFileToBuild(targetGuid, fileGuid);
        Debug.Log("[SobotBuild] SobotKit.bundle ensured in Copy Bundle Resources");
    }

    private static void RemoveLegacyBundleReference(PBXProject project, string targetGuid, string buildPath)
    {
        string legacyGuid = project.FindFileGuidByProjectPath(LegacyBundleXcodeRelativePath);
        if (!string.IsNullOrEmpty(legacyGuid))
        {
            project.RemoveFileFromBuild(targetGuid, legacyGuid);
            project.RemoveFile(legacyGuid);
            Debug.Log("[SobotBuild] Removed legacy SobotKit.bundle Xcode reference");
        }

        string legacyPath = Path.Combine(buildPath, LegacyBundleXcodeRelativePath);
        if (Directory.Exists(legacyPath))
        {
            Directory.Delete(legacyPath, true);
            Debug.Log($"[SobotBuild] Removed legacy SobotKit.bundle copy at {legacyPath}");
        }
    }

    /// <summary>
    /// 向 Info.plist 添加智齿 SDK 所需权限
    /// </summary>
    private static void PatchInfoPlist(string buildPath)
    {
        string plistPath = Path.Combine(buildPath, "Info.plist");
        PlistDocument plist = new PlistDocument();
        plist.ReadFromFile(plistPath);

        PlistElementDict root = plist.root;

        // 相机权限
        if (!root.values.ContainsKey("NSCameraUsageDescription"))
            root.SetString("NSCameraUsageDescription", "发送图片需要访问相机");

        // 麦克风权限
        if (!root.values.ContainsKey("NSMicrophoneUsageDescription"))
            root.SetString("NSMicrophoneUsageDescription", "发送语音需要访问麦克风");

        // 相册权限
        if (!root.values.ContainsKey("NSPhotoLibraryUsageDescription"))
            root.SetString("NSPhotoLibraryUsageDescription", "发送图片需要访问相册");

        plist.WriteToFile(plistPath);
        Debug.Log("[SobotBuild] Info.plist permissions patched");
    }

    /// <summary>
    /// 递归复制目录
    /// </summary>
    private static void CopyDirectory(string src, string dst)
    {
        if (Directory.Exists(dst))
            Directory.Delete(dst, true);

        Directory.CreateDirectory(dst);

        foreach (string file in Directory.GetFiles(src))
        {
            string fileName = Path.GetFileName(file);
            // 跳过 .DS_Store 和 Unity meta 文件
            if (fileName == ".DS_Store" || fileName.EndsWith(".meta")) continue;
            File.Copy(file, Path.Combine(dst, fileName));
        }

        foreach (string dir in Directory.GetDirectories(src))
        {
            string dirName = Path.GetFileName(dir);
            CopyDirectory(dir, Path.Combine(dst, dirName));
        }
    }
}
#endif
