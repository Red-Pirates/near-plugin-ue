#pragma once
#include "CoreMinimal.h"
#include "FCreateAccountRequestStruct.generated.h"

USTRUCT(BlueprintType)
struct FCreateAccountRequestStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Amount;
};
