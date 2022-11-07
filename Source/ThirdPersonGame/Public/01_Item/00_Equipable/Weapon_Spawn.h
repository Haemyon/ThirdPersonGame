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

	//히트된 대상을 저장하는 Actor포인터 배열입니다.
	UPROPERTY()
		TArray<AActor*> HitActors;
public:
	//히트된 대상을 저장합니다.
	void AddUniqueHitActor(AActor* HitActor);
	//이미 히트된 대상인지 확인합니다. 히트된 대상이면 참
	bool IsAlreadyHitActor(AActor* HitActor);
	//히트 액터 배열을 비웁니다.
	void ClearHitActors();

protected:
	virtual void BeginPlay() override;

	virtual void PostInitializeComponents() override;

	UFUNCTION()
		void OnActorBeginOverlapEvent(AActor* OverlappedActor, AActor* OtherActor);

public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		class UNiagaraSystem* HitParticle;
};
