#pragma once

#include "CoreMinimal.h"
#include "FAccountStateStruct.generated.h"

USTRUCT(BlueprintType)
struct FAccountStateStruct
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Amount;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString BlockHash;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 BlockHeight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString CodeHash;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Locked;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 StoragePaidAt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 StorageUsage;
};
