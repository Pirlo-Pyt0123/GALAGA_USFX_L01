// Copyright Epic Games, Inc. All Rights Reserve


#include "GameFramework/ProjectileMovementComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "GALAGA_USFX_L01Pawn.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/StaticMesh.h"
#include  "naveEnemigaCazaSigilosa.h"


AGALAGA_USFX_L01Projectile::AGALAGA_USFX_L01Projectile() 
{
	// Static reference to the mesh to use for the projectile
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ProjectileMeshAsset(TEXT("StaticMesh'/Game/TwinStick/Meshes/BulletEnemyLevel2.BulletEnemyLevel2'"));

	// Create mesh component for the projectile sphere
	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh0"));
	ProjectileMesh->SetStaticMesh(ProjectileMeshAsset.Object);
	ProjectileMesh->SetupAttachment(RootComponent);
	ProjectileMesh->BodyInstance.SetCollisionProfileName("Projectile");
	ProjectileMesh->OnComponentHit.AddDynamic(this, &AGALAGA_USFX_L01Projectile::OnHit);		// set up a notification for when this component hits something
	RootComponent = ProjectileMesh;
	static ConstructorHelpers::FObjectFinder<USoundBase> FireAudio(TEXT("SoundWave'/Game/TwinStick/Audio/laser.laser'"));
	FireSound = FireAudio.Object;
	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement0"));
	ProjectileMovement->UpdatedComponent = ProjectileMesh;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = false;
	ProjectileMovement->ProjectileGravityScale = 0.f; // No gravity

	// Die after 3 seconds by default
	InitialLifeSpan = 3.0f;

	GunOffset = FVector(90.f, 0.f, 0.f);
	bCanFire = true;
	
	
}



void AGALAGA_USFX_L01Projectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Only add impulse and destroy projectile if we hit a physics
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->AddImpulseAtLocation(GetVelocity() * 20.0f, GetActorLocation());
	}

	Destroy();
	//AActor* nave = Cast<AActor>(OtherActor);
	//nave->Destroy();
}









