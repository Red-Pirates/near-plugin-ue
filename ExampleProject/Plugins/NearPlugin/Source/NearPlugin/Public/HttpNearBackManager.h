#pragma once

#include "CoreMinimal.h"
#include "FAccountBalanceStruct.h"
#include "FAccountDetailsStruct.h"
#include "FFtBalanceStruct.h"
#include "FGetAccountNFTRequestStruct.h"
#include "FAccountNftStruct.h"
#include "FAccountStateStruct.h"
#include "FCallFunctionArgsStruct.h"
#include "FNftSupplyStruct.h"
#include "FCreateAccountRequestStruct.h"
#include "FDeployContractRequestStruct.h"
#include "FFtMetadataStruct.h"
#include "FFtTotalSupplyStruct.h"
#include "FGetNftListRequestStruct.h"
#include "FNftContractMetaStruct.h"
#include "FNftListStruct.h"
#include "FNftTokenStruct.h"
#include "FViewFunctionArgsStruct.h"
#include "Interfaces/IHttpRequest.h"
#include "Json.h"
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
    FString UserSecretKey;
	
    UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FAccountBalanceStruct AccountBalance;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FAccountStateStruct AccountState;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FAccountDetailsStruct AccountDetails;	
	UPROPERTY(BlueprintReadOnly, BlueprintAssignable)
	FOnDAtaReceived OnUserAccountIdReceived;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
    FFtBalanceStruct FtBalance;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FFtMetadataStruct FtMetadata;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FFtTotalSupplyStruct FtTotalSupply;
  
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FNftTokenStruct NftToken;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FAccountNftStruct AccountNftTokens;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FNftSupplyStruct NftSupply;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FNftSupplyStruct NftTotalSupply;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FNftListStruct NftTokens;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FNftContractMetaStruct NftMetadata;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FJsonObjectWrapper ViewFunctionResponseObject;
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FJsonObjectWrapper CallFunctionResponseObject;
	
	UPROPERTY(BlueprintReadOnly, BlueprintAssignable)
	FOnDAtaReceived OnAccountBalanceReceived;
	UPROPERTY(BlueprintReadOnly, BlueprintAssignable)
	FOnDAtaReceived OnAccountDetailsReceived;
	UPROPERTY(BlueprintReadOnly, BlueprintAssignable)
	FOnDAtaReceived OnAccountStateReceived;

	UPROPERTY(BlueprintReadOnly, BlueprintAssignable)
	FOnDAtaReceived OnFtBalanceReceived;
	UPROPERTY(BlueprintReadOnly, BlueprintAssignable)
	FOnDAtaReceived OnFtMetadataReceived;
	UPROPERTY(BlueprintReadOnly, BlueprintAssignable)
	FOnDAtaReceived OnFtTotalSupplyReceived;

	UPROPERTY(BlueprintReadOnly, BlueprintAssignable)
	FOnDAtaReceived OnAccountNftReceived;
	UPROPERTY(BlueprintReadOnly, BlueprintAssignable)
	FOnDAtaReceived OnNftSupplyReceived;
	UPROPERTY(BlueprintReadOnly, BlueprintAssignable)
	FOnDAtaReceived OnNftTotalSupplyReceived;
	UPROPERTY(BlueprintReadOnly, BlueprintAssignable)
	FOnDAtaReceived OnNftListReceived;
	UPROPERTY(BlueprintReadOnly, BlueprintAssignable)
	FOnDAtaReceived OnNftMetadataReceived;
	UPROPERTY(BlueprintReadOnly, BlueprintAssignable)
	FOnDAtaReceived OnNftTokenReceived;

	UPROPERTY(BlueprintReadOnly, BlueprintAssignable)
	FOnDAtaReceived OnContractDeployed;
	UPROPERTY(BlueprintReadOnly, BlueprintAssignable)
	FOnDAtaReceived OnViewFunctionReceived;
	UPROPERTY(BlueprintReadOnly, BlueprintAssignable)
	FOnDAtaReceived OnCallFunctionReceived;
	
	UFUNCTION(BlueprintCallable)
	void SendAccountBalanceRequest(FString AccountId);
	void OnAccountBalanceReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

	UFUNCTION(BlueprintCallable)
	void SendAccountStateRequest(FString AccountId);
	void OnAccountStateReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

	UFUNCTION(BlueprintCallable)
	void SendAccountDetailsRequest(FString AccountId);
	void OnAccountDetailsReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

	UFUNCTION(BlueprintCallable)
	void SendDeployContractRequest(FDeployContractRequestStruct RequestStruct);
	void OnDeployContractReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

	UFUNCTION(BlueprintCallable)
	void SendAccountFtBalanceRequest(FString AccountId, FString ContractId);
    void OnAccountFtBalanceReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

	UFUNCTION(BlueprintCallable)
	void SendFtMetadataRequest(FString ContractId);
	void OnFtMetadataReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

	UFUNCTION(BlueprintCallable)
	void SendFtTotalSupplyRequest(FString ContractId);
	void OnFtTotalSupplyReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

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
	void SendNftTotalSupplyRequest(FString ContractId);
	void OnNftTotalSupplyReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

	UFUNCTION(BlueprintCallable)
	void SendNftListRequest(FGetNftListRequestStruct RequestStruct);
	void OnNftListReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

	UFUNCTION(BlueprintCallable)
	void SendNftMetadataRequest(FString ContractId);
	void OnNfMetadataReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

	UFUNCTION(BlueprintCallable)
	void SendNftTokenInfoRequest(FString ContractId, FString TokenId);
	void OnNftTokenInfoReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

	UFUNCTION(BlueprintCallable)
	void SendViewFunctionRequest(FViewFunctionArgsStruct RequestStruct);
	void OnViewFunctionReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

	UFUNCTION(BlueprintCallable)
	void SendCallFunctionRequest(FCallFunctionArgsStruct RequestStruct);
	void OnCallFunctionReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
		
	UFUNCTION(BlueprintCallable)
	void Login(FString ContractId);
	void OnLoginReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

private:
	static bool ResponseIsValid(FHttpResponsePtr Response, bool bWasSuccessful);
};


