// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Curves/CurveFloat.h"
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

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UBoxComponent* Body;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* BodyMesh;

	UPROPERTY(BlueprintReadWrite, Category = "Movement Parameters")
	float ForwardValue;
	UPROPERTY(BlueprintReadWrite, Category = "Movement Parameters")
	float TurnValue;
	UPROPERTY(EditAnywhere, Category = "Movement Parameters")
	float TurnRate = 2;
	UPROPERTY(EditAnywhere, Category = "Movement Parameters")
	float AccForce = 10;
	UPROPERTY(EditAnywhere, Category = "Movement Parameters")
	float SlideForce = 40;
	UPROPERTY(EditAnywhere, Category = "Movement Parameters")
	FRuntimeFloatCurve TurnCurve;

	void Forward();
	void Turn();
	void AntiSlide();
	void ForwardInput(float AxisValue);
	void TurnInput(float AxisValue);

public:
	UPROPERTY(BlueprintReadWrite, Category = "Movement Parameters")
		float MobileForwardValue;
	UPROPERTY(BlueprintReadWrite, Category = "Movement Parameters")
		float MobileTurnValue;

	
};
