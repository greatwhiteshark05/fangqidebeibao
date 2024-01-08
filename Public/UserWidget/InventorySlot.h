// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
//#include "S_Iteminfo.h"
#include "E_ItemCategory.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/CanvasPanel.h"
#include "Components/Image.h"
#include "Components/ScrollBox.h"
#include "Components/TextBlock.h"
#include "InventorySlot.generated.h"
/**
 * 
 */
//DECLARE_EVENT(UInventorySlot,UpdateSlot)
//UCLASS(Blueprintable,NotBlueprintType)
UCLASS(Blueprintable)
class RIDER_API UInventorySlot : public UUserWidget
{
	GENERATED_BODY()
	
public:
	bool Initialize();
	virtual void NativeConstruct() override;
	void Init();
	UPROPERTY(meta = (BindWidget),BlueprintReadWrite)
	UButton* SlotButton;
	UPROPERTY(meta = (BindWidget),BlueprintReadWrite)
	UImage *Icon;
	UPROPERTY(meta = (BindWidget),BlueprintReadWrite)
	UTextBlock *Text;
	int Index;//外界告知索引，每个格子索引不变
	int Amount;//数量
	//给Text的文字创建绑定，可能有问题
	UFUNCTION(meta = (BindWidget))
	UTextBlock *SetText2();
	//创建绑定，可能有问题
	ESlateVisibility  SetVisiblty();
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Mantra")
	int Dutebianhao;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mantra")
	FText Name;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mantra")
	FText Description;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Mantra")
	UTexture2D *Icon2;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Mantra")
	FText Icon2dizhi;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Mantra")
	FString Icon2dizhi2;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Mantra")
	bool CanbuUse;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mantra")
	FText UseText;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Mantra")
	bool CanbeStacked;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Mantra")
	E_ItemCategory Category;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mantra")
	int Amount2;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mantra")
	int Value=20;

	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	
};
