// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "C_Character.generated.h"

UCLASS()
class ALEPH_API AC_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AC_Character();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Input")
	float Sensitivity = 0.25f;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Input: Controller")
	float ZSensitivity = 25.0f;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Input: Controller")
	float YSensitivity = 45.0f;

	UFUNCTION(BlueprintPure)
		float GetSens() const { return Sensitivity; }
	UFUNCTION(Exec, BlueprintCallable)
		void SetSens(float Value);
	UFUNCTION(Exec, BlueprintCallable)
		void SetZSens(float Value);
	UFUNCTION(Exec, BlueprintCallable)
		void SetYSens(float Value);
	UFUNCTION(BlueprintPure)
		float GetZSens() const { return ZSensitivity; }
	UFUNCTION(BlueprintPure)
		float GetYSens() const { return YSensitivity; }

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Character: Movement - Dash")
		int DashKeyAmount;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character: Movement - Dash")
		float D_Axis = 0.0f;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character: Movement - Dash")
		bool IsWalkingV = false;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character: Movement - Dash")
		bool IsWalkingH = false;
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Character: Movement Speed")
		float BaseWalkSpeed = 375.0f;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Character: Movement Speed")
		float BaseWalkSpeedMultiplier = 1.6f;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Character: Movement Speed")
		float BaseCrouchSpeed = 150.0f;

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Camera")
		bool IsZooming = false;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character: Interaction")
		bool IsGrabbing = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character: Interaction")
		float GrabDistance = 180.0f;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Character: Interaction")
		float OutlineRange = 256.0f;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Character: Interaction")
		float OutlineRadius = 128.0f;
};
