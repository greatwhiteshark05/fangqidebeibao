// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "deng.h"
#include  "Engine/SpotLight.h"
#include "CoreMinimal.h"

/**
 * 
 */
class RIDER_API danxiancheng1:public FRunnable
{
public:
	danxiancheng1(Adeng *shandeng);
	virtual bool Init() override;
	virtual uint32 Run() override;
	virtual void Stop() override;
	virtual  void Exit() override;
	Adeng *shandeng;
	danxiancheng1();
	~danxiancheng1();
};
