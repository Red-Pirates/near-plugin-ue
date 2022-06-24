#pragma once

#include "CoreMinimal.h"
#include "FNftSupplyStruct.generated.h"

USTRUCT(BlueprintType)
struct FNftSupplyStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString NftSupply;
};
