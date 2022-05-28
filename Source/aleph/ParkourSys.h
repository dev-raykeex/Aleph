// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ParkourSys.generated.h"


UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ALEPH_API UParkourSys : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UParkourSys();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
protected:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		float DefaultGravity;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		FVector WR_Normal;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		float WR_Speed = 825.0f;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool bWR_Gravity = true;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		bool bWR_Left;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		bool bWR_Right;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		float WR_TargetGrav = 0.25f;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		bool bWR_Suppressed;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		float WR_JumpHeight = 500.0f;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		float WR_JumpForce = 625.0f;
};
