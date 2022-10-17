#pragma once

#include "CoreMinimal.h"
#include "FNftContractMetaStruct.generated.h"

USTRUCT(BlueprintType)
struct FNftContractMetaStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Spec;
    
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;
    
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Symbol;
    
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Icon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString BaseUri;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Reference;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString  ReferenceHash;
};
