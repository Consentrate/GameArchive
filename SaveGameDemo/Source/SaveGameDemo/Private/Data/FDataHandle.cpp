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
	//切换语言
	switch (Culture)
	{
	case ECultureTeam::EN:
		FInternationalization::Get().SetCurrentCulture(TEXT("en"));
		break;
	case ECultureTeam::ZH:
		FInternationalization::Get().SetCurrentCulture(TEXT("zh"));
		break;
	}
	//修改当前存档语言
	CurrentRecordData.Culture = Culture;
	//更新存档文件数据
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
	//添加新的存档名
	CurrentRecordData.RecordNameList.Emplace(CurrentRecordName);
	//更新存档文件数据
	UpdateRecordData();
}

void FDataHandle::UpdateRecordData()
{
	FSingleton<FJsonHandle>::Get()->SaveArchiveFile<FRecordData>(RECORDDATAFILENAME, CurrentRecordData);
}

void FDataHandle::InitRecordData()
{
	//初始化当前存档名
	CurrentRecordName = "";

	//加载本地存档文件，并缓存数据到CurrentRecordData
	FSingleton<FJsonHandle>::Get()->LoadArchiveFile<FRecordData>(RECORDDATAFILENAME, CurrentRecordData);

	//初始化语言
	ChangeLocalizationCulture(CurrentRecordData.Culture);
}

void FDataHandle::InitMenuAudio()
{

}

FDataHandle::FDataHandle()
{
	//初始化存档数据
	InitRecordData();
	//初始化菜单音乐
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

