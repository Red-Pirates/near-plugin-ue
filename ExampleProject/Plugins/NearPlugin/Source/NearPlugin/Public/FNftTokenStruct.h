#pragma once

#include "CoreMinimal.h"
#include "FNftMetadataStruct.h"
#include "FNftTokenStruct.generated.h"

USTRUCT(BlueprintType)
struct FNftTokenStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString TokenId;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString OwnerId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FNftMetadataStruct Metadata;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString,int> ApprovedAccountIds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString,int> Royalty;
};