#include "NearPlayerState.h"
#include "HttpNearBackManager.h"

void ANearPlayerState::BeginPlay()
{
	NearBackManager = NewObject<UHttpNearBackManager>();
	Super::BeginPlay();
}
