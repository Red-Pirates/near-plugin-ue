#pragma once

#include "CoreMinimal.h"
#include "FAccountAuthorizedAppStruct.h"
#include "FAccountDetailsStruct.generated.h"

USTRUCT(BlueprintType)
struct FAccountDetailsStruct
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FAccountAuthorizedAppStruct> AuthorizedApps;
};
