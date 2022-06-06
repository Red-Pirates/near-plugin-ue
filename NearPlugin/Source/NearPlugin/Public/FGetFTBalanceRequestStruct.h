#pragma once

#include "CoreMinimal.h"
#include "FGetFTBalanceRequestStruct.generated.h"

USTRUCT(BlueprintType)
struct FGetFTBalanceRequestStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ContractId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString AccountId;
};
