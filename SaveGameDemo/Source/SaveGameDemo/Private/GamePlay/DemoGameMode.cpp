// Fill out your copyright notice in the Description page of Project Settings.


#include "DemoGameMode.h"
#include "FDataHandle.h"
#include "DemoSaveGame.h"

#include "MainWidget.h"
#include "Player/DemoPlayerController.h"

#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"

ADemoGameMode::ADemoGameMode()
{	
	//允许开启tick函数
	PrimaryActorTick.bCanEverTick = true;

	PlayerControllerClass = ADemoPlayerController::StaticClass();
	HUDClass = UMainWidget::StaticClass();

	//开始设置不能够加载存档
	bEnableLoadRecord = true;
}

void ADemoGameMode::SaveGame()
{
	//如果存档名是Default,不进行保存
	if (FDataHandle::Get()->CurrentRecordName.Equals(FString("Default"))) return;

	//创建一个新存档
	UDemoSaveGame* NewRecord = Cast<UDemoSaveGame>(UGameplayStatics::CreateSaveGameObject(UDemoSaveGame::StaticClass()));
	NewRecord->TestString = "woyeshizuile";

	//保存存档
	UGameplayStatics::SaveGameToSlot(NewRecord, FDataHandle::Get()->CurrentRecordName, 0);

	//查看json是否已经有这个存档
	bool IsRecordExist = false;
	for (TArray<FString>::TIterator It(FDataHandle::Get()->CurrentRecordData.RecordNameList); It; ++It)
	{
		//只要有一个相同,就跳出
		if ((*It).Equals(FDataHandle::Get()->CurrentRecordName)) {
			IsRecordExist = true;
			break;
		}
	}
	//如果存档不存在,让数据管理类添加存档到json
	if (!IsRecordExist) FDataHandle::Get()->AddNewRecord();
}

void ADemoGameMode::BeginPlay()
{
	//初始化游戏数据
	FDataHandle::Get()->InitializeGameData();

	//播放音乐


	//加载存档
	LoadRecord();
}

void ADemoGameMode::LoadRecord()
{
	if (FDataHandle::Get()->CurrentRecordName.IsEmpty() || FDataHandle::Get()->CurrentRecordName.Equals(FString("Default")))
	{
		return;
	}

	//遍历存档是否存在
	for (TArray<FString>::TIterator It(FDataHandle::Get()->CurrentRecordData.RecordNameList); It; ++It)
	{
		//存在一个相同的就设置可以加载存档，并跳出
		if ((*It).Equals(FDataHandle::Get()->CurrentRecordName))
		{
			bEnableLoadRecord = true;
			break;
		}
	}

	//如果可以加载，并且存档存在，进行加载
	if (bEnableLoadRecord && UGameplayStatics::DoesSaveGameExist(FDataHandle::Get()->CurrentRecordName, 0))
	{
		GameRecord = Cast<UDemoSaveGame>(UGameplayStatics::LoadGameFromSlot(FDataHandle::Get()->CurrentRecordName, 0));
	}
	else
	{
		bEnableLoadRecord = false;
	}

	//如果可以加载，并且存档加载成功，进行游戏内容设置
	if (bEnableLoadRecord && GameRecord)
	{
		//设置玩家位置和血量

		//循环设置敌人

		//循环设置资源

		//测试用
		FString testt = GameRecord->TestString;
		GEngine->AddOnScreenDebugMessage(-1, 30, FColor::Black, testt);

	}
}
