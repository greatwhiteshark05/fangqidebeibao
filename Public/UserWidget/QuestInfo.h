// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MasterItem.h"
#include "UObject/NoExportTypes.h"
#include"Engine/Datatable.h"
#include "QuestInfo.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct RIDER_API FQuestInfo:public FTableRowBase
{
	GENERATED_BODY()
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="hahhaah");
	int32 Dutebianhao;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="hahhaah");
	TSubclassOf<AMasterItem> avx;
};
