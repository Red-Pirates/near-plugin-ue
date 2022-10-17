#pragma once

#include "CoreMinimal.h"
#include "FNftTokenStruct.h"
#include "FAccountNftStruct.generated.h"

USTRUCT(BlueprintType)
struct FAccountNftStruct
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FNftTokenStruct> AccountNftTokens;
};
