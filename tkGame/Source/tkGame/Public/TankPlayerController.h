// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TKGAME_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

	ATank* GetTankControled() const;
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	//Start the tank moving the Barrel so that a shot would hit where the crosshair
	//intersects with the world
	void AimTowardsCrossHair();

private:
	//return an out parameter, true if hit the landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;
};
