// Copyright Epic Games, Inc. All Rights Reserved.

#include "riderGameMode.h"
#include "riderCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "deng.h"

#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

#include "riderCharacter.h"
AriderGameMode::AriderGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	Danta=CreateWidget<UShopWidget_1>(GetWorld(), LoadClass<UShopWidget_1>(NULL, TEXT("/Game/blueprints/Npc/BP_ShopWidget_1.BP_ShopWidget_1_C")));

	/*
	TSubclassOf<UInventorySlot>InventorySlot2;
	UInventorySlot *InventorySlot3;
	static ConstructorHelpers::FClassFinder<UInventorySlot> UnitSelector(TEXT("/Game/blueprints/Widget/BP_InventorySlot.BP_InventorySlot_C"));
	InventorySlot2 = UnitSelector.Class; 
	if(InventorySlot2)
	{
		//UE_LOG(LogTemp, Error, TEXT("InventorySlot2成功"));
	//	InventorySlot3=CreateWidget<UInventorySlot>(GetWorld(),LoadClass<UInventorySlot>(NULL, TEXT("/Game/blueprints/Widget/BP_InventorySlot.BP_InventorySlot_C")));
		InventorySlot3=CreateWidget<UInventorySlot>(GetWorld(),InventorySlot2);

		if(InventorySlot3)
		{
			UE_LOG(LogTemp, Error, TEXT("InventorySlot3成功"));
		}else
		{
			UE_LOG(LogTemp, Error, TEXT("InventorySlot3失败"));
		}
	}
	*/
}