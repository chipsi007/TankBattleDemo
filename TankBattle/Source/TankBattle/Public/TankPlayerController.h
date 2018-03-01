// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TANKBATTLE_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
void BeginPlay() override;
virtual void Tick(float DeltaTime) override;


private:
	ATank * GetControlledTank() const; 
	void ATankPlayerController::AimTowardsCrosshair();
	bool ATankPlayerController::GetSightRayHitLocation(FVector & OutHitLocation) const;
	bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const;
	bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector &Hitlocation) const;

private:
	UPROPERTY(EditAnywhere)
	float crossHairXLocation = 0.5f;

	UPROPERTY(EditAnywhere)
	float crossHairYLocation = 0.33333f;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 100000.0f;
};
