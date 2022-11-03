#include "HttpNearBackManager.h"
#include "HttpModule.h"
#include "JsonObjectConverter.h"
#include "FAccountBalanceStruct.h"
#include "FFtMetadataStruct.h"
#include "FFtTotalSupplyStruct.h"
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

void UHttpNearBackManager::SendAccountStateRequest(FString AccountId)
{
	FHttpModule* Module = &FHttpModule::Get();
	const TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = Module->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &ThisClass::OnAccountStateReceivedResponse);
	Request->SetURL("http://localhost:3000/api/v1/accounts/" + AccountId + "/state");
	Request->SetVerb("GET");
	Request->ProcessRequest();
}

void UHttpNearBackManager::OnAccountStateReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response,
                                                          bool bWasSuccessful)
{
	if (!ResponseIsValid(Response, bWasSuccessful)) return;
	{
		const FString Data = Response->GetContentAsString();
		FJsonObjectConverter::JsonObjectStringToUStruct<FAccountStateStruct>(Data, &AccountState);
		UE_LOG(LogTemp, Log, TEXT("Near account state: %s"), *Data);
	}
	OnAccountStateReceived.Broadcast();
}

void UHttpNearBackManager::SendAccountDetailsRequest(FString AccountId)
{
	FHttpModule* Module = &FHttpModule::Get();
	const TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = Module->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &ThisClass::OnAccountDetailsReceivedResponse);
	Request->SetURL("http://localhost:3000/api/v1/accounts/" + AccountId + "/details");
	Request->SetVerb("GET");
	Request->ProcessRequest();
}

void UHttpNearBackManager::OnAccountDetailsReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response,
                                                            bool bWasSuccessful)
{
	if (!ResponseIsValid(Response, bWasSuccessful)) return;
	{
		const FString Data = Response->GetContentAsString();
		FJsonObjectConverter::JsonObjectStringToUStruct<FAccountDetailsStruct>(Data, &AccountDetails);
		UE_LOG(LogTemp, Log, TEXT("Near account state: %s"), *Data);
	}
	OnAccountDetailsReceived.Broadcast();
}

void UHttpNearBackManager::SendCreateAccountRequest(FCreateAccountRequestStruct RequestStruct)
{
	FString ContentJsonString;
	FJsonObjectConverter::UStructToJsonObjectString(FCreateAccountRequestStruct::StaticStruct(), &RequestStruct,
	                                                ContentJsonString, 0, 0);
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

void UHttpNearBackManager::SendAccountFtBalanceRequest(FString AccountId, FString ContractId)
{
	FHttpModule* Module = &FHttpModule::Get();
	const TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = Module->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &ThisClass::OnAccountFtBalanceReceivedResponse);
	Request->SetURL("http://localhost:3000/api/v1/ft-contracts/" + ContractId + "/accounts/" + AccountId + "/balance");
	Request->SetVerb("GET");
	Request->ProcessRequest();
}

void UHttpNearBackManager::OnAccountFtBalanceReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response,
                                                              bool bWasSuccessful)
{
	if (!ResponseIsValid(Response, bWasSuccessful)) return;

	const FString Data = Response->GetContentAsString();
	FJsonObjectConverter::JsonObjectStringToUStruct<FFtBalanceStruct>(Data, &FtBalance);
	UE_LOG(LogTemp, Log, TEXT("Near FT Balance: %s"), *FtBalance.Balance);
	OnFtBalanceReceived.Broadcast();
}

void UHttpNearBackManager::SendFtMetadataRequest(FString ContractId)
{
	FHttpModule* Module = &FHttpModule::Get();
	const TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = Module->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &ThisClass::OnFtMetadataReceivedResponse);
	Request->SetURL("http://localhost:3000/api/v1/ft-contracts/" + ContractId + "/meta");
	Request->SetVerb("GET");
	Request->ProcessRequest();
}

void UHttpNearBackManager::OnFtMetadataReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response,
															  bool bWasSuccessful)
{
	if (!ResponseIsValid(Response, bWasSuccessful)) return;
	
	const FString Data = Response->GetContentAsString();
	FJsonObjectConverter::JsonObjectStringToUStruct<FFtMetadataStruct>(Data, &FtMetadata);
	UE_LOG(LogTemp, Log, TEXT("Near FT TokenName: %s"), *FtMetadata.Name);
	UE_LOG(LogTemp, Log, TEXT("Near FT Symbol: %s"), *FtMetadata.Symbol);
	UE_LOG(LogTemp, Log, TEXT("Near FT Icon: %s"), *FtMetadata.Icon);
	OnFtMetadataReceived.Broadcast();
}

void UHttpNearBackManager::SendFtTotalSupplyRequest(FString ContractId)
{
	FHttpModule* Module = &FHttpModule::Get();
	const TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = Module->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &ThisClass::OnFtTotalSupplyReceivedResponse);
	Request->SetURL("http://localhost:3000/api/v1/ft-contracts/" + ContractId + "/total-supply");
	Request->SetVerb("GET");
	Request->ProcessRequest();
}

void UHttpNearBackManager::OnFtTotalSupplyReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response,
															  bool bWasSuccessful)
{
	if (!ResponseIsValid(Response, bWasSuccessful)) return;
	
	const FString Data = Response->GetContentAsString();
	FJsonObjectConverter::JsonObjectStringToUStruct<FFtTotalSupplyStruct>(Data, &FtTotalSupply);
	UE_LOG(LogTemp, Log, TEXT("FT Total supply: %s"), *FtTotalSupply.Balance);
	OnFtTotalSupplyReceived.Broadcast();
}

void UHttpNearBackManager::SendAccountNftRequest(FGetAccountNftRequestStruct RequestStruct)
{
	FHttpModule* Module = &FHttpModule::Get();
	const TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = Module->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &ThisClass::OnAccountNftReceivedResponse);
	Request->SetURL("http://localhost:3000/api/v1/nft-contracts/" + RequestStruct.ContractId + "/accounts/" +
		RequestStruct.AccountId + "/list?fromIndex=" + RequestStruct.FromIndex + "&limit=" + RequestStruct.Limit);
	Request->SetVerb("GET");
	Request->ProcessRequest();
}

void UHttpNearBackManager::OnAccountNftReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response,
                                                        bool bWasSuccessful)
{
	if (!ResponseIsValid(Response, bWasSuccessful)) return;

	const FString Data = Response->GetContentAsString();
	FJsonObjectConverter::JsonObjectStringToUStruct<FAccountNftStruct>(*Data, &AccountNftTokens);
	for (int32 b = 0; b < AccountNftTokens.AccountNftTokens.Num(); b++)
	{
		UE_LOG(LogClass, Log, TEXT("Title:  %s "), *AccountNftTokens.AccountNftTokens[b].Metadata.Title);
		UE_LOG(LogClass, Log, TEXT("Media:  %s "), *AccountNftTokens.AccountNftTokens[b].Metadata.Media);
		UE_LOG(LogClass, Log, TEXT("Description:  %s "), *AccountNftTokens.AccountNftTokens[b].Metadata.Description);
		UE_LOG(LogClass, Log, TEXT("/n"));
	}
	OnAccountNftReceived.Broadcast();
}

void UHttpNearBackManager::SendAccountNftSupplyRequest(FString AccountId, FString ContractId)
{
	FHttpModule* Module = &FHttpModule::Get();
	const TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = Module->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &ThisClass::OnAccountNftSupplyReceivedResponse);
	Request->SetURL("http://localhost:3000/api/v1/nft-contracts/" + ContractId + "/accounts/" + AccountId + "/supply");
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

void UHttpNearBackManager::SendNftListRequest(FGetNftListRequestStruct RequestStruct)
{
	FHttpModule* Module = &FHttpModule::Get();
	const TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = Module->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &ThisClass::OnNftListReceivedResponse);
	Request->SetURL("http://localhost:3000/api/v1/nft-contracts/" + RequestStruct.ContractId  + "/list?fromIndex=" + RequestStruct.FromIndex + "&limit=" + RequestStruct.Limit);
	Request->SetVerb("GET");
	Request->ProcessRequest();
}

void UHttpNearBackManager::OnNftListReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response,
														bool bWasSuccessful)
{
	if (!ResponseIsValid(Response, bWasSuccessful)) return;

	const FString Data = Response->GetContentAsString();
	FJsonObjectConverter::JsonObjectStringToUStruct<FNftListStruct>(*Data, &NftTokens);
	for (int32 b = 0; b < NftTokens.NftTokens.Num(); b++)
	{
		UE_LOG(LogClass, Log, TEXT("Title:  %s "), *NftTokens.NftTokens[b].Metadata.Title);
		UE_LOG(LogClass, Log, TEXT("Media:  %s "), *NftTokens.NftTokens[b].Metadata.Media);
		UE_LOG(LogClass, Log, TEXT("Description:  %s "), *NftTokens.NftTokens[b].Metadata.Description);
		UE_LOG(LogClass, Log, TEXT("/n"));
	}
	OnNftListReceived.Broadcast();
}

void UHttpNearBackManager::SendNftTotalSupplyRequest(FString ContractId)
{
	FHttpModule* Module = &FHttpModule::Get();
	const TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = Module->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &ThisClass::OnNftTotalSupplyReceivedResponse);
	Request->SetURL("http://localhost:3000/api/v1/nft-contracts/" + ContractId + "/total-supply");
	Request->SetVerb("GET");
	Request->ProcessRequest();
}

void UHttpNearBackManager::OnNftTotalSupplyReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response,
															  bool bWasSuccessful)
{
	if (!ResponseIsValid(Response, bWasSuccessful)) return;
	const FString Data = Response->GetContentAsString();
	FJsonObjectConverter::JsonObjectStringToUStruct<FNftSupplyStruct>(*Data, &NftTotalSupply);
	UE_LOG(LogClass, Log, TEXT("NFT total supply:  %s "), *NftTotalSupply.NftSupply);
	OnNftTotalSupplyReceived.Broadcast();
}

void UHttpNearBackManager::SendNftMetadataRequest(FString ContractId)
{
	FHttpModule* Module = &FHttpModule::Get();
	const TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = Module->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &ThisClass::OnNfMetadataReceivedResponse);
	Request->SetURL("http://localhost:3000/api/v1/nft-contracts/" + ContractId + "/metadata");
	Request->SetVerb("GET");
	Request->ProcessRequest();
}

void UHttpNearBackManager::OnNfMetadataReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response,
															  bool bWasSuccessful)
{
	if (!ResponseIsValid(Response, bWasSuccessful)) return;
	const FString Data = Response->GetContentAsString();
	FJsonObjectConverter::JsonObjectStringToUStruct<FNftContractMetaStruct>(*Data, &NftMetadata);
	UE_LOG(LogClass, Log, TEXT("NFT metadata name:  %s "), *NftMetadata.Name);
	UE_LOG(LogClass, Log, TEXT("NFT metadata symbol:  %s "), *NftMetadata.Symbol);
	OnNftMetadataReceived.Broadcast();
}

void UHttpNearBackManager::SendNftTokenInfoRequest(FString ContractId, FString TokenId)
{
	FHttpModule* Module = &FHttpModule::Get();
	const TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = Module->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &ThisClass::OnNftTokenInfoReceivedResponse);
	Request->SetURL("http://localhost:3000/api/v1/nft-contracts/" + ContractId + "/tokens/" + TokenId);
	Request->SetVerb("GET");
	Request->ProcessRequest();
}

void UHttpNearBackManager::OnNftTokenInfoReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response,
															  bool bWasSuccessful)
{
	if (!ResponseIsValid(Response, bWasSuccessful)) return;
	const FString Data = Response->GetContentAsString();
	FJsonObjectConverter::JsonObjectStringToUStruct<FNftTokenStruct>(*Data, &NftToken);
	UE_LOG(LogClass, Log, TEXT("NFT  token id:  %s "), *NftToken.TokenId);
	UE_LOG(LogClass, Log, TEXT("NFT owner id:  %s "), *NftToken.OwnerId);
	OnNftTokenReceived.Broadcast();
}

void UHttpNearBackManager::SendViewFunctionRequest(FViewFunctionArgsStruct RequestStruct )
{

	FString ContentJsonString;
	FJsonObjectConverter::UStructToJsonObjectString(FViewFunctionArgsStruct::StaticStruct(), &RequestStruct,
													ContentJsonString, 0, 0);
	
	FHttpModule* Module = &FHttpModule::Get();
	const TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = Module->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &ThisClass::OnViewFunctionReceivedResponse);
	Request->SetURL("http://localhost:3000/api/v1/contracts/view");
	Request->SetVerb("POST");
	Request->SetHeader("Content-Type", "application/json");
	Request->SetContentAsString(ContentJsonString);
	Request->ProcessRequest();
}

void UHttpNearBackManager::OnViewFunctionReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response,
															  bool bWasSuccessful)
{
	if (!ResponseIsValid(Response, bWasSuccessful)) return;
	const FString Data = Response->GetContentAsString();
	FJsonObjectConverter::JsonObjectStringToUStruct<FJsonObjectWrapper>(*Data, &ViewFunctionResponseObject);
	UE_LOG(LogClass, Log, TEXT("View function data:  %s "), *Data);
	OnViewFunctionReceived.Broadcast();
}

void UHttpNearBackManager::SendCallFunctionRequest(FCallFunctionArgsStruct RequestStruct)
{
	FString ContentJsonString;
	FJsonObjectConverter::UStructToJsonObjectString(FCallFunctionArgsStruct::StaticStruct(), &RequestStruct,
													ContentJsonString, 0, 0);
	FHttpModule* Module = &FHttpModule::Get();
	const TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = Module->CreateRequest();
	Request->OnProcessRequestComplete().BindUObject(this, &ThisClass::OnCallFunctionReceivedResponse);
	Request->SetURL("http://localhost:3000/api/v1/contracts/call");
	Request->SetVerb("POST");
	Request->SetHeader("Content-Type", "application/json");
	Request->SetContentAsString(ContentJsonString);
	Request->ProcessRequest();
}

void UHttpNearBackManager::OnCallFunctionReceivedResponse(FHttpRequestPtr Request, FHttpResponsePtr Response,
															  bool bWasSuccessful)
{
	if (!ResponseIsValid(Response, bWasSuccessful)) return;
	const FString Data = Response->GetContentAsString();
	FJsonObjectConverter::JsonObjectStringToUStruct<FJsonObjectWrapper>(*Data, &CallFunctionResponseObject);
	UE_LOG(LogClass, Log, TEXT("Call function data:  %s "), *Data);
	OnCallFunctionReceived.Broadcast();
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

	FPlatformProcess::LaunchURL(*DataStruct.LoginUrl, nullptr, nullptr);

	const FString ServerURL = TEXT("ws://localhost:5000");
	const FString ServerProtocol = TEXT("ws");

	TSharedRef<IWebSocket> Socket = FWebSocketsModule::Get().CreateWebSocket(ServerURL, ServerProtocol);

	Socket->OnConnected().AddLambda([Socket]()
	{
		UE_LOG(LogTemp, Log, TEXT("Connected to websocket server."));
	});

	Socket->OnConnectionError().AddLambda([](const FString& Error)
	{
		UE_LOG(LogTemp, Log, TEXT("Failed to connect to websocket server with error: \"%s\"."), *Error);
	});

	Socket->OnMessage().AddLambda([&](const FString& Message)
	{
		UE_LOG(LogTemp, Log, TEXT("Received message from websocket server: \"%s\"."), *Message);
		UserAccountId = Message;
		UE_LOG(LogTemp, Log, TEXT("User Account Id: \"%s\"."), *UserAccountId);
		OnUserAccountIdReceived.Broadcast();
	});

	Socket->OnClosed().AddLambda([&](int32 StatusCode, const FString& Reason, bool bWasClean)
	{
		UE_LOG(LogTemp, Log,
		       TEXT("Connection to websocket server has been closed with status code: \"%d\" and reason: \"%s\"."),
		       StatusCode, *Reason);
	});

	Socket->Connect();
}

bool UHttpNearBackManager::ResponseIsValid(FHttpResponsePtr Response, bool bWasSuccessful)
{
	if (EHttpResponseCodes::IsOk(Response->GetResponseCode()))
	{
		return true;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Http Response returned error code: %d"), Response->GetResponseCode());
		return false;
	}
}
