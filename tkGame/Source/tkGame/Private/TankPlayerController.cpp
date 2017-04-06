// Fill out your copyright notice in the Description page of Project Settings.

#include "tkGame.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay() 
{
	Super::BeginPlay();

	auto ControlledTank = GetTankControled();

	if(!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing tank"));
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController tank possessed: %s"), *(ControlledTank->GetName()));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp, Warning, TEXT("Hell yeah, i am ticking"));
}


ATank* ATankPlayerController::GetTankControled() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrossHair() 
{
	if (!GetTankControled()) 
	{
		return;
	}
}