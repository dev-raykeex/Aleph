// Fill out your copyright notice in the Description page of Project Settings.


#include "C_Instance.h"

#include "OnlineSessionSettings.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "Interfaces/OnlineIdentityInterface.h"
#include "OnlineSubsystem.h"

UC_Instance::UC_Instance()
{
	bIsLoggedIn = false;
	bIsConnected = false;
}

void UC_Instance::Init()
{
	Super::Init();
}

void UC_Instance::EnableOnlineServicesAndLogin()
{
	if (bAllowOnlineServices != true) {
		bAllowOnlineServices = true;
		OnlineSubsystem = IOnlineSubsystem::Get();
		Login();
		UE_LOG(LogTemp, Warning, TEXT("The Online Services are now enabled and you are logged in!"));
	} else {
		UE_LOG(LogTemp, Warning, TEXT("The Online Services are already enabled!"));
	}
}

void UC_Instance::Login()
{
	if (OnlineSubsystem)
	{
		if (IOnlineIdentityPtr Identity = OnlineSubsystem->GetIdentityInterface())
		{
			FOnlineAccountCredentials Credentials;
			Credentials.Id = FString("localhost:6300");
			Credentials.Token = FString("Context_1");
			Credentials.Type = FString("developer");

			Identity->OnLoginCompleteDelegates->AddUObject(this, &UC_Instance::OnLoginComplete);
			Identity->Login(0, Credentials);
		}
	}
}

void UC_Instance::OnLoginComplete(int32 LocalUserNum, bool bWasSuccessful, const FUniqueNetId& UserId, const FString& Error)
{
	if (bWasSuccessful == true) {
		UE_LOG(LogTemp, Error, TEXT("Client successfully logged in EOS."));
		bIsLoggedIn = bWasSuccessful;

		if (IOnlineIdentityPtr Identity = OnlineSubsystem->GetIdentityInterface())
		{
			OnlineUsername = Identity->GetUserAccount(UserId)->GetDisplayName();
			Identity->ClearOnLoginCompleteDelegates(0, this);
		}
	} else {
		UE_LOG(LogTemp, Error, TEXT("Client failed logging in EOS."));
	}
}

void UC_Instance::CreateSession()
{
	if(bIsLoggedIn)
	{
		if(OnlineSubsystem)
		{
			if(IOnlineSessionPtr SessionPtr = OnlineSubsystem->GetSessionInterface())
			{
				FOnlineSessionSettings SessionSettings;
				SessionSettings.bIsDedicated = false;
				SessionSettings.bShouldAdvertise = true;
				SessionSettings.bIsLANMatch = false;
				SessionSettings.NumPublicConnections = 2;
				SessionSettings.bAllowJoinInProgress = true;
				SessionSettings.bAllowJoinViaPresence = true;
				SessionSettings.bUsesPresence = true;
				SessionSettings.bUseLobbiesIfAvailable = true;
				SessionSettings.bUseLobbiesVoiceChatIfAvailable = true;
				SessionSettings.Set(SEARCH_KEYWORDS, FString("AlephOfficialServer"), EOnlineDataAdvertisementType::ViaOnlineService);

				SessionPtr->OnCreateSessionCompleteDelegates.AddUObject(this, &UC_Instance::OnCreateSessionComplete);
				SessionPtr->CreateSession(0, FName("Aleph"), SessionSettings);
			}
		}
	} else {
		UE_LOG(LogTemp, Error, TEXT("Session creation has failed due to the user not being logged in."));
	}
}

void UC_Instance::OnCreateSessionComplete(FName SessionName, bool bWasSuccessful)
{
	UE_LOG(LogTemp, Warning, TEXT("Session created with success: %d"), bWasSuccessful);
	bIsConnected = bWasSuccessful;
	if(OnlineSubsystem)
	{
		if(IOnlineSessionPtr SessionPtr = OnlineSubsystem->GetSessionInterface())
		{
			SessionPtr->ClearOnCreateSessionCompleteDelegates(this);
		}
	}
}

void UC_Instance::map(FString name) {
	FString cmd = "open ";
	FString finalCMD = cmd + name;

	GetPrimaryPlayerController()->ConsoleCommand(finalCMD);
}