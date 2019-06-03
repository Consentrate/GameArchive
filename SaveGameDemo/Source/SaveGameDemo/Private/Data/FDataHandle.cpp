// Fill out your copyright notice in the Description page of Project Settings.


#include "FDataHandle.h"
#include "FJsonHandle.h"
#include "FSingleton.h"
#include "Engine/Engine.h"


TSharedPtr<FDataHandle> FDataHandle::DataInstance = NULL;


TSharedPtr<FDataHandle> FDataHandle::Get()
{
	Initialize();
	return DataInstance;
}

void FDataHandle::InitializeGameData()
{

}

void FDataHandle::ChangeLocalizationCulture(ECultureTeam Culture)
{
	//�л�����
	switch (Culture)
	{
	case ECultureTeam::EN:
		FInternationalization::Get().SetCurrentCulture(TEXT("en"));
		break;
	case ECultureTeam::ZH:
		FInternationalization::Get().SetCurrentCulture(TEXT("zh"));
		break;
	}
	//�޸ĵ�ǰ�浵����
	CurrentRecordData.Culture = Culture;
	//���´浵�ļ�����
	UpdateRecordData();
}

void FDataHandle::SetMenuVolume(float MusicVol, float SoundVol)
{

}

void FDataHandle::SetGameVolume(float MusicVol, float SoundVol)
{

}

void FDataHandle::AddNewRecord()
{
	//����µĴ浵��
	CurrentRecordData.RecordNameList.Emplace(CurrentRecordName);
	//���´浵�ļ�����
	UpdateRecordData();
}

void FDataHandle::UpdateRecordData()
{
	FSingleton<FJsonHandle>::Get()->SaveArchiveFile<FRecordData>(RECORDDATAFILENAME, CurrentRecordData);
}

void FDataHandle::InitRecordData()
{
	//��ʼ����ǰ�浵��
	CurrentRecordName = "";

	//���ر��ش浵�ļ������������ݵ�CurrentRecordData
	FSingleton<FJsonHandle>::Get()->LoadArchiveFile<FRecordData>(RECORDDATAFILENAME, CurrentRecordData);

	//��ʼ������
	ChangeLocalizationCulture(CurrentRecordData.Culture);
}

void FDataHandle::InitMenuAudio()
{

}

FDataHandle::FDataHandle()
{
	//��ʼ���浵����
	InitRecordData();
	//��ʼ���˵�����
	InitMenuAudio();
}

void FDataHandle::Initialize()
{
	if (!DataInstance.IsValid())
	{
		DataInstance = Create();
	}
}

TSharedRef<FDataHandle> FDataHandle::Create()
{
	TSharedRef<FDataHandle> DataRef = MakeShareable(new FDataHandle());
	return DataRef;
}

