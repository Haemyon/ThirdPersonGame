// Fill out your copyright notice in the Description page of Project Settings.


#include "01_Item/00_Equipable/Weapon_Spawn.h"

#include "Components/StaticMeshComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GamePlayStatics.h"

AWeapon_Spawn::AWeapon_Spawn()
{
	PrimaryActorTick.bCanEverTick = true;
	EquipmentMeshComponent->SetCollisionProfileName("WeaponPreset");
	SetActorEnableCollision(false);
}

void AWeapon_Spawn::AddUniqueHitActor(AActor* HitActor)
{
	HitActors.AddUnique(HitActor);
}

bool AWeapon_Spawn::IsAlreadyHitActor(AActor* HitActor)
{
	return HitActors.Contains(HitActor);
}

void AWeapon_Spawn::ClearHitActors()
{
	HitActors.Empty();
}

void AWeapon_Spawn::BeginPlay()
{
	Super::BeginPlay();
}

void AWeapon_Spawn::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	OnActorBeginOverlap.AddUniqueDynamic(this, &AWeapon_Spawn::OnActorBeginOverlapEvent);
}

void AWeapon_Spawn::OnActorBeginOverlapEvent(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor != nullptr)
	{
		FHitResult Hit;
		if (UKismetSystemLibrary::LineTraceSingle(this,
			GetActorLocation(),
			OtherActor->GetActorLocation(),
			UEngineTypes::ConvertToTraceType(ECC_GameTraceChannel1),
			false,
			TArray<AActor*>(),
			EDrawDebugTrace::ForOneFrame,
			Hit,
			true))
		{
			UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, HitParticle, Hit.ImpactPoint);
		}
		OtherActor->TakeDamage(10.f, FDamageEvent(), nullptr, nullptr);
	}
}

void AWeapon_Spawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
