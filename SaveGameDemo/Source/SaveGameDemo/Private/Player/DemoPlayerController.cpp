// Fill out your copyright notice in the Description page of Project Settings.


#include "DemoPlayerController.h"

ADemoPlayerController::ADemoPlayerController()
{
	//����ÿ֡����
	PrimaryActorTick.bCanEverTick = true;
}

void ADemoPlayerController::BeginPlay()
{
	Super::BeginPlay();

	//������겻��ʾ
	bShowMouseCursor = false;
	//��������ģʽ
	FInputModeGameOnly InputMode;
	InputMode.SetConsumeCaptureMouseDown(true);
	SetInputMode(InputMode);
}
