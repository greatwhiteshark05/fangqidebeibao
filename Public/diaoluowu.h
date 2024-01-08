// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyInterface.h"
#include "diaoluowu.generated.h"
UCLASS()
class RIDER_API Adiaoluowu : public AActor,public IMyInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Adiaoluowu();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* MyDoorMesh;
	UPROPERTY(EditAnywhere)
	class USceneComponent* MyDoor;
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
};
