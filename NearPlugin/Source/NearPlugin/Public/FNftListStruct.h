#pragma once

#include "CoreMinimal.h"
#include "FNftTokenStruct.h"
#include "FNftListStruct.generated.h"

USTRUCT(BlueprintType)
struct FNftListStruct
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FNftTokenStruct> NftTokens;
};
