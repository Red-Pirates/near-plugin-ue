#pragma once
#include "CoreMinimal.h"
#include "FLoginUrlStruct.generated.h"

USTRUCT(BlueprintType)
struct FLoginUrlStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString LoginUrl;
};
