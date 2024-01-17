// Fill out your copyright notice in the Description page of Project Settings.


#include "MasterItem.h"

#include "Components/WidgetComponent.h"
#include "GameFramework/PlayerInput.h"
#include "Kismet/GameplayStatics.h"
#include "rider/riderCharacter.h"


#include "UserWidget/PickupText.h"
#include "Runtime/InputDevice/Public/IInputDevice.h"

// Sets default values
AMasterItem::AMasterItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bCanEverTick = true;
	Sphere = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My Door"));
	Sphere->SetupAttachment(RootComponent);
	//RootComponent=Sphere;
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("My Box2"));
	SphereComponent->SetupAttachment(Sphere);
	//不用CreateWidget，直接在UE里选就行了./不得更改InventorySlot类，只能改InventorySlot里的变量
	InventorySlot =CreateDefaultSubobject<UInventorySlot>(TEXT("我的小垃圾包"));//√，①
	Name1=FName(TEXT("index_01_r"));
	PickUpText = CreateDefaultSubobject<UWidgetComponent>(TEXT("PickUpText"));
	PickUpText->SetupAttachment(Sphere);
	
}

// Called when the game starts or when spawned
void AMasterItem::BeginPlay()
{
	Super::BeginPlay();
	SphereComponent->OnComponentBeginOverlap.AddDynamic(this,&AMasterItem::jiale);
	SphereComponent->OnComponentEndOverlap.AddDynamic(this, &AMasterItem::chulai);
	//
	
	PickUpText->SetVisibility(0);
	auto InfoWidegetClass = LoadClass<UUserWidget>(NULL, TEXT("WidgetBlueprint'/Game/blueprints/Widget/BP_PickupText.BP_PickupText_C'"));
	PickUpText->SetWidgetClass(InfoWidegetClass);
	UpdateText_Implementation();
	////InfoWidgetComponent->SetWidgetSpace(EWidgetSpace::Screen);
	//InfoWidgetComponent->SetPivot(FVector2D(1, 0.5));
	//InfoWidgetComponent->SetDrawSize(FVector2D(120.0f, 10.0f));
	//InfoWidgetComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 95.0f));
}

// Called every frame
void AMasterItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void AMasterItem::jiale(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AActor *a=UGameplayStatics::GetPlayerPawn(GetWorld(),0);
	if(OtherActor == a)
	{
		APlayerController *aa=UGameplayStatics::GetPlayerController(this,0);
		AActor::EnableInput(aa);//之后是Gate
		AriderCharacter *ab=Cast<AriderCharacter>(UGameplayStatics::GetPlayerCharacter(this,0));
		ab->NearByPickUpActors.Add(this);
		//ab->InventoryRef->AddItem(ab,InventorySlot->Amount2,this);
		//this->Destroy();//删除的是 指针原本所指的那部分内存而已 指针还可以使用 但是避免野指针
		this->PickUpText->SetVisibility(1);
		this->PickUpText->SetHiddenInGame(0,0);
		
	}
	
}

void AMasterItem::chulai(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
	UE_LOG(LogTemp,Error,TEXT("哪里来的BUg，我要崩溃了"));
	
	AActor *a=UGameplayStatics::GetPlayerPawn(GetWorld(),0);
	
	if(OtherActor == a)
	{
		APlayerController *aa=UGameplayStatics::GetPlayerController(this,0);
		
		AActor::EnableInput(aa);//之后是Gate
		AriderCharacter *ab=Cast<AriderCharacter>(UGameplayStatics::GetPlayerCharacter(this,0));
		ab->NearByPickUpActors.RemoveSingle(this);
		
		
		this->PickUpText->SetVisibility(0);
	
		
	}
}

void AMasterItem::OnUsed2()
{
	UE_LOG(LogTemp, Error, TEXT("成功了调用这个类引用函数"));
}

void AMasterItem::OnPickUp_Implementation()//这个函数没有调用
{
	//AActor *a=UGameplayStatics::GetPlayerPawn(GetWorld(),0);
	//APlayerController *aa=UGameplayStatics::GetPlayerController(this,0);
	//AActor::EnableInput(aa);//之后是Gate
	//AriderCharacter *ab=Cast<AriderCharacter>(UGameplayStatics::GetPlayerCharacter(this,0));
	
	//ab->InventoryRef->AddItem(ab,InventorySlot->Amount2,this);
	//this->Destroy();//删除的是 指针原本所指的那部分内存而已 指针还可以使用 但是避免野指针
	this->Destroyed();
}

void AMasterItem::UpdateText_Implementation()
{
	//auto InfoWidegetClass = LoadCl ass<UUserWidget>(NULL, TEXT("WidgetBlueprint'/Game/blueprints/Widget/PickUpText.PickUpText_C'"));
	//TSubclassOf<APawn> classToFind;
	UPickupText *s=Cast<UPickupText>(PickUpText->GetUserWidgetObject());
	
	FString sg=InventorySlot->Name.ToString()+"-x"+FText::AsNumber(InventorySlot->Amount2).ToString();
	FText ad=FText::FromString(sg);
	//FText adc=FText::Format(InventorySlot->Name,NSLOCTEXT("-","x","{0} {1}"), NSLOCTEXT("Solus","Solus","Day"), FText::AsNumber(InventorySlot->Amount2)); 
	s->TextBlock->SetText(ad);
	
}

void AMasterItem::OnUsed_Implementation()
{
	UE_LOG(LogTemp, Error, TEXT("武器没出来啊我靠"));
}
