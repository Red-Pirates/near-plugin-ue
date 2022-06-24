#pragma once

#include "CoreMinimal.h"

class FNearPluginModule : public IModuleInterface
{
public:

	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
