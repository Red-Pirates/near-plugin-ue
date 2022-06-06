// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Object.h"
#include "IHttpRequest.h"
#include "FAccountBalanceStruct.h"
#include "FFTBalanceStruct.h"
#include "FNFTMetadataStruct.h"
#include "FGetFTBalanceRequestStruct.h"
#include "FGetNFTRequestStruct.h"
#include "FGetAccountNFTRequestStruct.h"
#include "FAccountNFTStruct.h"
#include "HttpNearBackManager.generated.h"

/**
 * 
 */
UCLASS()
class NEARPLUGIN_API UHttpNearBackManager : public UObject
{
	GENERATED_BODY()
	
public:

    UPROPERTY(BlueprintReadOnly)
	FAccountBalanceStruct AccountBalance;
	
	UPROPERTY(BlueprintReadOnly)
    FFTBalanceStruct FTBalance;
    
	UPROPERTY(BlueprintReadOnly)
	FNFTMetadataStruct NFTMetadata;
	
	UPROPERTY(BlueprintReadOnly)
	FAccountNFTStruct AccountNFT;
	
	UHttpNearBackManager();
	
	UFUNCTION(BlueprintCallable)
	void SendAccountBalanceRequest(FString AccountId);

    UFUNCTION(BlueprintCallable)
	static void GetNearAccountBalance(FString AccountId);

	void OnAccountBalanceReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

	UFUNCTION(BlueprintCallable)
	void SendAccountFTBalanceRequest(FGetFTBalanceRequestStruct RequestStruct);
    
    UFUNCTION(BlueprintCallable)
    static void GetNearAccountFTBalance(FGetFTBalanceRequestStruct RequestStruct);

    void OnAccountFTBalanceReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
   
    UFUNCTION(BlueprintCallable)
	void SendNFTMetadataRequest(FGetNFTRequestStruct RequestStruct);

	UFUNCTION(BlueprintCallable)
	static void GetNFTMetadata(FGetNFTRequestStruct RequestStruct);
    
	void OnNFTMetadataReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

	UFUNCTION(BlueprintCallable)
	void SendAccountNFTRequest(FGetAccountNFTRequestStruct RequestStruct);

	UFUNCTION(BlueprintCallable)
	static void GetAccountNFT(FGetAccountNFTRequestStruct RequestStruct);
    
	void OnAccountNFTReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);

	
private:
	
	static bool ResponseIsValid(FHttpResponsePtr Response, bool bWasSuccessful);
};


