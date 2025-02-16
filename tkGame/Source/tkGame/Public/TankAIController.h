// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */

class ATank;

UCLASS()
class TKGAME_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

private:
	ATank* GetTankControled() const;
	ATank* GetPlayerTank() const;
	virtual void Tick(float DeltaTime) override;
	
	
};
