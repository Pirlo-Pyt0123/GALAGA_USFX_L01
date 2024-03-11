// Copyright Epic Games, Inc. All Rights Reserved.

#include "Galaga_USFX_L01GameMode.h"
#include "GALAGA_USFX_L01Pawn.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaTransporte.h"
#include "NaveEnemigaCaza.h"
#include "NaveEnemigaEspia.h"
#include "NaveEnemigaNodriza.h"
#include "NaveEnemigaReabastecimiento.h"

AGalaga_USFX_L01GameMode::AGalaga_USFX_L01GameMode()
{
	 //set default pawn class to our character class
	 DefaultPawnClass = AGALAGA_USFX_L01Pawn::StaticClass();
	//NaveEnemiga01 = nullptr;
}

void AGalaga_USFX_L01GameMode::BeginPlay()
{
	Super::BeginPlay();
	//Set the game state to playing

	FVector ubicacionNave01 = FVector(850.0f, -700.0f, 250.0f);
	FVector ubicacionNave02 = FVector(620.0f, 640.0f, 250.0f);
	FVector ubicacionNave03 = FVector(600.0f, -700.0f, 250.0f);
	FVector ubicacionNave04 = FVector(800.0f, 600.0f, 250.0f);
	FVector ubicacionNave05 = FVector(410.0f, 660.0f, 250.0f);

	FRotator rotacionNave = FRotator(0.0f, 0.0f, 0.0f);

	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		// spawn the projectile
		NaveEnemigaTransporte01 = World->SpawnActor<ANaveEnemigaTransporte>(ubicacionNave01, rotacionNave);
		NaveEnemigaCaza01 = World->SpawnActor<AnaveEnemigaCaza>(ubicacionNave02, rotacionNave);
		NaveEnemigaEspia01 = World->SpawnActor<ANaveEnemigaEspia>(ubicacionNave03, rotacionNave);
		NaveEnemigaNodriza01 = World->SpawnActor<ANaveEnemigaNodriza>(ubicacionNave04, rotacionNave);
		NaveEnemigaReabastecimiento01 = World->SpawnActor<ANaveEnemigaReabastecimiento>(ubicacionNave05, rotacionNave);
	}

	NaveEnemigaTransporte01->SetPosicion(FVector(500.0f, -500.0f, 200.0f));
	NaveEnemigaCaza01->SetPosicion(FVector(-500.0f, 500.0f, 200.0f));
	NaveEnemigaEspia01->SetPosicion(FVector(-500.0f, 500.0f, 200.0f));
	NaveEnemigaNodriza01->SetPosicion(FVector(-500.0f, 500.0f, 200.0f));
	NaveEnemigaReabastecimiento01->SetPosicion(FVector(-500.0f, 500.0f, 200.0f));
}




