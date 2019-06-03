// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MenuController.generated.h"

/**
 * 开始关卡的角色控制类
 */
UCLASS()
class SAVEGAMEDEMO_API AMenuController : public APlayerController
{
	GENERATED_BODY()

public:
	AMenuController();

protected:

	virtual void BeginPlay() override;
};
