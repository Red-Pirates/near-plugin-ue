#include "HttpNearBackManager.h"
#include "HttpModule.h"
#include "JsonObjectConverter.h"
#include "FAccountBalanceStruct.h"
#include "FNFTMetadataStruct.h"
#include "Interfaces/IHttpResponse.h"

void UHttpNearBackManager::SendAccountBalanceRequest(FString AccountId)
{
	FHttpModule* Module = &FHttpModule::Get();
	const TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = Module->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &ThisClass::OnAccountBalanceReceivedResponse);
	Request->SetURL("http://localhost:3000/api/v1/accounts/" + AccountId + "/balance");
	Request->SetVerb("GET");
	Request->ProcessRequest();
}

void UHttpNearBackManager::OnAccountBalanceReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response,
                                                            bool bWasSuccessful)
{
	
	if (!ResponseIsValid(Response, bWasSuccessful)) return;
	{
		const FString Data = Response->GetContentAsString();
		FJsonObjectConverter::JsonObjectStringToUStruct<FAccountBalanceStruct>(Data, &AccountBalance);
		UE_LOG(LogTemp, Log, TEXT("Near account balance: %s"), *Data);
	}
	OnDAtaReceived.Broadcast();
}

void UHttpNearBackManager::SendAccountFTBalanceRequest(FString AccountId, FString ContractId)
{
	FHttpModule* Module = &FHttpModule::Get();
	const TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = Module->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &ThisClass::OnAccountBalanceReceivedResponse);
	Request->SetURL("http://localhost:3000/api/v1/accounts/" + AccountId + "/contracts" + ContractId + "/ft-balance");
	Request->SetVerb("GET");
	Request->ProcessRequest();
}

void UHttpNearBackManager::OnAccountFTBalanceReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response,
	bool bWasSuccessful)
{
	if (!ResponseIsValid(Response, bWasSuccessful)) return;
	
	const FString Data = Response->GetContentAsString();
	FJsonObjectConverter::JsonObjectStringToUStruct<FFTBalanceStruct>(Data, &FTBalance);
	UE_LOG(LogTemp, Log, TEXT("Near FT TokenName: %s"), *FTBalance.TokenName);
	UE_LOG(LogTemp, Log, TEXT("Near FT Symbol: %s"), *FTBalance.Symbol);
	UE_LOG(LogTemp, Log, TEXT("Near FT Icon: %s"), *FTBalance.Icon);
	UE_LOG(LogTemp, Log, TEXT("Near FT Balance: %s"), *FTBalance.Balance);
}

void UHttpNearBackManager::SendCreateAccountRequest(FCreateAccountRequestStruct RequestStruct)
{
	FString ContentJsonString;
	FJsonObjectConverter::UStructToJsonObjectString(FCreateAccountRequestStruct::StaticStruct(), &RequestStruct, ContentJsonString, 0, 0);
	FHttpModule* Module = &FHttpModule::Get();
	const TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = Module->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &ThisClass::OnAccountBalanceReceivedResponse);
	Request->SetURL("http://localhost:3000/api/v1/accounts");
	Request->SetVerb("POST");
    Request->SetHeader("Content-Type", "application/json");
	Request->SetContentAsString(ContentJsonString);
	Request->ProcessRequest();
}

void UHttpNearBackManager::OnCreateAccountReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response,
	bool bWasSuccessful)
{
	if (!ResponseIsValid(Response, bWasSuccessful)) return;
	
	const FString Data = Response->GetContentAsString();
	UE_LOG(LogTemp, Log, TEXT("New near account created: %s"), *Data);
}

void UHttpNearBackManager::SendAccountNFTRequest(FGetAccountNFTRequestStruct RequestStruct)
{
	FHttpModule* Module = &FHttpModule::Get();
	const TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = Module->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &ThisClass::OnAccountBalanceReceivedResponse);
	Request->SetURL("http://localhost:3000/api/v1/accounts/" + RequestStruct.AccountId + "/contracts" +
		RequestStruct.ContractId + "/nft-list?fromIndex=" + RequestStruct.FromIndex + "&limit=" + RequestStruct.Limit);
	Request->SetVerb("GET");
	Request->ProcessRequest();
}

void UHttpNearBackManager::OnAccountNFTReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response,
	bool bWasSuccessful)
{
	if (!ResponseIsValid(Response, bWasSuccessful)) return;
	
	const FString Data = Response->GetContentAsString();
	FJsonObjectConverter::JsonObjectStringToUStruct<FAccountNFTStruct>(Data, &AccountNFT);
	for (int32 b = 0; b < AccountNFT.AccountNFTList.Num(); b++)
	{
		UE_LOG(LogClass, Log, TEXT("Names:  %s "), *AccountNFT.AccountNFTList[b].Title); 
		UE_LOG(LogClass, Log, TEXT("Names:  %s "), *AccountNFT.AccountNFTList[b].Media); 
		UE_LOG(LogClass, Log, TEXT("Names:  %s "), *AccountNFT.AccountNFTList[b].Description); 
		UE_LOG(LogClass, Log, TEXT("/n")); 
	}
}

void UHttpNearBackManager::SendAccountNFTSupplyRequest(FString AccountId, FString ContractId)
{
	FHttpModule* Module = &FHttpModule::Get();
	const TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = Module->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &ThisClass::OnAccountBalanceReceivedResponse);
	Request->SetURL("http://localhost:3000/api/v1/accounts/" + AccountId + "/contracts" + ContractId + "/nft-supply");
	Request->SetVerb("GET");
	Request->ProcessRequest();
}

void UHttpNearBackManager::OnAccountNFTSupplyReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response,
	bool bWasSuccessful)
{
	if (!ResponseIsValid(Response, bWasSuccessful)) return;
	NFTSupply = Response->GetContentAsString();
	UE_LOG(LogClass, Log, TEXT("NFT supply:  %s "), *NFTSupply);
}

bool UHttpNearBackManager::ResponseIsValid(FHttpResponsePtr Response, bool bWasSuccessful) {
	if (EHttpResponseCodes::IsOk(Response->GetResponseCode())) {
		return true;
	} else {
	    UE_LOG(LogTemp, Warning, TEXT("Http Response returned error code: %d"), Response->GetResponseCode());
    	return false;
	}
}
