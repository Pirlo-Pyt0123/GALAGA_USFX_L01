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

	FVector ubicacionNaveTransporte01 = FVector(1680.0f, -700.0f, 250.0f);
	FVector ubicacionNaveCaza01 = FVector(1840.0f, -690.0f, 250.0f);
	FVector ubicacionNaveEspia01 = FVector(1520.0f, -700.0f, 250.0f);
	FVector ubicacionNaveNodriza01 = FVector(1360.0f, -680.0f, 250.0f);
	FVector ubicacionNaveReabastecimiento01 = FVector(1160.0f, -670.0f, 250.0f);
	FVector ubicacionNaveCazaSigilosa01 = FVector(1810.0f, 630.0f, 250.0f);
	FVector ubicacionNaveCazaVeloz01 = FVector(1640.0f, 655.0f, 250.0f);
	FVector ubicacionNaveEspiaPsicopata01 = FVector(1480.0f, 660.0f, 250.0f);
	FVector ubicacionNaveEspiaSupremo01 = FVector(1280.0f, 670.0f, 250.0f);
	FVector ubicacionNaveNodrizaComando01 = FVector(1110.0f, 680.0f, 250.0f);
	FVector ubicacionNaveNodrizaFabrica01 = FVector(920.0f, 690.0f, 250.0f);
	FVector ubicacionNaveReabastecimientoPeke01 = FVector(750.0f, 700.0f, 250.0f);
	FVector ubicacionNaveReabastecimientoSupra01 = FVector(570.0f, 720.0f, 250.0f);
	FVector ubicacionNaveTransporteDesplegable01 = FVector(390.0f, 720.0f, 250.0f);
	FVector ubicacionNaveTransporteInvisible01 = FVector(210.0f, 730.0f, 250.0f);



	FRotator rotacionNave = FRotator(0.0f, 0.0f, 0.0f);

	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		// spawn the projectile
		NaveEnemigaTransporte01 = World->SpawnActor<ANaveEnemigaTransporte>(ubicacionNaveTransporte01, rotacionNave);
		NaveEnemigaCaza01 = World->SpawnActor<AnaveEnemigaCaza>(ubicacionNaveCaza01, rotacionNave);

		NaveEnemigaCaza01->SetVelocidad(-120);

		NaveEnemigaEspia01 = World->SpawnActor<ANaveEnemigaEspia>(ubicacionNaveEspia01, rotacionNave);
		NaveEnemigaNodriza01 = World->SpawnActor<ANaveEnemigaNodriza>(ubicacionNaveNodriza01, rotacionNave);
		NaveEnemigaReabastecimiento01 = World->SpawnActor<ANaveEnemigaReabastecimiento>(ubicacionNaveReabastecimiento01, rotacionNave);
		NaveEnemigaReabastecimiento01->SetVelocidad(-150);
		NaveEnemigaCazaSigilosa01 = World->SpawnActor<AnaveEnemigaCaza>(ubicacionNaveCazaSigilosa01, rotacionNave);
		NaveEnemigaCazaSigilosa01->SetVelocidad(-150);
		NaveEnemigaCazaVeloz01 = World->SpawnActor<AnaveEnemigaCaza>(ubicacionNaveCazaVeloz01, rotacionNave);
		NaveEnemigaCazaVeloz01->SetVelocidad(-300);
		NaveEnemigaEspiaPsicopata01 = World->SpawnActor<ANaveEnemigaEspia>(ubicacionNaveEspiaPsicopata01, rotacionNave);
		NaveEnemigaEspiaPsicopata01->SetVelocidad(-250);

		NaveEnemigaEspiaSupremo01 = World->SpawnActor<ANaveEnemigaEspia>(ubicacionNaveEspiaSupremo01, rotacionNave);
		NaveEnemigaEspiaSupremo01->SetVelocidad(-200);

		NaveEnemigaNodrizaComando01 = World->SpawnActor<ANaveEnemigaNodriza>(ubicacionNaveNodrizaComando01, rotacionNave);
		NaveEnemigaNodrizaComando01->SetVelocidad(-15);

		NaveEnemigaNodrizaFabrica01 = World->SpawnActor<ANaveEnemigaNodriza>(ubicacionNaveNodrizaFabrica01, rotacionNave);
		NaveEnemigaNodrizaFabrica01->SetVelocidad(-18);

		NaveEnemigaReabastecimientoPeke01 = World->SpawnActor<ANaveEnemigaReabastecimiento>(ubicacionNaveReabastecimientoPeke01, rotacionNave);
		NaveEnemigaReabastecimientoPeke01->SetVelocidad(-250);

		NaveEnemigaReabastecimientoSupra01 = World->SpawnActor<ANaveEnemigaReabastecimiento>(ubicacionNaveReabastecimientoSupra01, rotacionNave);
		NaveEnemigaReabastecimientoSupra01->SetVelocidad(-180);

		NaveEnemigaTransporteDesplegable01 = World->SpawnActor<ANaveEnemigaTransporte>(ubicacionNaveTransporteDesplegable01, rotacionNave);
		NaveEnemigaTransporteDesplegable01->SetVelocidad(-80);

		NaveEnemigaTransporteInvisible01 = World->SpawnActor<ANaveEnemigaTransporte>(ubicacionNaveTransporteInvisible01, rotacionNave);
		NaveEnemigaTransporteInvisible01->SetVelocidad(-100);



	}

	NaveEnemigaTransporte01->SetPosicion(FVector(500.0f, -500.0f, 200.0f));
	NaveEnemigaCaza01->SetPosicion(FVector(-500.0f, 500.0f, 200.0f));
	NaveEnemigaEspia01->SetPosicion(FVector(-500.0f, 500.0f, 200.0f));
	NaveEnemigaNodriza01->SetPosicion(FVector(-500.0f, 500.0f, 200.0f));
	NaveEnemigaReabastecimiento01->SetPosicion(FVector(-500.0f, 500.0f, 200.0f));
}




