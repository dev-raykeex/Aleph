// Fill out your copyright notice in the Description page of Project Settings.


#include "Client.h"

#include "OnlineSubsystem.h"
#include "Interfaces/OnlineIdentityInterface.h"

UClient::UClient()
{
	bLoginStatus = false;
}

void UClient::Init()
{
	Super::Init();
	Login();
}

void UClient::Login()
{
	if(OnlineSubsystem)
	{
		if(IOnlineIdentityPtr Identity = OnlineSubsystem->GetIdentityInterface())
		{
			FOnlineAccountCredentials Credentials;
			Credentials.Id = FString("localhost:6300");
			Credentials.Token = FString("Context_1");
			Credentials.Type = FString("developer");

			Identity->OnLoginCompleteDelegates->AddUObject(this, &UClient::OnLoginComplete);
			Identity->Login(0, Credentials);
		}
	}
}

void UClient::OnLoginComplete(int32 LocalUserNum, bool bWasSuccessful, const FUniqueNetId& UserId, const FString& Error)
{
	if(bWasSuccessful == true)
	{
		UE_LOG(LogTemp, Warning, TEXT("Client successfully logged in."));
		bLoginStatus = bWasSuccessful;

		if(IOnlineIdentityPtr Identity = OnlineSubsystem->GetIdentityInterface())
		{
			OnlineID = Identity->GetUserAccount(UserId)->GetDisplayName();
			Identity->ClearOnLoginCompleteDelegates(0, this);
		}
	} else
	{
		UE_LOG(LogTemp, Error, TEXT("Client failed to login."))
	}
}
