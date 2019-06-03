// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DemoGameMode.generated.h"

/**
 * 主关卡的游戏模式类
 */
UCLASS()
class SAVEGAMEDEMO_API ADemoGameMode : public AGameModeBase
{
	GENERATED_BODY()
public:
	ADemoGameMode();

	/** 保存游戏 */
	//UFUNCTION(BlueprintCallable)
	void SaveGame();

protected:

	virtual void BeginPlay() override;

	/** 加载存档 */
	void LoadRecord();

private:

	/** 是否能够加载存档 */
	bool bEnableLoadRecord;

	/** 游戏存档指针 */
	class UDemoSaveGame* GameRecord;
};
