// Fill out your copyright notice in the Description page of Project Settings.


#include "DNCycle.h"

// Sets default values
ADNCycle::ADNCycle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADNCycle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADNCycle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (LightSource) { LightSource->AddActorLocalRotation(FRotator((DeltaTime * SunTurnRate), 0, 0)); }
	if (Sun) {
		FOutputDeviceNull ar;
		Sun->CallFunctionByNameWithArguments(TEXT("UpdateSunDirection"), ar, NULL, true);
	}
}