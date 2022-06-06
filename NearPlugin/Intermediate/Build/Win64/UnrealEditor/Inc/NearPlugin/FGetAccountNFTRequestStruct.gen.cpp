// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NearPlugin/Public/FGetAccountNFTRequestStruct.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFGetAccountNFTRequestStruct() {}
// Cross Module References
	NEARPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FGetAccountNFTRequestStruct();
	UPackage* Z_Construct_UPackage__Script_NearPlugin();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_GetAccountNFTRequestStruct;
class UScriptStruct* FGetAccountNFTRequestStruct::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_GetAccountNFTRequestStruct.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_GetAccountNFTRequestStruct.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FGetAccountNFTRequestStruct, Z_Construct_UPackage__Script_NearPlugin(), TEXT("GetAccountNFTRequestStruct"));
	}
	return Z_Registration_Info_UScriptStruct_GetAccountNFTRequestStruct.OuterSingleton;
}
template<> NEARPLUGIN_API UScriptStruct* StaticStruct<FGetAccountNFTRequestStruct>()
{
	return FGetAccountNFTRequestStruct::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FGetAccountNFTRequestStruct_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ContractId_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ContractId;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AccountId_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_AccountId;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FromIndex_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_FromIndex;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Limit_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_Limit;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGetAccountNFTRequestStruct_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/FGetAccountNFTRequestStruct.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FGetAccountNFTRequestStruct_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FGetAccountNFTRequestStruct>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGetAccountNFTRequestStruct_Statics::NewProp_ContractId_MetaData[] = {
		{ "Category", "GetAccountNFTRequestStruct" },
		{ "ModuleRelativePath", "Public/FGetAccountNFTRequestStruct.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FGetAccountNFTRequestStruct_Statics::NewProp_ContractId = { "ContractId", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FGetAccountNFTRequestStruct, ContractId), METADATA_PARAMS(Z_Construct_UScriptStruct_FGetAccountNFTRequestStruct_Statics::NewProp_ContractId_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGetAccountNFTRequestStruct_Statics::NewProp_ContractId_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGetAccountNFTRequestStruct_Statics::NewProp_AccountId_MetaData[] = {
		{ "Category", "GetAccountNFTRequestStruct" },
		{ "ModuleRelativePath", "Public/FGetAccountNFTRequestStruct.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FGetAccountNFTRequestStruct_Statics::NewProp_AccountId = { "AccountId", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FGetAccountNFTRequestStruct, AccountId), METADATA_PARAMS(Z_Construct_UScriptStruct_FGetAccountNFTRequestStruct_Statics::NewProp_AccountId_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGetAccountNFTRequestStruct_Statics::NewProp_AccountId_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGetAccountNFTRequestStruct_Statics::NewProp_FromIndex_MetaData[] = {
		{ "Category", "GetAccountNFTRequestStruct" },
		{ "ModuleRelativePath", "Public/FGetAccountNFTRequestStruct.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FGetAccountNFTRequestStruct_Statics::NewProp_FromIndex = { "FromIndex", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FGetAccountNFTRequestStruct, FromIndex), METADATA_PARAMS(Z_Construct_UScriptStruct_FGetAccountNFTRequestStruct_Statics::NewProp_FromIndex_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGetAccountNFTRequestStruct_Statics::NewProp_FromIndex_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGetAccountNFTRequestStruct_Statics::NewProp_Limit_MetaData[] = {
		{ "Category", "GetAccountNFTRequestStruct" },
		{ "ModuleRelativePath", "Public/FGetAccountNFTRequestStruct.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FGetAccountNFTRequestStruct_Statics::NewProp_Limit = { "Limit", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FGetAccountNFTRequestStruct, Limit), METADATA_PARAMS(Z_Construct_UScriptStruct_FGetAccountNFTRequestStruct_Statics::NewProp_Limit_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGetAccountNFTRequestStruct_Statics::NewProp_Limit_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FGetAccountNFTRequestStruct_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGetAccountNFTRequestStruct_Statics::NewProp_ContractId,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGetAccountNFTRequestStruct_Statics::NewProp_AccountId,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGetAccountNFTRequestStruct_Statics::NewProp_FromIndex,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGetAccountNFTRequestStruct_Statics::NewProp_Limit,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FGetAccountNFTRequestStruct_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_NearPlugin,
		nullptr,
		&NewStructOps,
		"GetAccountNFTRequestStruct",
		sizeof(FGetAccountNFTRequestStruct),
		alignof(FGetAccountNFTRequestStruct),
		Z_Construct_UScriptStruct_FGetAccountNFTRequestStruct_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGetAccountNFTRequestStruct_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FGetAccountNFTRequestStruct_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGetAccountNFTRequestStruct_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FGetAccountNFTRequestStruct()
	{
		if (!Z_Registration_Info_UScriptStruct_GetAccountNFTRequestStruct.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_GetAccountNFTRequestStruct.InnerSingleton, Z_Construct_UScriptStruct_FGetAccountNFTRequestStruct_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_GetAccountNFTRequestStruct.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_FGetAccountNFTRequestStruct_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_FGetAccountNFTRequestStruct_h_Statics::ScriptStructInfo[] = {
		{ FGetAccountNFTRequestStruct::StaticStruct, Z_Construct_UScriptStruct_FGetAccountNFTRequestStruct_Statics::NewStructOps, TEXT("GetAccountNFTRequestStruct"), &Z_Registration_Info_UScriptStruct_GetAccountNFTRequestStruct, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FGetAccountNFTRequestStruct), 4100657156U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_FGetAccountNFTRequestStruct_h_1375716638(TEXT("/Script/NearPlugin"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_FGetAccountNFTRequestStruct_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_FGetAccountNFTRequestStruct_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
