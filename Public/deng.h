// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "MyInterface2.h"
#include "CoreMinimal.h"
#include "Components/SpotLightComponent.h"
#include "GameFramework/Actor.h"


#include "deng.generated.h"

UCLASS()
class RIDER_API Adeng : public AActor,public IMyInterface2
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Adeng();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere)
	class USpotLightComponent *deng;
	UFUNCTION(Blueprintable)
	void liangdeng();
	UFUNCTION(Blueprintable)
	void guandeng();
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* denggan;
	UPROPERTY(EditAnywhere)
	class USceneComponent* MyDoor;

	//void Interact_Implementation(APawn* InstigatorPawn);
};
