#pragma once

#include "CoreMinimal.h"
#include "FAccountAuthorizedAppStruct.generated.h"

USTRUCT(BlueprintType)
struct FAccountAuthorizedAppStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ContractId;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Amount;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString PublicKey;
};
