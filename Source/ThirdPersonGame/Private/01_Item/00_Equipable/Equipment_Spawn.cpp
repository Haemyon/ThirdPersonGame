// Fill out your copyright notice in the Description page of Project Settings.


#include "01_Item/00_Equipable/Equipment_Spawn.h"

// Sets default values
AEquipment_Spawn::AEquipment_Spawn()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	EquipmentMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EquipmentMeshComponent"));
	RootComponent = EquipmentMeshComponent;
}

// Called when the game starts or when spawned
void AEquipment_Spawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEquipment_Spawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

