// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PCharacter.generated.h"

UCLASS()
class ALEPH_API APCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Character Movement")
		float BaseWalkSpeed = 450.0f;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Character Movement")
		float BaseCrouchSpeed = 150.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character Movement")
		float BaseWalkMultiplier = 1.0f;

protected:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Input")
	float Sensitivity = 0.25f;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Input: Controller")
	float ZSensitivity = 25.0f; // Controller sens.

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Input: Controller")
	float YSensitivity = 45.0f; // Controller sens.

	UFUNCTION(Exec, Category = "Commands")
		void SetMouseSens(float value);

	UFUNCTION(BlueprintPure)
		float GetSens() const { return Sensitivity; }
	UFUNCTION(BlueprintPure)
		float GetZSens() const { return ZSensitivity; }
	UFUNCTION(BlueprintPure)
		float GetYSens() const { return YSensitivity; }

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character: Interaction")
		bool IsGrabbing = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Camera")
		bool IsZoomed = false;

protected:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Input")
		int InputAmount = 0;

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character: Interaction")
		float GrabDistance = 180.0f;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Character: Interaction")
		float OutlineRange = 256.0f;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Character: Interaction")
		float OutlineRadius = 128.0f;

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character Movement: Dash")
		float D_Axis = 0.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character Movement: Dash")
		bool IsWalkingV = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character Movement: Dash")
		bool IsWalkingH = false;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
