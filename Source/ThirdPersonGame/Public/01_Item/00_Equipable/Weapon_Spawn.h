// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "01_Item/00_Equipable/Equipment_Spawn.h"
#include "Weapon_Spawn.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPERSONGAME_API AWeapon_Spawn : public AEquipment_Spawn
{
	GENERATED_BODY()
	
protected:
	AWeapon_Spawn();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
