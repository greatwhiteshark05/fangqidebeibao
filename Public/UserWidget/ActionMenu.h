// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Inventory.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "ActionMenu.generated.h"

/**
 * 
 */
UCLASS()
class RIDER_API UActionMenu : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual void NativeConstruct() override;
	UPROPERTY(meta = (BindWidget))	
	UButton *ThrowButton;
	UPROPERTY(meta = (BindWidget))	
	UButton *HandButton;
	UPROPERTY(meta = (BindWidget))	
    UButton *Button_2;
	UPROPERTY(meta = (BindWidget))	
	UButton *UseButton;
	UPROPERTY(meta = (BindWidget))	
	UTextBlock *UseText;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Mantra")
	int Index=1;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Mantra")
	int Amount;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Mantra")
	UInventory *InventoryRef;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Mantra")
	UInventorySlot *ItemInfo;
	UFUNCTION(BlueprintCallable,Category="Custom|myfun")
	void Update(int Index1);
	UFUNCTION(BlueprintCallable)//不加这一句就不起效果的
	void OnClickedThrowButton();
	UFUNCTION(BlueprintCallable) //不加这一句就不起效果的
	void OnClickedHandButton();
};
