// Fill out your copyright notice in the Description page of Project Settings.

#include "tkGame.h"
#include "TankTurret.h"


void UTankTurret::Rotate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto ElevateChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = RelativeRotation.Yaw + ElevateChange;
	SetRelativeRotation(FRotator(0, RawNewRotation, 0));
}

