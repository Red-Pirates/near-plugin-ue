// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NearPlugin/Public/FGetFTBalanceRequestStruct.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFGetFTBalanceRequestStruct() {}
// Cross Module References
	NEARPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FGetFTBalanceRequestStruct();
	UPackage* Z_Construct_UPackage__Script_NearPlugin();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_GetFTBalanceRequestStruct;
class UScriptStruct* FGetFTBalanceRequestStruct::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_GetFTBalanceRequestStruct.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_GetFTBalanceRequestStruct.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FGetFTBalanceRequestStruct, Z_Construct_UPackage__Script_NearPlugin(), TEXT("GetFTBalanceRequestStruct"));
	}
	return Z_Registration_Info_UScriptStruct_GetFTBalanceRequestStruct.OuterSingleton;
}
template<> NEARPLUGIN_API UScriptStruct* StaticStruct<FGetFTBalanceRequestStruct>()
{
	return FGetFTBalanceRequestStruct::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FGetFTBalanceRequestStruct_Statics
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
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGetFTBalanceRequestStruct_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/FGetFTBalanceRequestStruct.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FGetFTBalanceRequestStruct_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FGetFTBalanceRequestStruct>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGetFTBalanceRequestStruct_Statics::NewProp_ContractId_MetaData[] = {
		{ "Category", "GetFTBalanceRequestStruct" },
		{ "ModuleRelativePath", "Public/FGetFTBalanceRequestStruct.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FGetFTBalanceRequestStruct_Statics::NewProp_ContractId = { "ContractId", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FGetFTBalanceRequestStruct, ContractId), METADATA_PARAMS(Z_Construct_UScriptStruct_FGetFTBalanceRequestStruct_Statics::NewProp_ContractId_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGetFTBalanceRequestStruct_Statics::NewProp_ContractId_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FGetFTBalanceRequestStruct_Statics::NewProp_AccountId_MetaData[] = {
		{ "Category", "GetFTBalanceRequestStruct" },
		{ "ModuleRelativePath", "Public/FGetFTBalanceRequestStruct.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FGetFTBalanceRequestStruct_Statics::NewProp_AccountId = { "AccountId", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FGetFTBalanceRequestStruct, AccountId), METADATA_PARAMS(Z_Construct_UScriptStruct_FGetFTBalanceRequestStruct_Statics::NewProp_AccountId_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGetFTBalanceRequestStruct_Statics::NewProp_AccountId_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FGetFTBalanceRequestStruct_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGetFTBalanceRequestStruct_Statics::NewProp_ContractId,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGetFTBalanceRequestStruct_Statics::NewProp_AccountId,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FGetFTBalanceRequestStruct_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_NearPlugin,
		nullptr,
		&NewStructOps,
		"GetFTBalanceRequestStruct",
		sizeof(FGetFTBalanceRequestStruct),
		alignof(FGetFTBalanceRequestStruct),
		Z_Construct_UScriptStruct_FGetFTBalanceRequestStruct_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGetFTBalanceRequestStruct_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FGetFTBalanceRequestStruct_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGetFTBalanceRequestStruct_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FGetFTBalanceRequestStruct()
	{
		if (!Z_Registration_Info_UScriptStruct_GetFTBalanceRequestStruct.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_GetFTBalanceRequestStruct.InnerSingleton, Z_Construct_UScriptStruct_FGetFTBalanceRequestStruct_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_GetFTBalanceRequestStruct.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_FGetFTBalanceRequestStruct_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_FGetFTBalanceRequestStruct_h_Statics::ScriptStructInfo[] = {
		{ FGetFTBalanceRequestStruct::StaticStruct, Z_Construct_UScriptStruct_FGetFTBalanceRequestStruct_Statics::NewStructOps, TEXT("GetFTBalanceRequestStruct"), &Z_Registration_Info_UScriptStruct_GetFTBalanceRequestStruct, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FGetFTBalanceRequestStruct), 2818162397U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_FGetFTBalanceRequestStruct_h_3991653855(TEXT("/Script/NearPlugin"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_FGetFTBalanceRequestStruct_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_FGetFTBalanceRequestStruct_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
