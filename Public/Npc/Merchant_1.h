// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"

#include "rider/riderCharacter.h"//这句放在后面就出错了
#include "GameFramework/Character.h"
#include "Merchant_1.generated.h"

UCLASS()
class RIDER_API AMerchant_1 : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMerchant_1();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void OnInteract(AriderCharacter *a);

	void OnShopClose();

	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mantra")//需要在蓝图中修改生成实例类型时使用,暴露给蓝图,只可修改默认值,分栏为Custom
	TArray<TSubclassOf<AMasterItem>> Offer;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Mantra")
	USphereComponent *SphereComponent;
	UFUNCTION()
	void jinru(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void chulai(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex);
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mantra")//需要
	UWidgetComponent* WidgetComponent;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)//需要
	UWidgetComponent* WidgetComponent2;
	//UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mantra")//需要
	//USkeletalMesh 
	//UWidgetComponent* WidgetComponent;
	//UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mantra")//需要
	//UStaticMeshComponent *MeshComponent;
};
