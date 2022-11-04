// Fill out your copyright notice in the Description page of Project Settings.


#include "00_Character/99_Component/StatusComponent.h"

#include "00_Character/BaseCharacter.h"
#include "00_Character/00_Player/PlayerCharacter.h"

// Sets default values for this component's properties
UStatusComponent::UStatusComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UStatusComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


void UStatusComponent::AddSP(float Value)
{
	SP = FMath::Clamp(SP + Value, 0.f, MaxSP);
	GetOwner<ABaseCharacter>()->OnChangedSP.Broadcast(this);
}

bool UStatusComponent::CheckSP(float Value)
{
	return SP >= Value;
}

// Called every frame
void UStatusComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	EActionState State = GetOwner<ABaseCharacter>()->GetActionState();
	if (State == EActionState::RUN)
	{
		const float needSP = 10 * DeltaTime;
		if (CheckSP(needSP)) {
			AddSP(-needSP);
		}
		else
		{
			if (GetOwner()->IsA<APlayerCharacter>())
			{
				GetOwner<APlayerCharacter>()->StopRun();
			}
		}
	}
	else if (State == EActionState::NORMAL)
	{
		AddSP(6.f * DeltaTime);
	}
}

