// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Npc/ShopWidget_1.h"
#include "riderGameMode.generated.h"
DECLARE_MULTICAST_DELEGATE_OneParam(FDelegate,bool)
UCLASS(minimalapi)
class AriderGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AriderGameMode();
	UShopWidget_1 *Danta;
};



