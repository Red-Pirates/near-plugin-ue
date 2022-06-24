#pragma once

#include "CoreMinimal.h"
#include "FNftMetadataStruct.generated.h"

USTRUCT(BlueprintType)
struct FNftMetadataStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString TokenId;
	
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString OwnerId;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Title;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Description;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Media;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString MediaHash;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Copies;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 IssuedAt;
     
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 ExpiresAt;
     
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 StartsAt;
     
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 UpdatedAt;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Extra;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Reference;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString  ReferenceHash;
};
