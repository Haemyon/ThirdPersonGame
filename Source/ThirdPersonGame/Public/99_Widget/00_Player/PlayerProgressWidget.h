// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerProgressWidget.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPERSONGAME_API UPlayerProgressWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY()
		class UProgressBar* ProgressBar_HP;
	UPROPERTY()
		class UProgressBar* ProgressBar_SP;

public:

	void UpdateProgressHP(class UStatusComponent* statsComp);
	void UpdateProgressSP(class UStatusComponent* statsComp);
};
