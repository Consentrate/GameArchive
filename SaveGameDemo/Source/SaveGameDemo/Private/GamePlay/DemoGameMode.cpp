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
	//������tick����
	PrimaryActorTick.bCanEverTick = true;

	PlayerControllerClass = ADemoPlayerController::StaticClass();
	HUDClass = UMainWidget::StaticClass();

	//��ʼ���ò��ܹ����ش浵
	bEnableLoadRecord = true;
}

void ADemoGameMode::SaveGame()
{
	//����浵����Default,�����б���
	if (FDataHandle::Get()->CurrentRecordName.Equals(FString("Default"))) return;

	//����һ���´浵
	UDemoSaveGame* NewRecord = Cast<UDemoSaveGame>(UGameplayStatics::CreateSaveGameObject(UDemoSaveGame::StaticClass()));
	NewRecord->TestString = "woyeshizuile";

	//����浵
	UGameplayStatics::SaveGameToSlot(NewRecord, FDataHandle::Get()->CurrentRecordName, 0);

	//�鿴json�Ƿ��Ѿ�������浵
	bool IsRecordExist = false;
	for (TArray<FString>::TIterator It(FDataHandle::Get()->CurrentRecordData.RecordNameList); It; ++It)
	{
		//ֻҪ��һ����ͬ,������
		if ((*It).Equals(FDataHandle::Get()->CurrentRecordName)) {
			IsRecordExist = true;
			break;
		}
	}
	//����浵������,�����ݹ�������Ӵ浵��json
	if (!IsRecordExist) FDataHandle::Get()->AddNewRecord();
}

void ADemoGameMode::BeginPlay()
{
	//��ʼ����Ϸ����
	FDataHandle::Get()->InitializeGameData();

	//��������


	//���ش浵
	LoadRecord();
}

void ADemoGameMode::LoadRecord()
{
	if (FDataHandle::Get()->CurrentRecordName.IsEmpty() || FDataHandle::Get()->CurrentRecordName.Equals(FString("Default")))
	{
		return;
	}

	//�����浵�Ƿ����
	for (TArray<FString>::TIterator It(FDataHandle::Get()->CurrentRecordData.RecordNameList); It; ++It)
	{
		//����һ����ͬ�ľ����ÿ��Լ��ش浵��������
		if ((*It).Equals(FDataHandle::Get()->CurrentRecordName))
		{
			bEnableLoadRecord = true;
			break;
		}
	}

	//������Լ��أ����Ҵ浵���ڣ����м���
	if (bEnableLoadRecord && UGameplayStatics::DoesSaveGameExist(FDataHandle::Get()->CurrentRecordName, 0))
	{
		GameRecord = Cast<UDemoSaveGame>(UGameplayStatics::LoadGameFromSlot(FDataHandle::Get()->CurrentRecordName, 0));
	}
	else
	{
		bEnableLoadRecord = false;
	}

	//������Լ��أ����Ҵ浵���سɹ���������Ϸ��������
	if (bEnableLoadRecord && GameRecord)
	{
		//�������λ�ú�Ѫ��

		//ѭ�����õ���

		//ѭ��������Դ

		//������
		FString testt = GameRecord->TestString;
		GEngine->AddOnScreenDebugMessage(-1, 30, FColor::Black, testt);

	}
}
