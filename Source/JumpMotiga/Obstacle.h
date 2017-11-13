// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "ConstructorHelpers.h"
#include "Math/UnrealMathUtility.h"
#include "Engine/EngineTypes.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "TimerManager.h"
#include "Obstacle.generated.h"

UCLASS()
class JUMPMOTIGA_API AObstacle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObstacle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	//SphereComponent make it can work in physic world
	USphereComponent* SphereComponent;

	//MeshComponent make obstacle visible
	UStaticMeshComponent* SphereVisual;

	//Tags to add to the componet
	TArray<FName>Tags;

	//EndPlay Function will be call if hit the edge
	void EndPlay(const EEndPlayReason::Type EndPlayReason);

	//Init ShpereComponet
	void AddSphereCompont();

	//Init StaticMeshComponent
	void AddStaticMeshComponet();

	//define what the obstacle will do when spawned
	void athlectics(float DeltaTime);

	//How Obstacle Move in Every frame
	float YSpeed=2.0f;

	//Handles the delay between the Obstacle Generate
	FTimerHandle ObstacleTimerHandle;

	//Make Timer call Endplay throgh this function
	void deleteSelf();

	//EndPlayReason
	EEndPlayReason::Type EndPlayReason;
};
