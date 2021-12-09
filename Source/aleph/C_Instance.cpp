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
	if(bAllowOnlineServices)
	{
		OnlineSubsystem = IOnlineSubsystem::Get();
		Login();
	}
}

void UC_Instance::EnableOnlineServices()
{
	bAllowOnlineServices = true;
	UE_LOG(LogTemp, Warning, TEXT("The Online Services are now enabled!"));

	if(!OnlineSubsystem)
	{
		OnlineSubsystem = IOnlineSubsystem::Get();
		Login();
	}
}

void UC_Instance::Login()
{
	if(OnlineSubsystem)
	{
		if(IOnlineIdentityPtr Identity = OnlineSubsystem->GetIdentityInterface())
		{
			FOnlineAccountCredentials Credentials;
			Credentials.Id = FString("127.0.0.1:8080");
			Credentials.Token = FString("Whiteline");
			Credentials.Type = FString("developer");
			Identity->OnLoginCompleteDelegates->AddUObject(this, &UC_Instance::OnLoginComplete);
			Identity->Login(0, Credentials);
		}
	}
}

void UC_Instance::OnLoginComplete(int32 LocalUserNum, bool bWasSuccessful, const FUniqueNetId& UserId, const FString& Error)
{
	UE_LOG(LogTemp, Warning, TEXT("Login Successful: %d"), bWasSuccessful);
	bIsLoggedIn = bWasSuccessful;
	
	if(bWasSuccessful == false) 
	{
		bAllowOnlineServices = false;
	}
	
	if(OnlineSubsystem)
	{
		if(IOnlineIdentityPtr Identity = OnlineSubsystem->GetIdentityInterface())
		{
			OnlineUsername = Identity->GetUserAccount(UserId)->GetDisplayName();
			Identity->ClearOnLoginCompleteDelegates(0, this);
		}
	}
}

void UC_Instance::CreateSession()
{
	if(bAllowOnlineServices)
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
					SessionSettings.bIsLANMatch = true;
					SessionSettings.NumPublicConnections = 4;
					SessionSettings.bAllowJoinInProgress = true;
					SessionSettings.bAllowJoinViaPresence = true;
					SessionSettings.bUsesPresence = true;

					SessionPtr->OnCreateSessionCompleteDelegates.AddUObject(this, &UC_Instance::OnCreateSessionComplete);
					SessionPtr->CreateSession(0, FName("Aleph"), SessionSettings);
				}
			}
		} else {
			UE_LOG(LogTemp, Error, TEXT("Session creation has failed due to the user not being logged in."));
		}
	} else {
		UE_LOG(LogTemp, Error, TEXT("Please enable Online Services before continuing with the Session creation."));
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
