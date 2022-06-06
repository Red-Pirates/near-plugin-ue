#include "NearPlugin.h"

#include "HttpNearBackManager.h"

#define LOCTEXT_NAMESPACE "FNearPluginModule"

void FNearPluginModule::StartupModule()
{
	UE_LOG(LogTemp, Log, TEXT("FNearPluginModule: StartupModule"));
	NearBackManager = NewObject<UHttpNearBackManager>();
}

void FNearPluginModule::ShutdownModule()
{
	UE_LOG(LogTemp, Log, TEXT("FNearPluginModule: ShutdownModule"));
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FNearPluginModule, NearPlugin)