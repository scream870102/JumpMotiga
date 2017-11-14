// Fill out your copyright notice in the Description page of Project Settings.

#include "Obstacle.h"


// Sets default values
AObstacle::AObstacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AddSphereCompont();
	AddStaticMeshComponet();
}

// Called when the game starts or when spawned
void AObstacle::BeginPlay()
{
	Super::BeginPlay();

	//Init YSpeed
	YSpeed = FMath::RandRange(YSpeedMIn, YSpeedMax);

	//SetTimer To call the EndPlay Function
	GetWorld()->GetTimerManager().SetTimer(ObstacleTimerHandle,this,&AObstacle::deleteSelf, 10.0f, false);

	UE_LOG(LogTemp, Warning, TEXT("%s spawn"), *GetName());
	
}

// Called every frame
void AObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//When Spawn call athlectics function
	athlectics(DeltaTime);
}

//EndPlay function
void AObstacle::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	UE_LOG(LogTemp, Error, TEXT("%s destroyed"),*GetName());
	Destroy();
}


//Add Sphere make Obstacle can react physic
void AObstacle::AddSphereCompont()
{
	// Our root component will be a sphere that reacts to physics
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	RootComponent = SphereComponent;
	SphereComponent->InitSphereRadius(40.0f);
	SphereComponent->SetCollisionProfileName(TEXT("Obstacle"));
	//Set collsion block all
	//answers.unrealengine.com/questions/111274/why-does-a-c-generated-static-mesh-not-block-my-co.html
	SphereComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);

	//Add tags to the sphere Componets when the actor hit the components which have diesign will call its endplay function
	Tags.Add(TEXT("DieSign"));
	SphereComponent->ComponentTags = Tags;
}

void AObstacle::AddStaticMeshComponet()
{
	//docs.unrealengine.com/latest/INT/Programming/Tutorials/Components/1/
	// Create and position a mesh component so we can see where our sphere is
	SphereVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	SphereVisual->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));
	if (SphereVisualAsset.Succeeded())
	{
		SphereVisual->SetStaticMesh(SphereVisualAsset.Object);
		SphereVisual->SetRelativeLocation(FVector(0.0f, 0.0f,-40.0f));
		SphereVisual->SetWorldScale3D(FVector(1.2f));
		SphereVisual->ComponentTags = Tags;
	}
}

//Set how Obstacle will move
void AObstacle::athlectics(float DeltaTime)
{
	FVector InitLocation=GetActorLocation();
	FVector NewLocation = InitLocation + FVector(0.0f, YSpeed, 0.0f);
	SetActorLocation(NewLocation);
}

//Make Timer can call EndPlay function
void AObstacle::deleteSelf()
{
	EndPlay(EndPlayReason);
}




