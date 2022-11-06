// Fill out your copyright notice in the Description page of Project Settings.


#include "98_Animation/00_NotifyState/AttackNotifyState.h"

#include "00_Character/00_Player/PlayerCharacter.h"
#include "01_Item/00_Equipable/Weapon_Spawn.h"

#include "Components/SkeletalMeshComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Components/ChildActorComponent.h"
#include "Kismet/GameplayStatics.h"

void UAttackNotifyState::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration);

	Owner = MeshComp->GetOwner<APlayerCharacter>();
}

void UAttackNotifyState::NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime)
{
	Super::NotifyTick(MeshComp, Animation, FrameDeltaTime);

	if (Owner != nullptr) {

		if (Owner->IsA<APlayerCharacter>())
		{
			auto player = Cast<APlayerCharacter>(Owner);
			AActor* childActor = player->GetWeaponComponent()->GetChildActor();
			if (childActor != nullptr)
			{
				AWeapon_Spawn* weapon = Cast<AWeapon_Spawn>(childActor);
				if (weapon != nullptr)
				{
					FVector StartLocation = weapon->GetEquipmentMeshComponent()->GetSocketLocation(StartSocket);
					FVector EndLocation = weapon->GetEquipmentMeshComponent()->GetSocketLocation(EndSocket);

					TArray<FHitResult> Hits;

					if (UKismetSystemLibrary::SphereTraceMultiForObjects(Owner,
						StartLocation,
						EndLocation,
						Radius,
						ObjectTypes,
						false,
						TArray<AActor*>(),
						EDrawDebugTrace::ForOneFrame,
						Hits, true))
					{
						UE_LOG(LogTemp, Log, TEXT("Hit"));

						for (FHitResult Hit : Hits)
						{
							UGameplayStatics::SpawnEmitterAtLocation(player, player->HitParticle, Hit.Location);
						}
					}
				}
			}
		}
	}
}

void UAttackNotifyState::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::NotifyEnd(MeshComp, Animation);
}
