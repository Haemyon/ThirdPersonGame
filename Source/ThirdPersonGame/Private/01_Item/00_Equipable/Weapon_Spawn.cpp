// Fill out your copyright notice in the Description page of Project Settings.


#include "01_Item/00_Equipable/Weapon_Spawn.h"

AWeapon_Spawn::AWeapon_Spawn()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AWeapon_Spawn::BeginPlay()
{
	Super::BeginPlay();
}

void AWeapon_Spawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
