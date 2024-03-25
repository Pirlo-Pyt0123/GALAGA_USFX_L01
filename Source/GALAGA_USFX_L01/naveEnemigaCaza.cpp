// Fill out your copyright notice in the Description page of Project Settings.


#include "naveEnemigaCaza.h"
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


AnaveEnemigaCaza::AnaveEnemigaCaza()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/TwinStick/Meshes/EnemyLevel1.EnemyLevel1'"));
	NaveEnemigaMesh->SetStaticMesh(ShipMesh.Object);

    PrimaryActorTick.bCanEverTick = true;
	GunOfsset = FVector(90.0f, 0.0f, 0.0f);
	FireRate = 0.1f;
	bDisparando = true;


}

void AnaveEnemigaCaza::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
	Disparar(FVector(-1, 0, 0));

}
  
//voids mamalones


void AnaveEnemigaCaza::Mover(float DeltaTime)
{
	velocity = 1;
	SetActorLocation(FVector(GetActorLocation().X - velocity, GetActorLocation().Y, GetActorLocation().Z));

}

void AnaveEnemigaCaza::Disparar(FVector DireccionFuego)
{
	if (bDisparando)
	{  
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Disparando"));
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

void AnaveEnemigaCaza::destruirse()
{

}

void AnaveEnemigaCaza::Escapar()
{

}

void AnaveEnemigaCaza::ShotTimerExpired()
{
		bDisparando = true;
}




