// Fill out your copyright notice in the Description page of Project Settings.

#include "HitDetect.h"


// Sets default values for this component's properties
UHitDetect::UHitDetect()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UHitDetect::BeginPlay()
{
	Super::BeginPlay();

	//Init CapsuleComponents
	FindCapsuleComponents();
	//Bind collision component to hit function
	CollisionComponent->OnComponentHit.AddDynamic(this, &UHitDetect::OnHit);
	
}


// Called every frame
void UHitDetect::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHitDetect::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	//Get hitting actor name
	if (OtherActor)
		UE_LOG(LogTemp, Warning, TEXT("Hit by %s"), *OtherActor->GetName());
	if (OtherComponent)
		UE_LOG(LogTemp, Warning, TEXT("Hit by %s"), *OtherComponent->GetName());

	//Check if hit Obstacle hit it then endplay
	if (OtherComponent->ComponentHasTag(FName("DieSign"))) {
		UE_LOG(LogTemp, Warning, TEXT("Hit by %s and will die"), *OtherActor->GetName());
		Owner->EndPlay(EndPlayReason);
	}
		
}

void UHitDetect::FindCapsuleComponents() {
	CollisionComponent = GetOwner()->FindComponentByClass<UCapsuleComponent>();

	//Protect CollisionComponent
	if (CollisionComponent == nullptr)
		UE_LOG(LogTemp, Error, TEXT("%s missing the CapsuleComponent"), *GetOwner()->GetName());
	if (CollisionComponent)
		UE_LOG(LogTemp, Error, TEXT("%s find the CapsuleComponent"), *GetOwner()->GetName());
}


