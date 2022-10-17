#pragma once

#include "CoreMinimal.h"
#include "FGetNftListRequestStruct.generated.h"

USTRUCT(BlueprintType)
struct FGetNftListRequestStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ContractId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString FromIndex;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Limit;
};
