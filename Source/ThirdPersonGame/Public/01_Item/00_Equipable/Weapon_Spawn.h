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

	//��Ʈ�� ����� �����ϴ� Actor������ �迭�Դϴ�.
	UPROPERTY()
		TArray<AActor*> HitActors;
public:
	//��Ʈ�� ����� �����մϴ�.
	void AddUniqueHitActor(AActor* HitActor);
	//�̹� ��Ʈ�� ������� Ȯ���մϴ�. ��Ʈ�� ����̸� ��
	bool IsAlreadyHitActor(AActor* HitActor);
	//��Ʈ ���� �迭�� ���ϴ�.
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
