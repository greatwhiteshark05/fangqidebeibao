// Fill out your copyright notice in the Description page of Project Settings.


#include "USurInteractionComponent2.h"

#include "MyInterface2.h"

// Sets default values for this component's properties
UUSurInteractionComponent2::UUSurInteractionComponent2()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UUSurInteractionComponent2::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UUSurInteractionComponent2::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
void UUSurInteractionComponent2::PrimaryInteract()
{
	FHitResult Hit; // 检测结果

	FVector EyeLocation; // 角色眼睛位置
	FRotator EyeRotation; // 角色视线方向
	AActor* MyOwner = GetOwner(); // 获取控制角色
	// 将玩家视线的位置和方向输出到EyeLocation和EyeRotation
	MyOwner->GetActorEyesViewPoint(EyeLocation, EyeRotation);
	// 沿着视线方向，模型的眼睛位置开始1000cm距离的点为终点
	FVector End = EyeLocation + (EyeRotation.Vector() * 1000);

	FCollisionObjectQueryParams ObjectQueryParams; // 查询参数
	ObjectQueryParams.AddObjectTypesToQuery(ECC_WorldDynamic); // 选择查询场景动态对象

	GetWorld()->LineTraceSingleByObjectType(Hit, EyeLocation, End, ObjectQueryParams);
	AActor* HitActor = Hit.GetActor();
	if (HitActor) {
		// 如果检测到actor不为空，再判断actor有没有实现SurGameplayInterface类
		if (HitActor->Implements<UMyInterface2>()) {
			// 我们定义的Interact()传入为Pawn类型，因此做类型转换
			APawn* MyPawn = Cast<APawn>(MyOwner);
			// 多态，根据传入的HitActor调用相应函数
			// 第一个参数不能为空，所以外层已经判空；第二个参数是我们自定义的，暂时没有影响，可以不判空
			IMyInterface2::Execute_Interact(HitActor, MyPawn);
			// 用于debug，绘制这条碰撞检测的线，绿色
			DrawDebugLine(GetWorld(), EyeLocation, End, FColor::Green, false, 3);
		}
	}
	else{ DrawDebugLine(GetWorld(), EyeLocation, End, FColor::Red, false, 3); } 
	
} 