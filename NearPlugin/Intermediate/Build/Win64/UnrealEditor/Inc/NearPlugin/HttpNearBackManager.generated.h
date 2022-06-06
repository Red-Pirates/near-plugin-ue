// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FGetAccountNFTRequestStruct;
struct FGetNFTRequestStruct;
struct FGetFTBalanceRequestStruct;
#ifdef NEARPLUGIN_HttpNearBackManager_generated_h
#error "HttpNearBackManager.generated.h already included, missing '#pragma once' in HttpNearBackManager.h"
#endif
#define NEARPLUGIN_HttpNearBackManager_generated_h

#define FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_HttpNearBackManager_h_17_SPARSE_DATA
#define FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_HttpNearBackManager_h_17_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetAccountNFT); \
	DECLARE_FUNCTION(execSendAccountNFTRequest); \
	DECLARE_FUNCTION(execGetNFTMetadata); \
	DECLARE_FUNCTION(execSendNFTMetadataRequest); \
	DECLARE_FUNCTION(execGetNearAccountFTBalance); \
	DECLARE_FUNCTION(execSendAccountFTBalanceRequest); \
	DECLARE_FUNCTION(execGetNearAccountBalance); \
	DECLARE_FUNCTION(execSendAccountBalanceRequest);


#define FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_HttpNearBackManager_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetAccountNFT); \
	DECLARE_FUNCTION(execSendAccountNFTRequest); \
	DECLARE_FUNCTION(execGetNFTMetadata); \
	DECLARE_FUNCTION(execSendNFTMetadataRequest); \
	DECLARE_FUNCTION(execGetNearAccountFTBalance); \
	DECLARE_FUNCTION(execSendAccountFTBalanceRequest); \
	DECLARE_FUNCTION(execGetNearAccountBalance); \
	DECLARE_FUNCTION(execSendAccountBalanceRequest);


#define FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_HttpNearBackManager_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUHttpNearBackManager(); \
	friend struct Z_Construct_UClass_UHttpNearBackManager_Statics; \
public: \
	DECLARE_CLASS(UHttpNearBackManager, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/NearPlugin"), NO_API) \
	DECLARE_SERIALIZER(UHttpNearBackManager)


#define FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_HttpNearBackManager_h_17_INCLASS \
private: \
	static void StaticRegisterNativesUHttpNearBackManager(); \
	friend struct Z_Construct_UClass_UHttpNearBackManager_Statics; \
public: \
	DECLARE_CLASS(UHttpNearBackManager, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/NearPlugin"), NO_API) \
	DECLARE_SERIALIZER(UHttpNearBackManager)


#define FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_HttpNearBackManager_h_17_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UHttpNearBackManager(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UHttpNearBackManager) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UHttpNearBackManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UHttpNearBackManager); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UHttpNearBackManager(UHttpNearBackManager&&); \
	NO_API UHttpNearBackManager(const UHttpNearBackManager&); \
public:


#define FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_HttpNearBackManager_h_17_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UHttpNearBackManager(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UHttpNearBackManager(UHttpNearBackManager&&); \
	NO_API UHttpNearBackManager(const UHttpNearBackManager&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UHttpNearBackManager); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UHttpNearBackManager); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UHttpNearBackManager)


#define FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_HttpNearBackManager_h_14_PROLOG
#define FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_HttpNearBackManager_h_17_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_HttpNearBackManager_h_17_SPARSE_DATA \
	FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_HttpNearBackManager_h_17_RPC_WRAPPERS \
	FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_HttpNearBackManager_h_17_INCLASS \
	FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_HttpNearBackManager_h_17_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_HttpNearBackManager_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_HttpNearBackManager_h_17_SPARSE_DATA \
	FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_HttpNearBackManager_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_HttpNearBackManager_h_17_INCLASS_NO_PURE_DECLS \
	FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_HttpNearBackManager_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> NEARPLUGIN_API UClass* StaticClass<class UHttpNearBackManager>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_near_plugin_Plugins_NearPlugin_Source_NearPlugin_Public_HttpNearBackManager_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
