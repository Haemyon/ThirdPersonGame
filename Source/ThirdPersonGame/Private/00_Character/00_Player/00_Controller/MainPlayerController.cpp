// Fill out your copyright notice in the Description page of Project Settings.


#include "00_Character/00_Player/00_Controller/MainPlayerController.h"

#include "99_Widget/00_Player/MainWidget.h"

void AMainPlayerController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);

	if (MainWidgetObject != nullptr)
	{
		MainWidget = CreateWidget<UMainWidget>(this, MainWidgetObject);
		if (MainWidget != nullptr)
		{
			MainWidget->AddToViewport();
		}
	}

}