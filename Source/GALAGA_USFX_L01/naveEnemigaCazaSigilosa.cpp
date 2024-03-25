// Fill out your copyright notice in the Description page of Project Settings.


#include "naveEnemigaCazaSigilosa.h"
#include "naveEnemigaCaza.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "GALAGA_USFX_L01Projectile.h"
#include "TimerManager.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Engine/CollisionProfile.h"
#include "Engine/StaticMesh.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"



AnaveEnemigaCazaSigilosa::AnaveEnemigaCazaSigilosa()
{
	posicion = GetActorLocation();
	


}
void AnaveEnemigaCazaSigilosa::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);

    Disparar (FVector(-1,0,0));
    
}



void AnaveEnemigaCazaSigilosa::Mover(float DeltaTime)
{
	AnaveEnemigaCaza::Mover(DeltaTime);
	velocity = 3;
	SetActorLocation(FVector(GetActorLocation().X - velocity, GetActorLocation().Y + velocity * bandera, GetActorLocation().Z));
	if (GetActorLocation().Y > GetPosicion().Y +100 || GetActorLocation().Y < GetPosicion().Y-200){
		bandera *= -1;

	}
	if (GetActorLocation().X < -1800) {
		SetActorLocation(FVector(posicion));
	}
}

void AnaveEnemigaCazaSigilosa::Disparar(FVector DireccionFuego)
{
	if (bDisparando)
	{
		if (DireccionFuego.SizeSquared() > 0.0f)
		{
			const FRotator FireRotation = DireccionFuego.Rotation();
			const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOfsset);

			UWorld* const World = GetWorld();
			if (World != nullptr)
			{
				World->SpawnActor<AGALAGA_USFX_L01Projectile>(SpawnLocation, FireRotation);
			}

			bDisparando = false;

			World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &AnaveEnemigaCaza::ShotTimerExpired, 1.0f, false);
		}

	}
}

void AnaveEnemigaCazaSigilosa::destruirse()
{


}


void AnaveEnemigaCazaSigilosa::Escapar()
{
	
}


