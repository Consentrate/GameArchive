// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MenuController.generated.h"

/**
 * ��ʼ�ؿ��Ľ�ɫ������
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
