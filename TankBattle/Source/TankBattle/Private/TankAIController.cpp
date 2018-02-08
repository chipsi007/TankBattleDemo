// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


ATank * ATankAIController::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto aiControlledTank = GetAIControlledTank();


	if (!aiControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Not possessing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI controller possessing: %s"), *(aiControlledTank->GetName()));

	}
}