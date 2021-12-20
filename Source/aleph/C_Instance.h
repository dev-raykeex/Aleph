// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "C_Instance.generated.h"

/**
 * 
 */
UCLASS()
class ALEPH_API UC_Instance : public UGameInstance
{
	GENERATED_BODY()

public:
	UC_Instance();

	virtual void Init() override;
	
	UFUNCTION(Exec, BlueprintCallable, Category = "Commands")
		void EnableOnlineServicesAndLogin();

	UFUNCTION(Exec, BlueprintCallable, Category = "Commands")
		void Login();
	
	void OnLoginComplete(int32 LocalUserNum, bool bWasSuccessful, const FUniqueNetId& UserId, const FString& Error);

	UFUNCTION(Exec, BlueprintCallable, Category = "Commands")
		void CreateSession();

	void OnCreateSessionComplete(FName SessionName, bool bWasSuccessful);
	
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Gameplay")
		bool bToggleCrouch = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Gameplay")
		bool bToggleSprint = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Gameplay")
		bool bToggleInteract = false;
	
	UFUNCTION(Exec, Category = "Commands")
		void map(FString name);

protected:
	class IOnlineSubsystem* OnlineSubsystem;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool bAllowOnlineServices = false;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		bool bIsLoggedIn;
		
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
        bool bIsConnected;

protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		FString OnlineUsername;
};
