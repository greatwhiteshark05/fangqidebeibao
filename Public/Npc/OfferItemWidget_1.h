// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/Slider.h"
#include "Components/TextBlock.h"
#include "UserWidget/InventorySlot.h"
#include "OfferItemWidget_1.generated.h"

/**
 * 
 */
UCLASS()
class RIDER_API UOfferItemWidget_1 : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual void NativeConstruct() override;
	UPROPERTY(meta = (BindWidget))
	UButton *BuyButton;
	UPROPERTY(meta = (BindWidget))
	UImage *Icon;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Mantra")
	FString Icon2dizhi2;
	UPROPERTY(meta = (BindWidget))
	UImage *Icon3;
	UPROPERTY(meta = (BindWidget))
	UTextBlock *NameText;
	UPROPERTY(meta = (BindWidget))
	UTextBlock *PriceText;
	UPROPERTY(meta = (BindWidget))
	UTextBlock *AmountText;
	UPROPERTY(meta = (BindWidget))
	USlider *AmountSlider;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Mantra")
	UTexture2D *Icon2;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mantra")
	UInventorySlot *ItemInfo;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mantra")
	int CurrentAmount=1;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mantra")
	int MaxAmountToBuy=99;
	UFUNCTION(BlueprintCallable,Category="Custom|myfun")
	void UpdatePrice();//没做，88集后一半部分
	UFUNCTION(BlueprintCallable,Category="Custom|myfun")
	void Init();
	UFUNCTION(BlueprintCallable,Category="Custom|myfun")
	void huatiao(float ad);
	UFUNCTION(BlueprintCallable,Category="Custom|myfun")
	void Buy();
	UFUNCTION(BlueprintCallable,Category="Custom|myfun")
	void CheckGold();//90
};

