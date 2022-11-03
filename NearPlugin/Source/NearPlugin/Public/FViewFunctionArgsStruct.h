#pragma once
#include "CoreMinimal.h"
#include "JsonObjectWrapper.h"
#include "FViewFunctionArgsStruct.generated.h"

USTRUCT(BlueprintType)
struct FViewFunctionArgsStruct {
    GENERATED_BODY()
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ContractId;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Method;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FJsonObjectWrapper Params;
};
