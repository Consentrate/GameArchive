// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataInfo.h"



/**
 * ���ݹ�����
 */
class SAVEGAMEDEMO_API FDataHandle
{
public:
	static TSharedPtr<FDataHandle> Get();

	/** ��ʼ����Ϸ���� */
	void InitializeGameData();

public:
	/** �޸ı������� */
	void ChangeLocalizationCulture(ECultureTeam Culture);
	/** �޸Ĳ˵����� */
	void SetMenuVolume(float MusicVol, float SoundVol);
	/** �޸���Ϸ���� */
	void SetGameVolume(float MusicVol, float SoundVol);
	/** ����´浵�� */
	void AddNewRecord();
private:
	/** ���´浵�ļ����� */
	void UpdateRecordData();

public:

	/** ��ǰ�浵���б� */
	FString CurrentRecordName;

	/** ��ǰ�浵���� */
	FRecordData CurrentRecordData;



private:

	/** ����Enum���ͻ�ȡ�ַ��� */
	template<typename TEnum>
	FString GetEnumValueAsString(const FString& Name, TEnum Value);
	/** �����ַ�����ȡEnumֵ */
	template<typename TEnum>
	TEnum GetEnumValueFromString(const FString& Name, FString Value);


	/** ��ʼ���浵���� */
	void InitRecordData();
	/** ��ʼ��Menu�������� */
	void InitMenuAudio();



public:
	FDataHandle();
private:
	static void Initialize();
	static TSharedRef<FDataHandle> Create();
private:
	static TSharedPtr<FDataHandle> DataInstance;
};


template<typename TEnum>
FString FDataHandle::GetEnumValueAsString(const FString& Name, TEnum Value)
{
	const UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, *Name, true);
	if (!EnumPtr) 
	{
		return FString("InValid");
	}
	return EnumPtr->GetEnumName((int32)Value);
}

template<typename TEnum>
TEnum FDataHandle::GetEnumValueFromString(const FString& Name, FString Value)
{
	const UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, *Name, true);
	if (!EnumPtr) 
	{
		return TEnum(0);
	}
	return (TEnum)EnumPtr->GetIndexByName(FName(*FString(Value)));
}

