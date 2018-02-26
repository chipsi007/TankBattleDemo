// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

ATank * ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn()); 
}


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay(); 
	auto controlledTank = GetControlledTank(); 
	
	
	if (!controlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Not possessing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s"), *(controlledTank->GetName()));

	}

	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//UE_LOG(LogTemp, Warning, TEXT("Ticking"));
	AimTowardsCrosshair(); 
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return;  }

}