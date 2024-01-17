// Fill out your copyright notice in the Description page of Project Settings.


#include "UserWidget/Inventory.h"

#include "AITypes.h"
#include "GameplayTagsManager.h"
#include "K2Node_GetDataTableRow.h"
#include "ModuleDescriptor.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetArrayLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "Blueprint/WidgetLayoutLibrary.h"

#include "NavigationSystemTypes.h"
#include "WidgetBlueprint.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Blueprint/WidgetTree.h"
#include "Components/UniformGridSlot.h"
#include "Engine/UserDefinedStruct.h"
#include "Kismet/DataTableFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetStringLibrary.h"
#include "Misc/OutputDeviceDebug.h"
#include "UserWidget/ActionMenu.h"
#include "UserWidget/QuestInfo.h"


void UInventory::NativeConstruct()
{
	Super::NativeConstruct();
	//必须绑定在这里，写在 UInventory::ShowInventory()里没用
	Button_0->OnClicked.AddDynamic(this,&UInventory::HideInventory);
	
}

void UInventory::GenerateSlotWidget()
{

	UE_LOG(LogTemp,Error,TEXT("ji进来了"));
	SlotPanel = Cast<UUniformGridPanel>(GetWidgetFromName(TEXT("SlotPanel")));//没加这句闪退好几次
	SlotPanel->ClearChildren();
	for(size_t i=0;i<Slots.Num();i++)
	{
		int Row=UKismetMathLibrary::Divide_DoubleDouble(i,SlotPerRow);
		int Colum=UKismetMathLibrary::Percent_IntInt(i,SlotPerRow);
		SlotPanel->AddChildToUniformGrid(Slots[i],Row,Colum);
		Slots[i]->Text->SetText(FText::FromString(TEXT("X")+(FString::FormatAsNumber(Slots[i]->Amount2))));
		
			
		if(this->IsSlotEmpty(i)==1)
		{
			Slots[i]->SlotButton->SetIsEnabled(0);
			Slots[i]->Icon->SetBrushFromTexture(Slots[i]->Icon2,1);
			
			Slots[i]->Icon->SetVisibility(ESlateVisibility	::Visible);
		}else
		{
			Slots[i]->Amount=this->GetItemInfoAtIndex3(i);
			Slots[i]->SlotButton->SetIsEnabled(1);
			Slots[i]->Icon->SetBrushFromTexture(Slots[i]->Icon2,1);
			Slots[i]->Icon->SetVisibility(ESlateVisibility::HitTestInvisible);
		}
	}
	
	
}

void UInventory::HideInventory()
{
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController (GWorld, 0);
	PlayerController->bShowMouseCursor = false;
	PlayerController->SetIgnoreLookInput(false);
	IsVisible=0;
	this->SetIsEnabled(0);
	this->SetVisibility(ESlateVisibility::Hidden);
	PlayerController->bShowMouseCursor = false;
}

void UInventory::ShowInventory()
{
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController (GWorld, 0);
	PlayerController->bShowMouseCursor = true;
	PlayerController->SetIgnoreLookInput(true);
	IsVisible=1;
	this->SetIsEnabled(1);
	this->SetVisibility(ESlateVisibility::Visible);
}

//判断插槽为空?，返回1说明是空的
 bool UInventory::IsSlotEmpty(int Index)
{
	
	if(Slots.Num()<=Index)
	{
		return 1;
	}else
	{
		return 0;
	}

	
}
//给定索引，返回该物品信息

UInventorySlot* UInventory::GetItemInfoAtIndex2(int Index)
{
	if(IsSlotEmpty(Index))
	{
		return nullptr;
	}else
	{
		return Slots[Index];
	}
}

//给定索引，返回该物品数量
int UInventory::GetItemInfoAtIndex3(int Index)
{
		//return Slots[Index].Amount;
	if(IsSlotEmpty(Index))
	{
		return 0;
	}else
	{
		for(size_t i=0;i<Slots.Num();i++)
		{
			UE_LOG(LogTemp,Error,TEXT("编号为%i，名字为%s，描述信息为%s，使用说明为%s，数量为%i"),Slots[i]->Dutebianhao,
				*Slots[i]->Name.ToString(),*Slots[i]->Description.ToString(),*Slots[i]-> UseText.ToString(),
				Slots[i]->Amount2);
			
		
		}
		UE_LOG(LogTemp,Error,TEXT("`````````````````"));
		
		return Slots[Index]->Amount2;
	}
}
//查找空的插槽。返回空插槽的索引,记住要先用SearchEmptySlot2，如果SearchEmptySlot2==1，再用SearchEmptySlot()函数
int UInventory::SearchEmptySlot()
{
	
	int LocalIndex=0;
	//for (auto& s :Slots)
	for(size_t i=0;i<Slots.Num();i++)
	{
		if(IsSlotEmpty(LocalIndex)==0 && LocalIndex<MaxStackSize){return LocalIndex;}
			LocalIndex++;
	}
	
	return 0;
}
//是否成功，如果都满了，返回0，表示没找到
bool UInventory::SearchEmptySlot2()
{
	int LocalIndex=0;
	//for (auto& s :Slots)
	for(size_t i=0;i<Slots.Num();i++)
	{
		if(IsSlotEmpty(LocalIndex)==0 && LocalIndex<MaxStackSize){return 1;}
		LocalIndex++;
	}
	return 0;
}
//添加物品信息，返回1表示添加成功
bool UInventory::AddItem(ACharacter *TopDownCha2,int Amount, AMasterItem*Class)
{
	
	int LocalAmount=Amount;
	AMasterItem *LocalClass=Class;
	int FoundIndex;
	FoundIndex=SearchFreeStack(LocalClass);//找到可插入的位置，√
		if(FoundIndex>=Slots.Num())//√
		{
		LocalAmount=Amount;//对
		}else
		{
			LocalAmount=Slots[FoundIndex]->Amount2+Amount;
		}
		if(LocalClass->InventorySlot->CanbeStacked==1 && FoundIndex<Slots.Num() )//√
		{
			this->Slots[FoundIndex]->Text=Cast<UTextBlock>(this->Slots[FoundIndex]->GetWidgetFromName("Text"));
			Slots[FoundIndex]->Amount2 =LocalAmount;
			Slots[FoundIndex]->Text->SetText(FText::FromString(TEXT("X")+(FString::FormatAsNumber(Slots[FoundIndex]->Amount2))));
		}
		else
		{//直接给背包Add一个有用户空间的物体，也没有意义的，比如CreateWidget过的Add给他，没意义。Slots.Add(newUserWidget)),bu不过加进去后地址倒是一样
			UClass* SpecificBPClassFromCPlusPlus = LoadClass<UInventorySlot>(NULL, TEXT("/Game/blueprints/Widget/BP_InventorySlot.BP_InventorySlot_C"));
			Slots.Add(LocalClass->InventorySlot);//(Slots.Add(newUserWidget)
			//成功了，必须自己CreateWidget，如果用临时创建的变量CreateWidget然后赋值，那么控件会消失
			Slots[FoundIndex]=CreateWidget<UInventorySlot>(this, SpecificBPClassFromCPlusPlus);
			Slots[FoundIndex]->Text=Cast<UTextBlock>(Slots[FoundIndex]->GetWidgetFromName("Text"));
			Slots[FoundIndex]->SlotButton=Cast<UButton>(Slots[FoundIndex]->GetWidgetFromName("SlotButton"));
			Slots[FoundIndex]->Icon = Cast<UImage>(Slots[FoundIndex]->GetWidgetFromName(TEXT("Icon")));
			Slots[FoundIndex]->Amount2=LocalClass->InventorySlot->Amount2;
		
		//LocalClass->InventorySlot->Icon2=LoadObject<UTexture2D>(NULL, TEXT("/Game/StarterContent/Textures/T_Brick_Cut_Stone_D.T_Brick_Cut_Stone_D"), NULL, LOAD_None, NULL);
	
			Slots[FoundIndex]->Icon2=LocalClass->InventorySlot->Icon2;
			Slots[FoundIndex]->Icon->SetBrushFromTexture(Slots[FoundIndex]->Icon2,1);
			Slots[FoundIndex]->Dutebianhao=LocalClass->InventorySlot->Dutebianhao;
			Slots[FoundIndex]->Text->SetText(FText::FromString(TEXT("X")+(FString::FormatAsNumber(Slots[FoundIndex]->Amount2))));
			
		}
		this->GenerateSlotWidget();
		//Class->OnUsed();
		return 1;
	
	//return 0;
}
//添加物品信息，先用AddItem，如果AddItem==1，再用AddItem2返回加入的索引值
int UInventory::AddItem2(ACharacter *TopDownCha2,int Amount, AMasterItem *Class)
{
	AMasterItem *LocalClass=Class;
	int FoundIndex;
	
		FoundIndex=SearchFreeStack(LocalClass);//找到可插入的位置
		return FoundIndex;
	
}

bool UInventory::AddItem3(ACharacter* TopDownCha2, int Amount, UInventorySlot* InventorySlot)
{
	int LocalAmount=Amount;
	UInventorySlot* LocalInventorySlot=InventorySlot;
	int FoundIndex;
	FoundIndex=SearchFreeStack3(LocalInventorySlot);//找到可插入的位置，√
		if(FoundIndex>=Slots.Num())//√
		{
		LocalAmount=Amount;//对
		}else
		{
			LocalAmount=Slots[FoundIndex]->Amount2+Amount;
		}
		if(LocalInventorySlot->CanbeStacked==1 && FoundIndex<Slots.Num() )//√
		{
			this->Slots[FoundIndex]->Text=Cast<UTextBlock>(this->Slots[FoundIndex]->GetWidgetFromName("Text"));
			Slots[FoundIndex]->Amount2 =LocalAmount;
			Slots[FoundIndex]->Text->SetText(FText::FromString(TEXT("X")+(FString::FormatAsNumber(Slots[FoundIndex]->Amount2))));
		}
		else
		{//直接给背包Add一个有用户空间的物体，也没有意义的，比如CreateWidget过的Add给他，没意义。Slots.Add(newUserWidget)),bu不过加进去后地址倒是一样
			UClass* SpecificBPClassFromCPlusPlus = LoadClass<UInventorySlot>(NULL, TEXT("/Game/blueprints/Widget/BP_InventorySlot.BP_InventorySlot_C"));
			//Slots.Add(LocalInventorySlot);//(Slots.Add(newUserWidget)
			Slots.AddDefaulted();
			//成功了，必须自己CreateWidget，如果用临时创建的变量CreateWidget然后赋值，那么控件会消失
			Slots[FoundIndex]=CreateWidget<UInventorySlot>(this, SpecificBPClassFromCPlusPlus);
			Slots[FoundIndex]->Text=Cast<UTextBlock>(Slots[FoundIndex]->GetWidgetFromName("Text"));
			Slots[FoundIndex]->SlotButton=Cast<UButton>(Slots[FoundIndex]->GetWidgetFromName("SlotButton"));
			//Slots[FoundIndex]->Icon = Cast<UImage>(Slots[FoundIndex]->GetWidgetFromName(TEXT("Icon")));
			
			//const TCHAR *str=_T ("ShellHWDetection")(Slots[FoundIndex]->Icon2dizhi);//×
			//TCHAR *str=_T ("ShellHWDetection")("/Game/StarterContent/Textures/T_Brick_Cut_Stone_D.T_Brick_Cut_Stone_D");
		//	TCHAR str=*(Slots[FoundIndex]->Icon2dizhi2);
			Slots[FoundIndex]->Icon2=LoadObject<UTexture2D>(this, *(LocalInventorySlot->Icon2dizhi2), NULL, LOAD_None, NULL);
			//??????Slots[FoundIndex]->Icon2=LoadObject<UTexture2D>(this, *(Slots[FoundIndex]->Icon2dizhi2), NULL, LOAD_None, NULL);
			//IConsoleManager::Get().FindConsoleVariable(*(Slots[FoundIndex]->Icon2dizhi))->GetInt();
			//Slots[FoundIndex]->Icon->SetBrushFromTexture(Slots[FoundIndex]->Icon2,1);
	
			Slots[FoundIndex]->Amount2=LocalInventorySlot->Amount2;
		
		//LocalInventorySlot->Icon2=LoadObject<UTexture2D>(NULL, TEXT("/Game/StarterContent/Textures/T_Brick_Cut_Stone_D.T_Brick_Cut_Stone_D"), NULL, LOAD_None, NULL);
	
			//Slots[FoundIndex]->Icon2=LocalInventorySlot->Icon2;
			//Slots[FoundIndex]->Icon->SetBrushFromTexture(Slots[FoundIndex]->Icon2,1);
			//Slots[FoundIndex]->Icon->SetBrushFromTexture(LocalInventorySlot->Icon2,1);
			
			Slots[FoundIndex]->Dutebianhao=LocalInventorySlot->Dutebianhao;
			Slots[FoundIndex]->Text->SetText(FText::FromString(TEXT("X")+(FString::FormatAsNumber(Slots[FoundIndex]->Amount2))));
			
		}
		this->GenerateSlotWidget();
		//Class->OnUsed();
		return 1;
}

bool UInventory::RemoveItemAtIndex(int Amount, int Index)
{
	int LocalAmount=Amount;
	int LocalIndex=Index;
	if(IsSlotEmpty(LocalIndex)==0 && Slots[LocalIndex]->Amount2>0)
	{
		if(Slots[LocalIndex]->Amount2>LocalAmount)
		{
			Slots[LocalIndex]->Amount2-=LocalAmount;
			
		}else
		{//全删光了，超过了就当删除全部
			Slots.RemoveAt(LocalIndex);
			
		}
		this->GenerateSlotWidget();
		return 1;
	}else
	{
		return 0;
	}
}

bool UInventory::HandItemAtIndex(int Index)
{
	UE_LOG(LogTemp,Error,TEXT("拿在手上了"));
	//this[Index]
	return 0;
}

bool UInventory::SwapSlot(int Index1, int Index2)
{
	return 0;
}

//查找到了此物品可插入的位置，再用SearchFreeStack2(AMasterItem *Class)返回
int UInventory::SearchFreeStack(AMasterItem *Class)
{
	int LocalIndex=0;
	if(Slots.Num()==0)
	{UE_LOG(LogTemp,Error,TEXT("Slots.Num()为%d"),LocalIndex);
		return 0;
	}
	for (size_t i=0;i<Slots.Num();i++)
	{
		if(IsSlotEmpty(LocalIndex)==0)
		{
			if(Slots[LocalIndex]->Dutebianhao==Class->InventorySlot->Dutebianhao && Class->InventorySlot-> CanbeStacked==1)
			{UE_LOG(LogTemp,Error,TEXT("LocalIndex为%d"),LocalIndex);
				return LocalIndex;
			}
		}
		LocalIndex++;
	}
	UE_LOG(LogTemp,Error,TEXT("LocalIndex为%d"),LocalIndex);
	return Slots.Num();
}

int UInventory::SearchFreeStack3(UInventorySlot* InventorySlot)
{
	int LocalIndex=0;
	if(Slots.Num()==0)
	{UE_LOG(LogTemp,Error,TEXT("Slots.Num()为%d"),LocalIndex);
		return 0;
	}
	for (size_t i=0;i<Slots.Num();i++)
	{
		if(IsSlotEmpty(LocalIndex)==0)
		{
			if(Slots[LocalIndex]->Dutebianhao==InventorySlot->Dutebianhao && InventorySlot-> CanbeStacked==1)
			{UE_LOG(LogTemp,Error,TEXT("LocalIndex为%d"),LocalIndex);
				return LocalIndex;
			}
		}
		LocalIndex++;
	}
	UE_LOG(LogTemp,Error,TEXT("LocalIndex为%d"),LocalIndex);
	return Slots.Num();
}

void UInventory::OnSlotClick(UInventorySlot* Slot1)
{
	UE_LOG(LogTemp,Error,TEXT("成功点击按钮"));
	double Row=UWidgetLayoutLibrary::SlotAsUniformGridSlot(Slot1)->GetRow();
	double a=ScrollBox->GetScrollOffset();
	double Column=UWidgetLayoutLibrary::SlotAsUniformGridSlot(Slot1)->GetColumn();
	FVector2d ab=FVector2d(Column*64,UKismetMathLibrary::Clamp(Row-a,0,200));
	ActtionMenu->SetVisibility(ESlateVisibility::Visible);
UActionMenu *ActionMenu=Cast<UActionMenu>(ActtionMenu);
	
	//我们调用DCRLabelWidget对象的名为SetName的方法，并传入参数“0011”.

//Index不应该是0
	int i=Row+Column;
	ActionMenu->Index=i;
	ActionMenu->ItemInfo=Slot1;
	FString FieldName = FString::FromInt(i);
	FString cmd = TEXT("Update ")+ FieldName;
	FOutputDeviceDebug device;
	ActtionMenu->CallFunctionByNameWithArguments(*cmd, device, NULL, true);
	ActtionMenu->SetRenderTranslation(ab);
}

void UInventory::OnHand(int Index)
{
	//   /Game/blueprints/Widget/Data/DT_MasterDataTable.DT_MasterDataTable_C
	int LocalIndex=Index;
	FString LocalDutebianhao=UKismetStringLibrary::Conv_Int64ToString(Slots[LocalIndex]->Dutebianhao);
	UE_LOG(LogTemp,Error,TEXT("onHand调用了吗"));
//UWidgetBlueprintLibrary::GetAllWidgetsOfClass(GetWorld(),bbb,SpecificBPClassFromCPlusPlus,1);
//	UClass* SpecificBPClassFromCPlusPlus2=LoadClass<UDataTable>(NULL, TEXT("/Game/blueprints/Widget/Data/DT_MasterDataTable.DT_MasterDataTable_C"));
	FName ab=TEXT("Dutebianhao");
//	UClass* SpecificBPClassFromCPlusPlus=LoadClass<UDataTable>(NULL, TEXT("/Game/blueprints/Widget/Data/DT_MasterDataTable.DT_MasterDataTable_C"));
//	UDataTable *ab=Cast<UDataTable>(SpecificBPClassFromCPlusPlus);
	UDataTable *pDataTable = LoadObject<UDataTable>(NULL, UTF8_TO_TCHAR("DataTable'/Game/blueprints/Widget/Data/NewDataTable.NewDataTable'"));
	TArray<FString> RowNames;                                  
	RowNames = UDataTableFunctionLibrary::GetDataTableColumnAsString(pDataTable,ab);
	FTableRowBase haha;
	for (auto& name : RowNames)
	{
		if(LocalDutebianhao==name)
		{
			UE_LOG(LogTemp,Error,TEXT("找到了"));
			FName name1=FName(name);
			//UScriptStruct* Item = pDataTable->FindRow<UScriptStruct>(RowNames, "");
			//UStaticStruct *aaa=LoadObject<UUserDefinedStruct>(NULL, TEXT("/Game/ceshi/ceshi.ceshi_C"));
			//UStruct* OutRow = pDataTable->FindRow<UStruct>(name1, "");
		//	TSubclassOf<UStruct> avx= LoadClass<UStruct>(NULL, TEXT("/Game/ceshi/ceshi.ceshi_C"));
			//avx *sdf=
			//	FQuestInfo 
			//haha.OnDataTableChanged(pDataTable,name1);
			FQuestInfo* Item = pDataTable->FindRow<FQuestInfo>(name1, "");
			FTableRowBase *RowBase =pDataTable->FindRow<FQuestInfo>(name1, "",1); 
			//FTableRowBase *avx=Cast<FTableRowBase>(Item);//cuode
			//UDataTableFunctionLibrary::GetDataTableRowFromName(pDataTable,name1, RowBase);//这个函数不能用 的
			if(UDataTableFunctionLibrary::Generic_GetDataTableRowFromName(pDataTable,name1,Item))
			{
				UE_LOG(LogTemp,Error,TEXT("不错找到最难的了"));
				UE_LOG(LogTemp,Error,TEXT("输出Item->Dutebianhao为%d"),Item->Dutebianhao);
				TSubclassOf<AMasterItem> asda= Item->avx;
				FVector SpawnLocation;
				FRotator SpawnRotation;
				//AActor* FoundActor = UGameplayStatics::GetActorOfClass(GetWorld(), asda);
				AMasterItem *YC = GetWorld()->SpawnActor<AMasterItem>( Item->avx, SpawnLocation, SpawnRotation);  
				if(YC)
				{
					UE_LOG(LogTemp,Error,TEXT("创建物体成功"));
					YC->OnUsed();
				}
			}
			//UK2Node_GetDataTableRow::GetDataTableRowStructType()
			break;
		}
	}
	
	
}

