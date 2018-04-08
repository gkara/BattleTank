﻿// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("ΑΙ Controller Begin Play"));

	APawn* ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("ΑΙ Controller not possessing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("ΑΙ Controller possessing: %s"), *(ControlledTank->GetName()));
	}
}


ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
