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

	FVector HitLocation; 
	if (GetSightRayHitLocation(HitLocation))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Ray direction: %s"), *HitLocation.ToString());
		//TODO Tell controlled Tank to aim at this point. 
	}
	
}

bool const ATankPlayerController::GetSightRayHitLocation(FVector & OutHitLocation)
{
	int32 viewportSizeX, viewportSizeY; 
	GetViewportSize(viewportSizeX, viewportSizeY); // out params. 
	auto screenLocation = FVector2D(viewportSizeX * crossHairXLocation, viewportSizeY * crossHairYLocation);

	//"De-pproject" the screen posisiton of the crosshair to a world dirction
	//line-trace along that look direction and see what we hit( up to max range )
	return true;
}