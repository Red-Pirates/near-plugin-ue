#pragma once
#include "CoreMinimal.h"
#include "FDeployContractRequestStruct.generated.h"

USTRUCT(BlueprintType)
struct FDeployContractRequestStruct{
	
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString FileName;   
};
