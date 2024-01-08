// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventorySlot.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/UniformGridPanel.h"
#include "UObject/ConstructorHelpers.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include <MasterItem.h>
#include "Inventory.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)//Blueprintable不加这个查不出来
class RIDER_API UInventory : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual void NativeConstruct() override;
	//没加*导致闪退好多次。报错。
	UUniformGridPanel *SlotPanel;
	UPROPERTY(meta = (BindWidget))
	class UButton *Button_0;
	UPROPERTY(meta = (BindWidget))
	UScrollBox *ScrollBox;
	int SlotPerRow=5;//一行生成几个slot
	void GenerateSlotWidget();
	UFUNCTION(BlueprintCallable)
	void HideInventory();
	void ShowInventory();
	bool IsVisible=1;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Mantra")
	int AmountOfSlots=0;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Mantra")
	int MaxStackSize=100;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mantra")
	TArray<UInventorySlot*> Slots;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Mantra")
	TArray<UInventorySlot*> Slots2;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Mantra")
	ACharacter *TopDownCha;
	//判断插槽为空? 判断插槽为空?，返回1说明是空的
	UFUNCTION(BlueprintCallable,Category="Custom|myfun")
	bool IsSlotEmpty(int Index);
	//给定索引，返回信息
	UFUNCTION(BlueprintCallable,Category="Custom|myfun")
	UInventorySlot* GetItemInfoAtIndex2(int Index) ;
	UFUNCTION(BlueprintCallable,Category="Custom|myfun")
	int  GetItemInfoAtIndex3(int Index);
	//查找空的插槽。返回空插槽的索引,记住要先用SearchEmptySlot2，如果SearchEmptySlot2==1，再用SearchEmptySlot()函数
	UFUNCTION(BlueprintCallable,Category="Custom|myfun")
	int SearchEmptySlot();
	//是否成功，如果都满了，返回0，表示没找到
	UFUNCTION(BlueprintCallable,Category="Custom|myfun")
	bool SearchEmptySlot2();
	
	//添加物品信息
	UFUNCTION(BlueprintCallable,Category="Custom|myfun")
	bool AddItem(ACharacter *TopDownCha2,int Amount, AMasterItem *Class);
	UFUNCTION(BlueprintCallable,Category="Custom|myfun")
	int AddItem2(ACharacter *TopDownCha2,int Amount, AMasterItem *Class);
	
	//纯UI版本的添加物品信息
	UFUNCTION(BlueprintCallable,Category="Custom|myfun")
	bool AddItem3(ACharacter *TopDownCha2,int Amount, UInventorySlot *InventorySlot);
	
	//拖动UI扔掉物品,把索引A的元素移除掉，帧de的吗，这句话写在编译器里
	UFUNCTION(BlueprintCallable,Category="Custom|myfun") 
	bool RemoveItemAtIndex(int Amount,int Index);
	//把东西拿在手上
	UFUNCTION(BlueprintCallable,Category="Custom|myfun")
	bool HandItemAtIndex(int Index);
	//交换位置
	UFUNCTION(BlueprintCallable,Category="Custom|myfun")
	bool SwapSlot(int Index1,int Index2);
	//找一个相同的可叠加的类
	////查找到了此物品可插入的位置，必须先使用SearchFreeStack(AMasterItem *Class)判断，再用SearchFreeStack2(AMasterItem *Class)返回
	UFUNCTION(BlueprintCallable,Category="Custom|myfun")
	int SearchFreeStack(AMasterItem *Class);
	
	//纯UI版的查找插入位置
	UFUNCTION(BlueprintCallable,Category="Custom|myfun")
	int SearchFreeStack3(UInventorySlot *InventorySlot);
	
	UPROPERTY(meta = (BindWidget))
	UUserWidget* ActtionMenu = Cast<UUserWidget>(LoadClass<AActor>(nullptr, TEXT("Blueprint'/Game/blueprints/Widget/BP_ActionMenu.BP_ActionMenu_C'")));

	UFUNCTION(BlueprintCallable,Category="Custom|myfun")
	void OnSlotClick(UInventorySlot *Slot1);

	UFUNCTION(BlueprintCallable,Category="Custom|myfun")
	void OnHand(int Index);
};