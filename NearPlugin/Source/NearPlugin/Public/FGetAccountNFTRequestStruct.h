#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FGetAccountNFTRequestStruct.generated.h"

USTRUCT(BlueprintType)
struct FGetAccountNFTRequestStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ContractId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString AccountId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString FromIndex;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Limit;
};
