// Fill out your copyright notice in the Description page of Project Settings.


#include "deng.h"

#include "MyPawn.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "rider/riderGameMode.h"

// Sets default values
Adeng::Adeng()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MyDoor = CreateDefaultSubobject<USceneComponent>(TEXT("My Door"));
	denggan = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("我的灯杆"));
	deng=CreateDefaultSubobject<USpotLightComponent>(TEXT("我的路灯"));
	deng->SetupAttachment(MyDoor);
	denggan->SetupAttachment(MyDoor);
	deng->SetVisibility(0);
	
}
// Called when the game starts or when spawned
void Adeng::BeginPlay()
{
	Super::BeginPlay();
	deng->SetVisibility(0);
	
		
}

// Called every frame
void Adeng::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void Adeng::liangdeng()
{
	if(deng->GetVisibleFlag()==0)
	{
		deng->SetVisibility(1);
	}else
	{
		deng->SetVisibility(0);
	}
	
	
}

void Adeng::guandeng()
{
	deng->SetVisibility(0);
}
/*
void Adeng::Interact_Implementation(APawn* InstigatorPawn)
{
	if (GetWorld())
	{
		UE_LOG(LogTemp, Error, TEXT("灯也有UIle "));
		
	}


}*/