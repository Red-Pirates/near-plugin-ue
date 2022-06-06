// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNearPlugin_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_NearPlugin;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_NearPlugin()
	{
		if (!Z_Registration_Info_UPackage__Script_NearPlugin.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/NearPlugin",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0x227A29CE,
				0xAAF4D976,
				METADATA_PARAMS(nullptr, 0)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_NearPlugin.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_NearPlugin.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_NearPlugin(Z_Construct_UPackage__Script_NearPlugin, TEXT("/Script/NearPlugin"), Z_Registration_Info_UPackage__Script_NearPlugin, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x227A29CE, 0xAAF4D976));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
