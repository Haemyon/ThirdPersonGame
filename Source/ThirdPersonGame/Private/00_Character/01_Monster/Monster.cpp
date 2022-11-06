// Fill out your copyright notice in the Description page of Project Settings.


#include "00_Character/01_Monster/Monster.h"

#include "Components/CapsuleComponent.h"

AMonster::AMonster()
{
	GetCapsuleComponent()->SetCollisionProfileName("MonsterPreset");
}
