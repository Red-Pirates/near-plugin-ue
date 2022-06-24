#pragma once

#include "CoreMinimal.h"
#include "FGetAccountNftRequestStruct.generated.h"

USTRUCT(BlueprintType)
struct FGetAccountNftRequestStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ContractId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString AccountId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString FromIndex;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Limit;
};
