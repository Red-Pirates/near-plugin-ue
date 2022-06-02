// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HttpNearBackManager.h"
#include "Modules/ModuleManager.h"

class FNearPluginModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	
	UPROPERTY(BlueprintReadWrite)
	UHttpNearBackManager* NearBackManager;
};
