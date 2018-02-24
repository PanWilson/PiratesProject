// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Ship.generated.h"

UCLASS()
class PIRATESPROJECT_API AShip : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AShip();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere)
	class UBoxComponent* Body;
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* BodyMesh;

	float ForwardValue;
	float TurnValue;
	UPROPERTY(EditAnywhere, Category = "Movement Parameters")
	float TurnRate;
	UPROPERTY(EditAnywhere, Category = "Movement Parameters")
	float AccForce;

	void ForwardInput(float AxisValue);
	void TurnInput(float AxisValue);

	void Forward();
	void Turn();
	
};
