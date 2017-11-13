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

	//Get the Num of Obstacle and frequency from Editor
	UPROPERTY(EditAnyWhere)
		int32 MaxObstacleNum;
	UPROPERTY(EditAnyWhere)
		float SpawnFrequency;

	//Handles the delay between the Obstacle Generate
	FTimerHandle GenerateObstacleTimerHandle;

	//Check the Timer and set the boolea to check is now can generate obstacle
	bool bCanGenerateObstacle=true;

	//To get the current num of obstacle in the level
	int currentObstracleNum;

	//If Obstacle is been spawned then will call it to reset the boolean bVanGenerateObstacle and clean GenerateObstacleTimerHandle
	void UpdateTimer();

	//It will spawn obstacle and set bCanGenerateObstacle false after SpawnFrequnecy call UpdateTimer
	void SpawnObstacle();

	//Update num of obstacle in level and set Num to currentObstacleNum
	void UpdateObstacleNum();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
