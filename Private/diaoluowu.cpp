// Fill out your copyright notice in the Description page of Project Settings.


#include "diaoluowu.h"
#include "Components/SphereComponent.h"
#include "Components/BoxComponent.h"
#include "Particles/ParticleSystemComponent.h"
// Sets default values
Adiaoluowu::Adiaoluowu()
{
	MyDoor = CreateDefaultSubobject<USceneComponent>(TEXT("My Door"));
	MyDoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My DoorMesh"));
	MyDoorMesh->SetupAttachment(MyDoor);
	
	SetRootComponent (MyDoor);
	

}

// Called when the game starts or when spawned
void Adiaoluowu::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Adiaoluowu::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
