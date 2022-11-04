// Fill out your copyright notice in the Description page of Project Settings.


#include "99_Widget/00_Player/MainWidget.h"

#include "99_Widget/00_Player/PlayerProgressWidget.h"

void UMainWidget::UpdateHPPercent(UStatusComponent* StatComp)
{
	UMG_PlayerProgress->UpdateProgressHP(StatComp);
}

void UMainWidget::UpdateSPPercent(UStatusComponent* StatComp)
{
	UMG_PlayerProgress->UpdateProgressSP(StatComp);
}
