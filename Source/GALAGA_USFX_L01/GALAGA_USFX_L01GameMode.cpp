// Copyright Epic Games, Inc. All Rights Reserved.

#include "GALAGA_USFX_L01GameMode.h"
#include "GALAGA_USFX_L01Pawn.h"
#include "NaveEnemiga.h"
#include "naveEnemigaCaza.h"

AGALAGA_USFX_L01GameMode::AGALAGA_USFX_L01GameMode()
{
	
	// set default pawn class to our character class
	DefaultPawnClass = AGALAGA_USFX_L01Pawn::StaticClass();
	NaveEnemiga01 = nullptr;
}

void AGALAGA_USFX_L01GameMode::BeginPlay()
{
	Super::BeginPlay();
	//nave principal
	FVector ubicacionNave = FVector(0.0f, 50.0f,215.0f);
	FRotator rotationNave = FRotator(0.0f, 0.0f, 0.0f);
	//hijacaza
	FVector ubicacionNaveEnemigaCaza = FVector(150.0f, 50.0f, 215.0f);
	FRotator rotationNaveEnemigaCaza = FRotator(0.0f, 0.0f, 0.0f);
	//hijatransporte
	FVector ubicacionNaveEnemigaTransporte = FVector(270.0f, 50.0f, 215.0f);
	FRotator rotationNaveEnemigaTransporte = FRotator(0.0f, 0.0f, 0.0f);

	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		

		NaveEnemiga01=World-> SpawnActor<ANaveEnemiga>(ubicacionNave, rotationNave);

		NaveEnemigaCaza01 = World->SpawnActor<ANaveEnemiga>(ubicacionNaveEnemigaCaza, rotationNaveEnemigaCaza);

		NaveEnemigaTransporte01 = World->SpawnActor<ANaveEnemiga>(ubicacionNaveEnemigaTransporte, rotationNaveEnemigaTransporte);
	}
	

	NaveEnemiga01->SetPosicion(FVector(150.f, 0, 0));
}

