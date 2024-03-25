// Fill out your copyright notice in the Description page of Project Settings.


#include "shieldActive.h"
#include "GALAGA_USFX_L01Pawn.h"
#include "Components/SceneComponent.h"
#include "escudoPerron.h"
// Sets default values for this component's properties
UshieldActive::UshieldActive()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	ShieldActivado = CreateDefaultSubobject<USceneComponent>(TEXT("MySceneComponent"));
	//SeetRootComponent(ShieldActivado);
	// 
}

void UshieldActive::Spawn()
{
	UWorld* TheWorld = GetWorld();
	if (TheWorld != nullptr)
	{
		FTransform
			ComponentTransform(this->GetComponentTransform());
		TheWorld->SpawnActor(ActorToSpawn, &ComponentTransform);
	}
}




// Called when the game starts
void UshieldActive::BeginPlay()
{
	Super::BeginPlay();
	Spawn();
	// ...
	
}


// Called every frame
void UshieldActive::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


	if (ShieldActivado && GetOwner())
	{
		// Update the position of the ShieldActivado to match the position of the owning actor (the ship)
		ShieldActivado->SetWorldLocation(GetOwner()->GetActorLocation());
	}
	// ...
}

