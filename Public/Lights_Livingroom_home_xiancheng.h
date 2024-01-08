// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Lights_Livingroom_home.h"
#include  "Engine/SpotLight.h"
#include "CoreMinimal.h"

/**
 * 
 */
class RIDER_API Lights_Livingroom_home_xiancheng:public FRunnable
{
public:
	Lights_Livingroom_home_xiancheng(ALights_Livingroom_home *shandeng);
	virtual bool Init() override;
	virtual uint32 Run() override;
	virtual void Stop() override;
	virtual  void Exit() override;
	ALights_Livingroom_home*shandeng;
	Lights_Livingroom_home_xiancheng();
	~Lights_Livingroom_home_xiancheng();
};
