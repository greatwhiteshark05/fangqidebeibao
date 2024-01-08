// Fill out your copyright notice in the Description page of Project Settings.


#include "Npc/Merchant_1.h"

#include "Components/WidgetComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMerchant_1::AMerchant_1()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("My Box2"));
	//MeshComponent=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	WidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("WidgetComponent"));
	WidgetComponent->SetupAttachment(RootComponent);
	SphereComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AMerchant_1::BeginPlay()
{
	Super::BeginPlay();
	SphereComponent->OnComponentBeginOverlap.AddDynamic(this,&AMerchant_1::jinru);
	SphereComponent->OnComponentEndOverlap.AddDynamic(this,&AMerchant_1::chulai);
	WidgetComponent->SetVisibility(0);
	
}

// Called every frame
void AMerchant_1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMerchant_1::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMerchant_1::OnInteract(AriderCharacter* a)
{
	
}

void AMerchant_1::OnShopClose()
{

}

void AMerchant_1::jinru(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AActor *a=UGameplayStatics::GetPlayerPawn(GetWorld(),0);
	if(OtherActor == a)
	{
	UE_LOG(LogTemp,Error,TEXT("进来了"));
		APlayerController *aa=UGameplayStatics::GetPlayerController(this,0);
		AActor::EnableInput(aa);//之后是Gate
		AriderCharacter *ab=Cast<AriderCharacter>(UGameplayStatics::GetPlayerCharacter(this,0));
		this->WidgetComponent->SetVisibility(1);
		this->WidgetComponent->SetHiddenInGame(0,0);
	}
}

void AMerchant_1::chulai(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
	AActor *a=UGameplayStatics::GetPlayerPawn(GetWorld(),0);
	if(OtherActor == a)
	{
		UE_LOG(LogTemp,Error,TEXT("出去了"));
		APlayerController *aa=UGameplayStatics::GetPlayerController(this,0);
		AActor::EnableInput(aa);//之后是Gate
		AriderCharacter *ab=Cast<AriderCharacter>(UGameplayStatics::GetPlayerCharacter(this,0));
		this->WidgetComponent->SetVisibility(0);
	}
}

