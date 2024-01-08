// Fill out your copyright notice in the Description page of Project Settings.


#include "Lights_Livingroom_home_Switch.h"
#include"Lights_Livingroom_home.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputAction.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "rider/riderCharacter.h"

#include "Blueprint/UserWidget.h"
#include "Lights_Livingroom_home_xiancheng.h"//!!!
#include <Subsystems/PanelExtensionSubsystem.h>
#include <Blueprint/WidgetBlueprintLibrary.h>
#include <Blueprint/WidgetLayoutLibrary.h>

// Sets default values
ALights_Livingroom_home_Switch::ALights_Livingroom_home_Switch()
{
	
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MyDoor = CreateDefaultSubobject<USceneComponent>(TEXT("My Door"));
	MyDoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My DoorMesh"));
	MyDoorMesh->SetupAttachment(MyDoor);
	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("My Box"));
	Box->SetupAttachment(RootComponent);
	asd = 1;
	//bool UIshezhi=false;//记住，不可在.h里写bool xxx;
}

// Called when the game starts or when spawned
void ALights_Livingroom_home_Switch::BeginPlay()
{
	Super::BeginPlay();
	Box->OnComponentBeginOverlap.AddDynamic(this, &ALights_Livingroom_home_Switch::xiaohui);
	Box->OnComponentEndOverlap.AddDynamic(this, &ALights_Livingroom_home_Switch::xiaohui2);
	if (APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::
			GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("失败了"));
	}

	//GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &ALights_Livingroom_home_Switch::xunhuan, 1.0f, true);

}

// Called every frame
void ALights_Livingroom_home_Switch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ALights_Livingroom_home_Switch::xiaohui(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
	UE_LOG(LogTemp,Error,TEXT("1个"));
	AActor *a=UGameplayStatics::GetPlayerPawn(GetWorld(),0);
	if(OtherActor == a)
	{
		UE_LOG(LogTemp,Error,TEXT("2个"));
		APlayerController *aa=UGameplayStatics::GetPlayerController(this,0);
		AActor::EnableInput(aa);//之后是Gate
		
	}
}


void ALights_Livingroom_home_Switch::Interact_Implementation(APawn* InstigatorPawn)
{
	if (GetWorld() && asd ==1) {
		UE_LOG(LogTemp,Error,TEXT("很成功de 的"));
		UUserWidget* newUserWidget = nullptr;
		UClass* SpecificBPClassFromCPlusPlus = LoadClass<UUserWidget>(NULL, TEXT("/Game/RoboBars/Demo/Blueprints/BP_Hud.BP_Hud_C"));///Script/UMGEditor.WidgetBlueprint'/Game/RoboBars/Demo/Blueprints/BP_Hud.BP_Hud'
		if (SpecificBPClassFromCPlusPlus)
		{
			newUserWidget = CreateWidget<UUserWidget>(UGameplayStatics::GetPlayerController(GetWorld(), 0), SpecificBPClassFromCPlusPlus);
			check(newUserWidget)
		}
		newUserWidget->AddToPlayerScreen();

		GetWorld()->GetTimerManager().SetTimer(CountdownTimerHandle, this, &ALights_Livingroom_home_Switch::xunhuan, 1, false, 1);
		asd = true;
	}
	else {
		UClass* SpecificBPClassFromCPlusPlus = LoadClass<UUserWidget>(NULL, TEXT("/Game/RoboBars/Demo/Blueprints/BP_Hud.BP_Hud_C"));
		TArray<UUserWidget*> FoundWidgets;
		TSubclassOf<UUserWidget> WidgetClass;
		UWidgetBlueprintLibrary::GetAllWidgetsOfClass(GetWorld(), FoundWidgets, SpecificBPClassFromCPlusPlus, 1);
		UWidgetLayoutLibrary::RemoveAllWidgets(GetWorld());
		GetWorld()->GetTimerManager().ClearTimer(CountdownTimerHandle);
		asd = 1;
	}
	
}
	
	


void ALights_Livingroom_home_Switch::xiaohui2(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	asd = 1;

	UClass* SpecificBPClassFromCPlusPlus = LoadClass<UUserWidget>(NULL, TEXT("/Game/blueprints/123.123_C"));
	TArray<UUserWidget*> FoundWidgets;
	TSubclassOf<UUserWidget> WidgetClass;
	UWidgetBlueprintLibrary::GetAllWidgetsOfClass(GetWorld(), FoundWidgets, SpecificBPClassFromCPlusPlus, 0);
	//UWidgetLayoutLibrary::RemoveAllWidgets(GetWorld());
	for(size_t i=0;i<FoundWidgets.Num();i++)
	{
		FoundWidgets[i]->RemoveFromParent();
	}
}

void ALights_Livingroom_home_Switch::xunhuan()
{
	UE_LOG(LogTemp, Error, TEXT("箱子打开了，箱子盖子反转了"));

	if (GetWorld() && asd == false)
	{

		UE_LOG(LogTemp, Error, TEXT("不对不对"));
	}
	else {
		
		UClass* SpecificBPClassFromCPlusPlus = LoadClass<UUserWidget>(NULL, TEXT("/Game/RoboBars/Demo/Blueprints/BP_Hud.BP_Hud_C"));
		TArray<UUserWidget*> FoundWidgets;
		TSubclassOf<UUserWidget> WidgetClass;
		UWidgetBlueprintLibrary::GetAllWidgetsOfClass(GetWorld(), FoundWidgets, SpecificBPClassFromCPlusPlus, 1);
		UWidgetLayoutLibrary::RemoveAllWidgets(GetWorld());

		UE_LOG(LogTemp, Error, TEXT("对呀对呀"));
		TArray<AActor*> Actors;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ALights_Livingroom_home::StaticClass(), Actors);
		for (AActor* Actor : Actors)
		{
			ALights_Livingroom_home* Shanshuo;
			Shanshuo = Cast<ALights_Livingroom_home>(Actor);
			Lights_Livingroom_home_xiancheng* m_Danxiancheng = new Lights_Livingroom_home_xiancheng(Shanshuo);
			//开启线程
			FRunnableThread* RunnableThread = FRunnableThread::Create(m_Danxiancheng, TEXT("线程名称1"));
		}

		GetWorld()->GetTimerManager().ClearTimer(CountdownTimerHandle);

	}
	
}
