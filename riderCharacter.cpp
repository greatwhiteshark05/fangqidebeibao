// Copyright Epic Games, Inc. All Rights Reserved.

#include "riderCharacter.h"
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "PhysicsAssetUtils.h"
#include "riderGameMode.h"
#include "Kismet/GameplayStatics.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

AriderCharacter::AriderCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
		
	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	
	InteractionComp = CreateDefaultSubobject<UUSurInteractionComponent>("InteractionComp");
	//没这两句闪退。但可以编译
	InventoryRef =CreateWidget<UInventory>(UGameplayStatics::GetPlayerController(GetWorld(), 0), LoadClass<UInventory>(NULL, TEXT("/Game/blueprints/Widget/BP_Inventory.BP_Inventory_C")));
	
}

void AriderCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();
	//Add Input Mapping Context、
	
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////Script/UMGEditor.WidgetBlueprint''
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
	
	InventoryRef->AddToViewport();
	
	AGameModeBase* MyGameMode = GetWorld()->GetAuthGameMode();
	AriderGameMode *asd=Cast<AriderGameMode>(MyGameMode);
	if (asd)
	{
		asd->Danta->AddToViewport();
	}
	
}

void AriderCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	// 交互
	PlayerInputComponent->BindAction("PrimaryInteract", IE_Pressed, this, &AriderCharacter::PrimaryInteract);
	//PlayerInputComponent->BindAction("GGG", IE_Pressed, this, &AriderCharacter::FFF);

	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AriderCharacter::Move);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AriderCharacter::Look);
		
		EnhancedInputComponent->BindAction(FFFAction,ETriggerEvent::Completed,this,&AriderCharacter::PrimaryInteract);
		EnhancedInputComponent->BindAction(FFFAction,ETriggerEvent::Canceled,this,&AriderCharacter::PrimaryInteract);
		EnhancedInputComponent->BindAction(FFFAction,ETriggerEvent::Started,this,&AriderCharacter::PrimaryInteract);
		EnhancedInputComponent->BindAction(FFFAction,ETriggerEvent::Started,this,&AriderCharacter::FFF);
		//打开或者关闭背包
		EnhancedInputComponent->BindAction(BeibaoAction, ETriggerEvent::Started, this, &AriderCharacter::CaozuoBeibao);
		//捡起物体
		EnhancedInputComponent->BindAction(JianqiAction, ETriggerEvent::Started, this, &AriderCharacter::Jianqiwuti);
		
	}	
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
	
}

void AriderCharacter::Move(const FInputActionValue& Value)
{
	
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	
		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	
	 		
	}
}

void AriderCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}
void AriderCharacter::FFF(const FInputActionValue& Value)
{

	UE_LOG(LogTemp,Error,TEXT("asdasd"));
	//MainWidget->InventoryWidget=InventoryRef;
	//这个并不会把InventoryRef里的UserWidget传递给ManWidget。必须独立CreateWidget创建MainWidget->InventoryWidget的与用户控件，
	//但是背包里的增删改查是直接CreateWidget用户的InventoryRef,
	//MainWidget->Construct2();
//	MainWidget->SlotPanel->ClearChildren();
}

void AriderCharacter::CaozuoBeibao(const FInputActionValue& Value)
{
	if(InventoryRef->IsVisible==1)
	{
		
		InventoryRef->HideInventory();
		
	}else
	{
		InventoryRef->ShowInventory();
	}
}

void AriderCharacter::Jianqiwuti(const FInputActionValue& Value)
{
	UE_LOG(LogTemp,Error,TEXT("捡起来了"));
	if(NearByPickUpActors.Num()>0)
	{
		InventoryRef->AddItem(this,NearByPickUpActors[0]->InventorySlot->Amount2,NearByPickUpActors[0]);
		NearByPickUpActors[0]->Destroy();
		
	}
}

bool AriderCharacter::Equipitem(AMasterItem* Item)
{
	if(EquippedWeapon)
	{
		if(UEquipitem(EquippedWeapon))
		{
			Equipitem(Item);
			return 1;
		}else
		{
			
			return 0;
		}
	}else
	{
		
	}
	return 1;
}

bool AriderCharacter::UEquipitem(AMasterItem* Item)
{
	return 1;
}

void AriderCharacter::PrimaryInteract() {

	InteractionComp->PrimaryInteract();
}

void AriderCharacter::PrimaryInteract2()
{
	InteractionComp->PrimaryInteract2();
	UE_LOG(LogTemp,Error,TEXT("请销毁UI界面"));
}

void AriderCharacter::PrimaryInteract3()
{
	UE_LOG(LogTemp,Error,TEXT("开启Ui界面"));
	InteractionComp->PrimaryInteract3();
}