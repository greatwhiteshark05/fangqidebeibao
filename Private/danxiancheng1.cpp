// Fill out your copyright notice in the Description page of Project Settings.


#include "danxiancheng1.h"
#include "deng.h"

danxiancheng1::danxiancheng1(Adeng* shandeng)
{
	this->shandeng = shandeng;
}

bool danxiancheng1::Init()
{
	GEngine->AddOnScreenDebugMessage(-1,10,FColor::Red,TEXT("初始"));
	if(IsValid(shandeng))
	{
		
		return true;
	}
	
	return false;
	return FRunnable::Init();
}

uint32 danxiancheng1::Run()
{
	GEngine->AddOnScreenDebugMessage(-1,10,FColor::Red,TEXT("运行"));
	
	shandeng->liangdeng();
	return 0;
}

void danxiancheng1::Stop()
{
	GEngine->AddOnScreenDebugMessage(-1,10,FColor::Red,TEXT("暂停"));
	UE_LOG(LogScript,Error,TEXT("我真的暂停了"));
	FRunnable::Stop();
}

void danxiancheng1::Exit()
{
	GEngine->AddOnScreenDebugMessage(-1,10,FColor::Red,TEXT("退出"));
	UE_LOG(LogScript,Error,TEXT("我真的退出了"));
	FRunnable::Exit();
}

danxiancheng1::danxiancheng1()
{
}

danxiancheng1::~danxiancheng1()
{
}
