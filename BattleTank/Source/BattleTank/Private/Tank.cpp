// Copyright Test.

#include "Tank.h"
#include "Engine/World.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankAimingComponent.h"
#include "TankMovementComponent.h"

// Sets default values
ATank::ATank()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	UE_LOG(LogTemp, Warning, TEXT("------------ TANK CONSTRUCTOR "));
}

void ATank::BeginPlay()
{
	Super::BeginPlay();		// Needed for BP Begin Play to run!
	UE_LOG(LogTemp, Warning, TEXT("------------ TANK BEGINPLAY "));
}

void ATank::AimAt(FVector HitLocation)
{
	if (!TankAimingComponent)
		return;

	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::Fire()
{
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	
	
	//UE_LOG(LogTemp, Warning, TEXT("Projectile fired at %f"), isReloaded);


	if (Barrel && isReloaded)// && ProjectileBlueprint)
	{

		// Spawn a projectile at the socket location on the barrel
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, Barrel->GetSocketLocation(FName("Projectile")), Barrel->GetSocketRotation(FName("Projectile")));

		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}

