// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainWidget.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPERSONGAME_API UMainWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY()
		class UPlayerProgressWidget* UMG_PlayerProgress;

public:
	UFUNCTION()
		void UpdateHPPercent(class UStatusComponent* StatComp);
	UFUNCTION()
		void UpdateSPPercent(class UStatusComponent* StatComp);
};
