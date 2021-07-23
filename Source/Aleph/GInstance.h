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

protected:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Input")
		float MouseSensitivity = 0.175f;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Input")
		float GamepadSensitivity = 3.0f;

	UFUNCTION(BlueprintPure)
		float GetMouseSensitivity() const { return MouseSensitivity; }

	UFUNCTION(BlueprintPure)
		float GetGamepadSensitivity() const { return GamepadSensitivity; }
};
