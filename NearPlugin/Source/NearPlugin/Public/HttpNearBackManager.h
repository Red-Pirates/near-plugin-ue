#pragma once

#include "CoreMinimal.h"
#include "FAccountBalanceStruct.h"
#include "FFTBalanceStruct.h"
#include "FNFTMetadataStruct.h"
#include "FGetAccountNFTRequestStruct.h"
#include "FAccountNFTStruct.h"
#include "FCreateAccountRequestStruct.h"
#include "Interfaces/IHttpRequest.h"
#include "HttpNearBackManager.generated.h"

UCLASS()
class NEARPLUGIN_API UHttpNearBackManager : public UObject
{
	GENERATED_BODY()
	
public:
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FAccountBalanceStruct AccountBalance;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
    FFTBalanceStruct FTBalance;
    
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FNFTMetadataStruct NFTMetadata;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FAccountNFTStruct AccountNFT;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FString NFTSupply;
	
	UFUNCTION(BlueprintCallable)
	void SendAccountBalanceRequest(FString AccountId);

	void OnAccountBalanceReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

	UFUNCTION(BlueprintCallable)
	void SendAccountFTBalanceRequest(FString AccountId, FString ContractId);
    
    void OnAccountFTBalanceReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

	UFUNCTION(BlueprintCallable)
	void SendCreateAccountRequest(FCreateAccountRequestStruct RequestStruct);
    
	void OnCreateAccountReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
	
	UFUNCTION(BlueprintCallable)
	void SendAccountNFTRequest(FGetAccountNFTRequestStruct RequestStruct);

	void OnAccountNFTReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

	UFUNCTION(BlueprintCallable)
	void SendAccountNFTSupplyRequest(FString AccountId, FString ContractId);

	void OnAccountNFTSupplyReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
	
private:
	static bool ResponseIsValid(FHttpResponsePtr Response, bool bWasSuccessful);
};


