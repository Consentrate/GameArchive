// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataInfo.generated.h"


//�浵���·��
#define ARCHIVEFILE_RELATIVEPATH		TEXT("Res/ConfigData/")
//�浵�ļ���
#define RECORDDATAFILENAME				TEXT("RecordData.json")


/** ���� */
UENUM()
enum class ECultureTeam : uint8 
{
	EN = 0,
	ZH
};


/** ��Ϸ�浵���� */
USTRUCT()
struct FRecordData
{
	GENERATED_BODY()
public:
	FRecordData() {}
	FRecordData(ECultureTeam c, float m, float s, TArray<FString>* r)
		: Culture(c), MusicVolume(m), SoundVolume(s), RecordNameList(*r)
	{}

public:

	UPROPERTY()
	ECultureTeam Culture;

	UPROPERTY()
	float MusicVolume;

	UPROPERTY()
	float SoundVolume;

	UPROPERTY()
	TArray<FString> RecordNameList;
};
