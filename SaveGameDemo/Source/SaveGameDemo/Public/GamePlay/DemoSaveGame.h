// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "DemoSaveGame.generated.h"

/**
 * 保存游戏对象的类
 */
UCLASS()
class SAVEGAMEDEMO_API UDemoSaveGame : public USaveGame
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere)
	FString TestString;

};
