#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FNFTMetadataStruct.h"
#include "FAccountNFTStruct.generated.h"

USTRUCT(BlueprintType)
struct FAccountNFTStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FNFTMetadataStruct> AccountNFTList;
};
