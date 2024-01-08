// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/Pawn.h"
#include "MyInterface.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FDelegate,bool)//!!!

#include "MyPawn.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
UCLASS()
class RIDER_API AMyPawn : public APawn,public IMyInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	//virtual void SetupInputComponent()override;
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* MyDoorMesh;
	UPROPERTY(EditAnywhere)
	class USceneComponent* MyDoor;
	UPROPERTY(EditAnywhere)
	class UBoxComponent* Box;
	UFUNCTION()
	void xiaohui(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void FFF(const FInputActionValue& Value);
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Input",meta = (AllowPrivateAccess="true"))
	class UInputMappingContext *DefaultMappingContext;
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Input",meta = (AllowPrivateAccess="true"))
	class UInputAction *FFFAction;
	//virtual void SetupInputComponent()override;
	UFUNCTION()
	void Interact_Implementation(APawn* InstigatorPawn);
	//FDelegate MyDelegate;//!!!加了这句就会卡
	//bool UIshezhi;
	//int64 timestamp ;
};
