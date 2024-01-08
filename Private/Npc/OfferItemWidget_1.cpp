// Fill out your copyright notice in the Description page of Project Settings.


#include "Npc/OfferItemWidget_1.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "rider/riderCharacter.h"

void UOfferItemWidget_1::NativeConstruct()
{
	Super::NativeConstruct();
	//AmountSlider->OnValueChanged.AddDynamic(this,UOfferItemWidget_1::huatiao);//有问题
	//zhe里会有问题,因为ItemInfo还没有初始化；
	Init();//这里会有问题
	BuyButton->OnClicked.AddDynamic(this,&UOfferItemWidget_1::Buy);
}

void UOfferItemWidget_1::UpdatePrice()
{
	
}

void UOfferItemWidget_1::Init()
{
	UClass* SpecificBPClassFromCPlusPlus = LoadClass<UInventorySlot>(NULL, TEXT("/Game/blueprints/Widget/BP_InventorySlot.BP_InventorySlot_C"));
	ItemInfo=CreateWidget<UInventorySlot>(this, SpecificBPClassFromCPlusPlus);
	//ItemInfo=CreateWidget(this,)
	ItemInfo->Name=FText::FromString(TEXT("asd"));
	NameText->SetText(ItemInfo->Name);//CreateWidget后即可
	NameText->SetText(FText::FromString(TEXT("adasd")));//这句没问题
	Icon=ItemInfo->Icon;
	PriceText->SetText(FText::FromString(FString::FromInt(ItemInfo->Value)));
	AmountText->SetText(FText::FromString(FString::FromInt(ItemInfo->Amount2)));
	//AmountSlider->OnValueChanged.AddDynamic()只能用于Actor‘
}

void UOfferItemWidget_1::huatiao(float ad)
{
	int Local;
	Local=UKismetMathLibrary::Lerp(1,MaxAmountToBuy,ad);
	Local=UKismetMathLibrary::Round(Local);
	CurrentAmount=Local;
	AmountText->SetText(FText::FromString(FString::FromInt(CurrentAmount)));
	//updateprice
	
}

void UOfferItemWidget_1::Buy()
{//89集最后一点，还没做
	UE_LOG(LogTemp,Error,TEXT("买下来了"));
	AActor *a=UGameplayStatics::GetPlayerPawn(GetWorld(),0);
	
		APlayerController *aa=UGameplayStatics::GetPlayerController(this,0);
	
		AriderCharacter *ab=Cast<AriderCharacter>(UGameplayStatics::GetPlayerCharacter(this,0));
		//ab->InventoryRef->AddItem(ab,InventorySlot->Amount2,this);
		//this->Destroy();//删除的是 指针原本所指的那部分内存而已 指针还可以使用 但是避免野指针
		
		ab->InventoryRef->AddItem3(ab,2,this->ItemInfo);
		
}

void UOfferItemWidget_1::CheckGold()
{
	//，em没做90、
}
