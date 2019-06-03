// Fill out your copyright notice in the Description page of Project Settings.


#include "DemoPlayerController.h"

ADemoPlayerController::ADemoPlayerController()
{
	//允许每帧运行
	PrimaryActorTick.bCanEverTick = true;
}

void ADemoPlayerController::BeginPlay()
{
	Super::BeginPlay();

	//设置鼠标不显示
	bShowMouseCursor = false;
	//设置输入模式
	FInputModeGameOnly InputMode;
	InputMode.SetConsumeCaptureMouseDown(true);
	SetInputMode(InputMode);
}
