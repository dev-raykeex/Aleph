// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Client.generated.h"

/**
 * 
 */
UCLASS()
class ALEPH_API UClient : public UGameInstance
{
	GENERATED_BODY()

public:
	UClient();

	virtual void Init() override;

	UFUNCTION(BlueprintCallable, Category="Client")
		void Login();
		void OnLoginComplete(int32 LocalUserNum, bool bWasSuccessful, const FUniqueNetId& UserId, const FString& Error);

protected:
	class IOnlineSubsystem* OnlineSubsystem;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		bool bLoginStatus;

protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		FString OnlineID;

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Input")
		bool bToggleCrouch = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Input")
		bool bToggleSprint = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Input")
		bool bToggleInteract = false;
};
