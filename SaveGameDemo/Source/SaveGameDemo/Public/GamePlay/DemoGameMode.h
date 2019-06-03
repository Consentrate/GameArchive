// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DemoGameMode.generated.h"

/**
 * ���ؿ�����Ϸģʽ��
 */
UCLASS()
class SAVEGAMEDEMO_API ADemoGameMode : public AGameModeBase
{
	GENERATED_BODY()
public:
	ADemoGameMode();

	/** ������Ϸ */
	//UFUNCTION(BlueprintCallable)
	void SaveGame();

protected:

	virtual void BeginPlay() override;

	/** ���ش浵 */
	void LoadRecord();

private:

	/** �Ƿ��ܹ����ش浵 */
	bool bEnableLoadRecord;

	/** ��Ϸ�浵ָ�� */
	class UDemoSaveGame* GameRecord;
};
