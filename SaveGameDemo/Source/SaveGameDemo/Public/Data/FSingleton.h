// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * µ¥ÀýÄ£°åÀà
 */
template<class T>
class SAVEGAMEDEMO_API FSingleton
{
public:
	
	static TSharedPtr<T> Get();

private:

	static void Initialize();

	static TSharedPtr<T> Create();

private:

	static TSharedPtr<T> TInstance;
};



template<class T>
TSharedPtr<T> FSingleton<T>::TInstance = NULL;

template<class T>
TSharedPtr<T> FSingleton<T>::Create()
{
	TSharedPtr<T> TRef = MakeShareable(new T());
	return TRef;
}

template<class T>
void FSingleton<T>::Initialize()
{
	if (!TInstance.IsValid())
	{
		TInstance = Create();
	}
}

template<class T>
TSharedPtr<T> FSingleton<T>::Get()
{
	Initialize();
	return TInstance;
}


