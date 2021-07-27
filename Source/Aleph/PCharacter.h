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
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Character")
		float BaseWalkSpeed = 450.0f;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Character")
		float BaseCrouchSpeed = 150.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement")
		int DashCount = 2;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Camera")
		bool IsZoomed = false;

	UFUNCTION(BlueprintPure)
		int GetDashCount() const { return DashCount; }

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement")
		float DefaultGravity = 0.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement")
		float WR_Speed = 0.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement")
		float WR_TargetGravity = 0.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement")
		float WR_JumpHeight = 0.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement")
		bool WR = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement")
		bool WR_Left = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement")
		bool WR_Right = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement")
		bool WR_Gravity = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement")
		bool WR_Suppressed = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement")
		FVector WR_Normal = FVector(0.0f, 0.0f, 0.0f);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
