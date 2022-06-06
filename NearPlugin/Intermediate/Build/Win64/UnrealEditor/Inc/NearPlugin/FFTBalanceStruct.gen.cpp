// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NearPlugin/Public/FFTBalanceStruct.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFFTBalanceStruct() {}
// Cross Module References
	NEARPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FFTBalanceStruct();
	UPackage* Z_Construct_UPackage__Script_NearPlugin();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FTBalanceStruct;
class UScriptStruct* FFTBalanceStruct::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FTBalanceStruct.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FTBalanceStruct.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FFTBalanceStruct, Z_Construct_UPackage__Script_NearPlugin(), TEXT("FTBalanceStruct"));
	}
	return Z_Registration_Info_UScriptStruct_FTBalanceStruct.OuterSingleton;
}
template<> NEARPLUGIN_API UScriptStruct* StaticStruct<FFTBalanceStruct>()
{
	return FFTBalanceStruct::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FFTBalanceStruct_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TokenName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_TokenName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Symbol_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Symbol;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Icon_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Icon;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Balance_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Balance;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FFTBalanceStruct_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/FFTBalanceStruct.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FFTBalanceStruct_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FFTBalanceStruct>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FFTBalanceStruct_Statics::NewProp_TokenName_MetaData[] = {
		{ "Category", "FTBalanceStruct" },
		{ "ModuleRelativePath", "Public/FFTBalanceStruct.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FFTBalanceStruct_Statics::NewProp_TokenName = { "TokenName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FFTBalanceStruct, TokenName), METADATA_PARAMS(Z_Construct_UScriptStruct_FFTBalanceStruct_Statics::NewProp_TokenName_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFTBalanceStruct_Statics::NewProp_TokenName_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FFTBalanceStruct_Statics::NewProp_Symbol_MetaData[] = {
		{ "Category", "FTBalanceStruct" },
		{ "ModuleRelativePath", "Public/FFTBalanceStruct.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FFTBalanceStruct_Statics::NewProp_Symbol = { "Symbol", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FFTBalanceStruct, Symbol), METADATA_PARAMS(Z_Construct_UScriptStruct_FFTBalanceStruct_Statics::NewProp_Symbol_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFTBalanceStruct_Statics::NewProp_Symbol_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FFTBalanceStruct_Statics::NewProp_Icon_MetaData[] = {
		{ "Category", "FTBalanceStruct" },
		{ "ModuleRelativePath", "Public/FFTBalanceStruct.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FFTBalanceStruct_Statics::NewProp_Icon = { "Icon", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FFTBalanceStruct, Icon), METADATA_PARAMS(Z_Construct_UScriptStruct_FFTBalanceStruct_Statics::NewProp_Icon_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFTBalanceStruct_Statics::NewProp_Icon_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FFTBalanceStruct_Statics::NewProp_Balance_MetaData[] = {
		{ "Category", "FTBalanceStruct" },
		{ "ModuleRelativePath", "Public/FFTBalanceStruct.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FFTBalanceStruct_Statics::NewProp_Balance = { "Balance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FFTBalanceStruct, Balance), METADATA_PARAMS(Z_Construct_UScriptStruct_FFTBalanceStruct_Statics::NewProp_Balance_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFTBalanceStruct_Statics::NewProp_Balance_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FFTBalanceStruct_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFTBalanceStruct_Statics::NewProp_TokenName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFTBalanceStruct_Statics::NewProp_Symbol,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFTBalanceStruct_Statics::NewProp_Icon,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FFTBalanceStruct_Statics::NewProp_Balance,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FFTBalanceStruct_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_NearPlugin,
		nullptr,
		&NewStructOps,
		"FTBalanceStruct",
		sizeof(FFTBalanceStruct),
		alignof(FFTBalanceStruct),
		Z_Construct_UScriptStruct_FFTBalanceStruct_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFTBalanceStruct_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FFTBalanceStruct_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFTBalanceStruct_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FFTBalanceStruct()
	{
		if (!Z_Registration_Info_UScriptStruct_FTBalanceStruct.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FTBalanceStruct.InnerSingleton, Z_Construct_UScriptStruct_FFTBalanceStruct_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_FTBalanceStruct.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_FFTBalanceStruct_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_FFTBalanceStruct_h_Statics::ScriptStructInfo[] = {
		{ FFTBalanceStruct::StaticStruct, Z_Construct_UScriptStruct_FFTBalanceStruct_Statics::NewStructOps, TEXT("FTBalanceStruct"), &Z_Registration_Info_UScriptStruct_FTBalanceStruct, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FFTBalanceStruct), 3192516462U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_FFTBalanceStruct_h_3345359155(TEXT("/Script/NearPlugin"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_FFTBalanceStruct_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_FFTBalanceStruct_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
