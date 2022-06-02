#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FGetNFTRequestStruct.generated.h"

USTRUCT(BlueprintType)
struct FGetNFTRequestStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ContractId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString TokenId;
};
