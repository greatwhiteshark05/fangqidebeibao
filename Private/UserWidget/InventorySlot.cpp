// Fill out your copyright notice in the Description page of Project Settings.


#include "UserWidget/InventorySlot.h"

#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Components/CanvasPanel.h"
#include "Components/ScrollBox.h"
#include "Kismet/KismetInputLibrary.h"
#include "Kismet/KismetStringLibrary.h"
#include "Misc/TextBuffer.h"

#include "rider/riderCharacter.h"

bool UInventorySlot::Initialize()
{
	return Super::Initialize();
	this->Name=FText::FromString(TEXT("asd"));
}

void UInventorySlot::NativeConstruct()
{
	Super::NativeConstruct();
	this->Name=FText::FromString(TEXT("asd"));
}

void UInventorySlot::Init()
{
	SlotButton = Cast<UButton>(this->GetWidgetFromName("SlotButton"));
	
	

	
}



UTextBlock *UInventorySlot::SetText2()//给Text的文字创建绑定，可能有问题
{
	//FString TheString = "X"+FString::FromInt(Amount2);
	FString TheString = "hh"+FString::FromInt(9);
	
	Text->SetText(FText::FromString(TheString));
			
	return Text;
}

ESlateVisibility UInventorySlot::SetVisiblty()
{return ESlateVisibility::Hidden;

	/*
	if(InventoryRef->IsSlotEmpty(Index)==1)
	{
		return ESlateVisibility::Hidden;
	}else
	{
		if(Iteminfo->CanbeStacked==1)
		{
			return ESlateVisibility::HitTestInvisible;
		}else
		{
			return ESlateVisibility::Visible;
		}
	}
	*/
}

FReply UInventorySlot::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	if(SlotButton->GetIsEnabled())
	{
		if(UKismetInputLibrary::PointerEvent_IsMouseButtonDown(InMouseEvent,EKeys::RightMouseButton))
		{
			TArray<UUserWidget*> bbb;
			UClass* SpecificBPClassFromCPlusPlus = LoadClass<UInventory>(NULL, TEXT("/Game/blueprints/Widget/BP_Inventory.BP_Inventory_C"));
			UWidgetBlueprintLibrary::GetAllWidgetsOfClass(GetWorld(),bbb,SpecificBPClassFromCPlusPlus,1);
			for(size_t i=0;i<bbb.Num();i++)
			{
				UInventory *bbbb;
				bbbb=Cast<UInventory>(bbb[i]);
				bbbb->OnSlotClick(this);
			}
		}
	}
	return Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);
}


