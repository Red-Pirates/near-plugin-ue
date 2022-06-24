#pragma once

#include "CoreMinimal.h"
#include "FFtBalanceStruct.generated.h"

USTRUCT(BlueprintType)
struct FFtBalanceStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString TokenName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Symbol;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Icon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Balance;
};
