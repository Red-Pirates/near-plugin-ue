// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NearPlugin/Public/FNFTMetadataStruct.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFNFTMetadataStruct() {}
// Cross Module References
	NEARPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FNFTMetadataStruct();
	UPackage* Z_Construct_UPackage__Script_NearPlugin();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_NFTMetadataStruct;
class UScriptStruct* FNFTMetadataStruct::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_NFTMetadataStruct.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_NFTMetadataStruct.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FNFTMetadataStruct, Z_Construct_UPackage__Script_NearPlugin(), TEXT("NFTMetadataStruct"));
	}
	return Z_Registration_Info_UScriptStruct_NFTMetadataStruct.OuterSingleton;
}
template<> NEARPLUGIN_API UScriptStruct* StaticStruct<FNFTMetadataStruct>()
{
	return FNFTMetadataStruct::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TokenId_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_TokenId;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OwnerId_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_OwnerId;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Title_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Title;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Description_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Description;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Media_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Media;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Copies_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_Copies;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MediaHash_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_MediaHash;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IssuedAt_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_IssuedAt;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ExpiresAt_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_ExpiresAt;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StartsAt_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_StartsAt;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_UpdatedAt_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_UpdatedAt;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Extra_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Extra;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Reference_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Reference;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReferenceHash_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReferenceHash;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/FNFTMetadataStruct.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FNFTMetadataStruct>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_TokenId_MetaData[] = {
		{ "Category", "NFTMetadataStruct" },
		{ "ModuleRelativePath", "Public/FNFTMetadataStruct.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_TokenId = { "TokenId", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FNFTMetadataStruct, TokenId), METADATA_PARAMS(Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_TokenId_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_TokenId_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_OwnerId_MetaData[] = {
		{ "Category", "NFTMetadataStruct" },
		{ "ModuleRelativePath", "Public/FNFTMetadataStruct.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_OwnerId = { "OwnerId", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FNFTMetadataStruct, OwnerId), METADATA_PARAMS(Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_OwnerId_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_OwnerId_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_Title_MetaData[] = {
		{ "Category", "NFTMetadataStruct" },
		{ "ModuleRelativePath", "Public/FNFTMetadataStruct.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_Title = { "Title", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FNFTMetadataStruct, Title), METADATA_PARAMS(Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_Title_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_Title_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_Description_MetaData[] = {
		{ "Category", "NFTMetadataStruct" },
		{ "ModuleRelativePath", "Public/FNFTMetadataStruct.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_Description = { "Description", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FNFTMetadataStruct, Description), METADATA_PARAMS(Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_Description_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_Description_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_Media_MetaData[] = {
		{ "Category", "NFTMetadataStruct" },
		{ "ModuleRelativePath", "Public/FNFTMetadataStruct.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_Media = { "Media", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FNFTMetadataStruct, Media), METADATA_PARAMS(Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_Media_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_Media_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_Copies_MetaData[] = {
		{ "Category", "NFTMetadataStruct" },
		{ "ModuleRelativePath", "Public/FNFTMetadataStruct.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_Copies = { "Copies", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FNFTMetadataStruct, Copies), METADATA_PARAMS(Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_Copies_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_Copies_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_MediaHash_MetaData[] = {
		{ "Category", "NFTMetadataStruct" },
		{ "ModuleRelativePath", "Public/FNFTMetadataStruct.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_MediaHash = { "MediaHash", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FNFTMetadataStruct, MediaHash), METADATA_PARAMS(Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_MediaHash_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_MediaHash_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_IssuedAt_MetaData[] = {
		{ "Category", "NFTMetadataStruct" },
		{ "ModuleRelativePath", "Public/FNFTMetadataStruct.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_IssuedAt = { "IssuedAt", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FNFTMetadataStruct, IssuedAt), METADATA_PARAMS(Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_IssuedAt_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_IssuedAt_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_ExpiresAt_MetaData[] = {
		{ "Category", "NFTMetadataStruct" },
		{ "ModuleRelativePath", "Public/FNFTMetadataStruct.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_ExpiresAt = { "ExpiresAt", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FNFTMetadataStruct, ExpiresAt), METADATA_PARAMS(Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_ExpiresAt_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_ExpiresAt_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_StartsAt_MetaData[] = {
		{ "Category", "NFTMetadataStruct" },
		{ "ModuleRelativePath", "Public/FNFTMetadataStruct.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_StartsAt = { "StartsAt", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FNFTMetadataStruct, StartsAt), METADATA_PARAMS(Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_StartsAt_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_StartsAt_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_UpdatedAt_MetaData[] = {
		{ "Category", "NFTMetadataStruct" },
		{ "ModuleRelativePath", "Public/FNFTMetadataStruct.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_UpdatedAt = { "UpdatedAt", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FNFTMetadataStruct, UpdatedAt), METADATA_PARAMS(Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_UpdatedAt_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_UpdatedAt_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_Extra_MetaData[] = {
		{ "Category", "NFTMetadataStruct" },
		{ "ModuleRelativePath", "Public/FNFTMetadataStruct.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_Extra = { "Extra", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FNFTMetadataStruct, Extra), METADATA_PARAMS(Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_Extra_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_Extra_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_Reference_MetaData[] = {
		{ "Category", "NFTMetadataStruct" },
		{ "ModuleRelativePath", "Public/FNFTMetadataStruct.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_Reference = { "Reference", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FNFTMetadataStruct, Reference), METADATA_PARAMS(Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_Reference_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_Reference_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_ReferenceHash_MetaData[] = {
		{ "Category", "NFTMetadataStruct" },
		{ "ModuleRelativePath", "Public/FNFTMetadataStruct.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_ReferenceHash = { "ReferenceHash", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FNFTMetadataStruct, ReferenceHash), METADATA_PARAMS(Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_ReferenceHash_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_ReferenceHash_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_TokenId,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_OwnerId,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_Title,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_Description,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_Media,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_Copies,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_MediaHash,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_IssuedAt,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_ExpiresAt,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_StartsAt,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_UpdatedAt,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_Extra,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_Reference,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewProp_ReferenceHash,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_NearPlugin,
		nullptr,
		&NewStructOps,
		"NFTMetadataStruct",
		sizeof(FNFTMetadataStruct),
		alignof(FNFTMetadataStruct),
		Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FNFTMetadataStruct()
	{
		if (!Z_Registration_Info_UScriptStruct_NFTMetadataStruct.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_NFTMetadataStruct.InnerSingleton, Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_NFTMetadataStruct.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_FNFTMetadataStruct_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_FNFTMetadataStruct_h_Statics::ScriptStructInfo[] = {
		{ FNFTMetadataStruct::StaticStruct, Z_Construct_UScriptStruct_FNFTMetadataStruct_Statics::NewStructOps, TEXT("NFTMetadataStruct"), &Z_Registration_Info_UScriptStruct_NFTMetadataStruct, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FNFTMetadataStruct), 1269816385U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_FNFTMetadataStruct_h_588294247(TEXT("/Script/NearPlugin"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_FNFTMetadataStruct_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_FNFTMetadataStruct_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
