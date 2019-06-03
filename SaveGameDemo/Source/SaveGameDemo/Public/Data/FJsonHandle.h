// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "JsonUtilities/Public/JsonObjectConverter.h"
#include "DataInfo.h"

/**
 * Json������
 */
class SAVEGAMEDEMO_API FJsonHandle
{
public:

	/** ���ش浵�ļ� */
	template<typename StructType>
	void LoadArchiveFile(FString FileName, StructType& Data);

	/** ����浵�ļ� */
	template<typename StructType>
	void SaveArchiveFile(FString FileName, const StructType& Data);

private:

	/** ��ȡJson�ļ����ַ��� */
	bool LoadStringFromFile(const FString& FileName, const FString& RelaPath, FString& ResultString);

	/** �����ַ�����Json�ļ� */
	bool SaveStringToFile(const FString& FileName, const FString& RelaPath, const FString& JsonString);
};



template<typename StructType>
void FJsonHandle::LoadArchiveFile(FString FileName, StructType& Data)
{
	FString JsonString = "";
	if (LoadStringFromFile(FileName, ARCHIVEFILE_RELATIVEPATH, JsonString))
	{
		FJsonObjectConverter::JsonObjectStringToUStruct(JsonString, &Data, 0, 0);
	}
}

template<typename StructType>
void FJsonHandle::SaveArchiveFile(FString FileName, const StructType& Data)
{
	FString JsonString = "";
	if (FJsonObjectConverter::UStructToJsonObjectString(Data, JsonString))
	{
		SaveStringToFile(FileName, ARCHIVEFILE_RELATIVEPATH, JsonString);
	}
}
