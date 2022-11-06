// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Equipment_Spawn.generated.h"

UCLASS()
class THIRDPERSONGAME_API AEquipment_Spawn : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEquipment_Spawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* EquipmentMeshComponent;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UStaticMeshComponent* GetEquipmentMeshComponent() { return EquipmentMeshComponent; }
};
