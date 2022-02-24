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
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UFUNCTION(BlueprintCallable, Category = "Character: Movement")
		void move_forward(float Value);
	UFUNCTION(BlueprintCallable, Category = "Character: Movement")
		void move_side(float Value);

	UFUNCTION(BlueprintCallable, Category = "Character: Mouse")
		void look_vertical(float Axis);
	UFUNCTION(BlueprintCallable, Category = "Character: Mouse")
		void look_horizontal(float Axis);

	void Sprint();
	void StopSprinting();

protected:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Input")
		float Sensitivity = 0.25f;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Input: Controller")
		float ZSensitivity = 25.0f;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Input: Controller")
		float YSensitivity = 45.0f;

	UFUNCTION(BlueprintPure, Category = "Input")
		float GetSens() const { return Sensitivity; }
	UFUNCTION(BlueprintPure, Category = "Input: Controller")
		float GetZSens() const { return ZSensitivity; }
	UFUNCTION(BlueprintPure, Category = "Input: Controller")
		float GetYSens() const { return YSensitivity; }

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Character: Movement")
		float WalkSpeed = 375.0f;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Character: Movement")
		float SprintSpeed = WalkSpeed * 1.6f;

protected:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Character: Activity")
		bool bIsUsing;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Character: Activity")
		bool bIsCrouching;
};
