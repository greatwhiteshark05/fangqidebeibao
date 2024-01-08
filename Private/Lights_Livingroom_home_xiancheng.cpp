// Fill out your copyright notice in the Description page of Project Settings.


#include "Lights_Livingroom_home_xiancheng.h"
#include "Lights_Livingroom_home.h"

Lights_Livingroom_home_xiancheng::Lights_Livingroom_home_xiancheng(ALights_Livingroom_home* shandeng)
{
	this->shandeng = shandeng;
}

bool Lights_Livingroom_home_xiancheng::Init()
{
	GEngine->AddOnScreenDebugMessage(-1,10,FColor::Red,TEXT("初始"));
	if(IsValid(shandeng))
	{
		
		return true;
	}
	
	return false;
	return FRunnable::Init();
}

uint32 Lights_Livingroom_home_xiancheng::Run()
{
	GEngine->AddOnScreenDebugMessage(-1,10,FColor::Red,TEXT("运行"));
	
	shandeng->liangdeng();
	return 0;
}

void Lights_Livingroom_home_xiancheng::Stop()
{
	GEngine->AddOnScreenDebugMessage(-1,10,FColor::Red,TEXT("暂停"));
	UE_LOG(LogScript,Error,TEXT("我真的暂停了"));
	FRunnable::Stop();
}

void Lights_Livingroom_home_xiancheng::Exit()
{
	GEngine->AddOnScreenDebugMessage(-1,10,FColor::Red,TEXT("退出"));
	UE_LOG(LogScript,Error,TEXT("我真的退出了"));
	FRunnable::Exit();
}

Lights_Livingroom_home_xiancheng::Lights_Livingroom_home_xiancheng()
{
}

Lights_Livingroom_home_xiancheng::~Lights_Livingroom_home_xiancheng()
{
}
