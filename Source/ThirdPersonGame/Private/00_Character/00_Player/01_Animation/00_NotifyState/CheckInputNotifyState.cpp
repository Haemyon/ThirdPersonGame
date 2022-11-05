// Fill out your copyright notice in the Description page of Project Settings.


#include "00_Character/00_Player/01_Animation/00_NotifyState/CheckInputNotifyState.h"

#include "00_Character/99_Component/StatusComponent.h"
#include "00_Character/00_Player/PlayerCharacter.h"

UCheckInputNotifyState::UCheckInputNotifyState()
{
	bIsNativeBranchingPoint = true;
}

void UCheckInputNotifyState::BranchingPointNotifyBegin(FBranchingPointNotifyPayload& BranchingPointPayload)
{
	Super::BranchingPointNotifyBegin(BranchingPointPayload);
	bContinue = false;
	Player = BranchingPointPayload.SkelMeshComponent->GetOwner<APlayerCharacter>();
}

void UCheckInputNotifyState::BranchingPointNotifyTick(FBranchingPointNotifyPayload& BranchingPointPayload, float FrameDeltaTime)
{
	Super::BranchingPointNotifyTick(BranchingPointPayload, FrameDeltaTime);
	if (Player != nullptr)
	{
		if (bContinue == false)
		{
			if (Player->bPressAttack)
			{
				bContinue = true;
			}
		}
	}
}

void UCheckInputNotifyState::BranchingPointNotifyEnd(FBranchingPointNotifyPayload& BranchingPointPayload)
{
	Super::BranchingPointNotifyEnd(BranchingPointPayload);
	if (Player != nullptr)
	{
		if (bContinue)
		{
			if (Player->GetStatusComponent()->CheckSP(25.f))
			{
				Player->GetStatusComponent()->AddSP(-25.f);
				BranchingPointPayload.SkelMeshComponent->GetAnimInstance()->Montage_JumpToSection(NextSection);
				return;
			}
		}
		BranchingPointPayload.SkelMeshComponent->GetAnimInstance()->Montage_Stop(0.1f);
		Player->SetActionState(EActionState::NORMAL);
	}
}
