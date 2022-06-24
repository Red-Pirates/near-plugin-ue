#pragma once

#include "CoreMinimal.h"
#include "FAccountBalanceStruct.h"
#include "FFtBalanceStruct.h"
#include "FNftMetadataStruct.h"
#include "FGetAccountNFTRequestStruct.h"
#include "FAccountNftStruct.h"
#include "FNftSupplyStruct.h"
#include "FCreateAccountRequestStruct.h"
#include "Interfaces/IHttpRequest.h"
#include "HttpNearBackManager.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDAtaReceived);

UCLASS()
class NEARPLUGIN_API UHttpNearBackManager : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FString UserAccountId;

    UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FAccountBalanceStruct AccountBalance;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
    FFtBalanceStruct FtBalance;
    
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FNftMetadataStruct NftMetadata;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FAccountNftStruct AccountNFT;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FNftSupplyStruct NftSupply;

	UPROPERTY(BlueprintReadOnly, BlueprintAssignable)
	FOnDAtaReceived OnAccountBalanceReceived;

	UPROPERTY(BlueprintReadOnly, BlueprintAssignable)
	FOnDAtaReceived OnFtBalanceReceived;

	UPROPERTY(BlueprintReadOnly, BlueprintAssignable)
	FOnDAtaReceived OnUserAccountIdReceived;

	UPROPERTY(BlueprintReadOnly, BlueprintAssignable)
	FOnDAtaReceived OnAccountNftReceived;

	UPROPERTY(BlueprintReadOnly, BlueprintAssignable)
	FOnDAtaReceived OnNftSupplyReceived;
	
	UFUNCTION(BlueprintCallable)
	void SendAccountBalanceRequest(FString AccountId);

	void OnAccountBalanceReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

	UFUNCTION(BlueprintCallable)
	void SendAccountFtBalanceRequest(FString AccountId, FString ContractId);
    
    void OnAccountFtBalanceReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

	UFUNCTION(BlueprintCallable)
	void SendCreateAccountRequest(FCreateAccountRequestStruct RequestStruct);
    
	void OnCreateAccountReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
	
	UFUNCTION(BlueprintCallable)
	void SendAccountNftRequest(FGetAccountNftRequestStruct RequestStruct);

	void OnAccountNftReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

	UFUNCTION(BlueprintCallable)
	void SendAccountNftSupplyRequest(FString AccountId, FString ContractId);

	void OnAccountNftSupplyReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
	
	UFUNCTION(BlueprintCallable)
	void Login(FString ContractId);

	void OnLoginReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

private:
	static bool ResponseIsValid(FHttpResponsePtr Response, bool bWasSuccessful);
};


