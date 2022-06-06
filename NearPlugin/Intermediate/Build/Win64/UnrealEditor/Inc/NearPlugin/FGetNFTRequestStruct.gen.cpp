// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NearPlugin/Public/FGetNFTRequestStruct.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFGetNFTRequestStruct() {}
// Cross Module References
	NEARPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FGetNFTRequestStruct();
	UPackage* Z_Construct_UPackage__Script_NearPlugin();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_GetNFTRequestStruct;
class UScriptStruct* FGetNFTRequestStruct::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_GetNFTRequestStruct.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_GetNFTRequestStruct.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FGetNFTRequestStruct, Z_Construct_UPackage__Script_NearPlugin(), TEXT("GetNFTRequestStruct"));
	}
	return Z_Registration_Info_UScriptStruct_GetNFTRequestStruct.OuterSingleton;
}
template<> NEARPLUGIN_API UScriptStruct* StaticStruct<FGetNFTRequestStruct>()
{
	return FGetNFTRequestStruct::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FGetNFTRequestStruct_Statics
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
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TokenId_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_TokenId;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGetNFTRequestStruct_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/FGetNFTRequestStruct.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FGetNFTRequestStruct_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FGetNFTRequestStruct>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGetNFTRequestStruct_Statics::NewProp_ContractId_MetaData[] = {
		{ "Category", "GetNFTRequestStruct" },
		{ "ModuleRelativePath", "Public/FGetNFTRequestStruct.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FGetNFTRequestStruct_Statics::NewProp_ContractId = { "ContractId", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FGetNFTRequestStruct, ContractId), METADATA_PARAMS(Z_Construct_UScriptStruct_FGetNFTRequestStruct_Statics::NewProp_ContractId_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGetNFTRequestStruct_Statics::NewProp_ContractId_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGetNFTRequestStruct_Statics::NewProp_TokenId_MetaData[] = {
		{ "Category", "GetNFTRequestStruct" },
		{ "ModuleRelativePath", "Public/FGetNFTRequestStruct.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FGetNFTRequestStruct_Statics::NewProp_TokenId = { "TokenId", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FGetNFTRequestStruct, TokenId), METADATA_PARAMS(Z_Construct_UScriptStruct_FGetNFTRequestStruct_Statics::NewProp_TokenId_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGetNFTRequestStruct_Statics::NewProp_TokenId_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FGetNFTRequestStruct_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGetNFTRequestStruct_Statics::NewProp_ContractId,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGetNFTRequestStruct_Statics::NewProp_TokenId,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FGetNFTRequestStruct_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_NearPlugin,
		nullptr,
		&NewStructOps,
		"GetNFTRequestStruct",
		sizeof(FGetNFTRequestStruct),
		alignof(FGetNFTRequestStruct),
		Z_Construct_UScriptStruct_FGetNFTRequestStruct_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGetNFTRequestStruct_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FGetNFTRequestStruct_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGetNFTRequestStruct_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FGetNFTRequestStruct()
	{
		if (!Z_Registration_Info_UScriptStruct_GetNFTRequestStruct.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_GetNFTRequestStruct.InnerSingleton, Z_Construct_UScriptStruct_FGetNFTRequestStruct_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_GetNFTRequestStruct.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_FGetNFTRequestStruct_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_FGetNFTRequestStruct_h_Statics::ScriptStructInfo[] = {
		{ FGetNFTRequestStruct::StaticStruct, Z_Construct_UScriptStruct_FGetNFTRequestStruct_Statics::NewStructOps, TEXT("GetNFTRequestStruct"), &Z_Registration_Info_UScriptStruct_GetNFTRequestStruct, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FGetNFTRequestStruct), 1042617403U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_FGetNFTRequestStruct_h_371144742(TEXT("/Script/NearPlugin"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_FGetNFTRequestStruct_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_FGetNFTRequestStruct_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
