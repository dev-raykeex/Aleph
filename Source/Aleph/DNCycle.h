// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DirectionalLight.h"
#include "Misc/OutputDeviceNull.h"
#include "GameFramework/Actor.h"
#include "DNCycle.generated.h"

UCLASS()
class ALEPH_API ADNCycle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADNCycle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "General")
		AActor* Sun;

	UPROPERTY(EditAnywhere, Category = "General")
		ADirectionalLight* LightSource;

	UPROPERTY(EditAnywhere, Category = "General")
		float SunTurnRate;
};
