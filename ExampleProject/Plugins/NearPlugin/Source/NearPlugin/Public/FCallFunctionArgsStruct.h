#pragma once
#include "CoreMinimal.h"
#include "JsonObjectWrapper.h"
#include "FCallFunctionArgsStruct.generated.h"

USTRUCT(BlueprintType)
struct FCallFunctionArgsStruct {
	
	GENERATED_BODY()
    
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ContractId;
    
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Method;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FJsonObjectWrapper Params;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString AttachedGas;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString AttachedTokens;
};
