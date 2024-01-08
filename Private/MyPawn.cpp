// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"
#include"deng.h"
#include "diaoluowu.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputAction.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "rider/riderCharacter.h"

#include "danxiancheng1.h"//!!!
#include "Blueprint/UserWidget.h"

#include "TimerManager.h"
// Sets default values
AMyPawn::AMyPawn()
{
	
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MyDoor = CreateDefaultSubobject<USceneComponent>(TEXT("My Door"));
	MyDoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My DoorMesh"));
	MyDoorMesh->SetupAttachment(MyDoor);
	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("My Box"));
	Box->SetupAttachment(MyDoor);

}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	Box->OnComponentBeginOverlap.AddDynamic(this,&AMyPawn::xiaohui);
	if(APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::
			GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}else
	{
		UE_LOG(LogTemp,Error,TEXT("失败了"));
	}
//	GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &AMyPawn::RepeatingFunction, 2.0f, true, 5.0f);

	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	//Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
		
		// Jumping
		EnhancedInputComponent->BindAction(FFFAction,ETriggerEvent::Started,this,&AMyPawn::FFF);
		
	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("失败了啊啊啊啊啊啊！"), *GetNameSafe(this));
	}
	
}

void AMyPawn::xiaohui(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
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


void AMyPawn::FFF(const FInputActionValue& Value)
{

	UE_LOG(LogTemp,Error,TEXT("删除"));

}
void AMyPawn::Interact_Implementation(APawn* InstigatorPawn)
{
	if (GetWorld())
	{
		
		
		TArray<AActor*> Actors;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(),Adeng::StaticClass(), Actors);
		for (AActor* Actor : Actors)
		{
			Adeng *Shanshuo;
			Shanshuo = Cast<Adeng>(Actor);
			danxiancheng1 *m_Danxiancheng=new danxiancheng1(Shanshuo);
			//danxiancheng1 *m_Danxiancheng2=new danxiancheng1(Shanshuo2);
			//开启线程
			FRunnableThread *RunnableThread = FRunnableThread::Create(m_Danxiancheng,TEXT("线程名称1"));
		}
	}
	
	
}