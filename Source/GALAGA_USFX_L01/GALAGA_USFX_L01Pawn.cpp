// Copyright Epic Games, Inc. All Rights Reserved.

#include "GALAGA_USFX_L01Pawn.h"
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
#include "proyectilAmigo.h"
#include "shieldActive.h"


const FName AGALAGA_USFX_L01Pawn::MoveForwardBinding("MoveForward");
const FName AGALAGA_USFX_L01Pawn::MoveRightBinding("MoveRight");
const FName AGALAGA_USFX_L01Pawn::FireForwardBinding("FireForward");
const FName AGALAGA_USFX_L01Pawn::FireRightBinding("FireRight");

AGALAGA_USFX_L01Pawn::AGALAGA_USFX_L01Pawn()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO'"));
	// Create the mesh component
	ShipMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	RootComponent = ShipMeshComponent;
	ShipMeshComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	ShipMeshComponent->SetStaticMesh(ShipMesh.Object);

	// Cache our sound effect
	static ConstructorHelpers::FObjectFinder<USoundBase> FireAudio(TEXT("SoundWave'/Game/TwinStick/Audio/laser.laser'"));
	FireSound = FireAudio.Object;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when ship does
	CameraBoom->TargetArmLength = 1900.f;
	CameraBoom->SetRelativeRotation(FRotator(-70.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	CameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	CameraComponent->bUsePawnControlRotation = false;	// Camera does not rotate relative to arm

	// Movement
	MoveSpeed = 1000.0f;
	// Weapon
	GunOffset = FVector(90.f, 0.f, 0.f);
	FireRate = 0.1f;
	bCanFire = true;

	StartLocation = FVector(-1449.0, -15.0, 244.0);
	moveSaltarAndRegresar = CreateDefaultSubobject<UMovimientoRegreso>(TEXT("movimiento"));

}

void AGALAGA_USFX_L01Pawn::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);

	// set up gameplay key bindings
	PlayerInputComponent->BindAxis(MoveForwardBinding);
	PlayerInputComponent->BindAxis(MoveRightBinding);
	PlayerInputComponent->BindAxis(FireForwardBinding);
	PlayerInputComponent->BindAxis(FireRightBinding);



	////Teclas 00010
	//tecla Regreso a punto inicial
	FInputActionKeyMapping Regresar("volverInicio", EKeys::G, 0, 0, 0, 0);
	//tecla saltar modificado
	FInputActionKeyMapping saltando("Saltar", EKeys::T, 0, 0, 0, 0);
	//tecla teletransporte modificado
	FInputActionKeyMapping tepe("Teleport", EKeys::F, 0, 0, 0, 0);
	//tecla escudo modificado se encuentra en el archivo shieldActive.cpp

	//tecla doble disparo modificado
	FInputActionKeyMapping dobleDisparo("DobleShoot", EKeys::J, 0, 0, 0, 0);







	//Agregando las teclas al motor
	//agregado tecla regreso a punto inicial
	UPlayerInput::AddEngineDefinedActionMapping(Regresar);

	//agregado tecla saltar
	UPlayerInput::AddEngineDefinedActionMapping(saltando);

	//agregado tecla teletransporte
	UPlayerInput::AddEngineDefinedActionMapping(tepe);

	//agregado tecla doble disparo
	UPlayerInput::AddEngineDefinedActionMapping(dobleDisparo);


	// Bind actions

	// Vincular las acciones a los métodos correspºondientes de la clase AGALAGA_USFX_L01Pawn
	//tecla regreso a punto inicial
	PlayerInputComponent->BindAction("volverInicio", EInputEvent::IE_Pressed, this, &AGALAGA_USFX_L01Pawn::PointRegreso);
	//tecla saltar
	PlayerInputComponent->BindAction("Saltar", EInputEvent::IE_Pressed, this, &AGALAGA_USFX_L01Pawn::Saltar);
	//tecla teletransporte
	PlayerInputComponent->BindAction("Teleport", EInputEvent::IE_Pressed, this, &AGALAGA_USFX_L01Pawn::Teletransporte);
	//tecla doble disparo
	PlayerInputComponent->BindAction("DobleShoot", EInputEvent::IE_Pressed, this, &AGALAGA_USFX_L01Pawn::FireProjectile);




}

//funcion para regresar a la posicion inicial
void AGALAGA_USFX_L01Pawn::PointRegreso()
{
	moveSaltarAndRegresar->iniciarRegreso(true, StartLocation, 0);
}
//funcion para saltar
void AGALAGA_USFX_L01Pawn::Saltar()
{
	moveSaltarAndRegresar->jump();
}
//funcion para teletransportar
void AGALAGA_USFX_L01Pawn::Teletransporte()
{
	SetActorLocation(StartLocation + FVector(0.0f, 0.0f, 244.0f));
}


//funcion para dispararDoble
void AGALAGA_USFX_L01Pawn::FireProjectile()
{
	// Spawn two projectiles
	FVector SpawnLocation = GetActorLocation();
	FRotator FireRotation = GetActorRotation();
	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		// spawn the projectile
		World->SpawnActor<AGALAGA_USFX_L01Projectile>(SpawnLocation + 20, FireRotation);
		World->SpawnActor<AGALAGA_USFX_L01Projectile>(SpawnLocation + 80, FireRotation);

	}
	if (FireSound != nullptr)
	{
		UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Disparo"));
}

void AGALAGA_USFX_L01Pawn::Tick(float DeltaSeconds)
{

	// Find movement direction
	const float ForwardValue = GetInputAxisValue(MoveForwardBinding);
	const float RightValue = GetInputAxisValue(MoveRightBinding);




	// Clamp max size so that (X=1, Y=1) doesn't cause faster movement in diagonal directions

	const FVector MoveDirection = FVector(ForwardValue, RightValue, 0).GetClampedToMaxSize(1.0f);


	/*if (GetActorLocation().Z >= AlturaMaxima)
	{
		salto1 = -1.0f;
	}
	else if(GetActorLocation().Z <= 245.0f)
	{
		salto1 = 0.0f;
	}*/


	// Calculate  movement
	const FVector Movement = MoveDirection * MoveSpeed * DeltaSeconds;

	// If non-zero size, move this actor
	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = Movement.Rotation();
		FHitResult Hit(1.f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);

		if (Hit.IsValidBlockingHit())
		{
			const FVector Normal2D = Hit.Normal.GetSafeNormal2D();
			const FVector Deflection = FVector::VectorPlaneProject(Movement, Normal2D) * (1.f - Hit.Time);
			RootComponent->MoveComponent(Deflection, NewRotation, true);
		}
	}

	// Create fire direction vector
	const float FireForwardValue = GetInputAxisValue(FireForwardBinding);
	const float FireRightValue = GetInputAxisValue(FireRightBinding);
	const FVector FireDirection = FVector(FireForwardValue, FireRightValue, 0.f);

	// Try and fire a shot
	FireShot(FireDirection);








}

void AGALAGA_USFX_L01Pawn::FireShot(FVector FireDirection)
{
	// If it's ok to fire again
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
			World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &AGALAGA_USFX_L01Pawn::ShotTimerExpired, FireRate);

			// try and play the sound if specified
			if (FireSound != nullptr)
			{
				UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
			}

			bCanFire = false;
		}
	}
}

void AGALAGA_USFX_L01Pawn::ShotTimerExpired()
{
	bCanFire = true;
}
