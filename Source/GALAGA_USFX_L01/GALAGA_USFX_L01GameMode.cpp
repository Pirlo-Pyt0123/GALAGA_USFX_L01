// Copyright Epic Games, Inc. All Rights Reserved.

#include "GALAGA_USFX_L01GameMode.h"
#include "GALAGA_USFX_L01Pawn.h"
#include "NaveEnemiga.h"

AGALAGA_USFX_L01GameMode::AGALAGA_USFX_L01GameMode()
{
	
	// set default pawn class to our character class
	DefaultPawnClass = AGALAGA_USFX_L01Pawn::StaticClass();
	NaveEnemiga01 = nullptr;
}

void AGALAGA_USFX_L01GameMode::BeginPlay()
{
	Super::BeginPlay();
	FVector ubicacionNave = FVector(0.0f, 50.0f,215.0f);
	FRotator rotationNave = FRotator(0.0f, 0.0f, 0.0f);

	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		

		NaveEnemiga01=World-> SpawnActor<ANaveEnemiga>(ubicacionNave, rotationNave);
	}
	

	NaveEnemiga01->SetPosicion(FVector(150.f, 0, 0));
}

