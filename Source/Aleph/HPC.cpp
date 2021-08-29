// Fill out your copyright notice in the Description page of Project Settings.


#include "HPC.h"

// Sets default values for this component's properties
UHPC::UHPC()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	DefaultHealth = 100;
	Health = DefaultHealth;
}


// Called when the game starts
void UHPC::BeginPlay()
{
	Super::BeginPlay();

	AActor* Owner = GetOwner();
	if (Owner)
	{
		Owner->OnTakeAnyDamage.AddDynamic(this, &UHPC::TakeDamage);
	}	
}


void UHPC::TakeDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser)
{
	Health = FMath::Clamp(float(Health) - Damage, 0.0f, float(DefaultHealth));
}


