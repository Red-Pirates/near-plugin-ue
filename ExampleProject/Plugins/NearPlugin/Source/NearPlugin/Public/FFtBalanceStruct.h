#pragma once

#include "CoreMinimal.h"
#include "FFtBalanceStruct.generated.h"

USTRUCT(BlueprintType)
struct FFtBalanceStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Balance;
};
