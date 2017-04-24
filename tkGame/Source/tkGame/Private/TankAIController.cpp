// Fill out your copyright notice in the Description page of Project Settings.

#include "tkGame.h"
#include "Tank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetTankControled();

	auto PlayerTank = GetPlayerTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController not possessing tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController tank possessed: %s"), *(ControlledTank->GetName()));
	}
	
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not found"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController tank found: %s"), *(PlayerTank->GetName()));
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank()) 
	{
		GetTankControled()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}

ATank* ATankAIController::GetTankControled() const
{
	return Cast<ATank>(GetPawn());
}


ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerTank) {
		return nullptr;
	}
	return Cast<ATank>(PlayerTank);
}