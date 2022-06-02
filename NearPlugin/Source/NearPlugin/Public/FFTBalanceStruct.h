#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FFTBalanceStruct.generated.h"

USTRUCT(BlueprintType)
struct FFTBalanceStruct
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
