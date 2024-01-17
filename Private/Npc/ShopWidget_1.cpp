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
	
	UClass* SpecificBPClassFromCPlusPlus = LoadClass<UOfferItemWidget_1>(this, TEXT("/Game/blueprints/Npc/BP_OfferItemWidget_1.BP_OfferItemWidget_1_C"));
	OfferItemWidget[0]=CreateWidget<UOfferItemWidget_1>(this, SpecificBPClassFromCPlusPlus);
	OfferItemWidget[0]->Icon2dizhi2=FText::FromString(TEXT("/Game/blueprints/Widget/picture/jian.jian")).ToString();;
	OfferItemWidget[0]->Icon2=LoadObject<UTexture2D>(this, *(OfferItemWidget[0]->Icon2dizhi2), NULL, LOAD_None, NULL);
	OfferItemWidget[0]->Icon->SetBrushFromTexture(OfferItemWidget[0]->Icon2,1);
	
	UClass* SpecificBPClassFromCPlusPlus1 = LoadClass<UOfferItemWidget_1>(NULL, TEXT("/Game/blueprints/Npc/BP_OfferItemWidget_1.BP_OfferItemWidget_1_C"));
	OfferItemWidget[1]=CreateWidget<UOfferItemWidget_1>(this, SpecificBPClassFromCPlusPlus1);
	OfferItemWidget[1]->Icon2=LoadObject<UTexture2D>(this, TEXT("/Game/blueprints/Widget/picture/OIP-C.OIP-C"), NULL, LOAD_None, NULL);
	OfferItemWidget[1]->Icon->SetBrushFromTexture(OfferItemWidget[1]->Icon2,1);
	
	UClass* SpecificBPClassFromCPlusPlus2 = LoadClass<UOfferItemWidget_1>(NULL, TEXT("/Game/blueprints/Npc/BP_OfferItemWidget_1.BP_OfferItemWidget_1_C"));
	OfferItemWidget[2]=CreateWidget<UOfferItemWidget_1>(this, SpecificBPClassFromCPlusPlus2);
	OfferItemWidget[2]->Icon2=LoadObject<UTexture2D>(NULL, TEXT("/Game/blueprints/Widget/picture/R-C.R-C"));
	OfferItemWidget[2]->Icon->SetBrushFromTexture(OfferItemWidget[2]->Icon2,1);
	OfferItemWidget[2]->Icon3=OfferItemWidget[2]->Icon;
	
	UClass* SpecificBPClassFromCPlusPlus3 = LoadClass<UOfferItemWidget_1>(NULL, TEXT("/Game/blueprints/Npc/BP_OfferItemWidget_1.BP_OfferItemWidget_1_C"));
	OfferItemWidget[3]=CreateWidget<UOfferItemWidget_1>(this, SpecificBPClassFromCPlusPlus3);
	OfferItemWidget[3]->Icon2=LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/blueprints/Widget/picture/OIP-C__1_.OIP-C__1_'"), NULL, LOAD_None, NULL);
	OfferItemWidget[3]->Icon->SetBrushFromTexture(OfferItemWidget[3]->Icon2,1);
	OfferItemWidget[3]->Icon3=OfferItemWidget[3]->Icon;
	
	UClass* SpecificBPClassFromCPlusPlus4 = LoadClass<UOfferItemWidget_1>(NULL, TEXT("/Game/blueprints/Npc/BP_OfferItemWidget_1.BP_OfferItemWidget_1_C"));
	OfferItemWidget[4]=CreateWidget<UOfferItemWidget_1>(this, SpecificBPClassFromCPlusPlus4);
	OfferItemWidget[4]->Icon2=LoadObject<UTexture2D>(NULL, TEXT("/Game/blueprints/Widget/picture/OIP-C__2_.OIP-C__2_"), NULL, LOAD_None, NULL);
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
	OfferItemWidget[0]->ItemInfo->Dutebianhao=1;
	OfferItemWidget[1]->ItemInfo->Dutebianhao=2;
	OfferItemWidget[2]->ItemInfo->Dutebianhao=3;
	OfferItemWidget[3]->ItemInfo->Dutebianhao=4;
	OfferItemWidget[4]->ItemInfo->Dutebianhao=5;
	
	OfferItemWidget[0]->ItemInfo->Name=FText::FromString(TEXT("武器"));
	OfferItemWidget[1]->ItemInfo->Name=FText::FromString(TEXT("菠萝"));
	OfferItemWidget[2]->ItemInfo->Name=FText::FromString(TEXT("苹果"));
	OfferItemWidget[3]->ItemInfo->Name=FText::FromString(TEXT("香蕉"));
	OfferItemWidget[4]->ItemInfo->Name=FText::FromString(TEXT("西瓜"));
	
	OfferItemWidget[0]->NameText->SetText(OfferItemWidget[0]->ItemInfo->Name);
	OfferItemWidget[1]->NameText->SetText(OfferItemWidget[1]->ItemInfo->Name);
	OfferItemWidget[2]->NameText->SetText(OfferItemWidget[2]->ItemInfo->Name);
	OfferItemWidget[3]->NameText->SetText(OfferItemWidget[3]->ItemInfo->Name);
	OfferItemWidget[4]->NameText->SetText(OfferItemWidget[4]->ItemInfo->Name);
	
	
	OfferItemWidget[0]->ItemInfo->Icon2dizhi= FText::FromString(TEXT("/Game/blueprints/Widget/picture/jian.jian"));
	OfferItemWidget[1]->ItemInfo->Icon2dizhi= FText::FromString(TEXT("/Game/blueprints/Widget/picture/OIP-C.OIP-C"));
	OfferItemWidget[2]->ItemInfo->Icon2dizhi= FText::FromString(TEXT("/Game/blueprints/Widget/picture/R-C.R-C"));
	OfferItemWidget[3]->ItemInfo->Icon2dizhi= FText::FromString(TEXT("/Game/blueprints/Widget/picture/OIP-C__1_.OIP-C__1_"));
	OfferItemWidget[4]->ItemInfo->Icon2dizhi= FText::FromString(TEXT("/Game/blueprints/Widget/picture/OIP-C__2_.OIP-C__2_n"));

	OfferItemWidget[0]->ItemInfo->Icon2dizhi2=FText::FromString(TEXT("/Game/blueprints/Widget/picture/jian.jian")).ToString();
	OfferItemWidget[1]->ItemInfo->Icon2dizhi2=FText::FromString(TEXT("/Game/blueprints/Widget/picture/OIP-C.OIP-C")).ToString();
	OfferItemWidget[2]->ItemInfo->Icon2dizhi2=FText::FromString(TEXT("/Game/blueprints/Widget/picture/R-C.R-C")).ToString();
	OfferItemWidget[3]->ItemInfo->Icon2dizhi2=FText::FromString(TEXT("/Game/blueprints/Widget/picture/OIP-C__1_.OIP-C__1_")).ToString();
	OfferItemWidget[4]->ItemInfo->Icon2dizhi2=FText::FromString(TEXT("/Game/blueprints/Widget/picture/OIP-C__2_.OIP-C__2_")).ToString();
	//OfferItemWidget[0]->ItemInfo->Icon2dizhi2=OfferItemWidget[0]->ItemInfo->Icon2dizhi.ToString();

	//OfferItemWidget[1]->ItemInfo->Icon->SetBrushFromTexture(OfferItemWidget[1]->Icon2,1);
	//OfferItemWidget[2]->ItemInfo->Icon->SetBrushFromTexture(OfferItemWidget[2]->Icon2,1);
	//OfferItemWidget[3]->ItemInfo->Icon->SetBrushFromTexture(OfferItemWidget[3]->Icon2,1);
	OfferItemWidget[3]->ItemInfo->CanbeStacked=1;
	
	OfferItemWidget[0]->ItemInfo->Amount2=1;
	OfferItemWidget[1]->ItemInfo->Amount2=1;
	OfferItemWidget[2]->ItemInfo->Amount2=1;
	OfferItemWidget[3]->ItemInfo->Amount2=1;
	OfferItemWidget[4]->ItemInfo->Amount2=1;
	
}
