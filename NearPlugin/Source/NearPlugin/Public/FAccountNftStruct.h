#pragma once

#include "CoreMinimal.h"
#include "FNftMetadataStruct.h"
#include "FAccountNftStruct.generated.h"

USTRUCT(BlueprintType)
struct FAccountNftStruct
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FNftMetadataStruct> AccountNFTList;
};
