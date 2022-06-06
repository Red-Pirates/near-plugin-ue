#include "HttpNearBackManager.h"
#include "HttpModule.h"
#include "JsonObjectConverter.h"
#include "FAccountBalanceStruct.h"
#include "FNFTMetadataStruct.h"
#include "FGetFTBalanceRequestStruct.h"
#include "FGetNFTRequestStruct.h"
#include "Interfaces/IHttpResponse.h"

void UHttpNearBackManager::SendAccountBalanceRequest(FString AccountId)
{
	FHttpModule* Module = &FHttpModule::Get();
	const TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = Module->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &ThisClass::OnAccountBalanceReceivedResponse);
	Request->SetURL("http://localhost:3000/api/v1/account/" + AccountId + "/balance");
	Request->SetVerb("GET");
	Request->ProcessRequest();
}

void UHttpNearBackManager::OnAccountBalanceReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response,
                                                            bool bWasSuccessful)
{
	if (!ResponseIsValid(Response, bWasSuccessful)) return;
	
	const FString Data = Response->GetContentAsString();
	FJsonObjectConverter::JsonObjectStringToUStruct<FAccountBalanceStruct>(Data, &AccountBalance);
	UE_LOG(LogTemp, Log, TEXT("Near account balance: %s"), *Data);
	UE_LOG(LogTemp, Log, TEXT("Near account balance: %s"), *AccountBalance.Total);
	UE_LOG(LogTemp, Log, TEXT("Near account balance: %s"), *AccountBalance.Staked);
	UE_LOG(LogTemp, Log, TEXT("Near account balance: %s"), *AccountBalance.StateStaked);
	UE_LOG(LogTemp, Log, TEXT("Near account balance: %s"), *AccountBalance.Available);
}

void UHttpNearBackManager::GetNearAccountBalance(FString AccountId)
{
	const auto Manager = NewObject<UHttpNearBackManager>();
	Manager->SendAccountBalanceRequest(AccountId);
}

void UHttpNearBackManager::SendAccountFTBalanceRequest(FGetFTBalanceRequestStruct RequestStruct)
{
	FString ContentJsonString;
	FJsonObjectConverter::UStructToJsonObjectString(FGetFTBalanceRequestStruct::StaticStruct(), &RequestStruct, ContentJsonString, 0, 0);
	FHttpModule* Module = &FHttpModule::Get();
	const TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = Module->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &ThisClass::OnAccountBalanceReceivedResponse);
	Request->SetURL("http://localhost:3000/api/v1/ft/balance");
	Request->SetVerb("POST");
	Request->SetHeader("Content-Type", "application/json");
	Request->SetContentAsString(ContentJsonString);
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

void UHttpNearBackManager::GetNearAccountFTBalance(FGetFTBalanceRequestStruct RequestStruct)
{
	const auto Manager = NewObject<UHttpNearBackManager>();
	Manager->SendAccountFTBalanceRequest(RequestStruct);
}

void UHttpNearBackManager::SendNFTMetadataRequest(FGetNFTRequestStruct RequestStruct)
{
	FString ContentJsonString;
	FJsonObjectConverter::UStructToJsonObjectString(FGetNFTRequestStruct::StaticStruct(), &RequestStruct, ContentJsonString, 0, 0);
	FHttpModule* Module = &FHttpModule::Get();
	const TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = Module->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &ThisClass::OnAccountBalanceReceivedResponse);
	Request->SetURL("http://localhost:3000/api/v1/nft/get");
	Request->SetVerb("POST");
    Request->SetHeader("Content-Type", "application/json");
	Request->SetContentAsString(ContentJsonString);
	Request->ProcessRequest();
}

void UHttpNearBackManager::OnNFTMetadataReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response,
	bool bWasSuccessful)
{
	if (!ResponseIsValid(Response, bWasSuccessful)) return;
	
	const FString Data = Response->GetContentAsString();
	FJsonObjectConverter::JsonObjectStringToUStruct<FNFTMetadataStruct>(Data, &NFTMetadata);
	UE_LOG(LogTemp, Log, TEXT("NFT metadata: %s"), *Data);
}

void UHttpNearBackManager::GetNFTMetadata(FGetNFTRequestStruct RequestStruct)
{
	const auto Manager = NewObject<UHttpNearBackManager>();
	Manager->SendNFTMetadataRequest(RequestStruct);
}

void UHttpNearBackManager::SendAccountNFTRequest(FGetAccountNFTRequestStruct RequestStruct)
{
	FString ContentJsonString;
	FJsonObjectConverter::UStructToJsonObjectString(FGetAccountNFTRequestStruct::StaticStruct(), &RequestStruct, ContentJsonString, 0, 0);
	FHttpModule* Module = &FHttpModule::Get();
	const TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = Module->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &ThisClass::OnAccountBalanceReceivedResponse);
	Request->SetURL("http://localhost:3000/api/v1/nft/get-many");
	Request->SetVerb("POST");
	Request->SetHeader("Content-Type", "application/json");
	Request->SetContentAsString(ContentJsonString);
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

void UHttpNearBackManager::GetAccountNFT(FGetAccountNFTRequestStruct RequestStruct)
{
	const auto Manager = NewObject<UHttpNearBackManager>();
	Manager->SendAccountNFTRequest(RequestStruct);
}

bool UHttpNearBackManager::ResponseIsValid(FHttpResponsePtr Response, bool bWasSuccessful) {
	if (!bWasSuccessful || !Response.IsValid()) return false;
	if (EHttpResponseCodes::IsOk(Response->GetResponseCode())) {
	 return true;
	} else {
		UE_LOG(LogTemp, Warning, TEXT("Http Response returned error code: %d"), Response->GetResponseCode());
		return false;
	}
}