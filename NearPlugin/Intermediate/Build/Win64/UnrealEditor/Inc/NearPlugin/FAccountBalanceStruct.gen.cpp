// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NearPlugin/Public/FAccountBalanceStruct.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFAccountBalanceStruct() {}
// Cross Module References
	NEARPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FAccountBalanceStruct();
	UPackage* Z_Construct_UPackage__Script_NearPlugin();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_AccountBalanceStruct;
class UScriptStruct* FAccountBalanceStruct::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_AccountBalanceStruct.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_AccountBalanceStruct.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAccountBalanceStruct, Z_Construct_UPackage__Script_NearPlugin(), TEXT("AccountBalanceStruct"));
	}
	return Z_Registration_Info_UScriptStruct_AccountBalanceStruct.OuterSingleton;
}
template<> NEARPLUGIN_API UScriptStruct* StaticStruct<FAccountBalanceStruct>()
{
	return FAccountBalanceStruct::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FAccountBalanceStruct_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Total_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Total;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StateStaked_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_StateStaked;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Staked_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Staked;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Available_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Available;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAccountBalanceStruct_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/FAccountBalanceStruct.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FAccountBalanceStruct_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAccountBalanceStruct>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAccountBalanceStruct_Statics::NewProp_Total_MetaData[] = {
		{ "Category", "AccountBalanceStruct" },
		{ "ModuleRelativePath", "Public/FAccountBalanceStruct.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAccountBalanceStruct_Statics::NewProp_Total = { "Total", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FAccountBalanceStruct, Total), METADATA_PARAMS(Z_Construct_UScriptStruct_FAccountBalanceStruct_Statics::NewProp_Total_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAccountBalanceStruct_Statics::NewProp_Total_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAccountBalanceStruct_Statics::NewProp_StateStaked_MetaData[] = {
		{ "Category", "AccountBalanceStruct" },
		{ "ModuleRelativePath", "Public/FAccountBalanceStruct.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAccountBalanceStruct_Statics::NewProp_StateStaked = { "StateStaked", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FAccountBalanceStruct, StateStaked), METADATA_PARAMS(Z_Construct_UScriptStruct_FAccountBalanceStruct_Statics::NewProp_StateStaked_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAccountBalanceStruct_Statics::NewProp_StateStaked_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAccountBalanceStruct_Statics::NewProp_Staked_MetaData[] = {
		{ "Category", "AccountBalanceStruct" },
		{ "ModuleRelativePath", "Public/FAccountBalanceStruct.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAccountBalanceStruct_Statics::NewProp_Staked = { "Staked", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FAccountBalanceStruct, Staked), METADATA_PARAMS(Z_Construct_UScriptStruct_FAccountBalanceStruct_Statics::NewProp_Staked_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAccountBalanceStruct_Statics::NewProp_Staked_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAccountBalanceStruct_Statics::NewProp_Available_MetaData[] = {
		{ "Category", "AccountBalanceStruct" },
		{ "ModuleRelativePath", "Public/FAccountBalanceStruct.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAccountBalanceStruct_Statics::NewProp_Available = { "Available", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FAccountBalanceStruct, Available), METADATA_PARAMS(Z_Construct_UScriptStruct_FAccountBalanceStruct_Statics::NewProp_Available_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAccountBalanceStruct_Statics::NewProp_Available_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAccountBalanceStruct_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAccountBalanceStruct_Statics::NewProp_Total,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAccountBalanceStruct_Statics::NewProp_StateStaked,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAccountBalanceStruct_Statics::NewProp_Staked,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAccountBalanceStruct_Statics::NewProp_Available,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAccountBalanceStruct_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_NearPlugin,
		nullptr,
		&NewStructOps,
		"AccountBalanceStruct",
		sizeof(FAccountBalanceStruct),
		alignof(FAccountBalanceStruct),
		Z_Construct_UScriptStruct_FAccountBalanceStruct_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAccountBalanceStruct_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FAccountBalanceStruct_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAccountBalanceStruct_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FAccountBalanceStruct()
	{
		if (!Z_Registration_Info_UScriptStruct_AccountBalanceStruct.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_AccountBalanceStruct.InnerSingleton, Z_Construct_UScriptStruct_FAccountBalanceStruct_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_AccountBalanceStruct.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_FAccountBalanceStruct_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_FAccountBalanceStruct_h_Statics::ScriptStructInfo[] = {
		{ FAccountBalanceStruct::StaticStruct, Z_Construct_UScriptStruct_FAccountBalanceStruct_Statics::NewStructOps, TEXT("AccountBalanceStruct"), &Z_Registration_Info_UScriptStruct_AccountBalanceStruct, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAccountBalanceStruct), 3136607972U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_FAccountBalanceStruct_h_1696871610(TEXT("/Script/NearPlugin"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_FAccountBalanceStruct_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_FAccountBalanceStruct_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
