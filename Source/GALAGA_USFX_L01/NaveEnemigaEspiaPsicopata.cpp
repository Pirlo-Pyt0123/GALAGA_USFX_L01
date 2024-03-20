// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaEspiaPsicopata.h"
#include "GALAGA_USFX_L01Projectile.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

#include "GALAGA_USFX_L01Pawn.h"

ANaveEnemigaEspiaPsicopata::ANaveEnemigaEspiaPsicopata()
{
	posicion = FVector(1200, -1000, 250);
	posicion = FVector(1200, 1000, 250);
	float xc=200,yc=50,zc=250;
	GunOffset = FVector(90.f, 0.f, 0.f);
	FireRate = 0.1f;
	bCanFire = true;
}



void ANaveEnemigaEspiaPsicopata::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
	

}

void ANaveEnemigaEspiaPsicopata::FireShot(FVector FireDirection)
{
	if (bCanFire == true)
	{
		// If we are pressing fire stick in a direction
		if (FireDirection.SizeSquared() > 0.0f)
		{
			const FRotator FireRotation = FireDirection.Rotation();
			// Spawn projectile at an offset from this pawn
			const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

			UWorld* const World = GetWorld();
			if (World != nullptr)
			{
				// spawn the projectile
				World->SpawnActor<AGALAGA_USFX_L01Projectile>(SpawnLocation, FireRotation);
			}

			bCanFire = false;
			



		}
	}
}



void ANaveEnemigaEspiaPsicopata::Mover(float DeltaTime)
{
	ANaveEnemigaEspia::Mover(DeltaTime);
	bandera++;
	if (bandera < 300 && bandera >0) {

		SetActorLocation(FVector(GetActorLocation().X + GetSpeed(), GetActorLocation().Y, GetActorLocation().Z));
	}
	else if (bandera > 300) {
		bandera = -100;
	}
	else {
		SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y + GetSpeed(), GetActorLocation().Z));
	}

	if (GetActorLocation().X < -1800) {

		SetActorLocation(FVector(posicion));

	}
	
}

void ANaveEnemigaEspiaPsicopata::destruirse()
{
	ANaveEnemigaEspia::destruirse();
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("NaveEnemigaEspiaPsicopata destruida"));
	Destroy();

}

void ANaveEnemigaEspiaPsicopata::Disparar(bool bAtacar)
{
	
}
