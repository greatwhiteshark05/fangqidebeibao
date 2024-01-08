// Fill out your copyright notice in the Description page of Project Settings.


#include "Npc/ShopWidget_1.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "UObject/ConstructorHelpers.h"
void UShopWidget_1::NativeConstruct()
{
	Super::NativeConstruct();
	for(int i=0;i<5;i++)
	{
		OfferItemWidget.AddDefaulted();//加一个空白
	}
	//1SetBrushFromTexture这个函数只能在NativeConstruct()中运行，在其他普通函数中不可运行
	//2CreateWidget<UOfferItemWidget_1>和SetBrushFromTexture放在一起即可运行成功，可以放在普通函数里面
	//12均×
	//CreateWidget<UOfferItemWidget_1>和SetBrushFromTexture不放在一起就不起效果啊
	UClass* SpecificBPClassFromCPlusPlus = LoadClass<UOfferItemWidget_1>(this, TEXT("/Game/blueprints/Npc/BP_OfferItemWidget_1.BP_OfferItemWidget_1_C"));
	OfferItemWidget[0]=CreateWidget<UOfferItemWidget_1>(this, SpecificBPClassFromCPlusPlus);
	OfferItemWidget[0]->Icon2=LoadObject<UTexture2D>(this, TEXT("/Game/StarterContent/Textures/T_Brick_Cut_Stone_D.T_Brick_Cut_Stone_D"), NULL, LOAD_None, NULL);
	OfferItemWidget[0]->Icon->SetBrushFromTexture(OfferItemWidget[0]->Icon2,1);
	//OfferItemWidget[0]->ItemInfo->Icon2=LoadObject<UTexture2D>(this, TEXT("/Game/StarterContent/Textures/T_Brick_Cut_Stone_D.T_Brick_Cut_Stone_D"), NULL, LOAD_None, NULL);
	
	UClass* SpecificBPClassFromCPlusPlus1 = LoadClass<UOfferItemWidget_1>(NULL, TEXT("/Game/blueprints/Npc/BP_OfferItemWidget_1.BP_OfferItemWidget_1_C"));
	OfferItemWidget[1]=CreateWidget<UOfferItemWidget_1>(this, SpecificBPClassFromCPlusPlus1);
	OfferItemWidget[1]->Icon2=LoadObject<UTexture2D>(this, TEXT("/Engine/EngineResources/AICON-Red.AICON-Red"), NULL, LOAD_None, NULL);
	OfferItemWidget[1]->Icon->SetBrushFromTexture(OfferItemWidget[1]->Icon2,1);
	//OfferItemWidget[1]->ItemInfo->Icon2=LoadObject<UTexture2D>(this, TEXT("/Engine/EngineResources/AICON-Red.AICON-Red"), NULL, LOAD_None, NULL);
	
	//OfferItemWidget[1]->Icon2=LoadObject<UTexture2D>(NULL, TEXT("/Game/InfinityBladeWeapons/Weapons/Blade/Swords/Blade_Glimmer/T_Blade_Glimmer1_D.T_Blade_Glimmer1_D"));
	
	UClass* SpecificBPClassFromCPlusPlus2 = LoadClass<UOfferItemWidget_1>(NULL, TEXT("/Game/blueprints/Npc/BP_OfferItemWidget_1.BP_OfferItemWidget_1_C"));
	OfferItemWidget[2]=CreateWidget<UOfferItemWidget_1>(this, SpecificBPClassFromCPlusPlus2);
	OfferItemWidget[2]->Icon2=LoadObject<UTexture2D>(NULL, TEXT("/Game/InfinityBladeWeapons/Weapons/Blade/Swords/Blade_Glimmer/T_Blade_Glimmer1_D.T_Blade_Glimmer1_D"));
	
	OfferItemWidget[2]->Icon->SetBrushFromTexture(OfferItemWidget[2]->Icon2,1);
	OfferItemWidget[2]->Icon3=OfferItemWidget[2]->Icon;
	UClass* SpecificBPClassFromCPlusPlus3 = LoadClass<UOfferItemWidget_1>(NULL, TEXT("/Game/blueprints/Npc/BP_OfferItemWidget_1.BP_OfferItemWidget_1_C"));
	OfferItemWidget[3]=CreateWidget<UOfferItemWidget_1>(this, SpecificBPClassFromCPlusPlus3);
	OfferItemWidget[3]->Icon2=LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Engine/EngineResources/Bad.Bad'"), NULL, LOAD_None, NULL);
	OfferItemWidget[3]->Icon->SetBrushFromTexture(OfferItemWidget[3]->Icon2,1);
	OfferItemWidget[3]->Icon3=OfferItemWidget[3]->Icon;
	UClass* SpecificBPClassFromCPlusPlus4 = LoadClass<UOfferItemWidget_1>(NULL, TEXT("/Game/blueprints/Npc/BP_OfferItemWidget_1.BP_OfferItemWidget_1_C"));
	OfferItemWidget[4]=CreateWidget<UOfferItemWidget_1>(this, SpecificBPClassFromCPlusPlus4);
	OfferItemWidget[4]->Icon2=LoadObject<UTexture2D>(NULL, TEXT("/Engine/EngineResources/Black.Black"), NULL, LOAD_None, NULL);
	OfferItemWidget[4]->Icon->SetBrushFromTexture(OfferItemWidget[4]->Icon2,1);
	OfferItemWidget[4]->Icon3->SetBrushFromTexture(OfferItemWidget[4]->Icon2,1);
	GenerateOfferList();
}

void UShopWidget_1::GenerateOfferList()//更新
{
	GridPanel->ClearChildren();
	
	
	for(size_t i=0;i<OfferItemWidget.Num();i++)
	{
		int Row=UKismetMathLibrary::Divide_DoubleDouble(i,2);
		int Colum=UKismetMathLibrary::Percent_IntInt(i,2);
		GridPanel->AddChildToUniformGrid(OfferItemWidget[i],Row,Colum);
	}
	OfferItemWidget[0]->ItemInfo->Dutebianhao=0;
	OfferItemWidget[1]->ItemInfo->Dutebianhao=1;
	OfferItemWidget[2]->ItemInfo->Dutebianhao=2;
	OfferItemWidget[3]->ItemInfo->Dutebianhao=3;
	OfferItemWidget[4]->ItemInfo->Dutebianhao=4;
	OfferItemWidget[0]->ItemInfo->Name=FText::FromString(TEXT("武器"));
	OfferItemWidget[0]->ItemInfo->Icon2=OfferItemWidget[0]->Icon2;
	OfferItemWidget[0]->ItemInfo->Icon2=LoadObject<UTexture2D>(this, TEXT("/Game/StarterContent/Textures/T_Brick_Cut_Stone_D.T_Brick_Cut_Stone_D"), NULL, LOAD_None, NULL);
	
	
	OfferItemWidget[0]->ItemInfo->Icon2dizhi= FText::FromString(TEXT("/Game/StarterContent/Textures/T_Brick_Cut_Stone_D.T_Brick_Cut_Stone_D"));
	OfferItemWidget[0]->ItemInfo->Icon2dizhi2=OfferItemWidget[0]->ItemInfo->Icon2dizhi.ToString();
	
	OfferItemWidget[1]->ItemInfo->Icon2=OfferItemWidget[1]->Icon2;
	OfferItemWidget[2]->ItemInfo->Icon2=OfferItemWidget[2]->Icon2;
	OfferItemWidget[3]->ItemInfo->Icon2=OfferItemWidget[3]->Icon2;
	OfferItemWidget[0]->ItemInfo->Icon->SetBrushFromTexture(OfferItemWidget[0]->Icon2,1);
	
	OfferItemWidget[1]->ItemInfo->Icon->SetBrushFromTexture(OfferItemWidget[1]->Icon2,1);
	OfferItemWidget[2]->ItemInfo->Icon->SetBrushFromTexture(OfferItemWidget[2]->Icon2,1);
	OfferItemWidget[3]->ItemInfo->Icon->SetBrushFromTexture(OfferItemWidget[3]->Icon2,1);
	OfferItemWidget[1]->ItemInfo->Name=FText::FromString(TEXT("花椒"));
	OfferItemWidget[2]->ItemInfo->Name=FText::FromString(TEXT("面皮"));
	OfferItemWidget[0]->ItemInfo->Amount2=3;
	OfferItemWidget[0]->NameText->SetText(OfferItemWidget[0]->ItemInfo->Name);
	OfferItemWidget[1]->NameText->SetText(OfferItemWidget[1]->ItemInfo->Name);
	OfferItemWidget[2]->NameText->SetText(OfferItemWidget[2]->ItemInfo->Name);
	OfferItemWidget[0]->AmountText->SetText(OfferItemWidget[0]->ItemInfo->Name);
	OfferItemWidget[1]->AmountText->SetText(OfferItemWidget[1]->ItemInfo->Name);
	OfferItemWidget[2]->AmountText->SetText(OfferItemWidget[2]->ItemInfo->Name);
	//有函数作用域问题
	OfferItemWidget[2]->ItemInfo->Name=FText::FromString(TEXT("废物"));
	OfferItemWidget[2]->NameText->SetText(OfferItemWidget[2]->ItemInfo->Name);
	
	
	
}
