// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimerManager.h"
#include "Engine/World.h"
#include "Obstacle.h"
#include "ObstacleController.generated.h"

UCLASS()
class JUMPMOTIGA_API AObstacleController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObstacleController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Get frequency from Editor
	UPROPERTY(EditAnyWhere)
		float SpawnFrequency;

	//Handles the delay between the Obstacle Generate
	FTimerHandle GenerateObstacleTimerHandle;

	//Check the Timer and set the boolea to check is now can generate obstacle
	bool bCanGenerateObstacle=true;


	//If Obstacle is been spawned then will call it to reset the boolean bVanGenerateObstacle and clean GenerateObstacleTimerHandle
	void UpdateTimer();

	//It will spawn obstacle and set bCanGenerateObstacle false after SpawnFrequnecy call UpdateTimer
	void SpawnObstacle();


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
