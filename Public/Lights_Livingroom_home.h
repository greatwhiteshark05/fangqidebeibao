// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "MyInterface.h"
#include "CoreMinimal.h"
#include "Components/PointLightComponent.h"
#include "GameFramework/Actor.h"
#include "Lights_Livingroom_home.generated.h"

UCLASS()
class RIDER_API ALights_Livingroom_home : public AActor,public IMyInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALights_Livingroom_home();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere)
	class UPointLightComponent *deng;
	UFUNCTION(Blueprintable)
	void liangdeng();
	
	
};
