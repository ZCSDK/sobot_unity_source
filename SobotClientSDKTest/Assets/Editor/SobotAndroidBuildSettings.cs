using UnityEditor;
using UnityEngine;

[InitializeOnLoad]
public static class SobotAndroidBuildSettings
{
    static SobotAndroidBuildSettings()
    {
        EditorApplication.delayCall += Apply;
    }

    [MenuItem("Sobot/Apply Android Build Settings")]
    public static void Apply()
    {
        bool changed = false;

        if (PlayerSettings.GetScriptingBackend(BuildTargetGroup.Android) != ScriptingImplementation.IL2CPP)
        {
            PlayerSettings.SetScriptingBackend(BuildTargetGroup.Android, ScriptingImplementation.IL2CPP);
            changed = true;
        }

        if (PlayerSettings.Android.targetArchitectures != AndroidArchitecture.ARM64)
        {
            PlayerSettings.Android.targetArchitectures = AndroidArchitecture.ARM64;
            changed = true;
        }

        if (changed)
        {
            AssetDatabase.SaveAssets();
            Debug.Log("[SobotBuild] Android build settings applied: IL2CPP + ARM64");
        }
    }
}
