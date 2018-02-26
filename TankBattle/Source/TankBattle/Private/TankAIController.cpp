// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


ATank * ATankAIController::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	
	auto playerTank = GetPlayerTank(); 

	if (!playerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController can't find player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController Found: %s"), *(playerTank->GetName()));

	}
}

