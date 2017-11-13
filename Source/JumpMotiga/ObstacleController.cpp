// Fill out your copyright notice in the Description page of Project Settings.

#include "ObstacleController.h"


// Sets default values
AObstacleController::AObstacleController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AObstacleController::BeginPlay()
{
	Super::BeginPlay();

}



// Called every frame
void AObstacleController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//UpdateObstacleNum();
	// && currentObstracleNum <= MaxObstacleNum
	if (bCanGenerateObstacle)
	{
		SpawnObstacle();
		//UpdateObstacleNum();
	}
}


void AObstacleController::UpdateTimer()
{
	bCanGenerateObstacle = true;
	GetWorld()->GetTimerManager().ClearTimer(GenerateObstacleTimerHandle);
}

void AObstacleController::SpawnObstacle()
{
	//Set boolean false avoid spawn too much obstacle
	bCanGenerateObstacle = false;

	//Spawn The Obstacle
	UE_LOG(LogTemp, Warning, TEXT("Actor is being spawned"));
	FVector Location(1207.272f, -2000.0f, 204.6241f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;
	GetWorld()->SpawnActor<AObstacle>(Location, Rotation, SpawnInfo);

	//Set the Timer And Update the boolean after SpawnFrequency
	GetWorld()->GetTimerManager().SetTimer(GenerateObstacleTimerHandle, this, &AObstacleController::UpdateTimer, SpawnFrequency, false);
}

void AObstacleController::UpdateObstacleNum()
{
	//Update the Num try to get the Obstacle in the level
}
