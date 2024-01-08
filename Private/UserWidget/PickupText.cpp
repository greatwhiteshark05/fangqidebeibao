// Fill out your copyright notice in the Description page of Project Settings.


#include "UserWidget/PickupText.h"

void UPickupText::NativeConstruct()
{
	Super::NativeConstruct();
	//必须绑定在这里，写在 UInventory::ShowInventory()里没用
	//Button_0->OnClicked.AddDynamic(this, &UInventory::HideInventory);

}