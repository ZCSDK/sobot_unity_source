#include "pch-cpp.hpp"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif


#include <limits>


template <typename R>
struct VirtualFuncInvoker0
{
	typedef R (*Func)(void*, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj, invokeData.method);
	}
};
template <typename T1>
struct InvokerActionInvoker1
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1 p1)
	{
		void* params[1] = { &p1 };
		method->invoker_method(methodPtr, method, obj, params, NULL);
	}
};
template <typename T1, typename T2>
struct InvokerActionInvoker2;
template <typename T1, typename T2>
struct InvokerActionInvoker2<T1, T2*>
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1 p1, T2* p2)
	{
		void* params[2] = { &p1, p2 };
		method->invoker_method(methodPtr, method, obj, params, NULL);
	}
};
template <typename T1, typename T2>
struct InvokerActionInvoker2<T1*, T2>
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1, T2 p2)
	{
		void* params[2] = { p1, &p2 };
		method->invoker_method(methodPtr, method, obj, params, NULL);
	}
};
template <typename T1, typename T2, typename T3>
struct InvokerActionInvoker3
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1 p1, T2 p2, T3 p3)
	{
		void* params[3] = { &p1, &p2, &p3 };
		method->invoker_method(methodPtr, method, obj, params, NULL);
	}
};
template <typename T1, typename T2, typename T3>
struct InvokerActionInvoker3<T1, T2, T3*>
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1 p1, T2 p2, T3* p3)
	{
		void* params[3] = { &p1, &p2, p3 };
		method->invoker_method(methodPtr, method, obj, params, NULL);
	}
};
template <typename T1, typename T2, typename T3>
struct InvokerActionInvoker3<T1*, T2, T3*>
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1, T2 p2, T3* p3)
	{
		void* params[3] = { p1, &p2, p3 };
		method->invoker_method(methodPtr, method, obj, params, NULL);
	}
};
template <typename T1, typename T2, typename T3, typename T4>
struct InvokerActionInvoker4;
template <typename T1, typename T2, typename T3, typename T4>
struct InvokerActionInvoker4<T1*, T2, T3, T4>
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1, T2 p2, T3 p3, T4 p4)
	{
		void* params[4] = { p1, &p2, &p3, &p4 };
		method->invoker_method(methodPtr, method, obj, params, NULL);
	}
};
template <typename T1, typename T2, typename T3, typename T4>
struct InvokerActionInvoker4<T1*, T2, T3, T4*>
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1, T2 p2, T3 p3, T4* p4)
	{
		void* params[4] = { p1, &p2, &p3, p4 };
		method->invoker_method(methodPtr, method, obj, params, NULL);
	}
};
template <typename R, typename T1>
struct InvokerFuncInvoker1;
template <typename R, typename T1>
struct InvokerFuncInvoker1<R, T1*>
{
	static inline R Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1)
	{
		R ret;
		void* params[1] = { p1 };
		method->invoker_method(methodPtr, method, obj, params, &ret);
		return ret;
	}
};
template <typename R, typename T1, typename T2>
struct InvokerFuncInvoker2;
template <typename R, typename T1, typename T2>
struct InvokerFuncInvoker2<R, T1*, T2*>
{
	static inline R Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1, T2* p2)
	{
		R ret;
		void* params[2] = { p1, p2 };
		method->invoker_method(methodPtr, method, obj, params, &ret);
		return ret;
	}
};

// System.Collections.Generic.Dictionary`2<System.Object,System.Object>
struct Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA;
// System.Collections.Generic.Dictionary`2<System.String,SobotChatClient.ZCSobotApi/SendMessageResultCallback>
struct Dictionary_2_t90FE42767FAF03DFB400884E3F5B327D48A268A5;
// System.Collections.Generic.IEqualityComparer`1<System.String>
struct IEqualityComparer_1_tAE94C8F24AD5B94D4EE85CA9FC59E3409D41CAF7;
// System.Collections.Generic.Dictionary`2/KeyCollection<System.String,SobotChatClient.ZCSobotApi/SendMessageResultCallback>
struct KeyCollection_t6FB69EF3B5BE954211475F41C4279D9E68FDDF73;
// System.Collections.Generic.Dictionary`2/ValueCollection<System.String,SobotChatClient.ZCSobotApi/SendMessageResultCallback>
struct ValueCollection_t588203DD5E0FB22247FEAD430E2EF7E9CE59D7F8;
// System.Collections.Generic.Dictionary`2/Entry<System.String,SobotChatClient.ZCSobotApi/SendMessageResultCallback>[]
struct EntryU5BU5D_tE5FF8FA705E9631C3A2800CE145CA0AB97D0BD66;
// System.Byte[]
struct ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031;
// System.Char[]
struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB;
// System.Delegate[]
struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771;
// System.Int32[]
struct Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C;
// System.IntPtr[]
struct IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832;
// System.Diagnostics.StackTrace[]
struct StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF;
// System.String[]
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248;
// System.AsyncCallback
struct AsyncCallback_t7FEF460CBDCFB9C5FA2EF776984778B9A4145F4C;
// UnityEngine.Component
struct Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3;
// System.Delegate
struct Delegate_t;
// System.DelegateData
struct DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E;
// UnityEngine.GameObject
struct GameObject_t76FEDD663AB33C991A9C9A23129337651094216F;
// System.IAsyncResult
struct IAsyncResult_t7B9B5A0ECB35DCEC31B8A8122C37D687369253B5;
// System.Collections.IDictionary
struct IDictionary_t6D03155AF1FA9083817AA5B6AD7DEEACC26AB220;
// System.Reflection.MethodInfo
struct MethodInfo_t;
// UnityEngine.MonoBehaviour
struct MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71;
// UnityEngine.Object
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C;
// System.Runtime.Serialization.SafeSerializationManager
struct SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6;
// SobotChatClient.SobotParams
struct SobotParams_tCF40A43A8D519A95915ED461EFEF2BDDCA5B5168;
// System.String
struct String_t;
// System.Void
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;
// SobotChatClient.ZCSobotApi
struct ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179;
// SobotChatClient.ZCSobotApi/FunctionClickCallback
struct FunctionClickCallback_t133340AD88A3E68729476CCC597F418302E4F28C;
// SobotChatClient.ZCSobotApi/IOSFunctionClickCallback
struct IOSFunctionClickCallback_t9B9C81DAECBDABE1B68AD43DA4E42635B1A95613;
// SobotChatClient.ZCSobotApi/IOSLinkClickCallback
struct IOSLinkClickCallback_tE93B6F4ED698136320B42F54DE5AC652D635701A;
// SobotChatClient.ZCSobotApi/InitResultCallback
struct InitResultCallback_t681E10D9230FD32958B962D5B649178586A97B7B;
// SobotChatClient.ZCSobotApi/LinkClickCallback
struct LinkClickCallback_t74FFEF1A7387D900A6578354799B79ECB1F3013E;
// SobotChatClient.ZCSobotApi/OfflineMsgCallback
struct OfflineMsgCallback_t95A2C0AE5DEFB9A1F73D67591217112C51B655D5;
// SobotChatClient.ZCSobotApi/SendMessageResultCallback
struct SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475;

IL2CPP_EXTERN_C RuntimeClass* Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Dictionary_2_t90FE42767FAF03DFB400884E3F5B327D48A268A5_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Exception_t_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* GameObject_t76FEDD663AB33C991A9C9A23129337651094216F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IOSFunctionClickCallback_t9B9C81DAECBDABE1B68AD43DA4E42635B1A95613_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IOSLinkClickCallback_tE93B6F4ED698136320B42F54DE5AC652D635701A_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* RuntimeObject_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* SobotParams_tCF40A43A8D519A95915ED461EFEF2BDDCA5B5168_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* String_t_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C String_t* _stringLiteral06EAFAB9DEBE8A08B1216B113227678999BA00B8;
IL2CPP_EXTERN_C String_t* _stringLiteral14EF2B4F89B1C436C288DDCF653B81A2C1A786C4;
IL2CPP_EXTERN_C String_t* _stringLiteral2130FB49D4CB4A6C571BDE45991342B2F508A1D7;
IL2CPP_EXTERN_C String_t* _stringLiteral29FFB7ED65745EEFF8D1344FEB8A6B11C4C5A30D;
IL2CPP_EXTERN_C String_t* _stringLiteral448227D0A5EEB181F876672782704616B083B472;
IL2CPP_EXTERN_C String_t* _stringLiteral4EECFFC6C6F65EC439CEFB53065347E575849864;
IL2CPP_EXTERN_C String_t* _stringLiteral4F947DD752BAA3989FD8419D4B2425AD0C64D6C3;
IL2CPP_EXTERN_C String_t* _stringLiteral55B2E83BA85EED92C9B92A6A1BC216FC775979CA;
IL2CPP_EXTERN_C String_t* _stringLiteral595B9660F30811FEE11F7F4A63960C9D25416A90;
IL2CPP_EXTERN_C String_t* _stringLiteral5998AB72D667A3790249FC2477019B8A1A4B2AA4;
IL2CPP_EXTERN_C String_t* _stringLiteral5C0BC41AEE490DECA39B09619BAB8A416DC51077;
IL2CPP_EXTERN_C String_t* _stringLiteral6A395A640DCD0CAF877376113637F2876AC13B86;
IL2CPP_EXTERN_C String_t* _stringLiteral6ADA0DA779CE14355F1491C7EDA8C261D0D30480;
IL2CPP_EXTERN_C String_t* _stringLiteral6B7357B96E5399281C1DCFB6D78DB0E743B72BE1;
IL2CPP_EXTERN_C String_t* _stringLiteral709B70FE91B8BFC5062F4A07C1092D933B39B43B;
IL2CPP_EXTERN_C String_t* _stringLiteral72C82332D5DAF09CA94510D07B0E9CA2CD684F55;
IL2CPP_EXTERN_C String_t* _stringLiteral7A34F23A1242AA68485695F3DDF5C917EF2F0071;
IL2CPP_EXTERN_C String_t* _stringLiteral839FEB4159DABB7E5B5A06411C01ADE5012AAEBF;
IL2CPP_EXTERN_C String_t* _stringLiteral88FF9681ACC4160649786C9DB30EE86B79D22400;
IL2CPP_EXTERN_C String_t* _stringLiteral9235B2F5272F8AC7DEF6528CFE0675DA82D78199;
IL2CPP_EXTERN_C String_t* _stringLiteralB5099EC8CF481EF20354A7A53CAB860C81B09DCC;
IL2CPP_EXTERN_C String_t* _stringLiteralCA6B1C0631ABBE286728F052CFB9F3C70570B165;
IL2CPP_EXTERN_C String_t* _stringLiteralCF05829BAF1CDB87EC20E7C2B048FC8CD4399638;
IL2CPP_EXTERN_C String_t* _stringLiteralE5BDED738C6E9E230527D4C93CA322D8A99A0ECA;
IL2CPP_EXTERN_C String_t* _stringLiteralE9B162451526A2D190CEED3541835A10DCC2297C;
IL2CPP_EXTERN_C String_t* _stringLiteralEDD631D0D16C8226715DF2EC43CB2043F96199C8;
IL2CPP_EXTERN_C String_t* _stringLiteralF3604A983170476BA44D180A6DCF7BED87FB7359;
IL2CPP_EXTERN_C String_t* _stringLiteralF4C4C79442D53DB4FB4C8871F94A71CE073D6411;
IL2CPP_EXTERN_C String_t* _stringLiteralFCA74A9060DDEE6A3ECAE73E6AB96086770BE7E2;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_Remove_m6FA8FA49F3ED92FB7B3CB2B1092724F101C9B5D2_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_TryGetValue_m475E1A033333E5803F84DE43B65E527E77893F75_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2__ctor_m2BE66DBDC8AABB2807C7D4BDACF197D4372CCEBF_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Dictionary_2_set_Item_m8DAD2B757C763B0BE87D5193C64D145376059412_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* GameObject_AddComponent_TisZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_m33CC8380AEDE74B122867E5D940950D41729FAE3_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* ZCSobotApi_OnIOSFunctionClick_mCF84458642714F9D17C0ED66580DC8F5A879B718_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* ZCSobotApi_OnIOSLinkClick_mEEE708A3A1CBF9864C804FADC93618A3B752F03F_RuntimeMethod_var;
struct Delegate_t_marshaled_com;
struct Delegate_t_marshaled_pinvoke;
struct Exception_t_marshaled_com;
struct Exception_t_marshaled_pinvoke;

struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB;
struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771;
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248;

IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// <Module>
struct U3CModuleU3E_tF062866229C4952B8051AD32AB6E9D931142CC95 
{
};

// System.Collections.Generic.Dictionary`2<System.String,SobotChatClient.ZCSobotApi/SendMessageResultCallback>
struct Dictionary_2_t90FE42767FAF03DFB400884E3F5B327D48A268A5  : public RuntimeObject
{
	// System.Int32[] System.Collections.Generic.Dictionary`2::_buckets
	Int32U5BU5D_t19C97395396A72ECAF310612F0760F165060314C* ____buckets_0;
	// System.Collections.Generic.Dictionary`2/Entry<TKey,TValue>[] System.Collections.Generic.Dictionary`2::_entries
	EntryU5BU5D_tE5FF8FA705E9631C3A2800CE145CA0AB97D0BD66* ____entries_1;
	// System.Int32 System.Collections.Generic.Dictionary`2::_count
	int32_t ____count_2;
	// System.Int32 System.Collections.Generic.Dictionary`2::_freeList
	int32_t ____freeList_3;
	// System.Int32 System.Collections.Generic.Dictionary`2::_freeCount
	int32_t ____freeCount_4;
	// System.Int32 System.Collections.Generic.Dictionary`2::_version
	int32_t ____version_5;
	// System.Collections.Generic.IEqualityComparer`1<TKey> System.Collections.Generic.Dictionary`2::_comparer
	RuntimeObject* ____comparer_6;
	// System.Collections.Generic.Dictionary`2/KeyCollection<TKey,TValue> System.Collections.Generic.Dictionary`2::_keys
	KeyCollection_t6FB69EF3B5BE954211475F41C4279D9E68FDDF73* ____keys_7;
	// System.Collections.Generic.Dictionary`2/ValueCollection<TKey,TValue> System.Collections.Generic.Dictionary`2::_values
	ValueCollection_t588203DD5E0FB22247FEAD430E2EF7E9CE59D7F8* ____values_8;
	// System.Object System.Collections.Generic.Dictionary`2::_syncRoot
	RuntimeObject* ____syncRoot_9;
};

// SobotChatClient.SobotParams
struct SobotParams_tCF40A43A8D519A95915ED461EFEF2BDDCA5B5168  : public RuntimeObject
{
	// System.String SobotChatClient.SobotParams::api_host
	String_t* ___api_host_0;
	// System.String SobotChatClient.SobotParams::app_key
	String_t* ___app_key_1;
	// System.String SobotChatClient.SobotParams::partnerid
	String_t* ___partnerid_2;
	// System.String SobotChatClient.SobotParams::choose_adminid
	String_t* ___choose_adminid_3;
	// System.String SobotChatClient.SobotParams::tran_flag
	String_t* ___tran_flag_4;
	// System.String SobotChatClient.SobotParams::user_nick
	String_t* ___user_nick_5;
	// System.String SobotChatClient.SobotParams::user_name
	String_t* ___user_name_6;
	// System.String SobotChatClient.SobotParams::user_tels
	String_t* ___user_tels_7;
	// System.String SobotChatClient.SobotParams::user_emails
	String_t* ___user_emails_8;
	// System.String SobotChatClient.SobotParams::isVip
	String_t* ___isVip_9;
	// System.String SobotChatClient.SobotParams::vip_level
	String_t* ___vip_level_10;
	// System.String SobotChatClient.SobotParams::user_label
	String_t* ___user_label_11;
	// System.String SobotChatClient.SobotParams::qq
	String_t* ___qq_12;
	// System.String SobotChatClient.SobotParams::face
	String_t* ___face_13;
	// System.String SobotChatClient.SobotParams::remark
	String_t* ___remark_14;
	// System.String SobotChatClient.SobotParams::params
	String_t* ___params_15;
	// System.String SobotChatClient.SobotParams::customer_fields
	String_t* ___customer_fields_16;
	// System.String SobotChatClient.SobotParams::multi_params
	String_t* ___multi_params_17;
	// System.String SobotChatClient.SobotParams::groupid
	String_t* ___groupid_18;
	// System.String SobotChatClient.SobotParams::group_name
	String_t* ___group_name_19;
	// System.Int32 SobotChatClient.SobotParams::good_msg_type
	int32_t ___good_msg_type_20;
	// System.String SobotChatClient.SobotParams::content
	String_t* ___content_21;
	// System.String SobotChatClient.SobotParams::absolute_language
	String_t* ___absolute_language_22;
	// System.String SobotChatClient.SobotParams::urlRegular
	String_t* ___urlRegular_23;
	// System.String SobotChatClient.SobotParams::telRegular
	String_t* ___telRegular_24;
	// System.Boolean SobotChatClient.SobotParams::isOpenRecord
	bool ___isOpenRecord_25;
	// System.Boolean SobotChatClient.SobotParams::isOpenRobotVoice
	bool ___isOpenRobotVoice_26;
	// System.Boolean SobotChatClient.SobotParams::isShowReturnTips
	bool ___isShowReturnTips_27;
	// System.Boolean SobotChatClient.SobotParams::isShowClose
	bool ___isShowClose_28;
	// System.Boolean SobotChatClient.SobotParams::isOpenEvaluation
	bool ___isOpenEvaluation_29;
	// System.Boolean SobotChatClient.SobotParams::isShowEvaluation
	bool ___isShowEvaluation_30;
	// System.Boolean SobotChatClient.SobotParams::isShowCloseSatisfaction
	bool ___isShowCloseSatisfaction_31;
	// System.Boolean SobotChatClient.SobotParams::isCloseAfterEvaluation
	bool ___isCloseAfterEvaluation_32;
	// System.Boolean SobotChatClient.SobotParams::canBackWithNotEvaluation
	bool ___canBackWithNotEvaluation_33;
	// System.Boolean SobotChatClient.SobotParams::hideRototEvaluationLabels
	bool ___hideRototEvaluationLabels_34;
	// System.Boolean SobotChatClient.SobotParams::hideManualEvaluationLabels
	bool ___hideManualEvaluationLabels_35;
	// System.String SobotChatClient.SobotParams::leaveMsgGroupId
	String_t* ___leaveMsgGroupId_36;
	// System.Boolean SobotChatClient.SobotParams::leaveCompleteCanReply
	bool ___leaveCompleteCanReply_37;
	// System.Boolean SobotChatClient.SobotParams::isShowLog
	bool ___isShowLog_38;
	// System.Boolean SobotChatClient.SobotParams::landscape_screen
	bool ___landscape_screen_39;
	// System.Boolean SobotChatClient.SobotParams::isLandscapeMode
	bool ___isLandscapeMode_40;
	// System.Boolean SobotChatClient.SobotParams::showNotification
	bool ___showNotification_41;
	// System.Boolean SobotChatClient.SobotParams::isShowPortrait
	bool ___isShowPortrait_42;
	// System.Boolean SobotChatClient.SobotParams::ishidesBottomBarWhenPushed
	bool ___ishidesBottomBarWhenPushed_43;
	// System.Boolean SobotChatClient.SobotParams::navcBarHidden
	bool ___navcBarHidden_44;
	// System.Boolean SobotChatClient.SobotParams::isUseImagesxcassets
	bool ___isUseImagesxcassets_45;
	// System.String SobotChatClient.SobotParams::deviceToken
	String_t* ___deviceToken_46;
	// System.Boolean SobotChatClient.SobotParams::autoNotification
	bool ___autoNotification_47;
	// System.String SobotChatClient.SobotParams::custom_card
	String_t* ___custom_card_48;
	// System.String SobotChatClient.SobotParams::goodsTitle
	String_t* ___goodsTitle_49;
	// System.String SobotChatClient.SobotParams::goodsDesc
	String_t* ___goodsDesc_50;
	// System.String SobotChatClient.SobotParams::goodsLabel
	String_t* ___goodsLabel_51;
	// System.String SobotChatClient.SobotParams::goodsLink
	String_t* ___goodsLink_52;
	// System.String SobotChatClient.SobotParams::goodsImage
	String_t* ___goodsImage_53;
	// System.Boolean SobotChatClient.SobotParams::isSendInfoCard
	bool ___isSendInfoCard_54;
	// System.Boolean SobotChatClient.SobotParams::isEveryTimeSendCard
	bool ___isEveryTimeSendCard_55;
	// System.String SobotChatClient.SobotParams::orderCode
	String_t* ___orderCode_56;
	// System.String SobotChatClient.SobotParams::orderStatus
	String_t* ___orderStatus_57;
	// System.String SobotChatClient.SobotParams::statusCustom
	String_t* ___statusCustom_58;
	// System.String SobotChatClient.SobotParams::createTime
	String_t* ___createTime_59;
	// System.String SobotChatClient.SobotParams::goodsCount
	String_t* ___goodsCount_60;
	// System.String SobotChatClient.SobotParams::orderUrl
	String_t* ___orderUrl_61;
	// System.String SobotChatClient.SobotParams::goods
	String_t* ___goods_62;
	// System.String SobotChatClient.SobotParams::totalFee
	String_t* ___totalFee_63;
	// System.Boolean SobotChatClient.SobotParams::autoSendOrderMessage
	bool ___autoSendOrderMessage_64;
	// System.Boolean SobotChatClient.SobotParams::isEveryTimeAutoSend
	bool ___isEveryTimeAutoSend_65;
	// System.String SobotChatClient.SobotParams::lat
	String_t* ___lat_66;
	// System.String SobotChatClient.SobotParams::lng
	String_t* ___lng_67;
	// System.String SobotChatClient.SobotParams::localLabel
	String_t* ___localLabel_68;
	// System.String SobotChatClient.SobotParams::localName
	String_t* ___localName_69;
	// System.String SobotChatClient.SobotParams::file
	String_t* ___file_70;
	// System.String SobotChatClient.SobotParams::cusMoreArray
	String_t* ___cusMoreArray_71;
	// System.Boolean SobotChatClient.SobotParams::closePush
	bool ___closePush_72;
};

// System.String
struct String_t  : public RuntimeObject
{
	// System.Int32 System.String::_stringLength
	int32_t ____stringLength_4;
	// System.Char System.String::_firstChar
	Il2CppChar ____firstChar_5;
};

// System.ValueType
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F  : public RuntimeObject
{
};
// Native definition for P/Invoke marshalling of System.ValueType
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_pinvoke
{
};
// Native definition for COM marshalling of System.ValueType
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_com
{
};

// System.Boolean
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22 
{
	// System.Boolean System.Boolean::m_value
	bool ___m_value_0;
};

// System.Char
struct Char_t521A6F19B456D956AF452D926C32709DC03D6B17 
{
	// System.Char System.Char::m_value
	Il2CppChar ___m_value_0;
};

// System.Enum
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2  : public ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F
{
};
// Native definition for P/Invoke marshalling of System.Enum
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_marshaled_pinvoke
{
};
// Native definition for COM marshalling of System.Enum
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_marshaled_com
{
};

// System.Int32
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C 
{
	// System.Int32 System.Int32::m_value
	int32_t ___m_value_0;
};

// System.IntPtr
struct IntPtr_t 
{
	// System.Void* System.IntPtr::m_value
	void* ___m_value_0;
};

// System.Void
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915 
{
	union
	{
		struct
		{
		};
		uint8_t Void_t4861ACF8F4594C3437BB48B6E56783494B843915__padding[1];
	};
};

// System.Delegate
struct Delegate_t  : public RuntimeObject
{
	// System.IntPtr System.Delegate::method_ptr
	intptr_t ___method_ptr_0;
	// System.IntPtr System.Delegate::invoke_impl
	intptr_t ___invoke_impl_1;
	// System.Object System.Delegate::m_target
	RuntimeObject* ___m_target_2;
	// System.IntPtr System.Delegate::method
	intptr_t ___method_3;
	// System.IntPtr System.Delegate::delegate_trampoline
	intptr_t ___delegate_trampoline_4;
	// System.IntPtr System.Delegate::extra_arg
	intptr_t ___extra_arg_5;
	// System.IntPtr System.Delegate::method_code
	intptr_t ___method_code_6;
	// System.IntPtr System.Delegate::interp_method
	intptr_t ___interp_method_7;
	// System.IntPtr System.Delegate::interp_invoke_impl
	intptr_t ___interp_invoke_impl_8;
	// System.Reflection.MethodInfo System.Delegate::method_info
	MethodInfo_t* ___method_info_9;
	// System.Reflection.MethodInfo System.Delegate::original_method_info
	MethodInfo_t* ___original_method_info_10;
	// System.DelegateData System.Delegate::data
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data_11;
	// System.Boolean System.Delegate::method_is_virtual
	bool ___method_is_virtual_12;
};
// Native definition for P/Invoke marshalling of System.Delegate
struct Delegate_t_marshaled_pinvoke
{
	intptr_t ___method_ptr_0;
	intptr_t ___invoke_impl_1;
	Il2CppIUnknown* ___m_target_2;
	intptr_t ___method_3;
	intptr_t ___delegate_trampoline_4;
	intptr_t ___extra_arg_5;
	intptr_t ___method_code_6;
	intptr_t ___interp_method_7;
	intptr_t ___interp_invoke_impl_8;
	MethodInfo_t* ___method_info_9;
	MethodInfo_t* ___original_method_info_10;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data_11;
	int32_t ___method_is_virtual_12;
};
// Native definition for COM marshalling of System.Delegate
struct Delegate_t_marshaled_com
{
	intptr_t ___method_ptr_0;
	intptr_t ___invoke_impl_1;
	Il2CppIUnknown* ___m_target_2;
	intptr_t ___method_3;
	intptr_t ___delegate_trampoline_4;
	intptr_t ___extra_arg_5;
	intptr_t ___method_code_6;
	intptr_t ___interp_method_7;
	intptr_t ___interp_invoke_impl_8;
	MethodInfo_t* ___method_info_9;
	MethodInfo_t* ___original_method_info_10;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data_11;
	int32_t ___method_is_virtual_12;
};

// System.Exception
struct Exception_t  : public RuntimeObject
{
	// System.String System.Exception::_className
	String_t* ____className_1;
	// System.String System.Exception::_message
	String_t* ____message_2;
	// System.Collections.IDictionary System.Exception::_data
	RuntimeObject* ____data_3;
	// System.Exception System.Exception::_innerException
	Exception_t* ____innerException_4;
	// System.String System.Exception::_helpURL
	String_t* ____helpURL_5;
	// System.Object System.Exception::_stackTrace
	RuntimeObject* ____stackTrace_6;
	// System.String System.Exception::_stackTraceString
	String_t* ____stackTraceString_7;
	// System.String System.Exception::_remoteStackTraceString
	String_t* ____remoteStackTraceString_8;
	// System.Int32 System.Exception::_remoteStackIndex
	int32_t ____remoteStackIndex_9;
	// System.Object System.Exception::_dynamicMethods
	RuntimeObject* ____dynamicMethods_10;
	// System.Int32 System.Exception::_HResult
	int32_t ____HResult_11;
	// System.String System.Exception::_source
	String_t* ____source_12;
	// System.Runtime.Serialization.SafeSerializationManager System.Exception::_safeSerializationManager
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager_13;
	// System.Diagnostics.StackTrace[] System.Exception::captured_traces
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces_14;
	// System.IntPtr[] System.Exception::native_trace_ips
	IntPtrU5BU5D_tFD177F8C806A6921AD7150264CCC62FA00CAD832* ___native_trace_ips_15;
	// System.Int32 System.Exception::caught_in_unmanaged
	int32_t ___caught_in_unmanaged_16;
};
// Native definition for P/Invoke marshalling of System.Exception
struct Exception_t_marshaled_pinvoke
{
	char* ____className_1;
	char* ____message_2;
	RuntimeObject* ____data_3;
	Exception_t_marshaled_pinvoke* ____innerException_4;
	char* ____helpURL_5;
	Il2CppIUnknown* ____stackTrace_6;
	char* ____stackTraceString_7;
	char* ____remoteStackTraceString_8;
	int32_t ____remoteStackIndex_9;
	Il2CppIUnknown* ____dynamicMethods_10;
	int32_t ____HResult_11;
	char* ____source_12;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager_13;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces_14;
	Il2CppSafeArray/*NONE*/* ___native_trace_ips_15;
	int32_t ___caught_in_unmanaged_16;
};
// Native definition for COM marshalling of System.Exception
struct Exception_t_marshaled_com
{
	Il2CppChar* ____className_1;
	Il2CppChar* ____message_2;
	RuntimeObject* ____data_3;
	Exception_t_marshaled_com* ____innerException_4;
	Il2CppChar* ____helpURL_5;
	Il2CppIUnknown* ____stackTrace_6;
	Il2CppChar* ____stackTraceString_7;
	Il2CppChar* ____remoteStackTraceString_8;
	int32_t ____remoteStackIndex_9;
	Il2CppIUnknown* ____dynamicMethods_10;
	int32_t ____HResult_11;
	Il2CppChar* ____source_12;
	SafeSerializationManager_tCBB85B95DFD1634237140CD892E82D06ECB3F5E6* ____safeSerializationManager_13;
	StackTraceU5BU5D_t32FBCB20930EAF5BAE3F450FF75228E5450DA0DF* ___captured_traces_14;
	Il2CppSafeArray/*NONE*/* ___native_trace_ips_15;
	int32_t ___caught_in_unmanaged_16;
};

// UnityEngine.Object
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C  : public RuntimeObject
{
	// System.IntPtr UnityEngine.Object::m_CachedPtr
	intptr_t ___m_CachedPtr_0;
};
// Native definition for P/Invoke marshalling of UnityEngine.Object
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_marshaled_pinvoke
{
	intptr_t ___m_CachedPtr_0;
};
// Native definition for COM marshalling of UnityEngine.Object
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_marshaled_com
{
	intptr_t ___m_CachedPtr_0;
};

// System.StringSplitOptions
struct StringSplitOptions_t4DD892C76C70DD4800FC1B76054D69826F770062 
{
	// System.Int32 System.StringSplitOptions::value__
	int32_t ___value___2;
};

// UnityEngine.Component
struct Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3  : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C
{
};

// UnityEngine.GameObject
struct GameObject_t76FEDD663AB33C991A9C9A23129337651094216F  : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C
{
};

// System.MulticastDelegate
struct MulticastDelegate_t  : public Delegate_t
{
	// System.Delegate[] System.MulticastDelegate::delegates
	DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771* ___delegates_13;
};
// Native definition for P/Invoke marshalling of System.MulticastDelegate
struct MulticastDelegate_t_marshaled_pinvoke : public Delegate_t_marshaled_pinvoke
{
	Delegate_t_marshaled_pinvoke** ___delegates_13;
};
// Native definition for COM marshalling of System.MulticastDelegate
struct MulticastDelegate_t_marshaled_com : public Delegate_t_marshaled_com
{
	Delegate_t_marshaled_com** ___delegates_13;
};

// System.AsyncCallback
struct AsyncCallback_t7FEF460CBDCFB9C5FA2EF776984778B9A4145F4C  : public MulticastDelegate_t
{
};

// UnityEngine.Behaviour
struct Behaviour_t01970CFBBA658497AE30F311C447DB0440BAB7FA  : public Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3
{
};

// SobotChatClient.ZCSobotApi/FunctionClickCallback
struct FunctionClickCallback_t133340AD88A3E68729476CCC597F418302E4F28C  : public MulticastDelegate_t
{
};

// SobotChatClient.ZCSobotApi/IOSFunctionClickCallback
struct IOSFunctionClickCallback_t9B9C81DAECBDABE1B68AD43DA4E42635B1A95613  : public MulticastDelegate_t
{
};

// SobotChatClient.ZCSobotApi/IOSLinkClickCallback
struct IOSLinkClickCallback_tE93B6F4ED698136320B42F54DE5AC652D635701A  : public MulticastDelegate_t
{
};

// SobotChatClient.ZCSobotApi/InitResultCallback
struct InitResultCallback_t681E10D9230FD32958B962D5B649178586A97B7B  : public MulticastDelegate_t
{
};

// SobotChatClient.ZCSobotApi/LinkClickCallback
struct LinkClickCallback_t74FFEF1A7387D900A6578354799B79ECB1F3013E  : public MulticastDelegate_t
{
};

// SobotChatClient.ZCSobotApi/OfflineMsgCallback
struct OfflineMsgCallback_t95A2C0AE5DEFB9A1F73D67591217112C51B655D5  : public MulticastDelegate_t
{
};

// SobotChatClient.ZCSobotApi/SendMessageResultCallback
struct SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475  : public MulticastDelegate_t
{
};

// UnityEngine.MonoBehaviour
struct MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71  : public Behaviour_t01970CFBBA658497AE30F311C447DB0440BAB7FA
{
};

// SobotChatClient.ZCSobotApi
struct ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
};

// <Module>

// <Module>

// System.Collections.Generic.Dictionary`2<System.String,SobotChatClient.ZCSobotApi/SendMessageResultCallback>

// System.Collections.Generic.Dictionary`2<System.String,SobotChatClient.ZCSobotApi/SendMessageResultCallback>

// SobotChatClient.SobotParams

// SobotChatClient.SobotParams

// System.String
struct String_t_StaticFields
{
	// System.String System.String::Empty
	String_t* ___Empty_6;
};

// System.String

// System.Boolean
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_StaticFields
{
	// System.String System.Boolean::TrueString
	String_t* ___TrueString_5;
	// System.String System.Boolean::FalseString
	String_t* ___FalseString_6;
};

// System.Boolean

// System.Char
struct Char_t521A6F19B456D956AF452D926C32709DC03D6B17_StaticFields
{
	// System.Byte[] System.Char::s_categoryForLatin1
	ByteU5BU5D_tA6237BF417AE52AD70CFB4EF24A7A82613DF9031* ___s_categoryForLatin1_3;
};

// System.Char

// System.Int32

// System.Int32

// System.IntPtr
struct IntPtr_t_StaticFields
{
	// System.IntPtr System.IntPtr::Zero
	intptr_t ___Zero_1;
};

// System.IntPtr

// System.Void

// System.Void

// System.Delegate

// System.Delegate

// System.Exception
struct Exception_t_StaticFields
{
	// System.Object System.Exception::s_EDILock
	RuntimeObject* ___s_EDILock_0;
};

// System.Exception

// UnityEngine.Object
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_StaticFields
{
	// System.Int32 UnityEngine.Object::OffsetOfInstanceIDInCPlusPlusObject
	int32_t ___OffsetOfInstanceIDInCPlusPlusObject_1;
};

// UnityEngine.Object

// System.StringSplitOptions

// System.StringSplitOptions

// UnityEngine.Component

// UnityEngine.Component

// UnityEngine.GameObject

// UnityEngine.GameObject

// System.AsyncCallback

// System.AsyncCallback

// SobotChatClient.ZCSobotApi/FunctionClickCallback

// SobotChatClient.ZCSobotApi/FunctionClickCallback

// SobotChatClient.ZCSobotApi/IOSFunctionClickCallback

// SobotChatClient.ZCSobotApi/IOSFunctionClickCallback

// SobotChatClient.ZCSobotApi/IOSLinkClickCallback

// SobotChatClient.ZCSobotApi/IOSLinkClickCallback

// SobotChatClient.ZCSobotApi/InitResultCallback

// SobotChatClient.ZCSobotApi/InitResultCallback

// SobotChatClient.ZCSobotApi/LinkClickCallback

// SobotChatClient.ZCSobotApi/LinkClickCallback

// SobotChatClient.ZCSobotApi/OfflineMsgCallback

// SobotChatClient.ZCSobotApi/OfflineMsgCallback

// SobotChatClient.ZCSobotApi/SendMessageResultCallback

// SobotChatClient.ZCSobotApi/SendMessageResultCallback

// UnityEngine.MonoBehaviour

// UnityEngine.MonoBehaviour

// SobotChatClient.ZCSobotApi
struct ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_StaticFields
{
	// SobotChatClient.ZCSobotApi SobotChatClient.ZCSobotApi::_instance
	ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179* ____instance_4;
	// SobotChatClient.ZCSobotApi/InitResultCallback SobotChatClient.ZCSobotApi::_initCallback
	InitResultCallback_t681E10D9230FD32958B962D5B649178586A97B7B* ____initCallback_5;
	// SobotChatClient.ZCSobotApi/OfflineMsgCallback SobotChatClient.ZCSobotApi::_offlineMsgCallback
	OfflineMsgCallback_t95A2C0AE5DEFB9A1F73D67591217112C51B655D5* ____offlineMsgCallback_6;
	// SobotChatClient.ZCSobotApi/LinkClickCallback SobotChatClient.ZCSobotApi::_linkClickCallback
	LinkClickCallback_t74FFEF1A7387D900A6578354799B79ECB1F3013E* ____linkClickCallback_7;
	// SobotChatClient.ZCSobotApi/FunctionClickCallback SobotChatClient.ZCSobotApi::_functionClickCallback
	FunctionClickCallback_t133340AD88A3E68729476CCC597F418302E4F28C* ____functionClickCallback_8;
	// System.Boolean SobotChatClient.ZCSobotApi::_isInitialized
	bool ____isInitialized_9;
	// System.Int32 SobotChatClient.ZCSobotApi::_sendRequestSeq
	int32_t ____sendRequestSeq_10;
	// System.Collections.Generic.Dictionary`2<System.String,SobotChatClient.ZCSobotApi/SendMessageResultCallback> SobotChatClient.ZCSobotApi::_sendCallbacks
	Dictionary_2_t90FE42767FAF03DFB400884E3F5B327D48A268A5* ____sendCallbacks_11;
	// SobotChatClient.ZCSobotApi/IOSLinkClickCallback SobotChatClient.ZCSobotApi::_iosLinkClickCallback
	IOSLinkClickCallback_tE93B6F4ED698136320B42F54DE5AC652D635701A* ____iosLinkClickCallback_12;
	// SobotChatClient.ZCSobotApi/IOSFunctionClickCallback SobotChatClient.ZCSobotApi::_iosFunctionClickCallback
	IOSFunctionClickCallback_t9B9C81DAECBDABE1B68AD43DA4E42635B1A95613* ____iosFunctionClickCallback_13;
};

// SobotChatClient.ZCSobotApi
#ifdef __clang__
#pragma clang diagnostic pop
#endif
// System.String[]
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248  : public RuntimeArray
{
	ALIGN_FIELD (8) String_t* m_Items[1];

	inline String_t* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline String_t** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, String_t* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline String_t* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline String_t** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, String_t* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
// System.Char[]
struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB  : public RuntimeArray
{
	ALIGN_FIELD (8) Il2CppChar m_Items[1];

	inline Il2CppChar GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Il2CppChar* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Il2CppChar value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline Il2CppChar GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Il2CppChar* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Il2CppChar value)
	{
		m_Items[index] = value;
	}
};
// System.Delegate[]
struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771  : public RuntimeArray
{
	ALIGN_FIELD (8) Delegate_t* m_Items[1];

	inline Delegate_t* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Delegate_t** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Delegate_t* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline Delegate_t* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Delegate_t** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Delegate_t* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};


// T UnityEngine.GameObject::AddComponent<System.Object>()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* GameObject_AddComponent_TisRuntimeObject_m69B93700FACCF372F5753371C6E8FB780800B824_gshared (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* __this, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Object>::set_Item(TKey,TValue)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2_set_Item_m1A840355E8EDAECEA9D0C6F5E51B248FAA449CBD_gshared (Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA* __this, RuntimeObject* ___0_key, RuntimeObject* ___1_value, const RuntimeMethod* method) ;
// System.Boolean System.Collections.Generic.Dictionary`2<System.Object,System.Object>::TryGetValue(TKey,TValue&)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_TryGetValue_mD15380A4ED7CDEE99EA45881577D26BA9CE1B849_gshared (Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA* __this, RuntimeObject* ___0_key, RuntimeObject** ___1_value, const RuntimeMethod* method) ;
// System.Boolean System.Collections.Generic.Dictionary`2<System.Object,System.Object>::Remove(TKey)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Dictionary_2_Remove_m5C7C45E75D951A75843F3F7AADD56ECD64F6BC86_gshared (Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA* __this, RuntimeObject* ___0_key, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2<System.Object,System.Object>::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Dictionary_2__ctor_m5B32FBC624618211EB461D59CFBB10E987FD1329_gshared (Dictionary_2_t14FE4A752A83D53771C584E4C8D14E01F2AFD7BA* __this, const RuntimeMethod* method) ;

// System.Void System.Object::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2 (RuntimeObject* __this, const RuntimeMethod* method) ;
// System.Boolean SobotChatClient.ZCSobotApi::OnIOSLinkClick(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ZCSobotApi_OnIOSLinkClick_mEEE708A3A1CBF9864C804FADC93618A3B752F03F (String_t* ___0_url, const RuntimeMethod* method) ;
// System.Void SobotChatClient.ZCSobotApi::OnIOSFunctionClick(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ZCSobotApi_OnIOSFunctionClick_mCF84458642714F9D17C0ED66580DC8F5A879B718 (int32_t ___0_type, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.Object::op_Equality(UnityEngine.Object,UnityEngine.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Object_op_Equality_mB6120F782D83091EF56A198FCEBCF066DB4A9605 (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___0_x, Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___1_y, const RuntimeMethod* method) ;
// System.Void UnityEngine.GameObject::.ctor(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void GameObject__ctor_m37D512B05D292F954792225E6C6EEE95293A9B88 (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* __this, String_t* ___0_name, const RuntimeMethod* method) ;
// T UnityEngine.GameObject::AddComponent<SobotChatClient.ZCSobotApi>()
inline ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179* GameObject_AddComponent_TisZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_m33CC8380AEDE74B122867E5D940950D41729FAE3 (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* __this, const RuntimeMethod* method)
{
	return ((  ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179* (*) (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*, const RuntimeMethod*))GameObject_AddComponent_TisRuntimeObject_m69B93700FACCF372F5753371C6E8FB780800B824_gshared)(__this, method);
}
// System.Void UnityEngine.Object::DontDestroyOnLoad(UnityEngine.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Object_DontDestroyOnLoad_m4B70C3AEF886C176543D1295507B6455C9DCAEA7 (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___0_target, const RuntimeMethod* method) ;
// SobotChatClient.ZCSobotApi SobotChatClient.ZCSobotApi::get_Instance()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179* ZCSobotApi_get_Instance_m18C6611F9559B4F664A217C5F0CCB64C426A4155 (const RuntimeMethod* method) ;
// System.String SobotChatClient.ZCSobotApi::ToJson(SobotChatClient.SobotParams)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* ZCSobotApi_ToJson_m9440B37BB22A914C7CAD146110FAA2DE92E7DF0A (SobotParams_tCF40A43A8D519A95915ED461EFEF2BDDCA5B5168* ___0_param, const RuntimeMethod* method) ;
// UnityEngine.GameObject UnityEngine.Component::get_gameObject()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* Component_get_gameObject_m57AEFBB14DB39EC476F740BA000E170355DE691B (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3* __this, const RuntimeMethod* method) ;
// System.String UnityEngine.Object::get_name()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Object_get_name_mAC2F6B897CF1303BA4249B4CB55271AFACBB6392 (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* __this, const RuntimeMethod* method) ;
// System.Void SobotChatClient.ZCSobotApi::_sobotInitSDK(System.String,System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ZCSobotApi__sobotInitSDK_m1EF8E1459C431F7397BFCB9631960AC4B0AC631D (String_t* ___0_paramJson, String_t* ___1_gameObjectName, String_t* ___2_callbackMethod, const RuntimeMethod* method) ;
// System.Void SobotChatClient.ZCSobotApi::_sobotOpenChat(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ZCSobotApi__sobotOpenChat_m0236199F906D227E3B884F0B6740141A1CC2357C (String_t* ___0_paramJson, const RuntimeMethod* method) ;
// System.Void SobotChatClient.ZCSobotApi::_sobotOpenServiceCenter(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ZCSobotApi__sobotOpenServiceCenter_m6C7679DF119EFD55215E8FCBB39A5B2DFAA054B3 (String_t* ___0_paramJson, const RuntimeMethod* method) ;
// System.Void SobotChatClient.ZCSobotApi::_sobotOpenLeave(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ZCSobotApi__sobotOpenLeave_m8BC41A0E55BDD953C915913F22D43AF6DE44939D (String_t* ___0_paramJson, const RuntimeMethod* method) ;
// System.Void SobotChatClient.ZCSobotApi::_sobotGetOfflineMsg(System.String,System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ZCSobotApi__sobotGetOfflineMsg_mF971E574BD2BDB945E997E05AC631B5496224F21 (String_t* ___0_paramJson, String_t* ___1_gameObjectName, String_t* ___2_callbackMethod, const RuntimeMethod* method) ;
// System.Void SobotChatClient.ZCSobotApi::_sobotCloseSession(System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ZCSobotApi__sobotCloseSession_mA59E270A58751FD761DEE5AD8D90B824B9AC3F92 (bool ___0_closePush, const RuntimeMethod* method) ;
// System.Void SobotChatClient.ZCSobotApi::_sobotSetLinkClickListener(SobotChatClient.ZCSobotApi/IOSLinkClickCallback)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ZCSobotApi__sobotSetLinkClickListener_m32B191A8DD6AD0ED7075DFE1108460D7A74F63FF (IOSLinkClickCallback_tE93B6F4ED698136320B42F54DE5AC652D635701A* ___0_callback, const RuntimeMethod* method) ;
// System.Void UnityEngine.Debug::Log(System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Debug_Log_m87A9A3C761FF5C43ED8A53B16190A53D08F818BB (RuntimeObject* ___0_message, const RuntimeMethod* method) ;
// System.Void SobotChatClient.ZCSobotApi::_sobotSetFunctionClickListener(SobotChatClient.ZCSobotApi/IOSFunctionClickCallback)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ZCSobotApi__sobotSetFunctionClickListener_m8F4945C50CCA0C2CD925740B4308887739930CF8 (IOSFunctionClickCallback_t9B9C81DAECBDABE1B68AD43DA4E42635B1A95613* ___0_callback, const RuntimeMethod* method) ;
// System.Boolean SobotChatClient.ZCSobotApi::EnsureInitialized(System.String,SobotChatClient.ZCSobotApi/SendMessageResultCallback)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ZCSobotApi_EnsureInitialized_m24D0257CD08C8FACE30BE63713449A2DF7BB6F4E (String_t* ___0_methodName, SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475* ___1_callback, const RuntimeMethod* method) ;
// System.Boolean SobotChatClient.ZCSobotApi::RequireString(System.String,System.String,System.String,SobotChatClient.ZCSobotApi/SendMessageResultCallback)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ZCSobotApi_RequireString_m8018D7AD88EFFF77FA1A927324367599A608F8CE (String_t* ___0_value, String_t* ___1_methodName, String_t* ___2_fieldName, SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475* ___3_callback, const RuntimeMethod* method) ;
// System.String SobotChatClient.ZCSobotApi::StoreSendCallback(SobotChatClient.ZCSobotApi/SendMessageResultCallback)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* ZCSobotApi_StoreSendCallback_mD42610D0D741A738C11EDFF325BE4972E17D5921 (SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475* ___0_callback, const RuntimeMethod* method) ;
// System.Void SobotChatClient.ZCSobotApi::_sobotSendCustomCardToChat(System.String,System.String,System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ZCSobotApi__sobotSendCustomCardToChat_m6E00796E1206BDB9D028A47AD39EFFE47FD6A714 (String_t* ___0_paramJson, String_t* ___1_gameObjectName, String_t* ___2_callbackMethod, String_t* ___3_requestId, const RuntimeMethod* method) ;
// System.Void SobotChatClient.ZCSobotApi::_sobotSendProductInfo(System.String,System.String,System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ZCSobotApi__sobotSendProductInfo_mC4253F805498034853C9C3F62F5CCB9C15C10C9E (String_t* ___0_paramJson, String_t* ___1_gameObjectName, String_t* ___2_callbackMethod, String_t* ___3_requestId, const RuntimeMethod* method) ;
// System.Void SobotChatClient.ZCSobotApi::_sobotSendOrderGoodsInfo(System.String,System.String,System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ZCSobotApi__sobotSendOrderGoodsInfo_mF4D540AA3AB36164D4100179C83EFFF1840B5EED (String_t* ___0_paramJson, String_t* ___1_gameObjectName, String_t* ___2_callbackMethod, String_t* ___3_requestId, const RuntimeMethod* method) ;
// System.Void SobotChatClient.ZCSobotApi::_sobotSendLocation(System.String,System.String,System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ZCSobotApi__sobotSendLocation_mF30BF53D3CCB336531AE2CC2FD5CEE81E3D41AA7 (String_t* ___0_paramJson, String_t* ___1_gameObjectName, String_t* ___2_callbackMethod, String_t* ___3_requestId, const RuntimeMethod* method) ;
// System.Void SobotChatClient.SobotParams::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SobotParams__ctor_m0C6D3CA588C82C70B45BE6DE02AF384787F39D17 (SobotParams_tCF40A43A8D519A95915ED461EFEF2BDDCA5B5168* __this, const RuntimeMethod* method) ;
// System.String UnityEngine.JsonUtility::ToJson(System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* JsonUtility_ToJson_m28CC6843B9D3723D88AD13EA3829B71FDE7826BA (RuntimeObject* ___0_obj, const RuntimeMethod* method) ;
// System.String System.String::Replace(System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Replace_mABDB7003A1D0AEDCAE9FF85E3DFFFBA752D2A166 (String_t* __this, String_t* ___0_oldValue, String_t* ___1_newValue, const RuntimeMethod* method) ;
// System.String System.String::Concat(System.String,System.String,System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Concat_m093934F71A9B351911EE46311674ED463B180006 (String_t* ___0_str0, String_t* ___1_str1, String_t* ___2_str2, String_t* ___3_str3, const RuntimeMethod* method) ;
// System.Void UnityEngine.Debug::LogWarning(System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Debug_LogWarning_m33EF1B897E0C7C6FF538989610BFAFFEF4628CA9 (RuntimeObject* ___0_message, const RuntimeMethod* method) ;
// System.Void SobotChatClient.ZCSobotApi/SendMessageResultCallback::Invoke(System.Boolean,System.Int32,System.String)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void SendMessageResultCallback_Invoke_mBA48517CB222DA8E62EE9E645A007C21454870E4_inline (SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475* __this, bool ___0_success, int32_t ___1_code, String_t* ___2_message, const RuntimeMethod* method) ;
// System.Boolean System.String::IsNullOrEmpty(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool String_IsNullOrEmpty_mEA9E3FB005AC28FE02E69FCF95A7B8456192B478 (String_t* ___0_value, const RuntimeMethod* method) ;
// System.String System.String::Concat(System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Concat_m9E3155FB84015C823606188F53B47CB44C444991 (String_t* ___0_str0, String_t* ___1_str1, const RuntimeMethod* method) ;
// System.String System.Int32::ToString()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Int32_ToString_m030E01C24E294D6762FB0B6F37CB541581F55CA5 (int32_t* __this, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2<System.String,SobotChatClient.ZCSobotApi/SendMessageResultCallback>::set_Item(TKey,TValue)
inline void Dictionary_2_set_Item_m8DAD2B757C763B0BE87D5193C64D145376059412 (Dictionary_2_t90FE42767FAF03DFB400884E3F5B327D48A268A5* __this, String_t* ___0_key, SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475* ___1_value, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_t90FE42767FAF03DFB400884E3F5B327D48A268A5*, String_t*, SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475*, const RuntimeMethod*))Dictionary_2_set_Item_m1A840355E8EDAECEA9D0C6F5E51B248FAA449CBD_gshared)(__this, ___0_key, ___1_value, method);
}
// System.Boolean System.String::StartsWith(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool String_StartsWith_mF75DBA1EB709811E711B44E26FF919C88A8E65C0 (String_t* __this, String_t* ___0_value, const RuntimeMethod* method) ;
// System.Void SobotChatClient.ZCSobotApi/InitResultCallback::Invoke(System.Boolean,System.String)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void InitResultCallback_Invoke_mF07EB0A9EAB5519565C8DD8368BBB7ABBB8A05E8_inline (InitResultCallback_t681E10D9230FD32958B962D5B649178586A97B7B* __this, bool ___0_success, String_t* ___1_message, const RuntimeMethod* method) ;
// System.String[] System.String::Split(System.Char,System.StringSplitOptions)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* String_Split_m9530B73D02054692283BF35C3A27C8F2230946F4 (String_t* __this, Il2CppChar ___0_separator, int32_t ___1_options, const RuntimeMethod* method) ;
// System.Int32 System.Int32::Parse(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t Int32_Parse_m273CA1A9C7717C99641291A95C543711C0202AF0 (String_t* ___0_s, const RuntimeMethod* method) ;
// System.Void SobotChatClient.ZCSobotApi/OfflineMsgCallback::Invoke(System.Int32,System.Int32,System.Int32)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void OfflineMsgCallback_Invoke_mC45ED6E4DEA1ADA6B9CABFAE0BB02F5F85DA0CF5_inline (OfflineMsgCallback_t95A2C0AE5DEFB9A1F73D67591217112C51B655D5* __this, int32_t ___0_unReadSize, int32_t ___1_offlineSize, int32_t ___2_unAckSize, const RuntimeMethod* method) ;
// System.String[] System.String::Split(System.Char[],System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* String_Split_m3C63FA89A52BE352B4E49DB5379F7AAD6ACCA0E8 (String_t* __this, CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* ___0_separator, int32_t ___1_count, const RuntimeMethod* method) ;
// System.Boolean System.Collections.Generic.Dictionary`2<System.String,SobotChatClient.ZCSobotApi/SendMessageResultCallback>::TryGetValue(TKey,TValue&)
inline bool Dictionary_2_TryGetValue_m475E1A033333E5803F84DE43B65E527E77893F75 (Dictionary_2_t90FE42767FAF03DFB400884E3F5B327D48A268A5* __this, String_t* ___0_key, SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475** ___1_value, const RuntimeMethod* method)
{
	return ((  bool (*) (Dictionary_2_t90FE42767FAF03DFB400884E3F5B327D48A268A5*, String_t*, SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475**, const RuntimeMethod*))Dictionary_2_TryGetValue_mD15380A4ED7CDEE99EA45881577D26BA9CE1B849_gshared)(__this, ___0_key, ___1_value, method);
}
// System.Boolean System.Collections.Generic.Dictionary`2<System.String,SobotChatClient.ZCSobotApi/SendMessageResultCallback>::Remove(TKey)
inline bool Dictionary_2_Remove_m6FA8FA49F3ED92FB7B3CB2B1092724F101C9B5D2 (Dictionary_2_t90FE42767FAF03DFB400884E3F5B327D48A268A5* __this, String_t* ___0_key, const RuntimeMethod* method)
{
	return ((  bool (*) (Dictionary_2_t90FE42767FAF03DFB400884E3F5B327D48A268A5*, String_t*, const RuntimeMethod*))Dictionary_2_Remove_m5C7C45E75D951A75843F3F7AADD56ECD64F6BC86_gshared)(__this, ___0_key, method);
}
// System.Void UnityEngine.Debug::LogError(System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Debug_LogError_mB00B2B4468EF3CAF041B038D840820FB84C924B2 (RuntimeObject* ___0_message, const RuntimeMethod* method) ;
// System.Boolean SobotChatClient.ZCSobotApi/LinkClickCallback::Invoke(System.String)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool LinkClickCallback_Invoke_m9F0F19D8FDE3EA9803F1EAFEA89842946CF22054_inline (LinkClickCallback_t74FFEF1A7387D900A6578354799B79ECB1F3013E* __this, String_t* ___0_linkUrl, const RuntimeMethod* method) ;
// System.String System.String::Format(System.String,System.Object,System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987 (String_t* ___0_format, RuntimeObject* ___1_arg0, RuntimeObject* ___2_arg1, const RuntimeMethod* method) ;
// System.String System.String::Format(System.String,System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* String_Format_mA8DBB4C2516B9723C5A41E6CB1E2FAF4BBE96DD8 (String_t* ___0_format, RuntimeObject* ___1_arg0, const RuntimeMethod* method) ;
// System.Void SobotChatClient.ZCSobotApi/FunctionClickCallback::Invoke(System.Int32)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void FunctionClickCallback_Invoke_m5CD94C0005DBFE325075D4D04227207115CBBB57_inline (FunctionClickCallback_t133340AD88A3E68729476CCC597F418302E4F28C* __this, int32_t ___0_type, const RuntimeMethod* method) ;
// System.Void UnityEngine.MonoBehaviour::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E (MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71* __this, const RuntimeMethod* method) ;
// System.Void System.Collections.Generic.Dictionary`2<System.String,SobotChatClient.ZCSobotApi/SendMessageResultCallback>::.ctor()
inline void Dictionary_2__ctor_m2BE66DBDC8AABB2807C7D4BDACF197D4372CCEBF (Dictionary_2_t90FE42767FAF03DFB400884E3F5B327D48A268A5* __this, const RuntimeMethod* method)
{
	((  void (*) (Dictionary_2_t90FE42767FAF03DFB400884E3F5B327D48A268A5*, const RuntimeMethod*))Dictionary_2__ctor_m5B32FBC624618211EB461D59CFBB10E987FD1329_gshared)(__this, method);
}
// System.Void SobotChatClient.ZCSobotApi/IOSLinkClickCallback::.ctor(System.Object,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void IOSLinkClickCallback__ctor_m0189B376795B31F2451B85E93207801778C6008F (IOSLinkClickCallback_tE93B6F4ED698136320B42F54DE5AC652D635701A* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) ;
// System.Void SobotChatClient.ZCSobotApi/IOSFunctionClickCallback::.ctor(System.Object,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void IOSFunctionClickCallback__ctor_m4606F957CAC44663491AC37FB52AFB51F7416692 (IOSFunctionClickCallback_t9B9C81DAECBDABE1B68AD43DA4E42635B1A95613* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C void DEFAULT_CALL _sobotInitSDK(char*, char*, char*);
IL2CPP_EXTERN_C void DEFAULT_CALL _sobotOpenChat(char*);
IL2CPP_EXTERN_C void DEFAULT_CALL _sobotOpenServiceCenter(char*);
IL2CPP_EXTERN_C void DEFAULT_CALL _sobotOpenLeave(char*);
IL2CPP_EXTERN_C void DEFAULT_CALL _sobotCloseSession(int8_t);
IL2CPP_EXTERN_C void DEFAULT_CALL _sobotGetOfflineMsg(char*, char*, char*);
IL2CPP_EXTERN_C void DEFAULT_CALL _sobotSetLinkClickListener(Il2CppMethodPointer);
IL2CPP_EXTERN_C void DEFAULT_CALL _sobotSetFunctionClickListener(Il2CppMethodPointer);
IL2CPP_EXTERN_C void DEFAULT_CALL _sobotSendCustomCardToChat(char*, char*, char*, char*);
IL2CPP_EXTERN_C void DEFAULT_CALL _sobotSendProductInfo(char*, char*, char*, char*);
IL2CPP_EXTERN_C void DEFAULT_CALL _sobotSendOrderGoodsInfo(char*, char*, char*, char*);
IL2CPP_EXTERN_C void DEFAULT_CALL _sobotSendLocation(char*, char*, char*, char*);
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void SobotChatClient.SobotParams::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SobotParams__ctor_m0C6D3CA588C82C70B45BE6DE02AF384787F39D17 (SobotParams_tCF40A43A8D519A95915ED461EFEF2BDDCA5B5168* __this, const RuntimeMethod* method) 
{
	{
		Object__ctor_mE837C6B9FA8C6D5D109F4B2EC885D79919AC0EA2(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
extern "C" int8_t CDECL ReversePInvokeWrapper_ZCSobotApi_OnIOSLinkClick_mEEE708A3A1CBF9864C804FADC93618A3B752F03F(char* ___0_url)
{
	il2cpp::vm::ScopedThreadAttacher _vmThreadHelper;

	// Marshaling of parameter '___0_url' to managed representation
	String_t* ____0_url_unmarshaled = NULL;
	____0_url_unmarshaled = il2cpp_codegen_marshal_string_result(___0_url);

	// Managed method invocation
	bool returnValue;
	returnValue = ZCSobotApi_OnIOSLinkClick_mEEE708A3A1CBF9864C804FADC93618A3B752F03F(____0_url_unmarshaled, NULL);

	return static_cast<int8_t>(returnValue);
}
extern "C" void CDECL ReversePInvokeWrapper_ZCSobotApi_OnIOSFunctionClick_mCF84458642714F9D17C0ED66580DC8F5A879B718(int32_t ___0_type)
{
	il2cpp::vm::ScopedThreadAttacher _vmThreadHelper;

	// Managed method invocation
	ZCSobotApi_OnIOSFunctionClick_mCF84458642714F9D17C0ED66580DC8F5A879B718(___0_type, NULL);

}
// SobotChatClient.ZCSobotApi SobotChatClient.ZCSobotApi::get_Instance()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179* ZCSobotApi_get_Instance_m18C6611F9559B4F664A217C5F0CCB64C426A4155 (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameObject_AddComponent_TisZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_m33CC8380AEDE74B122867E5D940950D41729FAE3_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&GameObject_t76FEDD663AB33C991A9C9A23129337651094216F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral6ADA0DA779CE14355F1491C7EDA8C261D0D30480);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (_instance == null)
		il2cpp_codegen_runtime_class_init_inline(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
		ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179* L_0 = ((ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_StaticFields*)il2cpp_codegen_static_fields_for(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var))->____instance_4;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_1;
		L_1 = Object_op_Equality_mB6120F782D83091EF56A198FCEBCF066DB4A9605(L_0, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		if (!L_1)
		{
			goto IL_0027;
		}
	}
	{
		// GameObject go = new GameObject("ZCSobotApi");
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_2 = (GameObject_t76FEDD663AB33C991A9C9A23129337651094216F*)il2cpp_codegen_object_new(GameObject_t76FEDD663AB33C991A9C9A23129337651094216F_il2cpp_TypeInfo_var);
		NullCheck(L_2);
		GameObject__ctor_m37D512B05D292F954792225E6C6EEE95293A9B88(L_2, _stringLiteral6ADA0DA779CE14355F1491C7EDA8C261D0D30480, NULL);
		// _instance = go.AddComponent<ZCSobotApi>();
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_3 = L_2;
		NullCheck(L_3);
		ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179* L_4;
		L_4 = GameObject_AddComponent_TisZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_m33CC8380AEDE74B122867E5D940950D41729FAE3(L_3, GameObject_AddComponent_TisZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_m33CC8380AEDE74B122867E5D940950D41729FAE3_RuntimeMethod_var);
		il2cpp_codegen_runtime_class_init_inline(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
		((ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_StaticFields*)il2cpp_codegen_static_fields_for(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var))->____instance_4 = L_4;
		Il2CppCodeGenWriteBarrier((void**)(&((ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_StaticFields*)il2cpp_codegen_static_fields_for(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var))->____instance_4), (void*)L_4);
		// DontDestroyOnLoad(go);
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		Object_DontDestroyOnLoad_m4B70C3AEF886C176543D1295507B6455C9DCAEA7(L_3, NULL);
	}

IL_0027:
	{
		// return _instance;
		il2cpp_codegen_runtime_class_init_inline(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
		ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179* L_5 = ((ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_StaticFields*)il2cpp_codegen_static_fields_for(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var))->____instance_4;
		return L_5;
	}
}
// System.Void SobotChatClient.ZCSobotApi::_sobotInitSDK(System.String,System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ZCSobotApi__sobotInitSDK_m1EF8E1459C431F7397BFCB9631960AC4B0AC631D (String_t* ___0_paramJson, String_t* ___1_gameObjectName, String_t* ___2_callbackMethod, const RuntimeMethod* method) 
{
	typedef void (DEFAULT_CALL *PInvokeFunc) (char*, char*, char*);

	// Marshaling of parameter '___0_paramJson' to native representation
	char* ____0_paramJson_marshaled = NULL;
	____0_paramJson_marshaled = il2cpp_codegen_marshal_string(___0_paramJson);

	// Marshaling of parameter '___1_gameObjectName' to native representation
	char* ____1_gameObjectName_marshaled = NULL;
	____1_gameObjectName_marshaled = il2cpp_codegen_marshal_string(___1_gameObjectName);

	// Marshaling of parameter '___2_callbackMethod' to native representation
	char* ____2_callbackMethod_marshaled = NULL;
	____2_callbackMethod_marshaled = il2cpp_codegen_marshal_string(___2_callbackMethod);

	// Native function invocation
	reinterpret_cast<PInvokeFunc>(_sobotInitSDK)(____0_paramJson_marshaled, ____1_gameObjectName_marshaled, ____2_callbackMethod_marshaled);

	// Marshaling cleanup of parameter '___0_paramJson' native representation
	il2cpp_codegen_marshal_free(____0_paramJson_marshaled);
	____0_paramJson_marshaled = NULL;

	// Marshaling cleanup of parameter '___1_gameObjectName' native representation
	il2cpp_codegen_marshal_free(____1_gameObjectName_marshaled);
	____1_gameObjectName_marshaled = NULL;

	// Marshaling cleanup of parameter '___2_callbackMethod' native representation
	il2cpp_codegen_marshal_free(____2_callbackMethod_marshaled);
	____2_callbackMethod_marshaled = NULL;

}
// System.Void SobotChatClient.ZCSobotApi::_sobotOpenChat(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ZCSobotApi__sobotOpenChat_m0236199F906D227E3B884F0B6740141A1CC2357C (String_t* ___0_paramJson, const RuntimeMethod* method) 
{
	typedef void (DEFAULT_CALL *PInvokeFunc) (char*);

	// Marshaling of parameter '___0_paramJson' to native representation
	char* ____0_paramJson_marshaled = NULL;
	____0_paramJson_marshaled = il2cpp_codegen_marshal_string(___0_paramJson);

	// Native function invocation
	reinterpret_cast<PInvokeFunc>(_sobotOpenChat)(____0_paramJson_marshaled);

	// Marshaling cleanup of parameter '___0_paramJson' native representation
	il2cpp_codegen_marshal_free(____0_paramJson_marshaled);
	____0_paramJson_marshaled = NULL;

}
// System.Void SobotChatClient.ZCSobotApi::_sobotOpenServiceCenter(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ZCSobotApi__sobotOpenServiceCenter_m6C7679DF119EFD55215E8FCBB39A5B2DFAA054B3 (String_t* ___0_paramJson, const RuntimeMethod* method) 
{
	typedef void (DEFAULT_CALL *PInvokeFunc) (char*);

	// Marshaling of parameter '___0_paramJson' to native representation
	char* ____0_paramJson_marshaled = NULL;
	____0_paramJson_marshaled = il2cpp_codegen_marshal_string(___0_paramJson);

	// Native function invocation
	reinterpret_cast<PInvokeFunc>(_sobotOpenServiceCenter)(____0_paramJson_marshaled);

	// Marshaling cleanup of parameter '___0_paramJson' native representation
	il2cpp_codegen_marshal_free(____0_paramJson_marshaled);
	____0_paramJson_marshaled = NULL;

}
// System.Void SobotChatClient.ZCSobotApi::_sobotOpenLeave(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ZCSobotApi__sobotOpenLeave_m8BC41A0E55BDD953C915913F22D43AF6DE44939D (String_t* ___0_paramJson, const RuntimeMethod* method) 
{
	typedef void (DEFAULT_CALL *PInvokeFunc) (char*);

	// Marshaling of parameter '___0_paramJson' to native representation
	char* ____0_paramJson_marshaled = NULL;
	____0_paramJson_marshaled = il2cpp_codegen_marshal_string(___0_paramJson);

	// Native function invocation
	reinterpret_cast<PInvokeFunc>(_sobotOpenLeave)(____0_paramJson_marshaled);

	// Marshaling cleanup of parameter '___0_paramJson' native representation
	il2cpp_codegen_marshal_free(____0_paramJson_marshaled);
	____0_paramJson_marshaled = NULL;

}
// System.Void SobotChatClient.ZCSobotApi::_sobotCloseSession(System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ZCSobotApi__sobotCloseSession_mA59E270A58751FD761DEE5AD8D90B824B9AC3F92 (bool ___0_closePush, const RuntimeMethod* method) 
{
	typedef void (DEFAULT_CALL *PInvokeFunc) (int8_t);

	// Native function invocation
	reinterpret_cast<PInvokeFunc>(_sobotCloseSession)(static_cast<int8_t>(___0_closePush));

}
// System.Void SobotChatClient.ZCSobotApi::_sobotGetOfflineMsg(System.String,System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ZCSobotApi__sobotGetOfflineMsg_mF971E574BD2BDB945E997E05AC631B5496224F21 (String_t* ___0_paramJson, String_t* ___1_gameObjectName, String_t* ___2_callbackMethod, const RuntimeMethod* method) 
{
	typedef void (DEFAULT_CALL *PInvokeFunc) (char*, char*, char*);

	// Marshaling of parameter '___0_paramJson' to native representation
	char* ____0_paramJson_marshaled = NULL;
	____0_paramJson_marshaled = il2cpp_codegen_marshal_string(___0_paramJson);

	// Marshaling of parameter '___1_gameObjectName' to native representation
	char* ____1_gameObjectName_marshaled = NULL;
	____1_gameObjectName_marshaled = il2cpp_codegen_marshal_string(___1_gameObjectName);

	// Marshaling of parameter '___2_callbackMethod' to native representation
	char* ____2_callbackMethod_marshaled = NULL;
	____2_callbackMethod_marshaled = il2cpp_codegen_marshal_string(___2_callbackMethod);

	// Native function invocation
	reinterpret_cast<PInvokeFunc>(_sobotGetOfflineMsg)(____0_paramJson_marshaled, ____1_gameObjectName_marshaled, ____2_callbackMethod_marshaled);

	// Marshaling cleanup of parameter '___0_paramJson' native representation
	il2cpp_codegen_marshal_free(____0_paramJson_marshaled);
	____0_paramJson_marshaled = NULL;

	// Marshaling cleanup of parameter '___1_gameObjectName' native representation
	il2cpp_codegen_marshal_free(____1_gameObjectName_marshaled);
	____1_gameObjectName_marshaled = NULL;

	// Marshaling cleanup of parameter '___2_callbackMethod' native representation
	il2cpp_codegen_marshal_free(____2_callbackMethod_marshaled);
	____2_callbackMethod_marshaled = NULL;

}
// System.Void SobotChatClient.ZCSobotApi::_sobotSetLinkClickListener(SobotChatClient.ZCSobotApi/IOSLinkClickCallback)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ZCSobotApi__sobotSetLinkClickListener_m32B191A8DD6AD0ED7075DFE1108460D7A74F63FF (IOSLinkClickCallback_tE93B6F4ED698136320B42F54DE5AC652D635701A* ___0_callback, const RuntimeMethod* method) 
{
	typedef void (DEFAULT_CALL *PInvokeFunc) (Il2CppMethodPointer);

	// Marshaling of parameter '___0_callback' to native representation
	Il2CppMethodPointer ____0_callback_marshaled = NULL;
	____0_callback_marshaled = il2cpp_codegen_marshal_delegate(reinterpret_cast<MulticastDelegate_t*>(___0_callback));

	// Native function invocation
	reinterpret_cast<PInvokeFunc>(_sobotSetLinkClickListener)(____0_callback_marshaled);

}
// System.Void SobotChatClient.ZCSobotApi::_sobotSetFunctionClickListener(SobotChatClient.ZCSobotApi/IOSFunctionClickCallback)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ZCSobotApi__sobotSetFunctionClickListener_m8F4945C50CCA0C2CD925740B4308887739930CF8 (IOSFunctionClickCallback_t9B9C81DAECBDABE1B68AD43DA4E42635B1A95613* ___0_callback, const RuntimeMethod* method) 
{
	typedef void (DEFAULT_CALL *PInvokeFunc) (Il2CppMethodPointer);

	// Marshaling of parameter '___0_callback' to native representation
	Il2CppMethodPointer ____0_callback_marshaled = NULL;
	____0_callback_marshaled = il2cpp_codegen_marshal_delegate(reinterpret_cast<MulticastDelegate_t*>(___0_callback));

	// Native function invocation
	reinterpret_cast<PInvokeFunc>(_sobotSetFunctionClickListener)(____0_callback_marshaled);

}
// System.Void SobotChatClient.ZCSobotApi::_sobotSendCustomCardToChat(System.String,System.String,System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ZCSobotApi__sobotSendCustomCardToChat_m6E00796E1206BDB9D028A47AD39EFFE47FD6A714 (String_t* ___0_paramJson, String_t* ___1_gameObjectName, String_t* ___2_callbackMethod, String_t* ___3_requestId, const RuntimeMethod* method) 
{
	typedef void (DEFAULT_CALL *PInvokeFunc) (char*, char*, char*, char*);

	// Marshaling of parameter '___0_paramJson' to native representation
	char* ____0_paramJson_marshaled = NULL;
	____0_paramJson_marshaled = il2cpp_codegen_marshal_string(___0_paramJson);

	// Marshaling of parameter '___1_gameObjectName' to native representation
	char* ____1_gameObjectName_marshaled = NULL;
	____1_gameObjectName_marshaled = il2cpp_codegen_marshal_string(___1_gameObjectName);

	// Marshaling of parameter '___2_callbackMethod' to native representation
	char* ____2_callbackMethod_marshaled = NULL;
	____2_callbackMethod_marshaled = il2cpp_codegen_marshal_string(___2_callbackMethod);

	// Marshaling of parameter '___3_requestId' to native representation
	char* ____3_requestId_marshaled = NULL;
	____3_requestId_marshaled = il2cpp_codegen_marshal_string(___3_requestId);

	// Native function invocation
	reinterpret_cast<PInvokeFunc>(_sobotSendCustomCardToChat)(____0_paramJson_marshaled, ____1_gameObjectName_marshaled, ____2_callbackMethod_marshaled, ____3_requestId_marshaled);

	// Marshaling cleanup of parameter '___0_paramJson' native representation
	il2cpp_codegen_marshal_free(____0_paramJson_marshaled);
	____0_paramJson_marshaled = NULL;

	// Marshaling cleanup of parameter '___1_gameObjectName' native representation
	il2cpp_codegen_marshal_free(____1_gameObjectName_marshaled);
	____1_gameObjectName_marshaled = NULL;

	// Marshaling cleanup of parameter '___2_callbackMethod' native representation
	il2cpp_codegen_marshal_free(____2_callbackMethod_marshaled);
	____2_callbackMethod_marshaled = NULL;

	// Marshaling cleanup of parameter '___3_requestId' native representation
	il2cpp_codegen_marshal_free(____3_requestId_marshaled);
	____3_requestId_marshaled = NULL;

}
// System.Void SobotChatClient.ZCSobotApi::_sobotSendProductInfo(System.String,System.String,System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ZCSobotApi__sobotSendProductInfo_mC4253F805498034853C9C3F62F5CCB9C15C10C9E (String_t* ___0_paramJson, String_t* ___1_gameObjectName, String_t* ___2_callbackMethod, String_t* ___3_requestId, const RuntimeMethod* method) 
{
	typedef void (DEFAULT_CALL *PInvokeFunc) (char*, char*, char*, char*);

	// Marshaling of parameter '___0_paramJson' to native representation
	char* ____0_paramJson_marshaled = NULL;
	____0_paramJson_marshaled = il2cpp_codegen_marshal_string(___0_paramJson);

	// Marshaling of parameter '___1_gameObjectName' to native representation
	char* ____1_gameObjectName_marshaled = NULL;
	____1_gameObjectName_marshaled = il2cpp_codegen_marshal_string(___1_gameObjectName);

	// Marshaling of parameter '___2_callbackMethod' to native representation
	char* ____2_callbackMethod_marshaled = NULL;
	____2_callbackMethod_marshaled = il2cpp_codegen_marshal_string(___2_callbackMethod);

	// Marshaling of parameter '___3_requestId' to native representation
	char* ____3_requestId_marshaled = NULL;
	____3_requestId_marshaled = il2cpp_codegen_marshal_string(___3_requestId);

	// Native function invocation
	reinterpret_cast<PInvokeFunc>(_sobotSendProductInfo)(____0_paramJson_marshaled, ____1_gameObjectName_marshaled, ____2_callbackMethod_marshaled, ____3_requestId_marshaled);

	// Marshaling cleanup of parameter '___0_paramJson' native representation
	il2cpp_codegen_marshal_free(____0_paramJson_marshaled);
	____0_paramJson_marshaled = NULL;

	// Marshaling cleanup of parameter '___1_gameObjectName' native representation
	il2cpp_codegen_marshal_free(____1_gameObjectName_marshaled);
	____1_gameObjectName_marshaled = NULL;

	// Marshaling cleanup of parameter '___2_callbackMethod' native representation
	il2cpp_codegen_marshal_free(____2_callbackMethod_marshaled);
	____2_callbackMethod_marshaled = NULL;

	// Marshaling cleanup of parameter '___3_requestId' native representation
	il2cpp_codegen_marshal_free(____3_requestId_marshaled);
	____3_requestId_marshaled = NULL;

}
// System.Void SobotChatClient.ZCSobotApi::_sobotSendOrderGoodsInfo(System.String,System.String,System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ZCSobotApi__sobotSendOrderGoodsInfo_mF4D540AA3AB36164D4100179C83EFFF1840B5EED (String_t* ___0_paramJson, String_t* ___1_gameObjectName, String_t* ___2_callbackMethod, String_t* ___3_requestId, const RuntimeMethod* method) 
{
	typedef void (DEFAULT_CALL *PInvokeFunc) (char*, char*, char*, char*);

	// Marshaling of parameter '___0_paramJson' to native representation
	char* ____0_paramJson_marshaled = NULL;
	____0_paramJson_marshaled = il2cpp_codegen_marshal_string(___0_paramJson);

	// Marshaling of parameter '___1_gameObjectName' to native representation
	char* ____1_gameObjectName_marshaled = NULL;
	____1_gameObjectName_marshaled = il2cpp_codegen_marshal_string(___1_gameObjectName);

	// Marshaling of parameter '___2_callbackMethod' to native representation
	char* ____2_callbackMethod_marshaled = NULL;
	____2_callbackMethod_marshaled = il2cpp_codegen_marshal_string(___2_callbackMethod);

	// Marshaling of parameter '___3_requestId' to native representation
	char* ____3_requestId_marshaled = NULL;
	____3_requestId_marshaled = il2cpp_codegen_marshal_string(___3_requestId);

	// Native function invocation
	reinterpret_cast<PInvokeFunc>(_sobotSendOrderGoodsInfo)(____0_paramJson_marshaled, ____1_gameObjectName_marshaled, ____2_callbackMethod_marshaled, ____3_requestId_marshaled);

	// Marshaling cleanup of parameter '___0_paramJson' native representation
	il2cpp_codegen_marshal_free(____0_paramJson_marshaled);
	____0_paramJson_marshaled = NULL;

	// Marshaling cleanup of parameter '___1_gameObjectName' native representation
	il2cpp_codegen_marshal_free(____1_gameObjectName_marshaled);
	____1_gameObjectName_marshaled = NULL;

	// Marshaling cleanup of parameter '___2_callbackMethod' native representation
	il2cpp_codegen_marshal_free(____2_callbackMethod_marshaled);
	____2_callbackMethod_marshaled = NULL;

	// Marshaling cleanup of parameter '___3_requestId' native representation
	il2cpp_codegen_marshal_free(____3_requestId_marshaled);
	____3_requestId_marshaled = NULL;

}
// System.Void SobotChatClient.ZCSobotApi::_sobotSendLocation(System.String,System.String,System.String,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ZCSobotApi__sobotSendLocation_mF30BF53D3CCB336531AE2CC2FD5CEE81E3D41AA7 (String_t* ___0_paramJson, String_t* ___1_gameObjectName, String_t* ___2_callbackMethod, String_t* ___3_requestId, const RuntimeMethod* method) 
{
	typedef void (DEFAULT_CALL *PInvokeFunc) (char*, char*, char*, char*);

	// Marshaling of parameter '___0_paramJson' to native representation
	char* ____0_paramJson_marshaled = NULL;
	____0_paramJson_marshaled = il2cpp_codegen_marshal_string(___0_paramJson);

	// Marshaling of parameter '___1_gameObjectName' to native representation
	char* ____1_gameObjectName_marshaled = NULL;
	____1_gameObjectName_marshaled = il2cpp_codegen_marshal_string(___1_gameObjectName);

	// Marshaling of parameter '___2_callbackMethod' to native representation
	char* ____2_callbackMethod_marshaled = NULL;
	____2_callbackMethod_marshaled = il2cpp_codegen_marshal_string(___2_callbackMethod);

	// Marshaling of parameter '___3_requestId' to native representation
	char* ____3_requestId_marshaled = NULL;
	____3_requestId_marshaled = il2cpp_codegen_marshal_string(___3_requestId);

	// Native function invocation
	reinterpret_cast<PInvokeFunc>(_sobotSendLocation)(____0_paramJson_marshaled, ____1_gameObjectName_marshaled, ____2_callbackMethod_marshaled, ____3_requestId_marshaled);

	// Marshaling cleanup of parameter '___0_paramJson' native representation
	il2cpp_codegen_marshal_free(____0_paramJson_marshaled);
	____0_paramJson_marshaled = NULL;

	// Marshaling cleanup of parameter '___1_gameObjectName' native representation
	il2cpp_codegen_marshal_free(____1_gameObjectName_marshaled);
	____1_gameObjectName_marshaled = NULL;

	// Marshaling cleanup of parameter '___2_callbackMethod' native representation
	il2cpp_codegen_marshal_free(____2_callbackMethod_marshaled);
	____2_callbackMethod_marshaled = NULL;

	// Marshaling cleanup of parameter '___3_requestId' native representation
	il2cpp_codegen_marshal_free(____3_requestId_marshaled);
	____3_requestId_marshaled = NULL;

}
// System.Void SobotChatClient.ZCSobotApi::initSobotSDK(SobotChatClient.SobotParams,SobotChatClient.ZCSobotApi/InitResultCallback)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ZCSobotApi_initSobotSDK_m9BE8C5BF7D9A79EA96F1BB25B543280736A89C05 (SobotParams_tCF40A43A8D519A95915ED461EFEF2BDDCA5B5168* ___0_param, InitResultCallback_t681E10D9230FD32958B962D5B649178586A97B7B* ___1_callback, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral88FF9681ACC4160649786C9DB30EE86B79D22400);
		s_Il2CppMethodInitialized = true;
	}
	ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179* V_0 = NULL;
	{
		// _initCallback = callback;
		InitResultCallback_t681E10D9230FD32958B962D5B649178586A97B7B* L_0 = ___1_callback;
		il2cpp_codegen_runtime_class_init_inline(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
		((ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_StaticFields*)il2cpp_codegen_static_fields_for(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var))->____initCallback_5 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&((ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_StaticFields*)il2cpp_codegen_static_fields_for(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var))->____initCallback_5), (void*)L_0);
		// _isInitialized = false;
		((ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_StaticFields*)il2cpp_codegen_static_fields_for(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var))->____isInitialized_9 = (bool)0;
		// var inst = Instance;
		ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179* L_1;
		L_1 = ZCSobotApi_get_Instance_m18C6611F9559B4F664A217C5F0CCB64C426A4155(NULL);
		V_0 = L_1;
		// string paramJson = ToJson(param);
		SobotParams_tCF40A43A8D519A95915ED461EFEF2BDDCA5B5168* L_2 = ___0_param;
		String_t* L_3;
		L_3 = ZCSobotApi_ToJson_m9440B37BB22A914C7CAD146110FAA2DE92E7DF0A(L_2, NULL);
		// _sobotInitSDK(paramJson, inst.gameObject.name, "OnInitResult");
		ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179* L_4 = V_0;
		NullCheck(L_4);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_5;
		L_5 = Component_get_gameObject_m57AEFBB14DB39EC476F740BA000E170355DE691B(L_4, NULL);
		NullCheck(L_5);
		String_t* L_6;
		L_6 = Object_get_name_mAC2F6B897CF1303BA4249B4CB55271AFACBB6392(L_5, NULL);
		ZCSobotApi__sobotInitSDK_m1EF8E1459C431F7397BFCB9631960AC4B0AC631D(L_3, L_6, _stringLiteral88FF9681ACC4160649786C9DB30EE86B79D22400, NULL);
		// }
		return;
	}
}
// System.Void SobotChatClient.ZCSobotApi::openSobotChat(SobotChatClient.SobotParams)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ZCSobotApi_openSobotChat_mC836BEDE95E00D401394CB7E6656DEC5259811C0 (SobotParams_tCF40A43A8D519A95915ED461EFEF2BDDCA5B5168* ___0_param, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// string paramJson = ToJson(param);
		SobotParams_tCF40A43A8D519A95915ED461EFEF2BDDCA5B5168* L_0 = ___0_param;
		il2cpp_codegen_runtime_class_init_inline(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
		String_t* L_1;
		L_1 = ZCSobotApi_ToJson_m9440B37BB22A914C7CAD146110FAA2DE92E7DF0A(L_0, NULL);
		// _sobotOpenChat(paramJson);
		ZCSobotApi__sobotOpenChat_m0236199F906D227E3B884F0B6740141A1CC2357C(L_1, NULL);
		// }
		return;
	}
}
// System.Void SobotChatClient.ZCSobotApi::openSobotHelpCenter(SobotChatClient.SobotParams)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ZCSobotApi_openSobotHelpCenter_m83B56A26FEEF59C43644564FCFE8FD706580AFDE (SobotParams_tCF40A43A8D519A95915ED461EFEF2BDDCA5B5168* ___0_param, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// string paramJson = ToJson(param);
		SobotParams_tCF40A43A8D519A95915ED461EFEF2BDDCA5B5168* L_0 = ___0_param;
		il2cpp_codegen_runtime_class_init_inline(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
		String_t* L_1;
		L_1 = ZCSobotApi_ToJson_m9440B37BB22A914C7CAD146110FAA2DE92E7DF0A(L_0, NULL);
		// _sobotOpenServiceCenter(paramJson);
		ZCSobotApi__sobotOpenServiceCenter_m6C7679DF119EFD55215E8FCBB39A5B2DFAA054B3(L_1, NULL);
		// }
		return;
	}
}
// System.Void SobotChatClient.ZCSobotApi::openSobotLeave(SobotChatClient.SobotParams)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ZCSobotApi_openSobotLeave_mB44E5E295DD55B9481AF3D7BD2D513CCF48145B7 (SobotParams_tCF40A43A8D519A95915ED461EFEF2BDDCA5B5168* ___0_param, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// string paramJson = ToJson(param);
		SobotParams_tCF40A43A8D519A95915ED461EFEF2BDDCA5B5168* L_0 = ___0_param;
		il2cpp_codegen_runtime_class_init_inline(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
		String_t* L_1;
		L_1 = ZCSobotApi_ToJson_m9440B37BB22A914C7CAD146110FAA2DE92E7DF0A(L_0, NULL);
		// _sobotOpenLeave(paramJson);
		ZCSobotApi__sobotOpenLeave_m8BC41A0E55BDD953C915913F22D43AF6DE44939D(L_1, NULL);
		// }
		return;
	}
}
// System.Void SobotChatClient.ZCSobotApi::getUnReadMessage(SobotChatClient.SobotParams,SobotChatClient.ZCSobotApi/OfflineMsgCallback)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ZCSobotApi_getUnReadMessage_mB472E163BCDA1F9F30C4F6BEA2566AFCD4F44EA6 (SobotParams_tCF40A43A8D519A95915ED461EFEF2BDDCA5B5168* ___0_param, OfflineMsgCallback_t95A2C0AE5DEFB9A1F73D67591217112C51B655D5* ___1_callback, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE5BDED738C6E9E230527D4C93CA322D8A99A0ECA);
		s_Il2CppMethodInitialized = true;
	}
	ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179* V_0 = NULL;
	{
		// _offlineMsgCallback = callback;
		OfflineMsgCallback_t95A2C0AE5DEFB9A1F73D67591217112C51B655D5* L_0 = ___1_callback;
		il2cpp_codegen_runtime_class_init_inline(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
		((ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_StaticFields*)il2cpp_codegen_static_fields_for(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var))->____offlineMsgCallback_6 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&((ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_StaticFields*)il2cpp_codegen_static_fields_for(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var))->____offlineMsgCallback_6), (void*)L_0);
		// var inst = Instance;
		ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179* L_1;
		L_1 = ZCSobotApi_get_Instance_m18C6611F9559B4F664A217C5F0CCB64C426A4155(NULL);
		V_0 = L_1;
		// string paramJson = ToJson(param);
		SobotParams_tCF40A43A8D519A95915ED461EFEF2BDDCA5B5168* L_2 = ___0_param;
		String_t* L_3;
		L_3 = ZCSobotApi_ToJson_m9440B37BB22A914C7CAD146110FAA2DE92E7DF0A(L_2, NULL);
		// _sobotGetOfflineMsg(paramJson, inst.gameObject.name, "OnOfflineMsgResult");
		ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179* L_4 = V_0;
		NullCheck(L_4);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_5;
		L_5 = Component_get_gameObject_m57AEFBB14DB39EC476F740BA000E170355DE691B(L_4, NULL);
		NullCheck(L_5);
		String_t* L_6;
		L_6 = Object_get_name_mAC2F6B897CF1303BA4249B4CB55271AFACBB6392(L_5, NULL);
		ZCSobotApi__sobotGetOfflineMsg_mF971E574BD2BDB945E997E05AC631B5496224F21(L_3, L_6, _stringLiteralE5BDED738C6E9E230527D4C93CA322D8A99A0ECA, NULL);
		// }
		return;
	}
}
// System.Void SobotChatClient.ZCSobotApi::closeSobotChat(SobotChatClient.SobotParams)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ZCSobotApi_closeSobotChat_m0453E93848C045091A751A5B42AC851668698717 (SobotParams_tCF40A43A8D519A95915ED461EFEF2BDDCA5B5168* ___0_param, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t G_B3_0 = 0;
	{
		// bool closePush = param != null && param.closePush;
		SobotParams_tCF40A43A8D519A95915ED461EFEF2BDDCA5B5168* L_0 = ___0_param;
		if (!L_0)
		{
			goto IL_000b;
		}
	}
	{
		SobotParams_tCF40A43A8D519A95915ED461EFEF2BDDCA5B5168* L_1 = ___0_param;
		NullCheck(L_1);
		bool L_2 = L_1->___closePush_72;
		G_B3_0 = ((int32_t)(L_2));
		goto IL_000c;
	}

IL_000b:
	{
		G_B3_0 = 0;
	}

IL_000c:
	{
		// _sobotCloseSession(closePush);
		il2cpp_codegen_runtime_class_init_inline(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
		ZCSobotApi__sobotCloseSession_mA59E270A58751FD761DEE5AD8D90B824B9AC3F92((bool)G_B3_0, NULL);
		// }
		return;
	}
}
// System.Void SobotChatClient.ZCSobotApi::setMessageLinkClick(SobotChatClient.ZCSobotApi/LinkClickCallback)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ZCSobotApi_setMessageLinkClick_m85E0F8373DA486387035C70404F745BFC6CBBFB2 (LinkClickCallback_t74FFEF1A7387D900A6578354799B79ECB1F3013E* ___0_callback, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral72C82332D5DAF09CA94510D07B0E9CA2CD684F55);
		s_Il2CppMethodInitialized = true;
	}
	{
		// var inst = Instance;
		il2cpp_codegen_runtime_class_init_inline(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
		ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179* L_0;
		L_0 = ZCSobotApi_get_Instance_m18C6611F9559B4F664A217C5F0CCB64C426A4155(NULL);
		// _linkClickCallback = callback;
		LinkClickCallback_t74FFEF1A7387D900A6578354799B79ECB1F3013E* L_1 = ___0_callback;
		((ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_StaticFields*)il2cpp_codegen_static_fields_for(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var))->____linkClickCallback_7 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&((ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_StaticFields*)il2cpp_codegen_static_fields_for(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var))->____linkClickCallback_7), (void*)L_1);
		// _sobotSetLinkClickListener(_iosLinkClickCallback);
		IOSLinkClickCallback_tE93B6F4ED698136320B42F54DE5AC652D635701A* L_2 = ((ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_StaticFields*)il2cpp_codegen_static_fields_for(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var))->____iosLinkClickCallback_12;
		ZCSobotApi__sobotSetLinkClickListener_m32B191A8DD6AD0ED7075DFE1108460D7A74F63FF(L_2, NULL);
		// Debug.Log("[SobotSDK] setMessageLinkClick registered for iOS");
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_Log_m87A9A3C761FF5C43ED8A53B16190A53D08F818BB(_stringLiteral72C82332D5DAF09CA94510D07B0E9CA2CD684F55, NULL);
		// }
		return;
	}
}
// System.Void SobotChatClient.ZCSobotApi::setFunctionClickListener(SobotChatClient.ZCSobotApi/FunctionClickCallback)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ZCSobotApi_setFunctionClickListener_mB4894039D4623F1EEBAF2F5D433D6B828C9C556A (FunctionClickCallback_t133340AD88A3E68729476CCC597F418302E4F28C* ___0_callback, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralE9B162451526A2D190CEED3541835A10DCC2297C);
		s_Il2CppMethodInitialized = true;
	}
	{
		// var inst = Instance;
		il2cpp_codegen_runtime_class_init_inline(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
		ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179* L_0;
		L_0 = ZCSobotApi_get_Instance_m18C6611F9559B4F664A217C5F0CCB64C426A4155(NULL);
		// _functionClickCallback = callback;
		FunctionClickCallback_t133340AD88A3E68729476CCC597F418302E4F28C* L_1 = ___0_callback;
		((ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_StaticFields*)il2cpp_codegen_static_fields_for(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var))->____functionClickCallback_8 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&((ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_StaticFields*)il2cpp_codegen_static_fields_for(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var))->____functionClickCallback_8), (void*)L_1);
		// _sobotSetFunctionClickListener(_iosFunctionClickCallback);
		IOSFunctionClickCallback_t9B9C81DAECBDABE1B68AD43DA4E42635B1A95613* L_2 = ((ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_StaticFields*)il2cpp_codegen_static_fields_for(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var))->____iosFunctionClickCallback_13;
		ZCSobotApi__sobotSetFunctionClickListener_m8F4945C50CCA0C2CD925740B4308887739930CF8(L_2, NULL);
		// Debug.Log("[SobotSDK] setFunctionClickListener registered for iOS");
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_Log_m87A9A3C761FF5C43ED8A53B16190A53D08F818BB(_stringLiteralE9B162451526A2D190CEED3541835A10DCC2297C, NULL);
		// }
		return;
	}
}
// System.Void SobotChatClient.ZCSobotApi::sendCustomCardToChat(SobotChatClient.SobotParams,SobotChatClient.ZCSobotApi/SendMessageResultCallback)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ZCSobotApi_sendCustomCardToChat_mE30307E001FC14D9B08AEC8C0F19D05210D01E57 (SobotParams_tCF40A43A8D519A95915ED461EFEF2BDDCA5B5168* ___0_param, SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475* ___1_callback, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralCA6B1C0631ABBE286728F052CFB9F3C70570B165);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralF3604A983170476BA44D180A6DCF7BED87FB7359);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralF4C4C79442D53DB4FB4C8871F94A71CE073D6411);
		s_Il2CppMethodInitialized = true;
	}
	ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179* V_0 = NULL;
	String_t* V_1 = NULL;
	String_t* G_B5_0 = NULL;
	{
		// if (!EnsureInitialized("sendCustomCardToChat", callback)) return;
		SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475* L_0 = ___1_callback;
		il2cpp_codegen_runtime_class_init_inline(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
		bool L_1;
		L_1 = ZCSobotApi_EnsureInitialized_m24D0257CD08C8FACE30BE63713449A2DF7BB6F4E(_stringLiteralF3604A983170476BA44D180A6DCF7BED87FB7359, L_0, NULL);
		if (L_1)
		{
			goto IL_000e;
		}
	}
	{
		// if (!EnsureInitialized("sendCustomCardToChat", callback)) return;
		return;
	}

IL_000e:
	{
		// if (!RequireString(param?.custom_card, "sendCustomCardToChat", "custom_card", callback)) return;
		SobotParams_tCF40A43A8D519A95915ED461EFEF2BDDCA5B5168* L_2 = ___0_param;
		if (L_2)
		{
			goto IL_0014;
		}
	}
	{
		G_B5_0 = ((String_t*)(NULL));
		goto IL_001a;
	}

IL_0014:
	{
		SobotParams_tCF40A43A8D519A95915ED461EFEF2BDDCA5B5168* L_3 = ___0_param;
		NullCheck(L_3);
		String_t* L_4 = L_3->___custom_card_48;
		G_B5_0 = L_4;
	}

IL_001a:
	{
		SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475* L_5 = ___1_callback;
		il2cpp_codegen_runtime_class_init_inline(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
		bool L_6;
		L_6 = ZCSobotApi_RequireString_m8018D7AD88EFFF77FA1A927324367599A608F8CE(G_B5_0, _stringLiteralF3604A983170476BA44D180A6DCF7BED87FB7359, _stringLiteralF4C4C79442D53DB4FB4C8871F94A71CE073D6411, L_5, NULL);
		if (L_6)
		{
			goto IL_002d;
		}
	}
	{
		// if (!RequireString(param?.custom_card, "sendCustomCardToChat", "custom_card", callback)) return;
		return;
	}

IL_002d:
	{
		// var inst = Instance;
		il2cpp_codegen_runtime_class_init_inline(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
		ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179* L_7;
		L_7 = ZCSobotApi_get_Instance_m18C6611F9559B4F664A217C5F0CCB64C426A4155(NULL);
		V_0 = L_7;
		// string requestId = StoreSendCallback(callback);
		SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475* L_8 = ___1_callback;
		String_t* L_9;
		L_9 = ZCSobotApi_StoreSendCallback_mD42610D0D741A738C11EDFF325BE4972E17D5921(L_8, NULL);
		V_1 = L_9;
		// _sobotSendCustomCardToChat(ToJson(param), inst.gameObject.name, "OnSendMessageResult", requestId);
		SobotParams_tCF40A43A8D519A95915ED461EFEF2BDDCA5B5168* L_10 = ___0_param;
		String_t* L_11;
		L_11 = ZCSobotApi_ToJson_m9440B37BB22A914C7CAD146110FAA2DE92E7DF0A(L_10, NULL);
		ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179* L_12 = V_0;
		NullCheck(L_12);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_13;
		L_13 = Component_get_gameObject_m57AEFBB14DB39EC476F740BA000E170355DE691B(L_12, NULL);
		NullCheck(L_13);
		String_t* L_14;
		L_14 = Object_get_name_mAC2F6B897CF1303BA4249B4CB55271AFACBB6392(L_13, NULL);
		String_t* L_15 = V_1;
		ZCSobotApi__sobotSendCustomCardToChat_m6E00796E1206BDB9D028A47AD39EFFE47FD6A714(L_11, L_14, _stringLiteralCA6B1C0631ABBE286728F052CFB9F3C70570B165, L_15, NULL);
		// }
		return;
	}
}
// System.Void SobotChatClient.ZCSobotApi::sendProductInfo(SobotChatClient.SobotParams,SobotChatClient.ZCSobotApi/SendMessageResultCallback)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ZCSobotApi_sendProductInfo_m7B232747A130997E7C57E8454DCCAD779EB21DDD (SobotParams_tCF40A43A8D519A95915ED461EFEF2BDDCA5B5168* ___0_param, SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475* ___1_callback, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral06EAFAB9DEBE8A08B1216B113227678999BA00B8);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral29FFB7ED65745EEFF8D1344FEB8A6B11C4C5A30D);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral6B7357B96E5399281C1DCFB6D78DB0E743B72BE1);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralCA6B1C0631ABBE286728F052CFB9F3C70570B165);
		s_Il2CppMethodInitialized = true;
	}
	ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179* V_0 = NULL;
	String_t* V_1 = NULL;
	String_t* G_B5_0 = NULL;
	String_t* G_B10_0 = NULL;
	{
		// if (!EnsureInitialized("sendProductInfo", callback)) return;
		SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475* L_0 = ___1_callback;
		il2cpp_codegen_runtime_class_init_inline(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
		bool L_1;
		L_1 = ZCSobotApi_EnsureInitialized_m24D0257CD08C8FACE30BE63713449A2DF7BB6F4E(_stringLiteral06EAFAB9DEBE8A08B1216B113227678999BA00B8, L_0, NULL);
		if (L_1)
		{
			goto IL_000e;
		}
	}
	{
		// if (!EnsureInitialized("sendProductInfo", callback)) return;
		return;
	}

IL_000e:
	{
		// if (!RequireString(param?.goodsTitle, "sendProductInfo", "goodsTitle", callback)) return;
		SobotParams_tCF40A43A8D519A95915ED461EFEF2BDDCA5B5168* L_2 = ___0_param;
		if (L_2)
		{
			goto IL_0014;
		}
	}
	{
		G_B5_0 = ((String_t*)(NULL));
		goto IL_001a;
	}

IL_0014:
	{
		SobotParams_tCF40A43A8D519A95915ED461EFEF2BDDCA5B5168* L_3 = ___0_param;
		NullCheck(L_3);
		String_t* L_4 = L_3->___goodsTitle_49;
		G_B5_0 = L_4;
	}

IL_001a:
	{
		SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475* L_5 = ___1_callback;
		il2cpp_codegen_runtime_class_init_inline(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
		bool L_6;
		L_6 = ZCSobotApi_RequireString_m8018D7AD88EFFF77FA1A927324367599A608F8CE(G_B5_0, _stringLiteral06EAFAB9DEBE8A08B1216B113227678999BA00B8, _stringLiteral6B7357B96E5399281C1DCFB6D78DB0E743B72BE1, L_5, NULL);
		if (L_6)
		{
			goto IL_002d;
		}
	}
	{
		// if (!RequireString(param?.goodsTitle, "sendProductInfo", "goodsTitle", callback)) return;
		return;
	}

IL_002d:
	{
		// if (!RequireString(param?.goodsLink, "sendProductInfo", "goodsLink", callback)) return;
		SobotParams_tCF40A43A8D519A95915ED461EFEF2BDDCA5B5168* L_7 = ___0_param;
		if (L_7)
		{
			goto IL_0033;
		}
	}
	{
		G_B10_0 = ((String_t*)(NULL));
		goto IL_0039;
	}

IL_0033:
	{
		SobotParams_tCF40A43A8D519A95915ED461EFEF2BDDCA5B5168* L_8 = ___0_param;
		NullCheck(L_8);
		String_t* L_9 = L_8->___goodsLink_52;
		G_B10_0 = L_9;
	}

IL_0039:
	{
		SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475* L_10 = ___1_callback;
		il2cpp_codegen_runtime_class_init_inline(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
		bool L_11;
		L_11 = ZCSobotApi_RequireString_m8018D7AD88EFFF77FA1A927324367599A608F8CE(G_B10_0, _stringLiteral06EAFAB9DEBE8A08B1216B113227678999BA00B8, _stringLiteral29FFB7ED65745EEFF8D1344FEB8A6B11C4C5A30D, L_10, NULL);
		if (L_11)
		{
			goto IL_004c;
		}
	}
	{
		// if (!RequireString(param?.goodsLink, "sendProductInfo", "goodsLink", callback)) return;
		return;
	}

IL_004c:
	{
		// var inst = Instance;
		il2cpp_codegen_runtime_class_init_inline(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
		ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179* L_12;
		L_12 = ZCSobotApi_get_Instance_m18C6611F9559B4F664A217C5F0CCB64C426A4155(NULL);
		V_0 = L_12;
		// string requestId = StoreSendCallback(callback);
		SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475* L_13 = ___1_callback;
		String_t* L_14;
		L_14 = ZCSobotApi_StoreSendCallback_mD42610D0D741A738C11EDFF325BE4972E17D5921(L_13, NULL);
		V_1 = L_14;
		// _sobotSendProductInfo(ToJson(param), inst.gameObject.name, "OnSendMessageResult", requestId);
		SobotParams_tCF40A43A8D519A95915ED461EFEF2BDDCA5B5168* L_15 = ___0_param;
		String_t* L_16;
		L_16 = ZCSobotApi_ToJson_m9440B37BB22A914C7CAD146110FAA2DE92E7DF0A(L_15, NULL);
		ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179* L_17 = V_0;
		NullCheck(L_17);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_18;
		L_18 = Component_get_gameObject_m57AEFBB14DB39EC476F740BA000E170355DE691B(L_17, NULL);
		NullCheck(L_18);
		String_t* L_19;
		L_19 = Object_get_name_mAC2F6B897CF1303BA4249B4CB55271AFACBB6392(L_18, NULL);
		String_t* L_20 = V_1;
		ZCSobotApi__sobotSendProductInfo_mC4253F805498034853C9C3F62F5CCB9C15C10C9E(L_16, L_19, _stringLiteralCA6B1C0631ABBE286728F052CFB9F3C70570B165, L_20, NULL);
		// }
		return;
	}
}
// System.Void SobotChatClient.ZCSobotApi::sendOrderGoodsInfo(SobotChatClient.SobotParams,SobotChatClient.ZCSobotApi/SendMessageResultCallback)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ZCSobotApi_sendOrderGoodsInfo_m4BB172CF3A2DC453CF876723D3E3CC7EE586E216 (SobotParams_tCF40A43A8D519A95915ED461EFEF2BDDCA5B5168* ___0_param, SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475* ___1_callback, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral595B9660F30811FEE11F7F4A63960C9D25416A90);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral839FEB4159DABB7E5B5A06411C01ADE5012AAEBF);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralCA6B1C0631ABBE286728F052CFB9F3C70570B165);
		s_Il2CppMethodInitialized = true;
	}
	ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179* V_0 = NULL;
	String_t* V_1 = NULL;
	String_t* G_B5_0 = NULL;
	{
		// if (!EnsureInitialized("sendOrderGoodsInfo", callback)) return;
		SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475* L_0 = ___1_callback;
		il2cpp_codegen_runtime_class_init_inline(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
		bool L_1;
		L_1 = ZCSobotApi_EnsureInitialized_m24D0257CD08C8FACE30BE63713449A2DF7BB6F4E(_stringLiteral839FEB4159DABB7E5B5A06411C01ADE5012AAEBF, L_0, NULL);
		if (L_1)
		{
			goto IL_000e;
		}
	}
	{
		// if (!EnsureInitialized("sendOrderGoodsInfo", callback)) return;
		return;
	}

IL_000e:
	{
		// if (!RequireString(param?.orderCode, "sendOrderGoodsInfo", "orderCode", callback)) return;
		SobotParams_tCF40A43A8D519A95915ED461EFEF2BDDCA5B5168* L_2 = ___0_param;
		if (L_2)
		{
			goto IL_0014;
		}
	}
	{
		G_B5_0 = ((String_t*)(NULL));
		goto IL_001a;
	}

IL_0014:
	{
		SobotParams_tCF40A43A8D519A95915ED461EFEF2BDDCA5B5168* L_3 = ___0_param;
		NullCheck(L_3);
		String_t* L_4 = L_3->___orderCode_56;
		G_B5_0 = L_4;
	}

IL_001a:
	{
		SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475* L_5 = ___1_callback;
		il2cpp_codegen_runtime_class_init_inline(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
		bool L_6;
		L_6 = ZCSobotApi_RequireString_m8018D7AD88EFFF77FA1A927324367599A608F8CE(G_B5_0, _stringLiteral839FEB4159DABB7E5B5A06411C01ADE5012AAEBF, _stringLiteral595B9660F30811FEE11F7F4A63960C9D25416A90, L_5, NULL);
		if (L_6)
		{
			goto IL_002d;
		}
	}
	{
		// if (!RequireString(param?.orderCode, "sendOrderGoodsInfo", "orderCode", callback)) return;
		return;
	}

IL_002d:
	{
		// var inst = Instance;
		il2cpp_codegen_runtime_class_init_inline(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
		ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179* L_7;
		L_7 = ZCSobotApi_get_Instance_m18C6611F9559B4F664A217C5F0CCB64C426A4155(NULL);
		V_0 = L_7;
		// string requestId = StoreSendCallback(callback);
		SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475* L_8 = ___1_callback;
		String_t* L_9;
		L_9 = ZCSobotApi_StoreSendCallback_mD42610D0D741A738C11EDFF325BE4972E17D5921(L_8, NULL);
		V_1 = L_9;
		// _sobotSendOrderGoodsInfo(ToJson(param), inst.gameObject.name, "OnSendMessageResult", requestId);
		SobotParams_tCF40A43A8D519A95915ED461EFEF2BDDCA5B5168* L_10 = ___0_param;
		String_t* L_11;
		L_11 = ZCSobotApi_ToJson_m9440B37BB22A914C7CAD146110FAA2DE92E7DF0A(L_10, NULL);
		ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179* L_12 = V_0;
		NullCheck(L_12);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_13;
		L_13 = Component_get_gameObject_m57AEFBB14DB39EC476F740BA000E170355DE691B(L_12, NULL);
		NullCheck(L_13);
		String_t* L_14;
		L_14 = Object_get_name_mAC2F6B897CF1303BA4249B4CB55271AFACBB6392(L_13, NULL);
		String_t* L_15 = V_1;
		ZCSobotApi__sobotSendOrderGoodsInfo_mF4D540AA3AB36164D4100179C83EFFF1840B5EED(L_11, L_14, _stringLiteralCA6B1C0631ABBE286728F052CFB9F3C70570B165, L_15, NULL);
		// }
		return;
	}
}
// System.Void SobotChatClient.ZCSobotApi::sendLocation(SobotChatClient.SobotParams,SobotChatClient.ZCSobotApi/SendMessageResultCallback)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ZCSobotApi_sendLocation_mF4A4CF8B7E340791BF45256621F63218F9347B94 (SobotParams_tCF40A43A8D519A95915ED461EFEF2BDDCA5B5168* ___0_param, SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475* ___1_callback, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral2130FB49D4CB4A6C571BDE45991342B2F508A1D7);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral4F947DD752BAA3989FD8419D4B2425AD0C64D6C3);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral7A34F23A1242AA68485695F3DDF5C917EF2F0071);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralCA6B1C0631ABBE286728F052CFB9F3C70570B165);
		s_Il2CppMethodInitialized = true;
	}
	ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179* V_0 = NULL;
	String_t* V_1 = NULL;
	String_t* G_B5_0 = NULL;
	String_t* G_B10_0 = NULL;
	{
		// if (!EnsureInitialized("sendLocation", callback)) return;
		SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475* L_0 = ___1_callback;
		il2cpp_codegen_runtime_class_init_inline(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
		bool L_1;
		L_1 = ZCSobotApi_EnsureInitialized_m24D0257CD08C8FACE30BE63713449A2DF7BB6F4E(_stringLiteral7A34F23A1242AA68485695F3DDF5C917EF2F0071, L_0, NULL);
		if (L_1)
		{
			goto IL_000e;
		}
	}
	{
		// if (!EnsureInitialized("sendLocation", callback)) return;
		return;
	}

IL_000e:
	{
		// if (!RequireString(param?.lat, "sendLocation", "lat", callback)) return;
		SobotParams_tCF40A43A8D519A95915ED461EFEF2BDDCA5B5168* L_2 = ___0_param;
		if (L_2)
		{
			goto IL_0014;
		}
	}
	{
		G_B5_0 = ((String_t*)(NULL));
		goto IL_001a;
	}

IL_0014:
	{
		SobotParams_tCF40A43A8D519A95915ED461EFEF2BDDCA5B5168* L_3 = ___0_param;
		NullCheck(L_3);
		String_t* L_4 = L_3->___lat_66;
		G_B5_0 = L_4;
	}

IL_001a:
	{
		SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475* L_5 = ___1_callback;
		il2cpp_codegen_runtime_class_init_inline(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
		bool L_6;
		L_6 = ZCSobotApi_RequireString_m8018D7AD88EFFF77FA1A927324367599A608F8CE(G_B5_0, _stringLiteral7A34F23A1242AA68485695F3DDF5C917EF2F0071, _stringLiteral4F947DD752BAA3989FD8419D4B2425AD0C64D6C3, L_5, NULL);
		if (L_6)
		{
			goto IL_002d;
		}
	}
	{
		// if (!RequireString(param?.lat, "sendLocation", "lat", callback)) return;
		return;
	}

IL_002d:
	{
		// if (!RequireString(param?.lng, "sendLocation", "lng", callback)) return;
		SobotParams_tCF40A43A8D519A95915ED461EFEF2BDDCA5B5168* L_7 = ___0_param;
		if (L_7)
		{
			goto IL_0033;
		}
	}
	{
		G_B10_0 = ((String_t*)(NULL));
		goto IL_0039;
	}

IL_0033:
	{
		SobotParams_tCF40A43A8D519A95915ED461EFEF2BDDCA5B5168* L_8 = ___0_param;
		NullCheck(L_8);
		String_t* L_9 = L_8->___lng_67;
		G_B10_0 = L_9;
	}

IL_0039:
	{
		SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475* L_10 = ___1_callback;
		il2cpp_codegen_runtime_class_init_inline(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
		bool L_11;
		L_11 = ZCSobotApi_RequireString_m8018D7AD88EFFF77FA1A927324367599A608F8CE(G_B10_0, _stringLiteral7A34F23A1242AA68485695F3DDF5C917EF2F0071, _stringLiteral2130FB49D4CB4A6C571BDE45991342B2F508A1D7, L_10, NULL);
		if (L_11)
		{
			goto IL_004c;
		}
	}
	{
		// if (!RequireString(param?.lng, "sendLocation", "lng", callback)) return;
		return;
	}

IL_004c:
	{
		// var inst = Instance;
		il2cpp_codegen_runtime_class_init_inline(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
		ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179* L_12;
		L_12 = ZCSobotApi_get_Instance_m18C6611F9559B4F664A217C5F0CCB64C426A4155(NULL);
		V_0 = L_12;
		// string requestId = StoreSendCallback(callback);
		SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475* L_13 = ___1_callback;
		String_t* L_14;
		L_14 = ZCSobotApi_StoreSendCallback_mD42610D0D741A738C11EDFF325BE4972E17D5921(L_13, NULL);
		V_1 = L_14;
		// _sobotSendLocation(ToJson(param), inst.gameObject.name, "OnSendMessageResult", requestId);
		SobotParams_tCF40A43A8D519A95915ED461EFEF2BDDCA5B5168* L_15 = ___0_param;
		String_t* L_16;
		L_16 = ZCSobotApi_ToJson_m9440B37BB22A914C7CAD146110FAA2DE92E7DF0A(L_15, NULL);
		ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179* L_17 = V_0;
		NullCheck(L_17);
		GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* L_18;
		L_18 = Component_get_gameObject_m57AEFBB14DB39EC476F740BA000E170355DE691B(L_17, NULL);
		NullCheck(L_18);
		String_t* L_19;
		L_19 = Object_get_name_mAC2F6B897CF1303BA4249B4CB55271AFACBB6392(L_18, NULL);
		String_t* L_20 = V_1;
		ZCSobotApi__sobotSendLocation_mF30BF53D3CCB336531AE2CC2FD5CEE81E3D41AA7(L_16, L_19, _stringLiteralCA6B1C0631ABBE286728F052CFB9F3C70570B165, L_20, NULL);
		// }
		return;
	}
}
// System.String SobotChatClient.ZCSobotApi::ToJson(SobotChatClient.SobotParams)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* ZCSobotApi_ToJson_m9440B37BB22A914C7CAD146110FAA2DE92E7DF0A (SobotParams_tCF40A43A8D519A95915ED461EFEF2BDDCA5B5168* ___0_param, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SobotParams_tCF40A43A8D519A95915ED461EFEF2BDDCA5B5168_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral5998AB72D667A3790249FC2477019B8A1A4B2AA4);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralCF05829BAF1CDB87EC20E7C2B048FC8CD4399638);
		s_Il2CppMethodInitialized = true;
	}
	SobotParams_tCF40A43A8D519A95915ED461EFEF2BDDCA5B5168* G_B2_0 = NULL;
	SobotParams_tCF40A43A8D519A95915ED461EFEF2BDDCA5B5168* G_B1_0 = NULL;
	{
		// string json = JsonUtility.ToJson(param ?? new SobotParams());
		SobotParams_tCF40A43A8D519A95915ED461EFEF2BDDCA5B5168* L_0 = ___0_param;
		SobotParams_tCF40A43A8D519A95915ED461EFEF2BDDCA5B5168* L_1 = L_0;
		G_B1_0 = L_1;
		if (L_1)
		{
			G_B2_0 = L_1;
			goto IL_000a;
		}
	}
	{
		SobotParams_tCF40A43A8D519A95915ED461EFEF2BDDCA5B5168* L_2 = (SobotParams_tCF40A43A8D519A95915ED461EFEF2BDDCA5B5168*)il2cpp_codegen_object_new(SobotParams_tCF40A43A8D519A95915ED461EFEF2BDDCA5B5168_il2cpp_TypeInfo_var);
		NullCheck(L_2);
		SobotParams__ctor_m0C6D3CA588C82C70B45BE6DE02AF384787F39D17(L_2, NULL);
		G_B2_0 = L_2;
	}

IL_000a:
	{
		String_t* L_3;
		L_3 = JsonUtility_ToJson_m28CC6843B9D3723D88AD13EA3829B71FDE7826BA(G_B2_0, NULL);
		// return json.Replace("\"_params\"", "\"params\"");
		NullCheck(L_3);
		String_t* L_4;
		L_4 = String_Replace_mABDB7003A1D0AEDCAE9FF85E3DFFFBA752D2A166(L_3, _stringLiteral5998AB72D667A3790249FC2477019B8A1A4B2AA4, _stringLiteralCF05829BAF1CDB87EC20E7C2B048FC8CD4399638, NULL);
		return L_4;
	}
}
// System.Boolean SobotChatClient.ZCSobotApi::EnsureInitialized(System.String,SobotChatClient.ZCSobotApi/SendMessageResultCallback)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ZCSobotApi_EnsureInitialized_m24D0257CD08C8FACE30BE63713449A2DF7BB6F4E (String_t* ___0_methodName, SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475* ___1_callback, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral448227D0A5EEB181F876672782704616B083B472);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral55B2E83BA85EED92C9B92A6A1BC216FC775979CA);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralB5099EC8CF481EF20354A7A53CAB860C81B09DCC);
		s_Il2CppMethodInitialized = true;
	}
	String_t* V_0 = NULL;
	{
		// if (_isInitialized) return true;
		il2cpp_codegen_runtime_class_init_inline(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
		bool L_0 = ((ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_StaticFields*)il2cpp_codegen_static_fields_for(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var))->____isInitialized_9;
		if (!L_0)
		{
			goto IL_0009;
		}
	}
	{
		// if (_isInitialized) return true;
		return (bool)1;
	}

IL_0009:
	{
		// string message = "???? initSobotSDK ??????????????";
		V_0 = _stringLiteralB5099EC8CF481EF20354A7A53CAB860C81B09DCC;
		// Debug.LogWarning($"[SobotSDK] {methodName} ignored: {message}");
		String_t* L_1 = ___0_methodName;
		String_t* L_2 = V_0;
		String_t* L_3;
		L_3 = String_Concat_m093934F71A9B351911EE46311674ED463B180006(_stringLiteral448227D0A5EEB181F876672782704616B083B472, L_1, _stringLiteral55B2E83BA85EED92C9B92A6A1BC216FC775979CA, L_2, NULL);
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_LogWarning_m33EF1B897E0C7C6FF538989610BFAFFEF4628CA9(L_3, NULL);
		// callback?.Invoke(false, -1, message);
		SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475* L_4 = ___1_callback;
		if (!L_4)
		{
			goto IL_0031;
		}
	}
	{
		SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475* L_5 = ___1_callback;
		String_t* L_6 = V_0;
		NullCheck(L_5);
		SendMessageResultCallback_Invoke_mBA48517CB222DA8E62EE9E645A007C21454870E4_inline(L_5, (bool)0, (-1), L_6, NULL);
	}

IL_0031:
	{
		// return false;
		return (bool)0;
	}
}
// System.Boolean SobotChatClient.ZCSobotApi::RequireString(System.String,System.String,System.String,SobotChatClient.ZCSobotApi/SendMessageResultCallback)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ZCSobotApi_RequireString_m8018D7AD88EFFF77FA1A927324367599A608F8CE (String_t* ___0_value, String_t* ___1_methodName, String_t* ___2_fieldName, SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475* ___3_callback, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral14EF2B4F89B1C436C288DDCF653B81A2C1A786C4);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral448227D0A5EEB181F876672782704616B083B472);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral55B2E83BA85EED92C9B92A6A1BC216FC775979CA);
		s_Il2CppMethodInitialized = true;
	}
	String_t* V_0 = NULL;
	{
		// if (!string.IsNullOrEmpty(value)) return true;
		String_t* L_0 = ___0_value;
		bool L_1;
		L_1 = String_IsNullOrEmpty_mEA9E3FB005AC28FE02E69FCF95A7B8456192B478(L_0, NULL);
		if (L_1)
		{
			goto IL_000a;
		}
	}
	{
		// if (!string.IsNullOrEmpty(value)) return true;
		return (bool)1;
	}

IL_000a:
	{
		// string message = $"{fieldName} ????";
		String_t* L_2 = ___2_fieldName;
		String_t* L_3;
		L_3 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(L_2, _stringLiteral14EF2B4F89B1C436C288DDCF653B81A2C1A786C4, NULL);
		V_0 = L_3;
		// Debug.LogWarning($"[SobotSDK] {methodName} ignored: {message}");
		String_t* L_4 = ___1_methodName;
		String_t* L_5 = V_0;
		String_t* L_6;
		L_6 = String_Concat_m093934F71A9B351911EE46311674ED463B180006(_stringLiteral448227D0A5EEB181F876672782704616B083B472, L_4, _stringLiteral55B2E83BA85EED92C9B92A6A1BC216FC775979CA, L_5, NULL);
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_LogWarning_m33EF1B897E0C7C6FF538989610BFAFFEF4628CA9(L_6, NULL);
		// callback?.Invoke(false, -1, message);
		SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475* L_7 = ___3_callback;
		if (!L_7)
		{
			goto IL_0038;
		}
	}
	{
		SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475* L_8 = ___3_callback;
		String_t* L_9 = V_0;
		NullCheck(L_8);
		SendMessageResultCallback_Invoke_mBA48517CB222DA8E62EE9E645A007C21454870E4_inline(L_8, (bool)0, (-1), L_9, NULL);
	}

IL_0038:
	{
		// return false;
		return (bool)0;
	}
}
// System.String SobotChatClient.ZCSobotApi::StoreSendCallback(SobotChatClient.ZCSobotApi/SendMessageResultCallback)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* ZCSobotApi_StoreSendCallback_mD42610D0D741A738C11EDFF325BE4972E17D5921 (SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475* ___0_callback, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_set_Item_m8DAD2B757C763B0BE87D5193C64D145376059412_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&String_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	String_t* V_0 = NULL;
	int32_t V_1 = 0;
	{
		// if (callback == null) return string.Empty;
		SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475* L_0 = ___0_callback;
		if (L_0)
		{
			goto IL_0009;
		}
	}
	{
		// if (callback == null) return string.Empty;
		String_t* L_1 = ((String_t_StaticFields*)il2cpp_codegen_static_fields_for(String_t_il2cpp_TypeInfo_var))->___Empty_6;
		return L_1;
	}

IL_0009:
	{
		// string requestId = (++_sendRequestSeq).ToString();
		il2cpp_codegen_runtime_class_init_inline(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
		int32_t L_2 = ((ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_StaticFields*)il2cpp_codegen_static_fields_for(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var))->____sendRequestSeq_10;
		int32_t L_3 = ((int32_t)il2cpp_codegen_add(L_2, 1));
		((ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_StaticFields*)il2cpp_codegen_static_fields_for(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var))->____sendRequestSeq_10 = L_3;
		V_1 = L_3;
		String_t* L_4;
		L_4 = Int32_ToString_m030E01C24E294D6762FB0B6F37CB541581F55CA5((&V_1), NULL);
		V_0 = L_4;
		// _sendCallbacks[requestId] = callback;
		Dictionary_2_t90FE42767FAF03DFB400884E3F5B327D48A268A5* L_5 = ((ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_StaticFields*)il2cpp_codegen_static_fields_for(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var))->____sendCallbacks_11;
		String_t* L_6 = V_0;
		SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475* L_7 = ___0_callback;
		NullCheck(L_5);
		Dictionary_2_set_Item_m8DAD2B757C763B0BE87D5193C64D145376059412(L_5, L_6, L_7, Dictionary_2_set_Item_m8DAD2B757C763B0BE87D5193C64D145376059412_RuntimeMethod_var);
		// return requestId;
		String_t* L_8 = V_0;
		return L_8;
	}
}
// System.Void SobotChatClient.ZCSobotApi::OnInitResult(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ZCSobotApi_OnInitResult_mF22358BE44D978A96FC4EEC57F653F4DFF2D222F (ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179* __this, String_t* ___0_message, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral9235B2F5272F8AC7DEF6528CFE0675DA82D78199);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralFCA74A9060DDEE6A3ECAE73E6AB96086770BE7E2);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	int32_t G_B3_0 = 0;
	InitResultCallback_t681E10D9230FD32958B962D5B649178586A97B7B* G_B5_0 = NULL;
	InitResultCallback_t681E10D9230FD32958B962D5B649178586A97B7B* G_B4_0 = NULL;
	{
		// Debug.Log($"[SobotSDK] OnInitResult: {message}");
		String_t* L_0 = ___0_message;
		String_t* L_1;
		L_1 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(_stringLiteral9235B2F5272F8AC7DEF6528CFE0675DA82D78199, L_0, NULL);
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_Log_m87A9A3C761FF5C43ED8A53B16190A53D08F818BB(L_1, NULL);
		// bool success = message != null && !message.StartsWith("error");
		String_t* L_2 = ___0_message;
		if (!L_2)
		{
			goto IL_0023;
		}
	}
	{
		String_t* L_3 = ___0_message;
		NullCheck(L_3);
		bool L_4;
		L_4 = String_StartsWith_mF75DBA1EB709811E711B44E26FF919C88A8E65C0(L_3, _stringLiteralFCA74A9060DDEE6A3ECAE73E6AB96086770BE7E2, NULL);
		G_B3_0 = ((((int32_t)L_4) == ((int32_t)0))? 1 : 0);
		goto IL_0024;
	}

IL_0023:
	{
		G_B3_0 = 0;
	}

IL_0024:
	{
		V_0 = (bool)G_B3_0;
		// _isInitialized = success;
		bool L_5 = V_0;
		il2cpp_codegen_runtime_class_init_inline(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
		((ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_StaticFields*)il2cpp_codegen_static_fields_for(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var))->____isInitialized_9 = L_5;
		// _initCallback?.Invoke(success, message);
		InitResultCallback_t681E10D9230FD32958B962D5B649178586A97B7B* L_6 = ((ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_StaticFields*)il2cpp_codegen_static_fields_for(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var))->____initCallback_5;
		InitResultCallback_t681E10D9230FD32958B962D5B649178586A97B7B* L_7 = L_6;
		G_B4_0 = L_7;
		if (L_7)
		{
			G_B5_0 = L_7;
			goto IL_0035;
		}
	}
	{
		return;
	}

IL_0035:
	{
		bool L_8 = V_0;
		String_t* L_9 = ___0_message;
		NullCheck(G_B5_0);
		InitResultCallback_Invoke_mF07EB0A9EAB5519565C8DD8368BBB7ABBB8A05E8_inline(G_B5_0, L_8, L_9, NULL);
		// }
		return;
	}
}
// System.Void SobotChatClient.ZCSobotApi::OnOfflineMsgResult(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ZCSobotApi_OnOfflineMsgResult_m5882E2409CC51F348DA390816E6184716254029E (ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179* __this, String_t* ___0_data, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* V_0 = NULL;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	int32_t V_3 = 0;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	int32_t G_B3_0 = 0;
	int32_t G_B6_0 = 0;
	int32_t G_B9_0 = 0;
	OfflineMsgCallback_t95A2C0AE5DEFB9A1F73D67591217112C51B655D5* G_B11_0 = NULL;
	OfflineMsgCallback_t95A2C0AE5DEFB9A1F73D67591217112C51B655D5* G_B10_0 = NULL;
	OfflineMsgCallback_t95A2C0AE5DEFB9A1F73D67591217112C51B655D5* G_B15_0 = NULL;
	OfflineMsgCallback_t95A2C0AE5DEFB9A1F73D67591217112C51B655D5* G_B14_0 = NULL;
	try
	{// begin try (depth: 1)
		{
			// string[] parts = data.Split(',');
			String_t* L_0 = ___0_data;
			NullCheck(L_0);
			StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_1;
			L_1 = String_Split_m9530B73D02054692283BF35C3A27C8F2230946F4(L_0, ((int32_t)44), 0, NULL);
			V_0 = L_1;
			// int unRead = parts.Length > 0 ? int.Parse(parts[0]) : 0;
			StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_2 = V_0;
			NullCheck(L_2);
			if ((((RuntimeArray*)L_2)->max_length))
			{
				goto IL_0011_1;
			}
		}
		{
			G_B3_0 = 0;
			goto IL_0019_1;
		}

IL_0011_1:
		{
			StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_3 = V_0;
			NullCheck(L_3);
			int32_t L_4 = 0;
			String_t* L_5 = (L_3)->GetAt(static_cast<il2cpp_array_size_t>(L_4));
			int32_t L_6;
			L_6 = Int32_Parse_m273CA1A9C7717C99641291A95C543711C0202AF0(L_5, NULL);
			G_B3_0 = L_6;
		}

IL_0019_1:
		{
			V_1 = G_B3_0;
			// int offline = parts.Length > 1 ? int.Parse(parts[1]) : 0;
			StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_7 = V_0;
			NullCheck(L_7);
			if ((((int32_t)((int32_t)(((RuntimeArray*)L_7)->max_length))) > ((int32_t)1)))
			{
				goto IL_0023_1;
			}
		}
		{
			G_B6_0 = 0;
			goto IL_002b_1;
		}

IL_0023_1:
		{
			StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_8 = V_0;
			NullCheck(L_8);
			int32_t L_9 = 1;
			String_t* L_10 = (L_8)->GetAt(static_cast<il2cpp_array_size_t>(L_9));
			int32_t L_11;
			L_11 = Int32_Parse_m273CA1A9C7717C99641291A95C543711C0202AF0(L_10, NULL);
			G_B6_0 = L_11;
		}

IL_002b_1:
		{
			V_2 = G_B6_0;
			// int unAck = parts.Length > 2 ? int.Parse(parts[2]) : 0;
			StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_12 = V_0;
			NullCheck(L_12);
			if ((((int32_t)((int32_t)(((RuntimeArray*)L_12)->max_length))) > ((int32_t)2)))
			{
				goto IL_0035_1;
			}
		}
		{
			G_B9_0 = 0;
			goto IL_003d_1;
		}

IL_0035_1:
		{
			StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_13 = V_0;
			NullCheck(L_13);
			int32_t L_14 = 2;
			String_t* L_15 = (L_13)->GetAt(static_cast<il2cpp_array_size_t>(L_14));
			int32_t L_16;
			L_16 = Int32_Parse_m273CA1A9C7717C99641291A95C543711C0202AF0(L_15, NULL);
			G_B9_0 = L_16;
		}

IL_003d_1:
		{
			V_3 = G_B9_0;
			// _offlineMsgCallback?.Invoke(unRead, offline, unAck);
			il2cpp_codegen_runtime_class_init_inline(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
			OfflineMsgCallback_t95A2C0AE5DEFB9A1F73D67591217112C51B655D5* L_17 = ((ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_StaticFields*)il2cpp_codegen_static_fields_for(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var))->____offlineMsgCallback_6;
			OfflineMsgCallback_t95A2C0AE5DEFB9A1F73D67591217112C51B655D5* L_18 = L_17;
			G_B10_0 = L_18;
			if (L_18)
			{
				G_B11_0 = L_18;
				goto IL_0049_1;
			}
		}
		{
			goto IL_0051_1;
		}

IL_0049_1:
		{
			int32_t L_19 = V_1;
			int32_t L_20 = V_2;
			int32_t L_21 = V_3;
			NullCheck(G_B11_0);
			OfflineMsgCallback_Invoke_mC45ED6E4DEA1ADA6B9CABFAE0BB02F5F85DA0CF5_inline(G_B11_0, L_19, L_20, L_21, NULL);
		}

IL_0051_1:
		{
			// }
			goto IL_0069;
		}
	}// end try (depth: 1)
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&RuntimeObject_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0053;
		}
		throw e;
	}

CATCH_0053:
	{// begin catch(System.Object)
		{
			RuntimeObject* L_22 = ((RuntimeObject*)IL2CPP_GET_ACTIVE_EXCEPTION(RuntimeObject*));;
			// catch { _offlineMsgCallback?.Invoke(0, 0, 0); }
			// catch { _offlineMsgCallback?.Invoke(0, 0, 0); }
			il2cpp_codegen_runtime_class_init_inline(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var)));
			OfflineMsgCallback_t95A2C0AE5DEFB9A1F73D67591217112C51B655D5* L_23 = ((ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_StaticFields*)il2cpp_codegen_static_fields_for(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var))))->____offlineMsgCallback_6;
			OfflineMsgCallback_t95A2C0AE5DEFB9A1F73D67591217112C51B655D5* L_24 = L_23;
			G_B14_0 = L_24;
			if (L_24)
			{
				G_B15_0 = L_24;
				goto IL_005f;
			}
		}
		{
			goto IL_0067;
		}

IL_005f:
		{
			NullCheck(G_B15_0);
			OfflineMsgCallback_Invoke_mC45ED6E4DEA1ADA6B9CABFAE0BB02F5F85DA0CF5_inline(G_B15_0, 0, 0, 0, NULL);
		}

IL_0067:
		{
			// catch { _offlineMsgCallback?.Invoke(0, 0, 0); }
			IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
			goto IL_0069;
		}
	}// end catch (depth: 1)

IL_0069:
	{
		// }
		return;
	}
}
// System.Void SobotChatClient.ZCSobotApi::OnSendMessageResult(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ZCSobotApi_OnSendMessageResult_m864C6535B0E8462CCC61EA09BC377AA2F61AC98C (ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179* __this, String_t* ___0_data, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_Remove_m6FA8FA49F3ED92FB7B3CB2B1092724F101C9B5D2_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_TryGetValue_m475E1A033333E5803F84DE43B65E527E77893F75_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&String_t_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* V_0 = NULL;
	String_t* V_1 = NULL;
	int32_t V_2 = 0;
	String_t* V_3 = NULL;
	SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475* V_4 = NULL;
	Exception_t* V_5 = NULL;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	String_t* G_B2_0 = NULL;
	String_t* G_B1_0 = NULL;
	String_t* G_B5_0 = NULL;
	int32_t G_B8_0 = 0;
	String_t* G_B11_0 = NULL;
	try
	{// begin try (depth: 1)
		{
			// string[] parts = (data ?? string.Empty).Split(new[] { '|' }, 3);
			String_t* L_0 = ___0_data;
			String_t* L_1 = L_0;
			G_B1_0 = L_1;
			if (L_1)
			{
				G_B2_0 = L_1;
				goto IL_000a_1;
			}
		}
		{
			String_t* L_2 = ((String_t_StaticFields*)il2cpp_codegen_static_fields_for(String_t_il2cpp_TypeInfo_var))->___Empty_6;
			G_B2_0 = L_2;
		}

IL_000a_1:
		{
			CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* L_3 = (CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB*)(CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB*)SZArrayNew(CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB_il2cpp_TypeInfo_var, (uint32_t)1);
			CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB* L_4 = L_3;
			NullCheck(L_4);
			(L_4)->SetAt(static_cast<il2cpp_array_size_t>(0), (Il2CppChar)((int32_t)124));
			NullCheck(G_B2_0);
			StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_5;
			L_5 = String_Split_m3C63FA89A52BE352B4E49DB5379F7AAD6ACCA0E8(G_B2_0, L_4, 3, NULL);
			V_0 = L_5;
			// string requestId = parts.Length > 0 ? parts[0] : string.Empty;
			StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_6 = V_0;
			NullCheck(L_6);
			if ((((RuntimeArray*)L_6)->max_length))
			{
				goto IL_0027_1;
			}
		}
		{
			String_t* L_7 = ((String_t_StaticFields*)il2cpp_codegen_static_fields_for(String_t_il2cpp_TypeInfo_var))->___Empty_6;
			G_B5_0 = L_7;
			goto IL_002a_1;
		}

IL_0027_1:
		{
			StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_8 = V_0;
			NullCheck(L_8);
			int32_t L_9 = 0;
			String_t* L_10 = (L_8)->GetAt(static_cast<il2cpp_array_size_t>(L_9));
			G_B5_0 = L_10;
		}

IL_002a_1:
		{
			V_1 = G_B5_0;
			// int code = parts.Length > 1 ? int.Parse(parts[1]) : -1;
			StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_11 = V_0;
			NullCheck(L_11);
			if ((((int32_t)((int32_t)(((RuntimeArray*)L_11)->max_length))) > ((int32_t)1)))
			{
				goto IL_0034_1;
			}
		}
		{
			G_B8_0 = (-1);
			goto IL_003c_1;
		}

IL_0034_1:
		{
			StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_12 = V_0;
			NullCheck(L_12);
			int32_t L_13 = 1;
			String_t* L_14 = (L_12)->GetAt(static_cast<il2cpp_array_size_t>(L_13));
			int32_t L_15;
			L_15 = Int32_Parse_m273CA1A9C7717C99641291A95C543711C0202AF0(L_14, NULL);
			G_B8_0 = L_15;
		}

IL_003c_1:
		{
			V_2 = G_B8_0;
			// string message = parts.Length > 2 ? parts[2] : string.Empty;
			StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_16 = V_0;
			NullCheck(L_16);
			if ((((int32_t)((int32_t)(((RuntimeArray*)L_16)->max_length))) > ((int32_t)2)))
			{
				goto IL_004a_1;
			}
		}
		{
			String_t* L_17 = ((String_t_StaticFields*)il2cpp_codegen_static_fields_for(String_t_il2cpp_TypeInfo_var))->___Empty_6;
			G_B11_0 = L_17;
			goto IL_004d_1;
		}

IL_004a_1:
		{
			StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* L_18 = V_0;
			NullCheck(L_18);
			int32_t L_19 = 2;
			String_t* L_20 = (L_18)->GetAt(static_cast<il2cpp_array_size_t>(L_19));
			G_B11_0 = L_20;
		}

IL_004d_1:
		{
			V_3 = G_B11_0;
			// if (!string.IsNullOrEmpty(requestId) && _sendCallbacks.TryGetValue(requestId, out var callback))
			String_t* L_21 = V_1;
			bool L_22;
			L_22 = String_IsNullOrEmpty_mEA9E3FB005AC28FE02E69FCF95A7B8456192B478(L_21, NULL);
			if (L_22)
			{
				goto IL_0082_1;
			}
		}
		{
			il2cpp_codegen_runtime_class_init_inline(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
			Dictionary_2_t90FE42767FAF03DFB400884E3F5B327D48A268A5* L_23 = ((ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_StaticFields*)il2cpp_codegen_static_fields_for(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var))->____sendCallbacks_11;
			String_t* L_24 = V_1;
			NullCheck(L_23);
			bool L_25;
			L_25 = Dictionary_2_TryGetValue_m475E1A033333E5803F84DE43B65E527E77893F75(L_23, L_24, (&V_4), Dictionary_2_TryGetValue_m475E1A033333E5803F84DE43B65E527E77893F75_RuntimeMethod_var);
			if (!L_25)
			{
				goto IL_0082_1;
			}
		}
		{
			// _sendCallbacks.Remove(requestId);
			il2cpp_codegen_runtime_class_init_inline(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
			Dictionary_2_t90FE42767FAF03DFB400884E3F5B327D48A268A5* L_26 = ((ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_StaticFields*)il2cpp_codegen_static_fields_for(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var))->____sendCallbacks_11;
			String_t* L_27 = V_1;
			NullCheck(L_26);
			bool L_28;
			L_28 = Dictionary_2_Remove_m6FA8FA49F3ED92FB7B3CB2B1092724F101C9B5D2(L_26, L_27, Dictionary_2_Remove_m6FA8FA49F3ED92FB7B3CB2B1092724F101C9B5D2_RuntimeMethod_var);
			// callback?.Invoke(code == 0, code, message);
			SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475* L_29 = V_4;
			if (!L_29)
			{
				goto IL_0082_1;
			}
		}
		{
			SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475* L_30 = V_4;
			int32_t L_31 = V_2;
			int32_t L_32 = V_2;
			String_t* L_33 = V_3;
			NullCheck(L_30);
			SendMessageResultCallback_Invoke_mBA48517CB222DA8E62EE9E645A007C21454870E4_inline(L_30, (bool)((((int32_t)L_31) == ((int32_t)0))? 1 : 0), L_32, L_33, NULL);
		}

IL_0082_1:
		{
			// }
			goto IL_009e;
		}
	}// end try (depth: 1)
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Exception_t_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0084;
		}
		throw e;
	}

CATCH_0084:
	{// begin catch(System.Exception)
		Exception_t* L_34 = ((Exception_t*)IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*));;
		// catch (Exception e)
		V_5 = L_34;
		// Debug.LogError($"[SobotSDK] OnSendMessageResult error: {e.Message}");
		Exception_t* L_35 = V_5;
		NullCheck(L_35);
		String_t* L_36;
		L_36 = VirtualFuncInvoker0< String_t* >::Invoke(5 /* System.String System.Exception::get_Message() */, L_35);
		String_t* L_37;
		L_37 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral5C0BC41AEE490DECA39B09619BAB8A416DC51077)), L_36, NULL);
		il2cpp_codegen_runtime_class_init_inline(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var)));
		Debug_LogError_mB00B2B4468EF3CAF041B038D840820FB84C924B2(L_37, NULL);
		// }
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_009e;
	}// end catch (depth: 1)

IL_009e:
	{
		// }
		return;
	}
}
// System.Boolean SobotChatClient.ZCSobotApi::OnIOSLinkClick(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool ZCSobotApi_OnIOSLinkClick_mEEE708A3A1CBF9864C804FADC93618A3B752F03F (String_t* ___0_url, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral4EECFFC6C6F65EC439CEFB53065347E575849864);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	bool V_1 = false;
	Exception_t* V_2 = NULL;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	LinkClickCallback_t74FFEF1A7387D900A6578354799B79ECB1F3013E* G_B2_0 = NULL;
	LinkClickCallback_t74FFEF1A7387D900A6578354799B79ECB1F3013E* G_B1_0 = NULL;
	int32_t G_B3_0 = 0;
	try
	{// begin try (depth: 1)
		{
			// bool handled = _linkClickCallback?.Invoke(url) ?? false;
			il2cpp_codegen_runtime_class_init_inline(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
			LinkClickCallback_t74FFEF1A7387D900A6578354799B79ECB1F3013E* L_0 = ((ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_StaticFields*)il2cpp_codegen_static_fields_for(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var))->____linkClickCallback_7;
			LinkClickCallback_t74FFEF1A7387D900A6578354799B79ECB1F3013E* L_1 = L_0;
			G_B1_0 = L_1;
			if (L_1)
			{
				G_B2_0 = L_1;
				goto IL_000c_1;
			}
		}
		{
			G_B3_0 = 0;
			goto IL_0012_1;
		}

IL_000c_1:
		{
			String_t* L_2 = ___0_url;
			NullCheck(G_B2_0);
			bool L_3;
			L_3 = LinkClickCallback_Invoke_m9F0F19D8FDE3EA9803F1EAFEA89842946CF22054_inline(G_B2_0, L_2, NULL);
			G_B3_0 = ((int32_t)(L_3));
		}

IL_0012_1:
		{
			V_0 = (bool)G_B3_0;
			// Debug.Log($"[SobotSDK] OnIOSLinkClick url={url}, handled={handled}");
			String_t* L_4 = ___0_url;
			bool L_5 = V_0;
			bool L_6 = L_5;
			RuntimeObject* L_7 = Box(Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_il2cpp_TypeInfo_var, &L_6);
			String_t* L_8;
			L_8 = String_Format_mFB7DA489BD99F4670881FF50EC017BFB0A5C0987(_stringLiteral4EECFFC6C6F65EC439CEFB53065347E575849864, L_4, L_7, NULL);
			il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
			Debug_Log_m87A9A3C761FF5C43ED8A53B16190A53D08F818BB(L_8, NULL);
			// return handled;
			bool L_9 = V_0;
			V_1 = L_9;
			goto IL_0047;
		}
	}// end try (depth: 1)
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Exception_t_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_002d;
		}
		throw e;
	}

CATCH_002d:
	{// begin catch(System.Exception)
		Exception_t* L_10 = ((Exception_t*)IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*));;
		// catch (Exception e)
		V_2 = L_10;
		// Debug.LogError($"[SobotSDK] OnIOSLinkClick error: {e.Message}");
		Exception_t* L_11 = V_2;
		NullCheck(L_11);
		String_t* L_12;
		L_12 = VirtualFuncInvoker0< String_t* >::Invoke(5 /* System.String System.Exception::get_Message() */, L_11);
		String_t* L_13;
		L_13 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteral6A395A640DCD0CAF877376113637F2876AC13B86)), L_12, NULL);
		il2cpp_codegen_runtime_class_init_inline(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var)));
		Debug_LogError_mB00B2B4468EF3CAF041B038D840820FB84C924B2(L_13, NULL);
		// return false;
		V_1 = (bool)0;
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0047;
	}// end catch (depth: 1)

IL_0047:
	{
		// }
		bool L_14 = V_1;
		return L_14;
	}
}
// System.Void SobotChatClient.ZCSobotApi::OnIOSFunctionClick(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ZCSobotApi_OnIOSFunctionClick_mCF84458642714F9D17C0ED66580DC8F5A879B718 (int32_t ___0_type, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral709B70FE91B8BFC5062F4A07C1092D933B39B43B);
		s_Il2CppMethodInitialized = true;
	}
	Exception_t* V_0 = NULL;
	il2cpp::utils::ExceptionSupportStack<RuntimeObject*, 1> __active_exceptions;
	FunctionClickCallback_t133340AD88A3E68729476CCC597F418302E4F28C* G_B2_0 = NULL;
	FunctionClickCallback_t133340AD88A3E68729476CCC597F418302E4F28C* G_B1_0 = NULL;
	try
	{// begin try (depth: 1)
		{
			// Debug.Log($"[SobotSDK] OnIOSFunctionClick type={type}");
			int32_t L_0 = ___0_type;
			int32_t L_1 = L_0;
			RuntimeObject* L_2 = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &L_1);
			String_t* L_3;
			L_3 = String_Format_mA8DBB4C2516B9723C5A41E6CB1E2FAF4BBE96DD8(_stringLiteral709B70FE91B8BFC5062F4A07C1092D933B39B43B, L_2, NULL);
			il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
			Debug_Log_m87A9A3C761FF5C43ED8A53B16190A53D08F818BB(L_3, NULL);
			// _functionClickCallback?.Invoke(type);
			il2cpp_codegen_runtime_class_init_inline(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
			FunctionClickCallback_t133340AD88A3E68729476CCC597F418302E4F28C* L_4 = ((ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_StaticFields*)il2cpp_codegen_static_fields_for(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var))->____functionClickCallback_8;
			FunctionClickCallback_t133340AD88A3E68729476CCC597F418302E4F28C* L_5 = L_4;
			G_B1_0 = L_5;
			if (L_5)
			{
				G_B2_0 = L_5;
				goto IL_0020_1;
			}
		}
		{
			goto IL_0026_1;
		}

IL_0020_1:
		{
			int32_t L_6 = ___0_type;
			NullCheck(G_B2_0);
			FunctionClickCallback_Invoke_m5CD94C0005DBFE325075D4D04227207115CBBB57_inline(G_B2_0, L_6, NULL);
		}

IL_0026_1:
		{
			// }
			goto IL_0040;
		}
	}// end try (depth: 1)
	catch(Il2CppExceptionWrapper& e)
	{
		if(il2cpp_codegen_class_is_assignable_from (((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Exception_t_il2cpp_TypeInfo_var)), il2cpp_codegen_object_class(e.ex)))
		{
			IL2CPP_PUSH_ACTIVE_EXCEPTION(e.ex);
			goto CATCH_0028;
		}
		throw e;
	}

CATCH_0028:
	{// begin catch(System.Exception)
		Exception_t* L_7 = ((Exception_t*)IL2CPP_GET_ACTIVE_EXCEPTION(Exception_t*));;
		// catch (Exception e)
		V_0 = L_7;
		// Debug.LogError($"[SobotSDK] OnIOSFunctionClick error: {e.Message}");
		Exception_t* L_8 = V_0;
		NullCheck(L_8);
		String_t* L_9;
		L_9 = VirtualFuncInvoker0< String_t* >::Invoke(5 /* System.String System.Exception::get_Message() */, L_8);
		String_t* L_10;
		L_10 = String_Concat_m9E3155FB84015C823606188F53B47CB44C444991(((String_t*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&_stringLiteralEDD631D0D16C8226715DF2EC43CB2043F96199C8)), L_9, NULL);
		il2cpp_codegen_runtime_class_init_inline(((RuntimeClass*)il2cpp_codegen_initialize_runtime_metadata_inline((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var)));
		Debug_LogError_mB00B2B4468EF3CAF041B038D840820FB84C924B2(L_10, NULL);
		// }
		IL2CPP_POP_ACTIVE_EXCEPTION(Exception_t*);
		goto IL_0040;
	}// end catch (depth: 1)

IL_0040:
	{
		// }
		return;
	}
}
// System.Void SobotChatClient.ZCSobotApi::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ZCSobotApi__ctor_mC3B77CFB1EE12E7F681FF1492ED90F02506C8358 (ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179* __this, const RuntimeMethod* method) 
{
	{
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
// System.Void SobotChatClient.ZCSobotApi::.cctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void ZCSobotApi__cctor_m739A596B4894F35200EFA125F0EC5DF1DCB6E94F (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2__ctor_m2BE66DBDC8AABB2807C7D4BDACF197D4372CCEBF_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Dictionary_2_t90FE42767FAF03DFB400884E3F5B327D48A268A5_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IOSFunctionClickCallback_t9B9C81DAECBDABE1B68AD43DA4E42635B1A95613_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IOSLinkClickCallback_tE93B6F4ED698136320B42F54DE5AC652D635701A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ZCSobotApi_OnIOSFunctionClick_mCF84458642714F9D17C0ED66580DC8F5A879B718_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ZCSobotApi_OnIOSLinkClick_mEEE708A3A1CBF9864C804FADC93618A3B752F03F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// private static readonly Dictionary<string, SendMessageResultCallback> _sendCallbacks =
		//     new Dictionary<string, SendMessageResultCallback>();
		Dictionary_2_t90FE42767FAF03DFB400884E3F5B327D48A268A5* L_0 = (Dictionary_2_t90FE42767FAF03DFB400884E3F5B327D48A268A5*)il2cpp_codegen_object_new(Dictionary_2_t90FE42767FAF03DFB400884E3F5B327D48A268A5_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		Dictionary_2__ctor_m2BE66DBDC8AABB2807C7D4BDACF197D4372CCEBF(L_0, Dictionary_2__ctor_m2BE66DBDC8AABB2807C7D4BDACF197D4372CCEBF_RuntimeMethod_var);
		((ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_StaticFields*)il2cpp_codegen_static_fields_for(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var))->____sendCallbacks_11 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&((ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_StaticFields*)il2cpp_codegen_static_fields_for(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var))->____sendCallbacks_11), (void*)L_0);
		// private static readonly IOSLinkClickCallback _iosLinkClickCallback = OnIOSLinkClick;
		IOSLinkClickCallback_tE93B6F4ED698136320B42F54DE5AC652D635701A* L_1 = (IOSLinkClickCallback_tE93B6F4ED698136320B42F54DE5AC652D635701A*)il2cpp_codegen_object_new(IOSLinkClickCallback_tE93B6F4ED698136320B42F54DE5AC652D635701A_il2cpp_TypeInfo_var);
		NullCheck(L_1);
		IOSLinkClickCallback__ctor_m0189B376795B31F2451B85E93207801778C6008F(L_1, NULL, (intptr_t)((void*)ZCSobotApi_OnIOSLinkClick_mEEE708A3A1CBF9864C804FADC93618A3B752F03F_RuntimeMethod_var), NULL);
		((ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_StaticFields*)il2cpp_codegen_static_fields_for(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var))->____iosLinkClickCallback_12 = L_1;
		Il2CppCodeGenWriteBarrier((void**)(&((ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_StaticFields*)il2cpp_codegen_static_fields_for(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var))->____iosLinkClickCallback_12), (void*)L_1);
		// private static readonly IOSFunctionClickCallback _iosFunctionClickCallback = OnIOSFunctionClick;
		IOSFunctionClickCallback_t9B9C81DAECBDABE1B68AD43DA4E42635B1A95613* L_2 = (IOSFunctionClickCallback_t9B9C81DAECBDABE1B68AD43DA4E42635B1A95613*)il2cpp_codegen_object_new(IOSFunctionClickCallback_t9B9C81DAECBDABE1B68AD43DA4E42635B1A95613_il2cpp_TypeInfo_var);
		NullCheck(L_2);
		IOSFunctionClickCallback__ctor_m4606F957CAC44663491AC37FB52AFB51F7416692(L_2, NULL, (intptr_t)((void*)ZCSobotApi_OnIOSFunctionClick_mCF84458642714F9D17C0ED66580DC8F5A879B718_RuntimeMethod_var), NULL);
		((ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_StaticFields*)il2cpp_codegen_static_fields_for(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var))->____iosFunctionClickCallback_13 = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&((ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_StaticFields*)il2cpp_codegen_static_fields_for(ZCSobotApi_tA3CA4E9C9CE7BA438DB23CF2191669FEFF744179_il2cpp_TypeInfo_var))->____iosFunctionClickCallback_13), (void*)L_2);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
void InitResultCallback_Invoke_mF07EB0A9EAB5519565C8DD8368BBB7ABBB8A05E8_Multicast(InitResultCallback_t681E10D9230FD32958B962D5B649178586A97B7B* __this, bool ___0_success, String_t* ___1_message, const RuntimeMethod* method)
{
	il2cpp_array_size_t length = __this->___delegates_13->max_length;
	Delegate_t** delegatesToInvoke = reinterpret_cast<Delegate_t**>(__this->___delegates_13->GetAddressAtUnchecked(0));
	for (il2cpp_array_size_t i = 0; i < length; i++)
	{
		InitResultCallback_t681E10D9230FD32958B962D5B649178586A97B7B* currentDelegate = reinterpret_cast<InitResultCallback_t681E10D9230FD32958B962D5B649178586A97B7B*>(delegatesToInvoke[i]);
		typedef void (*FunctionPointerType) (RuntimeObject*, bool, String_t*, const RuntimeMethod*);
		((FunctionPointerType)currentDelegate->___invoke_impl_1)((Il2CppObject*)currentDelegate->___method_code_6, ___0_success, ___1_message, reinterpret_cast<RuntimeMethod*>(currentDelegate->___method_3));
	}
}
void InitResultCallback_Invoke_mF07EB0A9EAB5519565C8DD8368BBB7ABBB8A05E8_OpenInst(InitResultCallback_t681E10D9230FD32958B962D5B649178586A97B7B* __this, bool ___0_success, String_t* ___1_message, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (bool, String_t*, const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr_0)(___0_success, ___1_message, method);
}
void InitResultCallback_Invoke_mF07EB0A9EAB5519565C8DD8368BBB7ABBB8A05E8_OpenStatic(InitResultCallback_t681E10D9230FD32958B962D5B649178586A97B7B* __this, bool ___0_success, String_t* ___1_message, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (bool, String_t*, const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr_0)(___0_success, ___1_message, method);
}
void InitResultCallback_Invoke_mF07EB0A9EAB5519565C8DD8368BBB7ABBB8A05E8_OpenStaticInvoker(InitResultCallback_t681E10D9230FD32958B962D5B649178586A97B7B* __this, bool ___0_success, String_t* ___1_message, const RuntimeMethod* method)
{
	InvokerActionInvoker2< bool, String_t* >::Invoke((Il2CppMethodPointer)__this->___method_ptr_0, method, NULL, ___0_success, ___1_message);
}
void InitResultCallback_Invoke_mF07EB0A9EAB5519565C8DD8368BBB7ABBB8A05E8_ClosedStaticInvoker(InitResultCallback_t681E10D9230FD32958B962D5B649178586A97B7B* __this, bool ___0_success, String_t* ___1_message, const RuntimeMethod* method)
{
	InvokerActionInvoker3< RuntimeObject*, bool, String_t* >::Invoke((Il2CppMethodPointer)__this->___method_ptr_0, method, NULL, __this->___m_target_2, ___0_success, ___1_message);
}
IL2CPP_EXTERN_C  void DelegatePInvokeWrapper_InitResultCallback_t681E10D9230FD32958B962D5B649178586A97B7B (InitResultCallback_t681E10D9230FD32958B962D5B649178586A97B7B* __this, bool ___0_success, String_t* ___1_message, const RuntimeMethod* method)
{
	typedef void (DEFAULT_CALL *PInvokeFunc)(int32_t, char*);
	PInvokeFunc il2cppPInvokeFunc = reinterpret_cast<PInvokeFunc>(il2cpp_codegen_get_reverse_pinvoke_function_ptr(__this));
	// Marshaling of parameter '___1_message' to native representation
	char* ____1_message_marshaled = NULL;
	____1_message_marshaled = il2cpp_codegen_marshal_string(___1_message);

	// Native function invocation
	il2cppPInvokeFunc(static_cast<int32_t>(___0_success), ____1_message_marshaled);

	// Marshaling cleanup of parameter '___1_message' native representation
	il2cpp_codegen_marshal_free(____1_message_marshaled);
	____1_message_marshaled = NULL;

}
// System.Void SobotChatClient.ZCSobotApi/InitResultCallback::.ctor(System.Object,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void InitResultCallback__ctor_m3C10BC4E0A1EA31EE8C285604EF4E007AE93BE98 (InitResultCallback_t681E10D9230FD32958B962D5B649178586A97B7B* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) 
{
	__this->___method_ptr_0 = (intptr_t)il2cpp_codegen_get_virtual_call_method_pointer((RuntimeMethod*)___1_method);
	__this->___method_3 = ___1_method;
	__this->___m_target_2 = ___0_object;
	Il2CppCodeGenWriteBarrier((void**)(&__this->___m_target_2), (void*)___0_object);
	int parameterCount = il2cpp_codegen_method_parameter_count((RuntimeMethod*)___1_method);
	__this->___method_code_6 = (intptr_t)__this;
	if (MethodIsStatic((RuntimeMethod*)___1_method))
	{
		bool isOpen = parameterCount == 2;
		if (il2cpp_codegen_call_method_via_invoker((RuntimeMethod*)___1_method))
			if (isOpen)
				__this->___invoke_impl_1 = (intptr_t)&InitResultCallback_Invoke_mF07EB0A9EAB5519565C8DD8368BBB7ABBB8A05E8_OpenStaticInvoker;
			else
				__this->___invoke_impl_1 = (intptr_t)&InitResultCallback_Invoke_mF07EB0A9EAB5519565C8DD8368BBB7ABBB8A05E8_ClosedStaticInvoker;
		else
			if (isOpen)
				__this->___invoke_impl_1 = (intptr_t)&InitResultCallback_Invoke_mF07EB0A9EAB5519565C8DD8368BBB7ABBB8A05E8_OpenStatic;
			else
				{
					__this->___invoke_impl_1 = __this->___method_ptr_0;
					__this->___method_code_6 = (intptr_t)__this->___m_target_2;
				}
	}
	else
	{
		if (___0_object == NULL)
			il2cpp_codegen_raise_exception(il2cpp_codegen_get_argument_exception(NULL, "Delegate to an instance method cannot have null 'this'."), NULL);
		__this->___invoke_impl_1 = __this->___method_ptr_0;
		__this->___method_code_6 = (intptr_t)__this->___m_target_2;
	}
	__this->___extra_arg_5 = (intptr_t)&InitResultCallback_Invoke_mF07EB0A9EAB5519565C8DD8368BBB7ABBB8A05E8_Multicast;
}
// System.Void SobotChatClient.ZCSobotApi/InitResultCallback::Invoke(System.Boolean,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void InitResultCallback_Invoke_mF07EB0A9EAB5519565C8DD8368BBB7ABBB8A05E8 (InitResultCallback_t681E10D9230FD32958B962D5B649178586A97B7B* __this, bool ___0_success, String_t* ___1_message, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, bool, String_t*, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl_1)((Il2CppObject*)__this->___method_code_6, ___0_success, ___1_message, reinterpret_cast<RuntimeMethod*>(__this->___method_3));
}
// System.IAsyncResult SobotChatClient.ZCSobotApi/InitResultCallback::BeginInvoke(System.Boolean,System.String,System.AsyncCallback,System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* InitResultCallback_BeginInvoke_m926F40AAEB602EA4B5EC34E04FFC146325EF2A8D (InitResultCallback_t681E10D9230FD32958B962D5B649178586A97B7B* __this, bool ___0_success, String_t* ___1_message, AsyncCallback_t7FEF460CBDCFB9C5FA2EF776984778B9A4145F4C* ___2_callback, RuntimeObject* ___3_object, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	void *__d_args[3] = {0};
	__d_args[0] = Box(Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_il2cpp_TypeInfo_var, &___0_success);
	__d_args[1] = ___1_message;
	return (RuntimeObject*)il2cpp_codegen_delegate_begin_invoke((RuntimeDelegate*)__this, __d_args, (RuntimeDelegate*)___2_callback, (RuntimeObject*)___3_object);
}
// System.Void SobotChatClient.ZCSobotApi/InitResultCallback::EndInvoke(System.IAsyncResult)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void InitResultCallback_EndInvoke_m14043A144E0BB9163FD3D70611B3F70F025FF69C (InitResultCallback_t681E10D9230FD32958B962D5B649178586A97B7B* __this, RuntimeObject* ___0_result, const RuntimeMethod* method) 
{
	il2cpp_codegen_delegate_end_invoke((Il2CppAsyncResult*) ___0_result, 0);
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
void OfflineMsgCallback_Invoke_mC45ED6E4DEA1ADA6B9CABFAE0BB02F5F85DA0CF5_Multicast(OfflineMsgCallback_t95A2C0AE5DEFB9A1F73D67591217112C51B655D5* __this, int32_t ___0_unReadSize, int32_t ___1_offlineSize, int32_t ___2_unAckSize, const RuntimeMethod* method)
{
	il2cpp_array_size_t length = __this->___delegates_13->max_length;
	Delegate_t** delegatesToInvoke = reinterpret_cast<Delegate_t**>(__this->___delegates_13->GetAddressAtUnchecked(0));
	for (il2cpp_array_size_t i = 0; i < length; i++)
	{
		OfflineMsgCallback_t95A2C0AE5DEFB9A1F73D67591217112C51B655D5* currentDelegate = reinterpret_cast<OfflineMsgCallback_t95A2C0AE5DEFB9A1F73D67591217112C51B655D5*>(delegatesToInvoke[i]);
		typedef void (*FunctionPointerType) (RuntimeObject*, int32_t, int32_t, int32_t, const RuntimeMethod*);
		((FunctionPointerType)currentDelegate->___invoke_impl_1)((Il2CppObject*)currentDelegate->___method_code_6, ___0_unReadSize, ___1_offlineSize, ___2_unAckSize, reinterpret_cast<RuntimeMethod*>(currentDelegate->___method_3));
	}
}
void OfflineMsgCallback_Invoke_mC45ED6E4DEA1ADA6B9CABFAE0BB02F5F85DA0CF5_OpenInst(OfflineMsgCallback_t95A2C0AE5DEFB9A1F73D67591217112C51B655D5* __this, int32_t ___0_unReadSize, int32_t ___1_offlineSize, int32_t ___2_unAckSize, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (int32_t, int32_t, int32_t, const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr_0)(___0_unReadSize, ___1_offlineSize, ___2_unAckSize, method);
}
void OfflineMsgCallback_Invoke_mC45ED6E4DEA1ADA6B9CABFAE0BB02F5F85DA0CF5_OpenStatic(OfflineMsgCallback_t95A2C0AE5DEFB9A1F73D67591217112C51B655D5* __this, int32_t ___0_unReadSize, int32_t ___1_offlineSize, int32_t ___2_unAckSize, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (int32_t, int32_t, int32_t, const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr_0)(___0_unReadSize, ___1_offlineSize, ___2_unAckSize, method);
}
void OfflineMsgCallback_Invoke_mC45ED6E4DEA1ADA6B9CABFAE0BB02F5F85DA0CF5_OpenStaticInvoker(OfflineMsgCallback_t95A2C0AE5DEFB9A1F73D67591217112C51B655D5* __this, int32_t ___0_unReadSize, int32_t ___1_offlineSize, int32_t ___2_unAckSize, const RuntimeMethod* method)
{
	InvokerActionInvoker3< int32_t, int32_t, int32_t >::Invoke((Il2CppMethodPointer)__this->___method_ptr_0, method, NULL, ___0_unReadSize, ___1_offlineSize, ___2_unAckSize);
}
void OfflineMsgCallback_Invoke_mC45ED6E4DEA1ADA6B9CABFAE0BB02F5F85DA0CF5_ClosedStaticInvoker(OfflineMsgCallback_t95A2C0AE5DEFB9A1F73D67591217112C51B655D5* __this, int32_t ___0_unReadSize, int32_t ___1_offlineSize, int32_t ___2_unAckSize, const RuntimeMethod* method)
{
	InvokerActionInvoker4< RuntimeObject*, int32_t, int32_t, int32_t >::Invoke((Il2CppMethodPointer)__this->___method_ptr_0, method, NULL, __this->___m_target_2, ___0_unReadSize, ___1_offlineSize, ___2_unAckSize);
}
IL2CPP_EXTERN_C  void DelegatePInvokeWrapper_OfflineMsgCallback_t95A2C0AE5DEFB9A1F73D67591217112C51B655D5 (OfflineMsgCallback_t95A2C0AE5DEFB9A1F73D67591217112C51B655D5* __this, int32_t ___0_unReadSize, int32_t ___1_offlineSize, int32_t ___2_unAckSize, const RuntimeMethod* method)
{
	typedef void (DEFAULT_CALL *PInvokeFunc)(int32_t, int32_t, int32_t);
	PInvokeFunc il2cppPInvokeFunc = reinterpret_cast<PInvokeFunc>(il2cpp_codegen_get_reverse_pinvoke_function_ptr(__this));
	// Native function invocation
	il2cppPInvokeFunc(___0_unReadSize, ___1_offlineSize, ___2_unAckSize);

}
// System.Void SobotChatClient.ZCSobotApi/OfflineMsgCallback::.ctor(System.Object,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void OfflineMsgCallback__ctor_mBB098001D9F20A5C688506523CC4684504E60630 (OfflineMsgCallback_t95A2C0AE5DEFB9A1F73D67591217112C51B655D5* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) 
{
	__this->___method_ptr_0 = (intptr_t)il2cpp_codegen_get_virtual_call_method_pointer((RuntimeMethod*)___1_method);
	__this->___method_3 = ___1_method;
	__this->___m_target_2 = ___0_object;
	Il2CppCodeGenWriteBarrier((void**)(&__this->___m_target_2), (void*)___0_object);
	int parameterCount = il2cpp_codegen_method_parameter_count((RuntimeMethod*)___1_method);
	__this->___method_code_6 = (intptr_t)__this;
	if (MethodIsStatic((RuntimeMethod*)___1_method))
	{
		bool isOpen = parameterCount == 3;
		if (il2cpp_codegen_call_method_via_invoker((RuntimeMethod*)___1_method))
			if (isOpen)
				__this->___invoke_impl_1 = (intptr_t)&OfflineMsgCallback_Invoke_mC45ED6E4DEA1ADA6B9CABFAE0BB02F5F85DA0CF5_OpenStaticInvoker;
			else
				__this->___invoke_impl_1 = (intptr_t)&OfflineMsgCallback_Invoke_mC45ED6E4DEA1ADA6B9CABFAE0BB02F5F85DA0CF5_ClosedStaticInvoker;
		else
			if (isOpen)
				__this->___invoke_impl_1 = (intptr_t)&OfflineMsgCallback_Invoke_mC45ED6E4DEA1ADA6B9CABFAE0BB02F5F85DA0CF5_OpenStatic;
			else
				{
					__this->___invoke_impl_1 = __this->___method_ptr_0;
					__this->___method_code_6 = (intptr_t)__this->___m_target_2;
				}
	}
	else
	{
		if (___0_object == NULL)
			il2cpp_codegen_raise_exception(il2cpp_codegen_get_argument_exception(NULL, "Delegate to an instance method cannot have null 'this'."), NULL);
		__this->___invoke_impl_1 = __this->___method_ptr_0;
		__this->___method_code_6 = (intptr_t)__this->___m_target_2;
	}
	__this->___extra_arg_5 = (intptr_t)&OfflineMsgCallback_Invoke_mC45ED6E4DEA1ADA6B9CABFAE0BB02F5F85DA0CF5_Multicast;
}
// System.Void SobotChatClient.ZCSobotApi/OfflineMsgCallback::Invoke(System.Int32,System.Int32,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void OfflineMsgCallback_Invoke_mC45ED6E4DEA1ADA6B9CABFAE0BB02F5F85DA0CF5 (OfflineMsgCallback_t95A2C0AE5DEFB9A1F73D67591217112C51B655D5* __this, int32_t ___0_unReadSize, int32_t ___1_offlineSize, int32_t ___2_unAckSize, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, int32_t, int32_t, int32_t, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl_1)((Il2CppObject*)__this->___method_code_6, ___0_unReadSize, ___1_offlineSize, ___2_unAckSize, reinterpret_cast<RuntimeMethod*>(__this->___method_3));
}
// System.IAsyncResult SobotChatClient.ZCSobotApi/OfflineMsgCallback::BeginInvoke(System.Int32,System.Int32,System.Int32,System.AsyncCallback,System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* OfflineMsgCallback_BeginInvoke_mDF617C7E92BD0E98477576089AE6C2C2283870DE (OfflineMsgCallback_t95A2C0AE5DEFB9A1F73D67591217112C51B655D5* __this, int32_t ___0_unReadSize, int32_t ___1_offlineSize, int32_t ___2_unAckSize, AsyncCallback_t7FEF460CBDCFB9C5FA2EF776984778B9A4145F4C* ___3_callback, RuntimeObject* ___4_object, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	void *__d_args[4] = {0};
	__d_args[0] = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &___0_unReadSize);
	__d_args[1] = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &___1_offlineSize);
	__d_args[2] = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &___2_unAckSize);
	return (RuntimeObject*)il2cpp_codegen_delegate_begin_invoke((RuntimeDelegate*)__this, __d_args, (RuntimeDelegate*)___3_callback, (RuntimeObject*)___4_object);
}
// System.Void SobotChatClient.ZCSobotApi/OfflineMsgCallback::EndInvoke(System.IAsyncResult)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void OfflineMsgCallback_EndInvoke_mEF788795A9A09B8194C40529997D2D6CF12422B2 (OfflineMsgCallback_t95A2C0AE5DEFB9A1F73D67591217112C51B655D5* __this, RuntimeObject* ___0_result, const RuntimeMethod* method) 
{
	il2cpp_codegen_delegate_end_invoke((Il2CppAsyncResult*) ___0_result, 0);
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
bool LinkClickCallback_Invoke_m9F0F19D8FDE3EA9803F1EAFEA89842946CF22054_Multicast(LinkClickCallback_t74FFEF1A7387D900A6578354799B79ECB1F3013E* __this, String_t* ___0_linkUrl, const RuntimeMethod* method)
{
	il2cpp_array_size_t length = __this->___delegates_13->max_length;
	Delegate_t** delegatesToInvoke = reinterpret_cast<Delegate_t**>(__this->___delegates_13->GetAddressAtUnchecked(0));
	bool retVal = false;
	for (il2cpp_array_size_t i = 0; i < length; i++)
	{
		LinkClickCallback_t74FFEF1A7387D900A6578354799B79ECB1F3013E* currentDelegate = reinterpret_cast<LinkClickCallback_t74FFEF1A7387D900A6578354799B79ECB1F3013E*>(delegatesToInvoke[i]);
		typedef bool (*FunctionPointerType) (RuntimeObject*, String_t*, const RuntimeMethod*);
		retVal = ((FunctionPointerType)currentDelegate->___invoke_impl_1)((Il2CppObject*)currentDelegate->___method_code_6, ___0_linkUrl, reinterpret_cast<RuntimeMethod*>(currentDelegate->___method_3));
	}
	return retVal;
}
bool LinkClickCallback_Invoke_m9F0F19D8FDE3EA9803F1EAFEA89842946CF22054_OpenInst(LinkClickCallback_t74FFEF1A7387D900A6578354799B79ECB1F3013E* __this, String_t* ___0_linkUrl, const RuntimeMethod* method)
{
	NullCheck(___0_linkUrl);
	typedef bool (*FunctionPointerType) (String_t*, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___method_ptr_0)(___0_linkUrl, method);
}
bool LinkClickCallback_Invoke_m9F0F19D8FDE3EA9803F1EAFEA89842946CF22054_OpenStatic(LinkClickCallback_t74FFEF1A7387D900A6578354799B79ECB1F3013E* __this, String_t* ___0_linkUrl, const RuntimeMethod* method)
{
	typedef bool (*FunctionPointerType) (String_t*, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___method_ptr_0)(___0_linkUrl, method);
}
bool LinkClickCallback_Invoke_m9F0F19D8FDE3EA9803F1EAFEA89842946CF22054_OpenStaticInvoker(LinkClickCallback_t74FFEF1A7387D900A6578354799B79ECB1F3013E* __this, String_t* ___0_linkUrl, const RuntimeMethod* method)
{
	return InvokerFuncInvoker1< bool, String_t* >::Invoke((Il2CppMethodPointer)__this->___method_ptr_0, method, NULL, ___0_linkUrl);
}
bool LinkClickCallback_Invoke_m9F0F19D8FDE3EA9803F1EAFEA89842946CF22054_ClosedStaticInvoker(LinkClickCallback_t74FFEF1A7387D900A6578354799B79ECB1F3013E* __this, String_t* ___0_linkUrl, const RuntimeMethod* method)
{
	return InvokerFuncInvoker2< bool, RuntimeObject*, String_t* >::Invoke((Il2CppMethodPointer)__this->___method_ptr_0, method, NULL, __this->___m_target_2, ___0_linkUrl);
}
IL2CPP_EXTERN_C  bool DelegatePInvokeWrapper_LinkClickCallback_t74FFEF1A7387D900A6578354799B79ECB1F3013E (LinkClickCallback_t74FFEF1A7387D900A6578354799B79ECB1F3013E* __this, String_t* ___0_linkUrl, const RuntimeMethod* method)
{
	typedef int32_t (DEFAULT_CALL *PInvokeFunc)(char*);
	PInvokeFunc il2cppPInvokeFunc = reinterpret_cast<PInvokeFunc>(il2cpp_codegen_get_reverse_pinvoke_function_ptr(__this));
	// Marshaling of parameter '___0_linkUrl' to native representation
	char* ____0_linkUrl_marshaled = NULL;
	____0_linkUrl_marshaled = il2cpp_codegen_marshal_string(___0_linkUrl);

	// Native function invocation
	int32_t returnValue = il2cppPInvokeFunc(____0_linkUrl_marshaled);

	// Marshaling cleanup of parameter '___0_linkUrl' native representation
	il2cpp_codegen_marshal_free(____0_linkUrl_marshaled);
	____0_linkUrl_marshaled = NULL;

	return static_cast<bool>(returnValue);
}
// System.Void SobotChatClient.ZCSobotApi/LinkClickCallback::.ctor(System.Object,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void LinkClickCallback__ctor_m5572535DDA4D9784CD99CD478F08F31ADC2A16C8 (LinkClickCallback_t74FFEF1A7387D900A6578354799B79ECB1F3013E* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) 
{
	__this->___method_ptr_0 = (intptr_t)il2cpp_codegen_get_virtual_call_method_pointer((RuntimeMethod*)___1_method);
	__this->___method_3 = ___1_method;
	__this->___m_target_2 = ___0_object;
	Il2CppCodeGenWriteBarrier((void**)(&__this->___m_target_2), (void*)___0_object);
	int parameterCount = il2cpp_codegen_method_parameter_count((RuntimeMethod*)___1_method);
	__this->___method_code_6 = (intptr_t)__this;
	if (MethodIsStatic((RuntimeMethod*)___1_method))
	{
		bool isOpen = parameterCount == 1;
		if (il2cpp_codegen_call_method_via_invoker((RuntimeMethod*)___1_method))
			if (isOpen)
				__this->___invoke_impl_1 = (intptr_t)&LinkClickCallback_Invoke_m9F0F19D8FDE3EA9803F1EAFEA89842946CF22054_OpenStaticInvoker;
			else
				__this->___invoke_impl_1 = (intptr_t)&LinkClickCallback_Invoke_m9F0F19D8FDE3EA9803F1EAFEA89842946CF22054_ClosedStaticInvoker;
		else
			if (isOpen)
				__this->___invoke_impl_1 = (intptr_t)&LinkClickCallback_Invoke_m9F0F19D8FDE3EA9803F1EAFEA89842946CF22054_OpenStatic;
			else
				{
					__this->___invoke_impl_1 = __this->___method_ptr_0;
					__this->___method_code_6 = (intptr_t)__this->___m_target_2;
				}
	}
	else
	{
		bool isOpen = parameterCount == 0;
		if (isOpen)
		{
			__this->___invoke_impl_1 = (intptr_t)&LinkClickCallback_Invoke_m9F0F19D8FDE3EA9803F1EAFEA89842946CF22054_OpenInst;
		}
		else
		{
			if (___0_object == NULL)
				il2cpp_codegen_raise_exception(il2cpp_codegen_get_argument_exception(NULL, "Delegate to an instance method cannot have null 'this'."), NULL);
			__this->___invoke_impl_1 = __this->___method_ptr_0;
			__this->___method_code_6 = (intptr_t)__this->___m_target_2;
		}
	}
	__this->___extra_arg_5 = (intptr_t)&LinkClickCallback_Invoke_m9F0F19D8FDE3EA9803F1EAFEA89842946CF22054_Multicast;
}
// System.Boolean SobotChatClient.ZCSobotApi/LinkClickCallback::Invoke(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool LinkClickCallback_Invoke_m9F0F19D8FDE3EA9803F1EAFEA89842946CF22054 (LinkClickCallback_t74FFEF1A7387D900A6578354799B79ECB1F3013E* __this, String_t* ___0_linkUrl, const RuntimeMethod* method) 
{
	typedef bool (*FunctionPointerType) (RuntimeObject*, String_t*, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl_1)((Il2CppObject*)__this->___method_code_6, ___0_linkUrl, reinterpret_cast<RuntimeMethod*>(__this->___method_3));
}
// System.IAsyncResult SobotChatClient.ZCSobotApi/LinkClickCallback::BeginInvoke(System.String,System.AsyncCallback,System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* LinkClickCallback_BeginInvoke_m53725B918977EAF4ABFB07CCF41CFFE4C8B09445 (LinkClickCallback_t74FFEF1A7387D900A6578354799B79ECB1F3013E* __this, String_t* ___0_linkUrl, AsyncCallback_t7FEF460CBDCFB9C5FA2EF776984778B9A4145F4C* ___1_callback, RuntimeObject* ___2_object, const RuntimeMethod* method) 
{
	void *__d_args[2] = {0};
	__d_args[0] = ___0_linkUrl;
	return (RuntimeObject*)il2cpp_codegen_delegate_begin_invoke((RuntimeDelegate*)__this, __d_args, (RuntimeDelegate*)___1_callback, (RuntimeObject*)___2_object);
}
// System.Boolean SobotChatClient.ZCSobotApi/LinkClickCallback::EndInvoke(System.IAsyncResult)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool LinkClickCallback_EndInvoke_mF2646A721F852EE2B8022231D17BDE627930D836 (LinkClickCallback_t74FFEF1A7387D900A6578354799B79ECB1F3013E* __this, RuntimeObject* ___0_result, const RuntimeMethod* method) 
{
	RuntimeObject *__result = il2cpp_codegen_delegate_end_invoke((Il2CppAsyncResult*) ___0_result, 0);
	return *(bool*)UnBox ((RuntimeObject*)__result);
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
void FunctionClickCallback_Invoke_m5CD94C0005DBFE325075D4D04227207115CBBB57_Multicast(FunctionClickCallback_t133340AD88A3E68729476CCC597F418302E4F28C* __this, int32_t ___0_type, const RuntimeMethod* method)
{
	il2cpp_array_size_t length = __this->___delegates_13->max_length;
	Delegate_t** delegatesToInvoke = reinterpret_cast<Delegate_t**>(__this->___delegates_13->GetAddressAtUnchecked(0));
	for (il2cpp_array_size_t i = 0; i < length; i++)
	{
		FunctionClickCallback_t133340AD88A3E68729476CCC597F418302E4F28C* currentDelegate = reinterpret_cast<FunctionClickCallback_t133340AD88A3E68729476CCC597F418302E4F28C*>(delegatesToInvoke[i]);
		typedef void (*FunctionPointerType) (RuntimeObject*, int32_t, const RuntimeMethod*);
		((FunctionPointerType)currentDelegate->___invoke_impl_1)((Il2CppObject*)currentDelegate->___method_code_6, ___0_type, reinterpret_cast<RuntimeMethod*>(currentDelegate->___method_3));
	}
}
void FunctionClickCallback_Invoke_m5CD94C0005DBFE325075D4D04227207115CBBB57_OpenInst(FunctionClickCallback_t133340AD88A3E68729476CCC597F418302E4F28C* __this, int32_t ___0_type, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (int32_t, const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr_0)(___0_type, method);
}
void FunctionClickCallback_Invoke_m5CD94C0005DBFE325075D4D04227207115CBBB57_OpenStatic(FunctionClickCallback_t133340AD88A3E68729476CCC597F418302E4F28C* __this, int32_t ___0_type, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (int32_t, const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr_0)(___0_type, method);
}
void FunctionClickCallback_Invoke_m5CD94C0005DBFE325075D4D04227207115CBBB57_OpenStaticInvoker(FunctionClickCallback_t133340AD88A3E68729476CCC597F418302E4F28C* __this, int32_t ___0_type, const RuntimeMethod* method)
{
	InvokerActionInvoker1< int32_t >::Invoke((Il2CppMethodPointer)__this->___method_ptr_0, method, NULL, ___0_type);
}
void FunctionClickCallback_Invoke_m5CD94C0005DBFE325075D4D04227207115CBBB57_ClosedStaticInvoker(FunctionClickCallback_t133340AD88A3E68729476CCC597F418302E4F28C* __this, int32_t ___0_type, const RuntimeMethod* method)
{
	InvokerActionInvoker2< RuntimeObject*, int32_t >::Invoke((Il2CppMethodPointer)__this->___method_ptr_0, method, NULL, __this->___m_target_2, ___0_type);
}
IL2CPP_EXTERN_C  void DelegatePInvokeWrapper_FunctionClickCallback_t133340AD88A3E68729476CCC597F418302E4F28C (FunctionClickCallback_t133340AD88A3E68729476CCC597F418302E4F28C* __this, int32_t ___0_type, const RuntimeMethod* method)
{
	typedef void (DEFAULT_CALL *PInvokeFunc)(int32_t);
	PInvokeFunc il2cppPInvokeFunc = reinterpret_cast<PInvokeFunc>(il2cpp_codegen_get_reverse_pinvoke_function_ptr(__this));
	// Native function invocation
	il2cppPInvokeFunc(___0_type);

}
// System.Void SobotChatClient.ZCSobotApi/FunctionClickCallback::.ctor(System.Object,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void FunctionClickCallback__ctor_m80C1592253DCCF75936DDD24AA0F6162565E7C38 (FunctionClickCallback_t133340AD88A3E68729476CCC597F418302E4F28C* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) 
{
	__this->___method_ptr_0 = (intptr_t)il2cpp_codegen_get_virtual_call_method_pointer((RuntimeMethod*)___1_method);
	__this->___method_3 = ___1_method;
	__this->___m_target_2 = ___0_object;
	Il2CppCodeGenWriteBarrier((void**)(&__this->___m_target_2), (void*)___0_object);
	int parameterCount = il2cpp_codegen_method_parameter_count((RuntimeMethod*)___1_method);
	__this->___method_code_6 = (intptr_t)__this;
	if (MethodIsStatic((RuntimeMethod*)___1_method))
	{
		bool isOpen = parameterCount == 1;
		if (il2cpp_codegen_call_method_via_invoker((RuntimeMethod*)___1_method))
			if (isOpen)
				__this->___invoke_impl_1 = (intptr_t)&FunctionClickCallback_Invoke_m5CD94C0005DBFE325075D4D04227207115CBBB57_OpenStaticInvoker;
			else
				__this->___invoke_impl_1 = (intptr_t)&FunctionClickCallback_Invoke_m5CD94C0005DBFE325075D4D04227207115CBBB57_ClosedStaticInvoker;
		else
			if (isOpen)
				__this->___invoke_impl_1 = (intptr_t)&FunctionClickCallback_Invoke_m5CD94C0005DBFE325075D4D04227207115CBBB57_OpenStatic;
			else
				{
					__this->___invoke_impl_1 = __this->___method_ptr_0;
					__this->___method_code_6 = (intptr_t)__this->___m_target_2;
				}
	}
	else
	{
		if (___0_object == NULL)
			il2cpp_codegen_raise_exception(il2cpp_codegen_get_argument_exception(NULL, "Delegate to an instance method cannot have null 'this'."), NULL);
		__this->___invoke_impl_1 = __this->___method_ptr_0;
		__this->___method_code_6 = (intptr_t)__this->___m_target_2;
	}
	__this->___extra_arg_5 = (intptr_t)&FunctionClickCallback_Invoke_m5CD94C0005DBFE325075D4D04227207115CBBB57_Multicast;
}
// System.Void SobotChatClient.ZCSobotApi/FunctionClickCallback::Invoke(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void FunctionClickCallback_Invoke_m5CD94C0005DBFE325075D4D04227207115CBBB57 (FunctionClickCallback_t133340AD88A3E68729476CCC597F418302E4F28C* __this, int32_t ___0_type, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, int32_t, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl_1)((Il2CppObject*)__this->___method_code_6, ___0_type, reinterpret_cast<RuntimeMethod*>(__this->___method_3));
}
// System.IAsyncResult SobotChatClient.ZCSobotApi/FunctionClickCallback::BeginInvoke(System.Int32,System.AsyncCallback,System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* FunctionClickCallback_BeginInvoke_m91D83E0B17F038EB5E2F8F84BAC03319BB1804BD (FunctionClickCallback_t133340AD88A3E68729476CCC597F418302E4F28C* __this, int32_t ___0_type, AsyncCallback_t7FEF460CBDCFB9C5FA2EF776984778B9A4145F4C* ___1_callback, RuntimeObject* ___2_object, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	void *__d_args[2] = {0};
	__d_args[0] = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &___0_type);
	return (RuntimeObject*)il2cpp_codegen_delegate_begin_invoke((RuntimeDelegate*)__this, __d_args, (RuntimeDelegate*)___1_callback, (RuntimeObject*)___2_object);
}
// System.Void SobotChatClient.ZCSobotApi/FunctionClickCallback::EndInvoke(System.IAsyncResult)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void FunctionClickCallback_EndInvoke_m308A835466083BB9FFA562C2154AA7D565BB6D52 (FunctionClickCallback_t133340AD88A3E68729476CCC597F418302E4F28C* __this, RuntimeObject* ___0_result, const RuntimeMethod* method) 
{
	il2cpp_codegen_delegate_end_invoke((Il2CppAsyncResult*) ___0_result, 0);
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
void SendMessageResultCallback_Invoke_mBA48517CB222DA8E62EE9E645A007C21454870E4_Multicast(SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475* __this, bool ___0_success, int32_t ___1_code, String_t* ___2_message, const RuntimeMethod* method)
{
	il2cpp_array_size_t length = __this->___delegates_13->max_length;
	Delegate_t** delegatesToInvoke = reinterpret_cast<Delegate_t**>(__this->___delegates_13->GetAddressAtUnchecked(0));
	for (il2cpp_array_size_t i = 0; i < length; i++)
	{
		SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475* currentDelegate = reinterpret_cast<SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475*>(delegatesToInvoke[i]);
		typedef void (*FunctionPointerType) (RuntimeObject*, bool, int32_t, String_t*, const RuntimeMethod*);
		((FunctionPointerType)currentDelegate->___invoke_impl_1)((Il2CppObject*)currentDelegate->___method_code_6, ___0_success, ___1_code, ___2_message, reinterpret_cast<RuntimeMethod*>(currentDelegate->___method_3));
	}
}
void SendMessageResultCallback_Invoke_mBA48517CB222DA8E62EE9E645A007C21454870E4_OpenInst(SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475* __this, bool ___0_success, int32_t ___1_code, String_t* ___2_message, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (bool, int32_t, String_t*, const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr_0)(___0_success, ___1_code, ___2_message, method);
}
void SendMessageResultCallback_Invoke_mBA48517CB222DA8E62EE9E645A007C21454870E4_OpenStatic(SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475* __this, bool ___0_success, int32_t ___1_code, String_t* ___2_message, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (bool, int32_t, String_t*, const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr_0)(___0_success, ___1_code, ___2_message, method);
}
void SendMessageResultCallback_Invoke_mBA48517CB222DA8E62EE9E645A007C21454870E4_OpenStaticInvoker(SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475* __this, bool ___0_success, int32_t ___1_code, String_t* ___2_message, const RuntimeMethod* method)
{
	InvokerActionInvoker3< bool, int32_t, String_t* >::Invoke((Il2CppMethodPointer)__this->___method_ptr_0, method, NULL, ___0_success, ___1_code, ___2_message);
}
void SendMessageResultCallback_Invoke_mBA48517CB222DA8E62EE9E645A007C21454870E4_ClosedStaticInvoker(SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475* __this, bool ___0_success, int32_t ___1_code, String_t* ___2_message, const RuntimeMethod* method)
{
	InvokerActionInvoker4< RuntimeObject*, bool, int32_t, String_t* >::Invoke((Il2CppMethodPointer)__this->___method_ptr_0, method, NULL, __this->___m_target_2, ___0_success, ___1_code, ___2_message);
}
IL2CPP_EXTERN_C  void DelegatePInvokeWrapper_SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475 (SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475* __this, bool ___0_success, int32_t ___1_code, String_t* ___2_message, const RuntimeMethod* method)
{
	typedef void (DEFAULT_CALL *PInvokeFunc)(int32_t, int32_t, char*);
	PInvokeFunc il2cppPInvokeFunc = reinterpret_cast<PInvokeFunc>(il2cpp_codegen_get_reverse_pinvoke_function_ptr(__this));
	// Marshaling of parameter '___2_message' to native representation
	char* ____2_message_marshaled = NULL;
	____2_message_marshaled = il2cpp_codegen_marshal_string(___2_message);

	// Native function invocation
	il2cppPInvokeFunc(static_cast<int32_t>(___0_success), ___1_code, ____2_message_marshaled);

	// Marshaling cleanup of parameter '___2_message' native representation
	il2cpp_codegen_marshal_free(____2_message_marshaled);
	____2_message_marshaled = NULL;

}
// System.Void SobotChatClient.ZCSobotApi/SendMessageResultCallback::.ctor(System.Object,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SendMessageResultCallback__ctor_mB7F4863CA4528C0AE04B3D27E9F7BA2FD66C9F3E (SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) 
{
	__this->___method_ptr_0 = (intptr_t)il2cpp_codegen_get_virtual_call_method_pointer((RuntimeMethod*)___1_method);
	__this->___method_3 = ___1_method;
	__this->___m_target_2 = ___0_object;
	Il2CppCodeGenWriteBarrier((void**)(&__this->___m_target_2), (void*)___0_object);
	int parameterCount = il2cpp_codegen_method_parameter_count((RuntimeMethod*)___1_method);
	__this->___method_code_6 = (intptr_t)__this;
	if (MethodIsStatic((RuntimeMethod*)___1_method))
	{
		bool isOpen = parameterCount == 3;
		if (il2cpp_codegen_call_method_via_invoker((RuntimeMethod*)___1_method))
			if (isOpen)
				__this->___invoke_impl_1 = (intptr_t)&SendMessageResultCallback_Invoke_mBA48517CB222DA8E62EE9E645A007C21454870E4_OpenStaticInvoker;
			else
				__this->___invoke_impl_1 = (intptr_t)&SendMessageResultCallback_Invoke_mBA48517CB222DA8E62EE9E645A007C21454870E4_ClosedStaticInvoker;
		else
			if (isOpen)
				__this->___invoke_impl_1 = (intptr_t)&SendMessageResultCallback_Invoke_mBA48517CB222DA8E62EE9E645A007C21454870E4_OpenStatic;
			else
				{
					__this->___invoke_impl_1 = __this->___method_ptr_0;
					__this->___method_code_6 = (intptr_t)__this->___m_target_2;
				}
	}
	else
	{
		if (___0_object == NULL)
			il2cpp_codegen_raise_exception(il2cpp_codegen_get_argument_exception(NULL, "Delegate to an instance method cannot have null 'this'."), NULL);
		__this->___invoke_impl_1 = __this->___method_ptr_0;
		__this->___method_code_6 = (intptr_t)__this->___m_target_2;
	}
	__this->___extra_arg_5 = (intptr_t)&SendMessageResultCallback_Invoke_mBA48517CB222DA8E62EE9E645A007C21454870E4_Multicast;
}
// System.Void SobotChatClient.ZCSobotApi/SendMessageResultCallback::Invoke(System.Boolean,System.Int32,System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SendMessageResultCallback_Invoke_mBA48517CB222DA8E62EE9E645A007C21454870E4 (SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475* __this, bool ___0_success, int32_t ___1_code, String_t* ___2_message, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, bool, int32_t, String_t*, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl_1)((Il2CppObject*)__this->___method_code_6, ___0_success, ___1_code, ___2_message, reinterpret_cast<RuntimeMethod*>(__this->___method_3));
}
// System.IAsyncResult SobotChatClient.ZCSobotApi/SendMessageResultCallback::BeginInvoke(System.Boolean,System.Int32,System.String,System.AsyncCallback,System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* SendMessageResultCallback_BeginInvoke_mA12436555F02C9078BEBD262011C5F69A4E71B90 (SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475* __this, bool ___0_success, int32_t ___1_code, String_t* ___2_message, AsyncCallback_t7FEF460CBDCFB9C5FA2EF776984778B9A4145F4C* ___3_callback, RuntimeObject* ___4_object, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	void *__d_args[4] = {0};
	__d_args[0] = Box(Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_il2cpp_TypeInfo_var, &___0_success);
	__d_args[1] = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &___1_code);
	__d_args[2] = ___2_message;
	return (RuntimeObject*)il2cpp_codegen_delegate_begin_invoke((RuntimeDelegate*)__this, __d_args, (RuntimeDelegate*)___3_callback, (RuntimeObject*)___4_object);
}
// System.Void SobotChatClient.ZCSobotApi/SendMessageResultCallback::EndInvoke(System.IAsyncResult)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SendMessageResultCallback_EndInvoke_m0FAE0EDAB302320B14B55671D39CE1F47DB658C9 (SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475* __this, RuntimeObject* ___0_result, const RuntimeMethod* method) 
{
	il2cpp_codegen_delegate_end_invoke((Il2CppAsyncResult*) ___0_result, 0);
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
bool IOSLinkClickCallback_Invoke_m84B9D1EE6BD903EFFFE44DC55B1168E26F2978D5_Multicast(IOSLinkClickCallback_tE93B6F4ED698136320B42F54DE5AC652D635701A* __this, String_t* ___0_url, const RuntimeMethod* method)
{
	il2cpp_array_size_t length = __this->___delegates_13->max_length;
	Delegate_t** delegatesToInvoke = reinterpret_cast<Delegate_t**>(__this->___delegates_13->GetAddressAtUnchecked(0));
	bool retVal = false;
	for (il2cpp_array_size_t i = 0; i < length; i++)
	{
		IOSLinkClickCallback_tE93B6F4ED698136320B42F54DE5AC652D635701A* currentDelegate = reinterpret_cast<IOSLinkClickCallback_tE93B6F4ED698136320B42F54DE5AC652D635701A*>(delegatesToInvoke[i]);
		typedef bool (*FunctionPointerType) (RuntimeObject*, String_t*, const RuntimeMethod*);
		retVal = ((FunctionPointerType)currentDelegate->___invoke_impl_1)((Il2CppObject*)currentDelegate->___method_code_6, ___0_url, reinterpret_cast<RuntimeMethod*>(currentDelegate->___method_3));
	}
	return retVal;
}
bool IOSLinkClickCallback_Invoke_m84B9D1EE6BD903EFFFE44DC55B1168E26F2978D5_OpenInst(IOSLinkClickCallback_tE93B6F4ED698136320B42F54DE5AC652D635701A* __this, String_t* ___0_url, const RuntimeMethod* method)
{
	NullCheck(___0_url);
	typedef bool (*FunctionPointerType) (String_t*, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___method_ptr_0)(___0_url, method);
}
bool IOSLinkClickCallback_Invoke_m84B9D1EE6BD903EFFFE44DC55B1168E26F2978D5_OpenStatic(IOSLinkClickCallback_tE93B6F4ED698136320B42F54DE5AC652D635701A* __this, String_t* ___0_url, const RuntimeMethod* method)
{
	typedef bool (*FunctionPointerType) (String_t*, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___method_ptr_0)(___0_url, method);
}
bool IOSLinkClickCallback_Invoke_m84B9D1EE6BD903EFFFE44DC55B1168E26F2978D5_OpenStaticInvoker(IOSLinkClickCallback_tE93B6F4ED698136320B42F54DE5AC652D635701A* __this, String_t* ___0_url, const RuntimeMethod* method)
{
	return InvokerFuncInvoker1< bool, String_t* >::Invoke((Il2CppMethodPointer)__this->___method_ptr_0, method, NULL, ___0_url);
}
bool IOSLinkClickCallback_Invoke_m84B9D1EE6BD903EFFFE44DC55B1168E26F2978D5_ClosedStaticInvoker(IOSLinkClickCallback_tE93B6F4ED698136320B42F54DE5AC652D635701A* __this, String_t* ___0_url, const RuntimeMethod* method)
{
	return InvokerFuncInvoker2< bool, RuntimeObject*, String_t* >::Invoke((Il2CppMethodPointer)__this->___method_ptr_0, method, NULL, __this->___m_target_2, ___0_url);
}
IL2CPP_EXTERN_C  bool DelegatePInvokeWrapper_IOSLinkClickCallback_tE93B6F4ED698136320B42F54DE5AC652D635701A (IOSLinkClickCallback_tE93B6F4ED698136320B42F54DE5AC652D635701A* __this, String_t* ___0_url, const RuntimeMethod* method)
{
	typedef int8_t (CDECL *PInvokeFunc)(char*);
	PInvokeFunc il2cppPInvokeFunc = reinterpret_cast<PInvokeFunc>(il2cpp_codegen_get_reverse_pinvoke_function_ptr(__this));
	// Marshaling of parameter '___0_url' to native representation
	char* ____0_url_marshaled = NULL;
	____0_url_marshaled = il2cpp_codegen_marshal_string(___0_url);

	// Native function invocation
	int8_t returnValue = il2cppPInvokeFunc(____0_url_marshaled);

	// Marshaling cleanup of parameter '___0_url' native representation
	il2cpp_codegen_marshal_free(____0_url_marshaled);
	____0_url_marshaled = NULL;

	return static_cast<bool>(returnValue);
}
// System.Void SobotChatClient.ZCSobotApi/IOSLinkClickCallback::.ctor(System.Object,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void IOSLinkClickCallback__ctor_m0189B376795B31F2451B85E93207801778C6008F (IOSLinkClickCallback_tE93B6F4ED698136320B42F54DE5AC652D635701A* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) 
{
	__this->___method_ptr_0 = (intptr_t)il2cpp_codegen_get_virtual_call_method_pointer((RuntimeMethod*)___1_method);
	__this->___method_3 = ___1_method;
	__this->___m_target_2 = ___0_object;
	Il2CppCodeGenWriteBarrier((void**)(&__this->___m_target_2), (void*)___0_object);
	int parameterCount = il2cpp_codegen_method_parameter_count((RuntimeMethod*)___1_method);
	__this->___method_code_6 = (intptr_t)__this;
	if (MethodIsStatic((RuntimeMethod*)___1_method))
	{
		bool isOpen = parameterCount == 1;
		if (il2cpp_codegen_call_method_via_invoker((RuntimeMethod*)___1_method))
			if (isOpen)
				__this->___invoke_impl_1 = (intptr_t)&IOSLinkClickCallback_Invoke_m84B9D1EE6BD903EFFFE44DC55B1168E26F2978D5_OpenStaticInvoker;
			else
				__this->___invoke_impl_1 = (intptr_t)&IOSLinkClickCallback_Invoke_m84B9D1EE6BD903EFFFE44DC55B1168E26F2978D5_ClosedStaticInvoker;
		else
			if (isOpen)
				__this->___invoke_impl_1 = (intptr_t)&IOSLinkClickCallback_Invoke_m84B9D1EE6BD903EFFFE44DC55B1168E26F2978D5_OpenStatic;
			else
				{
					__this->___invoke_impl_1 = __this->___method_ptr_0;
					__this->___method_code_6 = (intptr_t)__this->___m_target_2;
				}
	}
	else
	{
		bool isOpen = parameterCount == 0;
		if (isOpen)
		{
			__this->___invoke_impl_1 = (intptr_t)&IOSLinkClickCallback_Invoke_m84B9D1EE6BD903EFFFE44DC55B1168E26F2978D5_OpenInst;
		}
		else
		{
			if (___0_object == NULL)
				il2cpp_codegen_raise_exception(il2cpp_codegen_get_argument_exception(NULL, "Delegate to an instance method cannot have null 'this'."), NULL);
			__this->___invoke_impl_1 = __this->___method_ptr_0;
			__this->___method_code_6 = (intptr_t)__this->___m_target_2;
		}
	}
	__this->___extra_arg_5 = (intptr_t)&IOSLinkClickCallback_Invoke_m84B9D1EE6BD903EFFFE44DC55B1168E26F2978D5_Multicast;
}
// System.Boolean SobotChatClient.ZCSobotApi/IOSLinkClickCallback::Invoke(System.String)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool IOSLinkClickCallback_Invoke_m84B9D1EE6BD903EFFFE44DC55B1168E26F2978D5 (IOSLinkClickCallback_tE93B6F4ED698136320B42F54DE5AC652D635701A* __this, String_t* ___0_url, const RuntimeMethod* method) 
{
	typedef bool (*FunctionPointerType) (RuntimeObject*, String_t*, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl_1)((Il2CppObject*)__this->___method_code_6, ___0_url, reinterpret_cast<RuntimeMethod*>(__this->___method_3));
}
// System.IAsyncResult SobotChatClient.ZCSobotApi/IOSLinkClickCallback::BeginInvoke(System.String,System.AsyncCallback,System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* IOSLinkClickCallback_BeginInvoke_mB44477F0FB1F56FCA0D93DA50CB09FC7F18488E4 (IOSLinkClickCallback_tE93B6F4ED698136320B42F54DE5AC652D635701A* __this, String_t* ___0_url, AsyncCallback_t7FEF460CBDCFB9C5FA2EF776984778B9A4145F4C* ___1_callback, RuntimeObject* ___2_object, const RuntimeMethod* method) 
{
	void *__d_args[2] = {0};
	__d_args[0] = ___0_url;
	return (RuntimeObject*)il2cpp_codegen_delegate_begin_invoke((RuntimeDelegate*)__this, __d_args, (RuntimeDelegate*)___1_callback, (RuntimeObject*)___2_object);
}
// System.Boolean SobotChatClient.ZCSobotApi/IOSLinkClickCallback::EndInvoke(System.IAsyncResult)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool IOSLinkClickCallback_EndInvoke_mCCC2E98C369D922AAE4D2882CD446B028BE3B38E (IOSLinkClickCallback_tE93B6F4ED698136320B42F54DE5AC652D635701A* __this, RuntimeObject* ___0_result, const RuntimeMethod* method) 
{
	RuntimeObject *__result = il2cpp_codegen_delegate_end_invoke((Il2CppAsyncResult*) ___0_result, 0);
	return *(bool*)UnBox ((RuntimeObject*)__result);
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
void IOSFunctionClickCallback_Invoke_m4DB04D4687A1ED8995B8AB1527616199CC89B195_Multicast(IOSFunctionClickCallback_t9B9C81DAECBDABE1B68AD43DA4E42635B1A95613* __this, int32_t ___0_type, const RuntimeMethod* method)
{
	il2cpp_array_size_t length = __this->___delegates_13->max_length;
	Delegate_t** delegatesToInvoke = reinterpret_cast<Delegate_t**>(__this->___delegates_13->GetAddressAtUnchecked(0));
	for (il2cpp_array_size_t i = 0; i < length; i++)
	{
		IOSFunctionClickCallback_t9B9C81DAECBDABE1B68AD43DA4E42635B1A95613* currentDelegate = reinterpret_cast<IOSFunctionClickCallback_t9B9C81DAECBDABE1B68AD43DA4E42635B1A95613*>(delegatesToInvoke[i]);
		typedef void (*FunctionPointerType) (RuntimeObject*, int32_t, const RuntimeMethod*);
		((FunctionPointerType)currentDelegate->___invoke_impl_1)((Il2CppObject*)currentDelegate->___method_code_6, ___0_type, reinterpret_cast<RuntimeMethod*>(currentDelegate->___method_3));
	}
}
void IOSFunctionClickCallback_Invoke_m4DB04D4687A1ED8995B8AB1527616199CC89B195_OpenInst(IOSFunctionClickCallback_t9B9C81DAECBDABE1B68AD43DA4E42635B1A95613* __this, int32_t ___0_type, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (int32_t, const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr_0)(___0_type, method);
}
void IOSFunctionClickCallback_Invoke_m4DB04D4687A1ED8995B8AB1527616199CC89B195_OpenStatic(IOSFunctionClickCallback_t9B9C81DAECBDABE1B68AD43DA4E42635B1A95613* __this, int32_t ___0_type, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (int32_t, const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr_0)(___0_type, method);
}
void IOSFunctionClickCallback_Invoke_m4DB04D4687A1ED8995B8AB1527616199CC89B195_OpenStaticInvoker(IOSFunctionClickCallback_t9B9C81DAECBDABE1B68AD43DA4E42635B1A95613* __this, int32_t ___0_type, const RuntimeMethod* method)
{
	InvokerActionInvoker1< int32_t >::Invoke((Il2CppMethodPointer)__this->___method_ptr_0, method, NULL, ___0_type);
}
void IOSFunctionClickCallback_Invoke_m4DB04D4687A1ED8995B8AB1527616199CC89B195_ClosedStaticInvoker(IOSFunctionClickCallback_t9B9C81DAECBDABE1B68AD43DA4E42635B1A95613* __this, int32_t ___0_type, const RuntimeMethod* method)
{
	InvokerActionInvoker2< RuntimeObject*, int32_t >::Invoke((Il2CppMethodPointer)__this->___method_ptr_0, method, NULL, __this->___m_target_2, ___0_type);
}
IL2CPP_EXTERN_C  void DelegatePInvokeWrapper_IOSFunctionClickCallback_t9B9C81DAECBDABE1B68AD43DA4E42635B1A95613 (IOSFunctionClickCallback_t9B9C81DAECBDABE1B68AD43DA4E42635B1A95613* __this, int32_t ___0_type, const RuntimeMethod* method)
{
	typedef void (CDECL *PInvokeFunc)(int32_t);
	PInvokeFunc il2cppPInvokeFunc = reinterpret_cast<PInvokeFunc>(il2cpp_codegen_get_reverse_pinvoke_function_ptr(__this));
	// Native function invocation
	il2cppPInvokeFunc(___0_type);

}
// System.Void SobotChatClient.ZCSobotApi/IOSFunctionClickCallback::.ctor(System.Object,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void IOSFunctionClickCallback__ctor_m4606F957CAC44663491AC37FB52AFB51F7416692 (IOSFunctionClickCallback_t9B9C81DAECBDABE1B68AD43DA4E42635B1A95613* __this, RuntimeObject* ___0_object, intptr_t ___1_method, const RuntimeMethod* method) 
{
	__this->___method_ptr_0 = (intptr_t)il2cpp_codegen_get_virtual_call_method_pointer((RuntimeMethod*)___1_method);
	__this->___method_3 = ___1_method;
	__this->___m_target_2 = ___0_object;
	Il2CppCodeGenWriteBarrier((void**)(&__this->___m_target_2), (void*)___0_object);
	int parameterCount = il2cpp_codegen_method_parameter_count((RuntimeMethod*)___1_method);
	__this->___method_code_6 = (intptr_t)__this;
	if (MethodIsStatic((RuntimeMethod*)___1_method))
	{
		bool isOpen = parameterCount == 1;
		if (il2cpp_codegen_call_method_via_invoker((RuntimeMethod*)___1_method))
			if (isOpen)
				__this->___invoke_impl_1 = (intptr_t)&IOSFunctionClickCallback_Invoke_m4DB04D4687A1ED8995B8AB1527616199CC89B195_OpenStaticInvoker;
			else
				__this->___invoke_impl_1 = (intptr_t)&IOSFunctionClickCallback_Invoke_m4DB04D4687A1ED8995B8AB1527616199CC89B195_ClosedStaticInvoker;
		else
			if (isOpen)
				__this->___invoke_impl_1 = (intptr_t)&IOSFunctionClickCallback_Invoke_m4DB04D4687A1ED8995B8AB1527616199CC89B195_OpenStatic;
			else
				{
					__this->___invoke_impl_1 = __this->___method_ptr_0;
					__this->___method_code_6 = (intptr_t)__this->___m_target_2;
				}
	}
	else
	{
		if (___0_object == NULL)
			il2cpp_codegen_raise_exception(il2cpp_codegen_get_argument_exception(NULL, "Delegate to an instance method cannot have null 'this'."), NULL);
		__this->___invoke_impl_1 = __this->___method_ptr_0;
		__this->___method_code_6 = (intptr_t)__this->___m_target_2;
	}
	__this->___extra_arg_5 = (intptr_t)&IOSFunctionClickCallback_Invoke_m4DB04D4687A1ED8995B8AB1527616199CC89B195_Multicast;
}
// System.Void SobotChatClient.ZCSobotApi/IOSFunctionClickCallback::Invoke(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void IOSFunctionClickCallback_Invoke_m4DB04D4687A1ED8995B8AB1527616199CC89B195 (IOSFunctionClickCallback_t9B9C81DAECBDABE1B68AD43DA4E42635B1A95613* __this, int32_t ___0_type, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, int32_t, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl_1)((Il2CppObject*)__this->___method_code_6, ___0_type, reinterpret_cast<RuntimeMethod*>(__this->___method_3));
}
// System.IAsyncResult SobotChatClient.ZCSobotApi/IOSFunctionClickCallback::BeginInvoke(System.Int32,System.AsyncCallback,System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* IOSFunctionClickCallback_BeginInvoke_mDBFE67C57EBD4CFF143A9B73ECFCB7FDC19005F4 (IOSFunctionClickCallback_t9B9C81DAECBDABE1B68AD43DA4E42635B1A95613* __this, int32_t ___0_type, AsyncCallback_t7FEF460CBDCFB9C5FA2EF776984778B9A4145F4C* ___1_callback, RuntimeObject* ___2_object, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	void *__d_args[2] = {0};
	__d_args[0] = Box(Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_il2cpp_TypeInfo_var, &___0_type);
	return (RuntimeObject*)il2cpp_codegen_delegate_begin_invoke((RuntimeDelegate*)__this, __d_args, (RuntimeDelegate*)___1_callback, (RuntimeObject*)___2_object);
}
// System.Void SobotChatClient.ZCSobotApi/IOSFunctionClickCallback::EndInvoke(System.IAsyncResult)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void IOSFunctionClickCallback_EndInvoke_m700658C258F407A9D170B5AB11C0B70FCC98CCA5 (IOSFunctionClickCallback_t9B9C81DAECBDABE1B68AD43DA4E42635B1A95613* __this, RuntimeObject* ___0_result, const RuntimeMethod* method) 
{
	il2cpp_codegen_delegate_end_invoke((Il2CppAsyncResult*) ___0_result, 0);
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void SendMessageResultCallback_Invoke_mBA48517CB222DA8E62EE9E645A007C21454870E4_inline (SendMessageResultCallback_tC9918745D4958203D9D7BF7A402649BD8428F475* __this, bool ___0_success, int32_t ___1_code, String_t* ___2_message, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, bool, int32_t, String_t*, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl_1)((Il2CppObject*)__this->___method_code_6, ___0_success, ___1_code, ___2_message, reinterpret_cast<RuntimeMethod*>(__this->___method_3));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void InitResultCallback_Invoke_mF07EB0A9EAB5519565C8DD8368BBB7ABBB8A05E8_inline (InitResultCallback_t681E10D9230FD32958B962D5B649178586A97B7B* __this, bool ___0_success, String_t* ___1_message, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, bool, String_t*, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl_1)((Il2CppObject*)__this->___method_code_6, ___0_success, ___1_message, reinterpret_cast<RuntimeMethod*>(__this->___method_3));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void OfflineMsgCallback_Invoke_mC45ED6E4DEA1ADA6B9CABFAE0BB02F5F85DA0CF5_inline (OfflineMsgCallback_t95A2C0AE5DEFB9A1F73D67591217112C51B655D5* __this, int32_t ___0_unReadSize, int32_t ___1_offlineSize, int32_t ___2_unAckSize, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, int32_t, int32_t, int32_t, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl_1)((Il2CppObject*)__this->___method_code_6, ___0_unReadSize, ___1_offlineSize, ___2_unAckSize, reinterpret_cast<RuntimeMethod*>(__this->___method_3));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool LinkClickCallback_Invoke_m9F0F19D8FDE3EA9803F1EAFEA89842946CF22054_inline (LinkClickCallback_t74FFEF1A7387D900A6578354799B79ECB1F3013E* __this, String_t* ___0_linkUrl, const RuntimeMethod* method) 
{
	typedef bool (*FunctionPointerType) (RuntimeObject*, String_t*, const RuntimeMethod*);
	return ((FunctionPointerType)__this->___invoke_impl_1)((Il2CppObject*)__this->___method_code_6, ___0_linkUrl, reinterpret_cast<RuntimeMethod*>(__this->___method_3));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void FunctionClickCallback_Invoke_m5CD94C0005DBFE325075D4D04227207115CBBB57_inline (FunctionClickCallback_t133340AD88A3E68729476CCC597F418302E4F28C* __this, int32_t ___0_type, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, int32_t, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl_1)((Il2CppObject*)__this->___method_code_6, ___0_type, reinterpret_cast<RuntimeMethod*>(__this->___method_3));
}
