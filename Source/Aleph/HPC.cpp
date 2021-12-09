// Fill out your copyright notice in the Description page of Project Settings.


#include "HPC.h"
#include "C_Character.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UHPC::UHPC()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	MaxHealth = 100;
	Health = MaxHealth;
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
	AC_Character* PCharacter = Cast<AC_Character>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	if (PCharacter->bAllowDamage) {
		Health = FMath::Clamp(float(Health) - Damage, 0.0f, float(MaxHealth));
	};
}

void UHPC::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	AC_Character* PCharacter = Cast<AC_Character>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	if (Health <= 0) {
		PCharacter->Destroy();
	};
}
