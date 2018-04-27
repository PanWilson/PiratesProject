// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "CannonBall.h"
#include "Cannon.generated.h"

/**
 * 
 */
UCLASS()
class PIRATESPROJECT_API ACannon : public AWeapon
{
	GENERATED_BODY()

private:


	
public:
	UPROPERTY(EditDefaultsOnly, Category = "Cannon")
	float time;
	UPROPERTY(EditDefaultsOnly, Category = "Cannon")
	float maxHeight;

	float LaunchVelocity;
	float angle;

	void BeginPlay();

	virtual void Shoot_Implementation() override;
	
	UPROPERTY(EditDefaultsOnly, Category = "Projectile")
		TSubclassOf<ACannonBall> ProjectileClass;
	
};
