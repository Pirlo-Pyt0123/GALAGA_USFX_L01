// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimerManager.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "GALAGA_USFX_L01Pawn.h"
#include "GALAGA_USFX_L01Projectile.generated.h"

class UProjectileMovementComponent;
class UStaticMeshComponent;
class proyectilAmigo;
class AnaveEnemigaCazaSigilosa;

UCLASS(config=Game)
class AGALAGA_USFX_L01Projectile : public AActor
{
	GENERATED_BODY()

	/** Sphere collision component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Projectile, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* ProjectileMesh;
	UPROPERTY(EditAnywhere, Category = Projectile)
	TSubclassOf<class AGALAGA_USFX_L01Projectile> ProjectileClass;
	/** Projectile movement component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	UProjectileMovementComponent* ProjectileMovement;
private:
	uint32 bCanFire : 1;

	

	//FTimerHandle TimerHandle_ShotTimerExpired;
public:
	AGALAGA_USFX_L01Projectile();
	//virtual void DobleShoot();
	/** Function to handle the projectile hitting something */
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	/** Returns ProjectileMesh subobject **/
	FORCEINLINE UStaticMeshComponent* GetProjectileMesh() const { return ProjectileMesh; }
	/** Returns ProjectileMovement subobject **/
	FORCEINLINE UProjectileMovementComponent* GetProjectileMovement() const { return ProjectileMovement; }
	FVector GunOffset;
	float FireRate= 0.1f;
	void ShotTimerExpired();
	UPROPERTY(Category = Audio, EditAnywhere, BlueprintReadWrite)
	class USoundBase* FireSound;
protected:
	FTimerHandle TimerHandle_ShotTimerExpired;
};

