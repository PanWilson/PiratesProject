// Fill out your copyright notice in the Description page of Project Settings.

#include "Ship.h"


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

	canMove = true;
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
	if (canMove) {
		Forward();
		Turn();
	}
	AntiSlide();
}

// Called to bind functionality to input
void AShip::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AShip::Forward() {

		FVector Force;
		Force = Body->GetForwardVector() * MobileForwardValue * AccForce;
		Body->AddForce(Force, NAME_None, true);

}

void AShip::Turn() {
	
	FVector Force;
	Force = Body->GetUpVector() * MobileTurnValue * TurnRate * TurnCurve.GetRichCurve()->Eval(MobileForwardValue);
	Body->AddTorqueInRadians(Force, NAME_None, true);

}

void AShip::AntiSlide() {

	float SlideFactor = FVector::DotProduct(Body->GetRightVector(), Body->GetComponentVelocity().GetSafeNormal());
	FVector Force = Body->GetRightVector() * SlideFactor * SlideForce *-1;
	Body->AddForce(Force, NAME_None, true);

}