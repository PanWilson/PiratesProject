// Fill out your copyright notice in the Description page of Project Settings.

#include "CannonBall.h"


// Sets default values
ACannonBall::ACannonBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

ACannonBall::ACannonBall(const FObjectInitializer& ObjectInitializer):Super(ObjectInitializer)
{
	// Use a sphere as a simple collision representation
	CollisionComp = ObjectInitializer.CreateDefaultSubobject<USphereComponent>(this, TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(15.0f);
	RootComponent = CollisionComp;

	ProjectileMovement = ObjectInitializer.CreateDefaultSubobject<UProjectileMovementComponent>(this, TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = CollisionComp;

	Mesh = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("MeshComponent"));
	Mesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ACannonBall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACannonBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACannonBall::InitVelocity(const FVector ShootDirection)
{
	if(ProjectileMovement)
	{
		ProjectileMovement->Velocity = ShootDirection;
	}
}
