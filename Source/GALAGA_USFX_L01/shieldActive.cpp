// Fill out your copyright notice in the Description page of Project Settings.


#include "Kismet/GameplayStatics.h"
#include "shieldActive.h"

// Sets default values for this component's properties
UshieldActive::UshieldActive()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	//ShieldActivado = CreateDefaultSubobject<USceneComponent>(TEXT("MySceneComponent"));
	//SeetRootComponent(ShieldActivado);
	NaveControl = Cast<AGALAGA_USFX_L01Pawn>(UGameplayStatics::GetPlayerPawn(this, 0));

}

void UshieldActive::Spawn()
{
	UWorld* TheWorld = GetWorld();
	if (TheWorld != nullptr) {
		tiempoAparecer++;
		if (tiempoAparecer >= 200) {
			FTransform TransformShield(this->GetComponentTransform());
			
			TransformShield.SetLocation(GetComponentLocation() + FVector(200, 0, 0));
			TransformShield.SetRotation(FQuat(0.f, 90.f, 0.f, 90.f));
			//TransformBarrera
			TheWorld->SpawnActor(shieldSpawn, &TransformShield);
			tiempoAparecer = 0;
		}
	}
}




// Called when the game starts
void UshieldActive::BeginPlay()
{
	Super::BeginPlay();
	
	//Spawn();
	// ...

	
}


// Called every frame
void UshieldActive::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (estaWea > 5.0f) {
		Spawn();
		estaWea = 0;
	}
	if (ShieldActivado && GetOwner())
	{
		// Update the position of the ShieldActivado to match the position of the owning actor (the ship)
		ShieldActivado->SetWorldLocation(GetOwner()->GetActorLocation());
	}

	estaWea += GetWorld()->DeltaTimeSeconds;
	// ...
}

