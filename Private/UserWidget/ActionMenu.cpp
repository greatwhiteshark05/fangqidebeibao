// Fill out your copyright notice in the Description page of Project Settings.


#include "UserWidget/ActionMenu.h"

#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Kismet/DataTableFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetStringLibrary.h"
#include "rider/riderCharacter.h"
#include "UserWidget/QuestInfo.h"

void UActionMenu::NativeConstruct()
{
	Super::NativeConstruct();
	ThrowButton->OnClicked.AddDynamic(this,&UActionMenu::OnClickedThrowButton);
	HandButton->OnClicked.AddDynamic(this,&UActionMenu::OnClickedHandButton);
	
}

void UActionMenu::Update(int Index1)
{
	UClass* SpecificBPClassFromCPlusPlus = LoadClass<UInventory>(NULL, TEXT("/Game/blueprints/Widget/BP_Inventory.BP_Inventory_C"));
	
	//TSubclassOf<UInventory> WidgetClass=SpecificBPClassFromCPlusPlus;
	
	TArray<UUserWidget*> bbb;
	UWidgetBlueprintLibrary::GetAllWidgetsOfClass(GetWorld(),bbb,SpecificBPClassFromCPlusPlus,1);
	for(size_t i=0;i<bbb.Num();i++)
	{
		UInventory *bbbb;
		bbbb=Cast<UInventory>(bbb[i]);
		UInventorySlot *bbbbb;
		bbbbb=bbbb->GetItemInfoAtIndex2(Index1);
		Amount=bbbb->GetItemInfoAtIndex3(Index1);
		if(bbbbb->CanbuUse)
		{
			this->UseButton->SetVisibility(ESlateVisibility::Visible);
			this->UseText->SetText(bbbbb->Text->GetText());
		
		}else
		{
			this->UseButton->SetVisibility(ESlateVisibility::Hidden);
		}
	}
}

void UActionMenu::OnClickedThrowButton()
{
	UClass* SpecificBPClassFromCPlusPlus = LoadClass<UInventory>(NULL, TEXT("/Game/blueprints/Widget/BP_Inventory.BP_Inventory_C"));
	TArray<UUserWidget*> bbb;
	UWidgetBlueprintLibrary::GetAllWidgetsOfClass(GetWorld(),bbb,SpecificBPClassFromCPlusPlus,1);
	for(size_t i=0;i<bbb.Num();i++)
	{
		UInventory *bbbb;
		bbbb=Cast<UInventory>(bbb[i]);
		bbbb->RemoveItemAtIndex(1,Index);
		bbbb->GenerateSlotWidget();
		///////////////////////
		int LocalIndex=Index;
	FString LocalDutebianhao=UKismetStringLibrary::Conv_Int64ToString(ItemInfo->Dutebianhao);
	FName ab=TEXT("Dutebianhao");
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
			FQuestInfo* Item = pDataTable->FindRow<FQuestInfo>(name1, "");
			//FTableRowBase *avx=Cast<FTableRowBase>(Item);//cuode
			//UDataTableFunctionLibrary::GetDataTableRowFromName(pDataTable,name1, RowBase);//这个函数不能用 的
			if(UDataTableFunctionLibrary::Generic_GetDataTableRowFromName(pDataTable,name1,Item))
			{
				APlayerController *aa=UGameplayStatics::GetPlayerController(this,0);
				//APlayerController *ab=GetWorld()->GetFirstPlayerController();这个是错的
				FVector SpawnLocation2=aa->K2_GetActorLocation();
				FVector SpawnLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
					//aa->GetSpawnLocation();
				FRotator SpawnRotation;
				AMasterItem *YC = GetWorld()->SpawnActor<AMasterItem>( Item->avx, SpawnLocation, SpawnRotation);  
				if(YC)
				{
					UE_LOG(LogTemp,Error,TEXT("创建物体成功"));
				
				}
			}
			//UK2Node_GetDataTableRow::GetDataTableRowStructType()
			break;
		}
	}
	
	
		/////////////////////////////
		this->SetVisibility(ESlateVisibility::Hidden);
	}
}

void UActionMenu::OnClickedHandButton()
{
	UClass* SpecificBPClassFromCPlusPlus = LoadClass<UInventory>(NULL, TEXT("/Game/blueprints/Widget/BP_Inventory.BP_Inventory_C"));
	TArray<UUserWidget*> bbb;
	UWidgetBlueprintLibrary::GetAllWidgetsOfClass(GetWorld(),bbb,SpecificBPClassFromCPlusPlus,1);
	for(size_t i=0;i<bbb.Num();i++)
	{
		UInventory *bbbb;
		bbbb=Cast<UInventory>(bbb[i]);
		bbbb->OnHand(Index);
		bbbb->HandItemAtIndex(Index);
		this->SetVisibility(ESlateVisibility::Hidden);
	}
}
