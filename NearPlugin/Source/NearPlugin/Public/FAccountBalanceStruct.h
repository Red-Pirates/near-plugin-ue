#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FAccountBalanceStruct.generated.h"

USTRUCT(BlueprintType)
struct FAccountBalanceStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Total;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString StateStaked;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Staked;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Available;
};
