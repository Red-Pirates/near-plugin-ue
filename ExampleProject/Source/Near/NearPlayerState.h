#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "NearPlayerState.generated.h"

class UHttpNearBackManager;
UCLASS()
class NEAR_API ANearPlayerState : public APlayerState
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;
	
public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	UHttpNearBackManager* NearBackManager;
};
