using System;
using System.IO;
using UnityEditor;
using UnityEngine;

public static class SobotPackageExporter
{
    private const string PackageName = "SobotUnitySDK";
    private const string DemoPackageName = "SobotUnitySDK_Demo";
    private const string DesktopFolderName = "三方平台SDK集成";
    private const string OutputFolderName = "UnitySDKPackage";

    private static readonly string[] SdkAssetPaths =
    {
        "Assets/Plugins/Sobot",
        "Assets/Editor/SobotPostProcessBuild.cs",
        "Assets/Editor/SobotAndroidBuildSettings.cs",
        "Assets/Editor/SobotLocalBuildCacheCleaner.cs"
    };

    private static readonly string[] DemoAssetPaths =
    {
        "Assets/Plugins/Sobot",
        "Assets/Editor/SobotPostProcessBuild.cs",
        "Assets/Editor/SobotAndroidBuildSettings.cs",
        "Assets/Editor/SobotLocalBuildCacheCleaner.cs",
        "Assets/StartPage.cs",
        "Assets/Scenes/SampleScene.unity"
    };

    [MenuItem("Sobot/Export Unity SDK Package")]
    public static void ExportSdkPackage()
    {
        ExportPackage(PackageName, SdkAssetPaths);
    }

    [MenuItem("Sobot/Export Unity SDK Demo Package")]
    public static void ExportDemoPackage()
    {
        ExportPackage(DemoPackageName, DemoAssetPaths);
    }

    public static void ExportSdkPackageForCI()
    {
        ExportSdkPackage();
    }

    public static void ExportDemoPackageForCI()
    {
        ExportDemoPackage();
    }

    private static void ExportPackage(string packageName, string[] assetPaths)
    {
        string outputDir = GetDefaultOutputDir();
        Directory.CreateDirectory(outputDir);

        string timestamp = DateTime.Now.ToString("yyyyMMdd_HHmmss");
        string packagePath = Path.Combine(outputDir, $"{packageName}_{timestamp}.unitypackage");

        AssetDatabase.Refresh();
        AssetDatabase.ExportPackage(
            assetPaths,
            packagePath,
            ExportPackageOptions.Recurse | ExportPackageOptions.IncludeDependencies
        );

        Debug.Log($"[SobotPackage] Exported {packageName}: {packagePath}");
        if (!Application.isBatchMode)
        {
            EditorUtility.RevealInFinder(packagePath);
        }
    }

    private static string GetDefaultOutputDir()
    {
        string desktop = Environment.GetFolderPath(Environment.SpecialFolder.DesktopDirectory);
        return Path.Combine(desktop, DesktopFolderName, OutputFolderName);
    }
}
