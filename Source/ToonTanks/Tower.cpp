// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"

void ATower::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	// Find Distance to the Tank
	if (IsValid(Tank))
	{
		float Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());
		
		// Check to see if the Tank is in range
		if (Distance <= FireRange)
		{
			// If in range, rotate turret toward tank
			RotateTurret(Tank->GetActorLocation());
		}
		
	}
	
}

void ATower::BeginPlay()
{
	Super::BeginPlay();

	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
	
}
