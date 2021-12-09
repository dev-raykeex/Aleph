// Fill out your copyright notice in the Description page of Project Settings.


#include "EPC.h"

// Sets default values for this component's properties
UEPC::UEPC()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	MaxEnergy = 100;
	Energy = MaxEnergy;
}


// Called when the game starts
void UEPC::BeginPlay()
{
	Super::BeginPlay();
}

void UEPC::SetEnergy(int value)
{
	Energy = value;
}