// Fill out your copyright notice in the Description page of Project Settings.


#include "Lights_Livingroom_home.h"

#include "Lights_Livingroom_home_Switch.h"
#include "Kismet/GameplayStatics.h"
#include "rider/riderGameMode.h"

// Sets default values
ALights_Livingroom_home::ALights_Livingroom_home()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	deng=CreateDefaultSubobject<UPointLightComponent>(TEXT("我的路灯"));
	deng->SetVisibility(1);
}
// Called when the game starts or when spawned
void ALights_Livingroom_home::BeginPlay()
{
	Super::BeginPlay();
	deng->SetVisibility(1);

		
}

// Called every frame
void ALights_Livingroom_home::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALights_Livingroom_home::liangdeng()
{
	if(deng->GetVisibleFlag()==0)
	{
		deng->SetVisibility(1);
	}else
	{
		deng->SetVisibility(0);
	}
	
	
}

