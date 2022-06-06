// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NearPlugin/Public/FAccountNFTStruct.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFAccountNFTStruct() {}
// Cross Module References
	NEARPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FAccountNFTStruct();
	UPackage* Z_Construct_UPackage__Script_NearPlugin();
	NEARPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FNFTMetadataStruct();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_AccountNFTStruct;
class UScriptStruct* FAccountNFTStruct::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_AccountNFTStruct.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_AccountNFTStruct.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAccountNFTStruct, Z_Construct_UPackage__Script_NearPlugin(), TEXT("AccountNFTStruct"));
	}
	return Z_Registration_Info_UScriptStruct_AccountNFTStruct.OuterSingleton;
}
template<> NEARPLUGIN_API UScriptStruct* StaticStruct<FAccountNFTStruct>()
{
	return FAccountNFTStruct::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FAccountNFTStruct_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructPropertyParams NewProp_AccountNFTList_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AccountNFTList_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_AccountNFTList;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAccountNFTStruct_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/FAccountNFTStruct.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FAccountNFTStruct_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAccountNFTStruct>();
	}
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAccountNFTStruct_Statics::NewProp_AccountNFTList_Inner = { "AccountNFTList", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FNFTMetadataStruct, METADATA_PARAMS(nullptr, 0) }; // 1269816385
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAccountNFTStruct_Statics::NewProp_AccountNFTList_MetaData[] = {
		{ "Category", "AccountNFTStruct" },
		{ "ModuleRelativePath", "Public/FAccountNFTStruct.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FAccountNFTStruct_Statics::NewProp_AccountNFTList = { "AccountNFTList", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FAccountNFTStruct, AccountNFTList), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FAccountNFTStruct_Statics::NewProp_AccountNFTList_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAccountNFTStruct_Statics::NewProp_AccountNFTList_MetaData)) }; // 1269816385
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAccountNFTStruct_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAccountNFTStruct_Statics::NewProp_AccountNFTList_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAccountNFTStruct_Statics::NewProp_AccountNFTList,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAccountNFTStruct_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_NearPlugin,
		nullptr,
		&NewStructOps,
		"AccountNFTStruct",
		sizeof(FAccountNFTStruct),
		alignof(FAccountNFTStruct),
		Z_Construct_UScriptStruct_FAccountNFTStruct_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAccountNFTStruct_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FAccountNFTStruct_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAccountNFTStruct_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FAccountNFTStruct()
	{
		if (!Z_Registration_Info_UScriptStruct_AccountNFTStruct.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_AccountNFTStruct.InnerSingleton, Z_Construct_UScriptStruct_FAccountNFTStruct_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_AccountNFTStruct.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_FAccountNFTStruct_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_FAccountNFTStruct_h_Statics::ScriptStructInfo[] = {
		{ FAccountNFTStruct::StaticStruct, Z_Construct_UScriptStruct_FAccountNFTStruct_Statics::NewStructOps, TEXT("AccountNFTStruct"), &Z_Registration_Info_UScriptStruct_AccountNFTStruct, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAccountNFTStruct), 2742704025U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_FAccountNFTStruct_h_2636155669(TEXT("/Script/NearPlugin"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_FAccountNFTStruct_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_FAccountNFTStruct_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
