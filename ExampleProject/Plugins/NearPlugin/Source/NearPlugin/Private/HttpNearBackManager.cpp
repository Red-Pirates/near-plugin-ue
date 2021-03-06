#include "HttpNearBackManager.h"
#include "HttpModule.h"
#include "JsonObjectConverter.h"
#include "FAccountBalanceStruct.h"
#include "FLoginUrlStruct.h"
#include "FNftMetadataStruct.h"
#include "IWebSocket.h"
#include "WebSocketsModule.h"
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
	OnAccountBalanceReceived.Broadcast();
}

void UHttpNearBackManager::SendAccountFtBalanceRequest(FString AccountId, FString ContractId)
{
	FHttpModule* Module = &FHttpModule::Get();
	const TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = Module->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &ThisClass::OnAccountFtBalanceReceivedResponse);
	Request->SetURL("http://localhost:3000/api/v1/accounts/" + AccountId + "/contracts/" + ContractId + "/ft-balance");
	Request->SetVerb("GET");
	Request->ProcessRequest();
}

void UHttpNearBackManager::OnAccountFtBalanceReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response,
	bool bWasSuccessful)
{
	if (!ResponseIsValid(Response, bWasSuccessful)) return;

	const FString Data = Response->GetContentAsString();
	FJsonObjectConverter::JsonObjectStringToUStruct<FFtBalanceStruct>(Data, &FtBalance);
	UE_LOG(LogTemp, Log, TEXT("Near FT TokenName: %s"), *FtBalance.TokenName);
	UE_LOG(LogTemp, Log, TEXT("Near FT Symbol: %s"), *FtBalance.Symbol);
	UE_LOG(LogTemp, Log, TEXT("Near FT Icon: %s"), *FtBalance.Icon);
	UE_LOG(LogTemp, Log, TEXT("Near FT Balance: %s"), *FtBalance.Balance);
	OnFtBalanceReceived.Broadcast();
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

void UHttpNearBackManager::SendAccountNftRequest(FGetAccountNftRequestStruct RequestStruct)
{
	FHttpModule* Module = &FHttpModule::Get();
	const TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = Module->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &ThisClass::OnAccountNftReceivedResponse);
	Request->SetURL("http://localhost:3000/api/v1/accounts/" + RequestStruct.AccountId + "/contracts/" +
		RequestStruct.ContractId + "/nft-list?fromIndex=" + RequestStruct.FromIndex + "&limit=" + RequestStruct.Limit);
	Request->SetVerb("GET");
	Request->ProcessRequest();
}

void UHttpNearBackManager::OnAccountNftReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response,
	bool bWasSuccessful)
{
	if (!ResponseIsValid(Response, bWasSuccessful)) return;

	const FString Data = Response->GetContentAsString();
	FJsonObjectConverter::JsonObjectStringToUStruct<FAccountNftStruct>(*Data, &AccountNFT);
	for (int32 b = 0; b < AccountNFT.AccountNFTList.Num(); b++)
	{
		UE_LOG(LogClass, Log, TEXT("Title:  %s "), *AccountNFT.AccountNFTList[b].Title);
		UE_LOG(LogClass, Log, TEXT("Media:  %s "), *AccountNFT.AccountNFTList[b].Media);
		UE_LOG(LogClass, Log, TEXT("Description:  %s "), *AccountNFT.AccountNFTList[b].Description);
		UE_LOG(LogClass, Log, TEXT("/n"));
	}
	OnAccountNftReceived.Broadcast();
}

void UHttpNearBackManager::SendAccountNftSupplyRequest(FString AccountId, FString ContractId)
{
	FHttpModule* Module = &FHttpModule::Get();
	const TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = Module->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &ThisClass::OnAccountNftSupplyReceivedResponse);
	Request->SetURL("http://localhost:3000/api/v1/accounts/" + AccountId + "/contracts/" + ContractId + "/nft-supply");
	Request->SetVerb("GET");
	Request->ProcessRequest();
}

void UHttpNearBackManager::OnAccountNftSupplyReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response,
	bool bWasSuccessful)
{
	if (!ResponseIsValid(Response, bWasSuccessful)) return;
	const FString Data = Response->GetContentAsString();
	FJsonObjectConverter::JsonObjectStringToUStruct<FNftSupplyStruct>(*Data, &NftSupply);
	UE_LOG(LogClass, Log, TEXT("NFT supply:  %s "), *NftSupply.NftSupply);
	OnNftSupplyReceived.Broadcast();
}

void UHttpNearBackManager::Login(FString ContractId)
{
	FHttpModule* Module = &FHttpModule::Get();
	const TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = Module->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &ThisClass::OnLoginReceivedResponse);
	Request->SetURL("http://localhost:3000/api/v1/contracts/" + ContractId + "/login-url");
	Request->SetVerb("GET");
	Request->ProcessRequest();
}

 void UHttpNearBackManager::OnLoginReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response,
	bool bWasSuccessful)
{
	if (!ResponseIsValid(Response, bWasSuccessful)) return;
	const FString Data = Response->GetContentAsString();
	UE_LOG(LogClass, Log, TEXT("LoginUrl:  %s "), *Data);

	FLoginUrlStruct DataStruct;
	FJsonObjectConverter::JsonObjectStringToUStruct<FLoginUrlStruct>(Data, &DataStruct);

	FPlatformProcess::LaunchURL( *DataStruct.LoginUrl, nullptr, nullptr);

	const FString ServerURL = TEXT("ws://localhost:5000");
	const FString ServerProtocol = TEXT("ws");

	TSharedRef<IWebSocket> Socket = FWebSocketsModule::Get().CreateWebSocket(ServerURL, ServerProtocol);

	Socket->OnConnected().AddLambda([Socket]() {
		UE_LOG(LogTemp, Log, TEXT("Connected to websocket server."));
	});

	Socket->OnConnectionError().AddLambda([](const FString& Error) {
		UE_LOG(LogTemp, Log, TEXT("Failed to connect to websocket server with error: \"%s\"."), *Error);
	});

	Socket->OnMessage().AddLambda([&](const FString& Message) {
		UE_LOG(LogTemp, Log, TEXT("Received message from websocket server: \"%s\"."), *Message);
		UserAccountId = Message;
		UE_LOG(LogTemp, Log, TEXT("User Account Id: \"%s\"."), *UserAccountId);
		OnUserAccountIdReceived.Broadcast();
	});

	Socket->OnClosed().AddLambda([&](int32 StatusCode, const FString& Reason, bool bWasClean) {
		UE_LOG(LogTemp, Log, TEXT("Connection to websocket server has been closed with status code: \"%d\" and reason: \"%s\"."), StatusCode, *Reason);
	});

	Socket->Connect();
}

bool UHttpNearBackManager::ResponseIsValid(FHttpResponsePtr Response, bool bWasSuccessful) {
	if (EHttpResponseCodes::IsOk(Response->GetResponseCode())) {
		return true;
	} else {
	    UE_LOG(LogTemp, Warning, TEXT("Http Response returned error code: %d"), Response->GetResponseCode());
    	return false;
	}
}
