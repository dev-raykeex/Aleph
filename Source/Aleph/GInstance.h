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
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Gameplay", meta = (GetOptions = "RetrieveUINaming"))
		FString UIStyle = "Alternative";

	UFUNCTION(BlueprintCallable)
		TArray<FString> RetrieveUINaming() const
		{
			return {
				"Off",
				"Aleph",
				"Alternative",
				"Classic"
			};
		}

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Debug")
		bool AllowDebug = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Debug")
		bool AllowDeath = true;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Debug")
		bool AllowAbilities = true;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Debug")
		bool AllowTakeDamage = true;

public:
	// The heal ability is enabled by default in Aleph.
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Abilities")
		bool AllowAbility_Heal = true;

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Session")
		bool AllowBasicMovement = true;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Session")
		bool AllowAdvancedMovement = true;

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Gameplay")
		bool HoldCrouch = true;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Gameplay")
		bool HoldShift = true;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Gameplay")
		bool HoldPickup = true;

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Subtitles")
		bool EnableSubtitles = true;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Subtitles")
		bool EnableClosedCaptions = false;

protected:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Input")
		float MouseSensitivity = 0.25f;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Input")
		float GamepadSensitivity = 45.0f;

	UFUNCTION(BlueprintPure)
		float GetMouseSensitivity() const { return MouseSensitivity; }

	UFUNCTION(BlueprintPure)
		float GetGamepadSensitivity() const { return GamepadSensitivity; }
};
