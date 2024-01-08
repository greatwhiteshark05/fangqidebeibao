// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */

UENUM(BlueprintType)
 enum class E_ItemCategory:uint8
 {
   Consumable,
   Equipment,
    Quest,
   Readable,
 Weapon
 };