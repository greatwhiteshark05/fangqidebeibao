// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "S_Iteminfo.h"
#include "E_ItemCategory.h"
#include "Components/SphereComponent.h"
#include "Components/WidgetComponent.h"
#include "GameFramework/Actor.h"
#include "UserWidget/InventorySlot.h"
#include "MasterItem.generated.h"

struct S_Iteminfo
{
	int Dutebianhao=0;
	
	FText Name=FText::FromString("None");
	FText Description=FText::FromString("None");
	UTexture2D *lcon=nullptr;
	bool CanbuUse=1;
	FText UseText=FText::FromString("None");
	bool CanbeStacked=1;
	E_ItemCategory Category;
	int Amount=0;
};
UCLASS(BlueprintType)
class RIDER_API AMasterItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMasterItem();
	S_Iteminfo Iteminfo;//新加的
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* Sphere;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Mantra")
	USphereComponent *SphereComponent;
	UFUNCTION()
	void jiale(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void chulai(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mantra")
	UInventorySlot *InventorySlot;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void OnUsed();
	UFUNCTION(BlueprintCallable, Category = "BPFunc_Lib")
	void OnUsed2();
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Mantra")
	USkeletalMesh *WeaponMesh1;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Mantra")
	FTransform Transform1;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Mantra")
	FName Name1;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mantra")//需要
	UWidgetComponent* PickUpText;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void UpdateText();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void OnPickUp();//这个函数没有调用
};
