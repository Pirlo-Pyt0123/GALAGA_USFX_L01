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
const FName AGALAGA_USFX_L01Pawn::MoveUpBinding("MoveUpBinding");



void AGALAGA_USFX_L01Pawn::DropItem()
{
	if (MyInventory->CurrentInventory.Num() == 0)
	{
		return;
	}
	AMunicionBeta* Item =MyInventory->CurrentInventory.Last();
	MyInventory->RemoveFromInventory(Item);
	FVector ItemOrigin;
	FVector ItemBounds;
	Item->GetActorBounds(false, ItemOrigin, ItemBounds);
	FTransform PutDownLocation = GetTransform() + FTransform(RootComponent->GetForwardVector() *ItemBounds.GetMax());
	Item->PutDown(PutDownLocation);

}

void AGALAGA_USFX_L01Pawn::TakeItem(AMunicionBeta* InventoryItem)
{
	InventoryItem->PickUp();
	MyInventory->AddToInventory(InventoryItem);

}

void AGALAGA_USFX_L01Pawn::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	AMunicionBeta* InventoryItem =
		Cast<AMunicionBeta>(Other);
	if (InventoryItem != nullptr)
	{
		TakeItem(InventoryItem);
	}
}

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

	MyInventory =CreateDefaultSubobject<UInventarioComp>("MyInventory");
	
	 
	StartLocation = FVector(-1449.0, -15.0, 244.0);

	
	bCanJump = true;

	PuedeSaltar = true;

	salto1 = 0.0f;


	AlturaMaxima = 525.0f;
}

void AGALAGA_USFX_L01Pawn::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);

	// set up gameplay key bindings
	PlayerInputComponent->BindAxis(MoveForwardBinding);
	PlayerInputComponent->BindAxis(MoveRightBinding);
	PlayerInputComponent->BindAxis(FireForwardBinding);
	PlayerInputComponent->BindAxis(FireRightBinding);

	PlayerInputComponent->BindAxis(MoveUpBinding);



	//inventario

	//PlayerInputComponent->BindAction("OpenInventario",EInputEvent::IE_Pressed,this,&AGALAGA_USFX_L01Pawn::DropItem);
	//vuelve al inicio
	PlayerInputComponent->BindAction("RestartGame", EInputEvent::IE_Pressed, this, &AGALAGA_USFX_L01Pawn::ReturnToStart);
	// saltito papu

	PlayerInputComponent->BindAction("Salto", IE_Pressed, this, &AGALAGA_USFX_L01Pawn::Saltar);
	//PlayerInputComponent->BindAction("Salto", IE_Released, this, &AGALAGA_USFX_L01Pawn::DejarDeSaltar);
	PlayerInputComponent->BindAction("Disparo", IE_Pressed, this, &AGALAGA_USFX_L01Pawn::FireProjectile);


}

void AGALAGA_USFX_L01Pawn::FireProjectile()
{
	Super::BeginPlay();
	// Spawn two projectiles
	FVector SpawnLocation = GetActorLocation();
	FRotator FireRotation = GetActorRotation();
	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		// spawn the projectile
		World->SpawnActor<AGALAGA_USFX_L01Projectile>(SpawnLocation-40, FireRotation);
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

	const float HeightValue = GetInputAxisValue(MoveUpBinding);



	// Clamp max size so that (X=1, Y=1) doesn't cause faster movement in diagonal directions

	const FVector MoveDirection = FVector(ForwardValue, RightValue, 0+ salto1).GetClampedToMaxSize(1.0f);

	
	if (GetActorLocation().Z >= AlturaMaxima)
	{
		salto1 = -1.0f;
	}
	else if(GetActorLocation().Z <= 245.0f)
	{
		salto1 = 0.0f;
	}


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

void AGALAGA_USFX_L01Pawn::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
	Saltar();
}





void AGALAGA_USFX_L01Pawn::Saltar()
{

	//Temporizador con timerhandle

	salto1 = 1.0f;



	//GetWorldTimerManager().SetTimer(TiempoSalto, this, &AGALAGA_USFX_L01Pawn::DejarDeSaltar, 5.0f, false);


}

void AGALAGA_USFX_L01Pawn::DejarDeSaltar()
{
	//SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z - 100.0f));

	bCanJump = true;


}



void AGALAGA_USFX_L01Pawn::ReturnToStart()
{
		SetActorLocation(StartLocation);

	
}



