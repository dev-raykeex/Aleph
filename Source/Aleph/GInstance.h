// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "GInstance.generated.h"

/**
 * 
 */
UCLASS()
class ALEPH_API UGInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init();	

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Session")
		bool ALLOW_DEBUG = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Session")
		bool ALLOW_DEATH = true;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Session")
		bool ALLOW_ABILITIES = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Session")
		bool ALLOW_BASIC_MOVEMENT = true;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Session")
		bool ALLOW_ADV_MOVEMENT = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Session")
		bool ALLOW_RECEIVE_DAMAGE = true;

protected:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Input")
		float MouseSensitivity = 0.35f;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Input")
		float GamepadSensitivity = 45.0f;

	UFUNCTION(BlueprintPure)
		float GetMouseSensitivity() const { return MouseSensitivity; }

	UFUNCTION(BlueprintPure)
		float GetGamepadSensitivity() const { return GamepadSensitivity; }
};
