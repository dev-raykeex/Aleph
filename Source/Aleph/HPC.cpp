// Fill out your copyright notice in the Description page of Project Settings.


#include "HPC.h"
#include "GInstance.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UHPC::UHPC()
{
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


void UHPC::SetHealth(int value)
{
	Health = value;
}

void UHPC::TakeDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser)
{
	UGInstance* Instance = Cast<UGInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (Instance->AllowTakeDamage) {
		Health = FMath::Clamp(float(Health) - Damage, 0.0f, float(DefaultHealth));
	}
}


