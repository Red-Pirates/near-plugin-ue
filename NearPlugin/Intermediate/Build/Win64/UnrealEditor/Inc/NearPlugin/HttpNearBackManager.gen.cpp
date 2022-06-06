// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NearPlugin/Public/HttpNearBackManager.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHttpNearBackManager() {}
// Cross Module References
	NEARPLUGIN_API UClass* Z_Construct_UClass_UHttpNearBackManager_NoRegister();
	NEARPLUGIN_API UClass* Z_Construct_UClass_UHttpNearBackManager();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_NearPlugin();
	NEARPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FGetAccountNFTRequestStruct();
	NEARPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FGetFTBalanceRequestStruct();
	NEARPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FGetNFTRequestStruct();
	NEARPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FAccountBalanceStruct();
	NEARPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FFTBalanceStruct();
	NEARPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FNFTMetadataStruct();
	NEARPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FAccountNFTStruct();
// End Cross Module References
	DEFINE_FUNCTION(UHttpNearBackManager::execGetAccountNFT)
	{
		P_GET_STRUCT(FGetAccountNFTRequestStruct,Z_Param_RequestStruct);
		P_FINISH;
		P_NATIVE_BEGIN;
		UHttpNearBackManager::GetAccountNFT(Z_Param_RequestStruct);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UHttpNearBackManager::execSendAccountNFTRequest)
	{
		P_GET_STRUCT(FGetAccountNFTRequestStruct,Z_Param_RequestStruct);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SendAccountNFTRequest(Z_Param_RequestStruct);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UHttpNearBackManager::execGetNFTMetadata)
	{
		P_GET_STRUCT(FGetNFTRequestStruct,Z_Param_RequestStruct);
		P_FINISH;
		P_NATIVE_BEGIN;
		UHttpNearBackManager::GetNFTMetadata(Z_Param_RequestStruct);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UHttpNearBackManager::execSendNFTMetadataRequest)
	{
		P_GET_STRUCT(FGetNFTRequestStruct,Z_Param_RequestStruct);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SendNFTMetadataRequest(Z_Param_RequestStruct);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UHttpNearBackManager::execGetNearAccountFTBalance)
	{
		P_GET_STRUCT(FGetFTBalanceRequestStruct,Z_Param_RequestStruct);
		P_FINISH;
		P_NATIVE_BEGIN;
		UHttpNearBackManager::GetNearAccountFTBalance(Z_Param_RequestStruct);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UHttpNearBackManager::execSendAccountFTBalanceRequest)
	{
		P_GET_STRUCT(FGetFTBalanceRequestStruct,Z_Param_RequestStruct);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SendAccountFTBalanceRequest(Z_Param_RequestStruct);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UHttpNearBackManager::execGetNearAccountBalance)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_AccountId);
		P_FINISH;
		P_NATIVE_BEGIN;
		UHttpNearBackManager::GetNearAccountBalance(Z_Param_AccountId);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UHttpNearBackManager::execSendAccountBalanceRequest)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_AccountId);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SendAccountBalanceRequest(Z_Param_AccountId);
		P_NATIVE_END;
	}
	void UHttpNearBackManager::StaticRegisterNativesUHttpNearBackManager()
	{
		UClass* Class = UHttpNearBackManager::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetAccountNFT", &UHttpNearBackManager::execGetAccountNFT },
			{ "GetNearAccountBalance", &UHttpNearBackManager::execGetNearAccountBalance },
			{ "GetNearAccountFTBalance", &UHttpNearBackManager::execGetNearAccountFTBalance },
			{ "GetNFTMetadata", &UHttpNearBackManager::execGetNFTMetadata },
			{ "SendAccountBalanceRequest", &UHttpNearBackManager::execSendAccountBalanceRequest },
			{ "SendAccountFTBalanceRequest", &UHttpNearBackManager::execSendAccountFTBalanceRequest },
			{ "SendAccountNFTRequest", &UHttpNearBackManager::execSendAccountNFTRequest },
			{ "SendNFTMetadataRequest", &UHttpNearBackManager::execSendNFTMetadataRequest },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UHttpNearBackManager_GetAccountNFT_Statics
	{
		struct HttpNearBackManager_eventGetAccountNFT_Parms
		{
			FGetAccountNFTRequestStruct RequestStruct;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_RequestStruct;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UHttpNearBackManager_GetAccountNFT_Statics::NewProp_RequestStruct = { "RequestStruct", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(HttpNearBackManager_eventGetAccountNFT_Parms, RequestStruct), Z_Construct_UScriptStruct_FGetAccountNFTRequestStruct, METADATA_PARAMS(nullptr, 0) }; // 4100657156
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UHttpNearBackManager_GetAccountNFT_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHttpNearBackManager_GetAccountNFT_Statics::NewProp_RequestStruct,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UHttpNearBackManager_GetAccountNFT_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/HttpNearBackManager.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UHttpNearBackManager_GetAccountNFT_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UHttpNearBackManager, nullptr, "GetAccountNFT", nullptr, nullptr, sizeof(Z_Construct_UFunction_UHttpNearBackManager_GetAccountNFT_Statics::HttpNearBackManager_eventGetAccountNFT_Parms), Z_Construct_UFunction_UHttpNearBackManager_GetAccountNFT_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UHttpNearBackManager_GetAccountNFT_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UHttpNearBackManager_GetAccountNFT_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UHttpNearBackManager_GetAccountNFT_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UHttpNearBackManager_GetAccountNFT()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UHttpNearBackManager_GetAccountNFT_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UHttpNearBackManager_GetNearAccountBalance_Statics
	{
		struct HttpNearBackManager_eventGetNearAccountBalance_Parms
		{
			FString AccountId;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_AccountId;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UHttpNearBackManager_GetNearAccountBalance_Statics::NewProp_AccountId = { "AccountId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(HttpNearBackManager_eventGetNearAccountBalance_Parms, AccountId), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UHttpNearBackManager_GetNearAccountBalance_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHttpNearBackManager_GetNearAccountBalance_Statics::NewProp_AccountId,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UHttpNearBackManager_GetNearAccountBalance_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/HttpNearBackManager.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UHttpNearBackManager_GetNearAccountBalance_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UHttpNearBackManager, nullptr, "GetNearAccountBalance", nullptr, nullptr, sizeof(Z_Construct_UFunction_UHttpNearBackManager_GetNearAccountBalance_Statics::HttpNearBackManager_eventGetNearAccountBalance_Parms), Z_Construct_UFunction_UHttpNearBackManager_GetNearAccountBalance_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UHttpNearBackManager_GetNearAccountBalance_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UHttpNearBackManager_GetNearAccountBalance_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UHttpNearBackManager_GetNearAccountBalance_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UHttpNearBackManager_GetNearAccountBalance()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UHttpNearBackManager_GetNearAccountBalance_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UHttpNearBackManager_GetNearAccountFTBalance_Statics
	{
		struct HttpNearBackManager_eventGetNearAccountFTBalance_Parms
		{
			FGetFTBalanceRequestStruct RequestStruct;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_RequestStruct;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UHttpNearBackManager_GetNearAccountFTBalance_Statics::NewProp_RequestStruct = { "RequestStruct", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(HttpNearBackManager_eventGetNearAccountFTBalance_Parms, RequestStruct), Z_Construct_UScriptStruct_FGetFTBalanceRequestStruct, METADATA_PARAMS(nullptr, 0) }; // 2818162397
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UHttpNearBackManager_GetNearAccountFTBalance_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHttpNearBackManager_GetNearAccountFTBalance_Statics::NewProp_RequestStruct,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UHttpNearBackManager_GetNearAccountFTBalance_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/HttpNearBackManager.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UHttpNearBackManager_GetNearAccountFTBalance_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UHttpNearBackManager, nullptr, "GetNearAccountFTBalance", nullptr, nullptr, sizeof(Z_Construct_UFunction_UHttpNearBackManager_GetNearAccountFTBalance_Statics::HttpNearBackManager_eventGetNearAccountFTBalance_Parms), Z_Construct_UFunction_UHttpNearBackManager_GetNearAccountFTBalance_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UHttpNearBackManager_GetNearAccountFTBalance_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UHttpNearBackManager_GetNearAccountFTBalance_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UHttpNearBackManager_GetNearAccountFTBalance_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UHttpNearBackManager_GetNearAccountFTBalance()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UHttpNearBackManager_GetNearAccountFTBalance_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UHttpNearBackManager_GetNFTMetadata_Statics
	{
		struct HttpNearBackManager_eventGetNFTMetadata_Parms
		{
			FGetNFTRequestStruct RequestStruct;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_RequestStruct;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UHttpNearBackManager_GetNFTMetadata_Statics::NewProp_RequestStruct = { "RequestStruct", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(HttpNearBackManager_eventGetNFTMetadata_Parms, RequestStruct), Z_Construct_UScriptStruct_FGetNFTRequestStruct, METADATA_PARAMS(nullptr, 0) }; // 1042617403
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UHttpNearBackManager_GetNFTMetadata_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHttpNearBackManager_GetNFTMetadata_Statics::NewProp_RequestStruct,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UHttpNearBackManager_GetNFTMetadata_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/HttpNearBackManager.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UHttpNearBackManager_GetNFTMetadata_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UHttpNearBackManager, nullptr, "GetNFTMetadata", nullptr, nullptr, sizeof(Z_Construct_UFunction_UHttpNearBackManager_GetNFTMetadata_Statics::HttpNearBackManager_eventGetNFTMetadata_Parms), Z_Construct_UFunction_UHttpNearBackManager_GetNFTMetadata_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UHttpNearBackManager_GetNFTMetadata_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UHttpNearBackManager_GetNFTMetadata_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UHttpNearBackManager_GetNFTMetadata_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UHttpNearBackManager_GetNFTMetadata()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UHttpNearBackManager_GetNFTMetadata_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UHttpNearBackManager_SendAccountBalanceRequest_Statics
	{
		struct HttpNearBackManager_eventSendAccountBalanceRequest_Parms
		{
			FString AccountId;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_AccountId;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UHttpNearBackManager_SendAccountBalanceRequest_Statics::NewProp_AccountId = { "AccountId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(HttpNearBackManager_eventSendAccountBalanceRequest_Parms, AccountId), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UHttpNearBackManager_SendAccountBalanceRequest_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHttpNearBackManager_SendAccountBalanceRequest_Statics::NewProp_AccountId,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UHttpNearBackManager_SendAccountBalanceRequest_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/HttpNearBackManager.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UHttpNearBackManager_SendAccountBalanceRequest_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UHttpNearBackManager, nullptr, "SendAccountBalanceRequest", nullptr, nullptr, sizeof(Z_Construct_UFunction_UHttpNearBackManager_SendAccountBalanceRequest_Statics::HttpNearBackManager_eventSendAccountBalanceRequest_Parms), Z_Construct_UFunction_UHttpNearBackManager_SendAccountBalanceRequest_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UHttpNearBackManager_SendAccountBalanceRequest_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UHttpNearBackManager_SendAccountBalanceRequest_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UHttpNearBackManager_SendAccountBalanceRequest_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UHttpNearBackManager_SendAccountBalanceRequest()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UHttpNearBackManager_SendAccountBalanceRequest_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UHttpNearBackManager_SendAccountFTBalanceRequest_Statics
	{
		struct HttpNearBackManager_eventSendAccountFTBalanceRequest_Parms
		{
			FGetFTBalanceRequestStruct RequestStruct;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_RequestStruct;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UHttpNearBackManager_SendAccountFTBalanceRequest_Statics::NewProp_RequestStruct = { "RequestStruct", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(HttpNearBackManager_eventSendAccountFTBalanceRequest_Parms, RequestStruct), Z_Construct_UScriptStruct_FGetFTBalanceRequestStruct, METADATA_PARAMS(nullptr, 0) }; // 2818162397
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UHttpNearBackManager_SendAccountFTBalanceRequest_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHttpNearBackManager_SendAccountFTBalanceRequest_Statics::NewProp_RequestStruct,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UHttpNearBackManager_SendAccountFTBalanceRequest_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/HttpNearBackManager.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UHttpNearBackManager_SendAccountFTBalanceRequest_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UHttpNearBackManager, nullptr, "SendAccountFTBalanceRequest", nullptr, nullptr, sizeof(Z_Construct_UFunction_UHttpNearBackManager_SendAccountFTBalanceRequest_Statics::HttpNearBackManager_eventSendAccountFTBalanceRequest_Parms), Z_Construct_UFunction_UHttpNearBackManager_SendAccountFTBalanceRequest_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UHttpNearBackManager_SendAccountFTBalanceRequest_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UHttpNearBackManager_SendAccountFTBalanceRequest_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UHttpNearBackManager_SendAccountFTBalanceRequest_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UHttpNearBackManager_SendAccountFTBalanceRequest()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UHttpNearBackManager_SendAccountFTBalanceRequest_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UHttpNearBackManager_SendAccountNFTRequest_Statics
	{
		struct HttpNearBackManager_eventSendAccountNFTRequest_Parms
		{
			FGetAccountNFTRequestStruct RequestStruct;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_RequestStruct;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UHttpNearBackManager_SendAccountNFTRequest_Statics::NewProp_RequestStruct = { "RequestStruct", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(HttpNearBackManager_eventSendAccountNFTRequest_Parms, RequestStruct), Z_Construct_UScriptStruct_FGetAccountNFTRequestStruct, METADATA_PARAMS(nullptr, 0) }; // 4100657156
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UHttpNearBackManager_SendAccountNFTRequest_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHttpNearBackManager_SendAccountNFTRequest_Statics::NewProp_RequestStruct,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UHttpNearBackManager_SendAccountNFTRequest_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/HttpNearBackManager.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UHttpNearBackManager_SendAccountNFTRequest_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UHttpNearBackManager, nullptr, "SendAccountNFTRequest", nullptr, nullptr, sizeof(Z_Construct_UFunction_UHttpNearBackManager_SendAccountNFTRequest_Statics::HttpNearBackManager_eventSendAccountNFTRequest_Parms), Z_Construct_UFunction_UHttpNearBackManager_SendAccountNFTRequest_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UHttpNearBackManager_SendAccountNFTRequest_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UHttpNearBackManager_SendAccountNFTRequest_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UHttpNearBackManager_SendAccountNFTRequest_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UHttpNearBackManager_SendAccountNFTRequest()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UHttpNearBackManager_SendAccountNFTRequest_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UHttpNearBackManager_SendNFTMetadataRequest_Statics
	{
		struct HttpNearBackManager_eventSendNFTMetadataRequest_Parms
		{
			FGetNFTRequestStruct RequestStruct;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_RequestStruct;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UHttpNearBackManager_SendNFTMetadataRequest_Statics::NewProp_RequestStruct = { "RequestStruct", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(HttpNearBackManager_eventSendNFTMetadataRequest_Parms, RequestStruct), Z_Construct_UScriptStruct_FGetNFTRequestStruct, METADATA_PARAMS(nullptr, 0) }; // 1042617403
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UHttpNearBackManager_SendNFTMetadataRequest_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UHttpNearBackManager_SendNFTMetadataRequest_Statics::NewProp_RequestStruct,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UHttpNearBackManager_SendNFTMetadataRequest_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/HttpNearBackManager.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UHttpNearBackManager_SendNFTMetadataRequest_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UHttpNearBackManager, nullptr, "SendNFTMetadataRequest", nullptr, nullptr, sizeof(Z_Construct_UFunction_UHttpNearBackManager_SendNFTMetadataRequest_Statics::HttpNearBackManager_eventSendNFTMetadataRequest_Parms), Z_Construct_UFunction_UHttpNearBackManager_SendNFTMetadataRequest_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UHttpNearBackManager_SendNFTMetadataRequest_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UHttpNearBackManager_SendNFTMetadataRequest_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UHttpNearBackManager_SendNFTMetadataRequest_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UHttpNearBackManager_SendNFTMetadataRequest()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UHttpNearBackManager_SendNFTMetadataRequest_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UHttpNearBackManager);
	UClass* Z_Construct_UClass_UHttpNearBackManager_NoRegister()
	{
		return UHttpNearBackManager::StaticClass();
	}
	struct Z_Construct_UClass_UHttpNearBackManager_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AccountBalance_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_AccountBalance;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FTBalance_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_FTBalance;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NFTMetadata_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_NFTMetadata;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AccountNFT_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_AccountNFT;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UHttpNearBackManager_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_NearPlugin,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UHttpNearBackManager_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UHttpNearBackManager_GetAccountNFT, "GetAccountNFT" }, // 3695862584
		{ &Z_Construct_UFunction_UHttpNearBackManager_GetNearAccountBalance, "GetNearAccountBalance" }, // 4288141726
		{ &Z_Construct_UFunction_UHttpNearBackManager_GetNearAccountFTBalance, "GetNearAccountFTBalance" }, // 3491148443
		{ &Z_Construct_UFunction_UHttpNearBackManager_GetNFTMetadata, "GetNFTMetadata" }, // 2441924357
		{ &Z_Construct_UFunction_UHttpNearBackManager_SendAccountBalanceRequest, "SendAccountBalanceRequest" }, // 3077602289
		{ &Z_Construct_UFunction_UHttpNearBackManager_SendAccountFTBalanceRequest, "SendAccountFTBalanceRequest" }, // 2531446593
		{ &Z_Construct_UFunction_UHttpNearBackManager_SendAccountNFTRequest, "SendAccountNFTRequest" }, // 3761984778
		{ &Z_Construct_UFunction_UHttpNearBackManager_SendNFTMetadataRequest, "SendNFTMetadataRequest" }, // 3749490445
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHttpNearBackManager_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "HttpNearBackManager.h" },
		{ "ModuleRelativePath", "Public/HttpNearBackManager.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHttpNearBackManager_Statics::NewProp_AccountBalance_MetaData[] = {
		{ "Category", "HttpNearBackManager" },
		{ "ModuleRelativePath", "Public/HttpNearBackManager.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UHttpNearBackManager_Statics::NewProp_AccountBalance = { "AccountBalance", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UHttpNearBackManager, AccountBalance), Z_Construct_UScriptStruct_FAccountBalanceStruct, METADATA_PARAMS(Z_Construct_UClass_UHttpNearBackManager_Statics::NewProp_AccountBalance_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UHttpNearBackManager_Statics::NewProp_AccountBalance_MetaData)) }; // 3136607972
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHttpNearBackManager_Statics::NewProp_FTBalance_MetaData[] = {
		{ "Category", "HttpNearBackManager" },
		{ "ModuleRelativePath", "Public/HttpNearBackManager.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UHttpNearBackManager_Statics::NewProp_FTBalance = { "FTBalance", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UHttpNearBackManager, FTBalance), Z_Construct_UScriptStruct_FFTBalanceStruct, METADATA_PARAMS(Z_Construct_UClass_UHttpNearBackManager_Statics::NewProp_FTBalance_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UHttpNearBackManager_Statics::NewProp_FTBalance_MetaData)) }; // 3192516462
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHttpNearBackManager_Statics::NewProp_NFTMetadata_MetaData[] = {
		{ "Category", "HttpNearBackManager" },
		{ "ModuleRelativePath", "Public/HttpNearBackManager.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UHttpNearBackManager_Statics::NewProp_NFTMetadata = { "NFTMetadata", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UHttpNearBackManager, NFTMetadata), Z_Construct_UScriptStruct_FNFTMetadataStruct, METADATA_PARAMS(Z_Construct_UClass_UHttpNearBackManager_Statics::NewProp_NFTMetadata_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UHttpNearBackManager_Statics::NewProp_NFTMetadata_MetaData)) }; // 1269816385
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UHttpNearBackManager_Statics::NewProp_AccountNFT_MetaData[] = {
		{ "Category", "HttpNearBackManager" },
		{ "ModuleRelativePath", "Public/HttpNearBackManager.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UHttpNearBackManager_Statics::NewProp_AccountNFT = { "AccountNFT", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UHttpNearBackManager, AccountNFT), Z_Construct_UScriptStruct_FAccountNFTStruct, METADATA_PARAMS(Z_Construct_UClass_UHttpNearBackManager_Statics::NewProp_AccountNFT_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UHttpNearBackManager_Statics::NewProp_AccountNFT_MetaData)) }; // 2742704025
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UHttpNearBackManager_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHttpNearBackManager_Statics::NewProp_AccountBalance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHttpNearBackManager_Statics::NewProp_FTBalance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHttpNearBackManager_Statics::NewProp_NFTMetadata,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHttpNearBackManager_Statics::NewProp_AccountNFT,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UHttpNearBackManager_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UHttpNearBackManager>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UHttpNearBackManager_Statics::ClassParams = {
		&UHttpNearBackManager::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UHttpNearBackManager_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UHttpNearBackManager_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UHttpNearBackManager_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UHttpNearBackManager_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UHttpNearBackManager()
	{
		if (!Z_Registration_Info_UClass_UHttpNearBackManager.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UHttpNearBackManager.OuterSingleton, Z_Construct_UClass_UHttpNearBackManager_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UHttpNearBackManager.OuterSingleton;
	}
	template<> NEARPLUGIN_API UClass* StaticClass<UHttpNearBackManager>()
	{
		return UHttpNearBackManager::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UHttpNearBackManager);
	struct Z_CompiledInDeferFile_FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_HttpNearBackManager_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_HttpNearBackManager_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UHttpNearBackManager, UHttpNearBackManager::StaticClass, TEXT("UHttpNearBackManager"), &Z_Registration_Info_UClass_UHttpNearBackManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UHttpNearBackManager), 839905795U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_HttpNearBackManager_h_3404063668(TEXT("/Script/NearPlugin"),
		Z_CompiledInDeferFile_FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_HttpNearBackManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_HttpNearBackManager_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
