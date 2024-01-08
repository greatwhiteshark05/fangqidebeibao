// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Merchant_1.h"
#include "OfferItemWidget_1.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/UniformGridPanel.h"
#include "ShopWidget_1.generated.h"

/**
 * 
 */
UCLASS()
class RIDER_API UShopWidget_1 : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual void NativeConstruct() override;
	UPROPERTY(meta = (BindWidget))
	UButton *CloseButton;
	UPROPERTY(meta = (BindWidget))
	UTextBlock *PriceText;
	UPROPERTY(meta = (BindWidget))
	UUniformGridPanel *GridPanel;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mantra")
	AMerchant_1 *Merchant;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mantra")
	TArray<UOfferItemWidget_1*>OfferItemWidget;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mantra")
	ACharacter *TopCharacter;
	//92,2;09出售没做
	UFUNCTION(BlueprintCallable,Category="Custom|myfun")
	void GenerateOfferList();
};
