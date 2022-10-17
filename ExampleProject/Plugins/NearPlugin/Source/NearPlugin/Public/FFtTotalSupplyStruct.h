#pragma once

#include "CoreMinimal.h"
#include "FFtTotalSupplyStruct.generated.h"

USTRUCT(BlueprintType)
struct FFtTotalSupplyStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Balance;
};
