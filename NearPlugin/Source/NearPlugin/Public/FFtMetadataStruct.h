#pragma once

#include "CoreMinimal.h"
#include "FFtMetadataStruct.generated.h"

USTRUCT(BlueprintType)
struct FFtMetadataStruct
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
	FString Reference;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ReferenceHash;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Decimals;
};
