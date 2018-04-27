// Fill out your copyright notice in the Description page of Project Settings.

#include "Cannon.h"

void ACannon::BeginPlay()
{
	UWorld* const World = GetWorld();
	if (World)
	{
		angle = FMath::Atan(4 * maxHeight / range);
		LaunchVelocity = FMath::Sqrt(range * World->GetGravityZ() *-1 / FMath::Sin(2 * angle));
	}
}

void ACannon::Shoot_Implementation()
{
	if(ProjectileClass != NULL)
	{
		UWorld* const World = GetWorld();
		if(World)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = Instigator;
			ACannonBall* const Projectile = World->SpawnActor<ACannonBall>(ProjectileClass, GetActorLocation(), GetActorRotation(), SpawnParams);
			if(Projectile)
			{
				FVector const LaunchVector = GetActorForwardVector().RotateAngleAxis(FMath::RadiansToDegrees(angle) * -1, GetActorRightVector()) * LaunchVelocity;
				Projectile->Damage = Damage;
				Projectile->InitVelocity(LaunchVector);
			}
		}
	}
}


