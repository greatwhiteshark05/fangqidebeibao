// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/Pawn.h"
#include "MyInterface.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FDelegate,bool)//!!!

#include "Lights_Livingroom_home_Switch.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
UCLASS()
class RIDER_API ALights_Livingroom_home_Switch : public APawn,public IMyInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ALights_Livingroom_home_Switch();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//virtual void SetupInputComponent()override;
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* MyDoorMesh;
	UPROPERTY(EditAnywhere)
	class USceneComponent* MyDoor;
	UPROPERTY(EditAnywhere)
	class UBoxComponent* Box;
	UFUNCTION()
	void xiaohui(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Input",meta = (AllowPrivateAccess="true"))
	class UInputMappingContext *DefaultMappingContext;
	
	//virtual void SetupInputComponent()override;
	UFUNCTION()
	void Interact_Implementation(APawn* InstigatorPawn);
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Input")
	bool asd;
	//FDelegate MyDelegate;//!!!加了这句就会卡退
	UFUNCTION()
	void xiaohui2(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	FTimerHandle CountdownTimerHandle;
	void xunhuan();
};
