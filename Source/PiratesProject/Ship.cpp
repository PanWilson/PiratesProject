// Fill out your copyright notice in the Description page of Project Settings.

#include "Ship.h"
#include "Components/BoxComponent.h"
#include "Components/InputComponent.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
AShip::AShip()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Body = CreateAbstractDefaultSubobject<UBoxComponent>(TEXT("Root object"));
	Body->SetSimulatePhysics(true);
	RootComponent = Body;

	BodyMesh = CreateAbstractDefaultSubobject<UStaticMeshComponent>(TEXT("Basic Mesh"));
	BodyMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

}

// Called when the game starts or when spawned
void AShip::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AShip::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("MoveForward", this, &AShip::ForwardInput);
	InputComponent->BindAxis("Turn", this, &AShip::TurnInput);

}

void AShip::ForwardInput(float AxisValue) {

	ForwardValue = AxisValue;

}

void AShip::TurnInput(float AxisValue) {

	TurnValue = AxisValue;

}

void AShip::Forward() {

	FVector Force = Body->GetForwardVector() * ForwardValue * AccForce;
	Body->AddForce(Force, NAME_None, true);

}

void AShip::Turn() {

	FVector Force = Body->GetUpVector() * TurnValue * TurnRate;
	Body->AddTorqueInRadians(Force, NAME_None, true);

}