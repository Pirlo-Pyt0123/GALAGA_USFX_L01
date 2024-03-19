// Copyright Epic Games, Inc. All Rights Reserved.

#include "Galaga_USFX_L01GameMode.h"
#include "GALAGA_USFX_L01Pawn.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaTransporte.h"
#include "naveEnemigaCaza.h"
#include "NaveEnemigaEspia.h"
#include "NaveEnemigaNodriza.h"
#include "NaveEnemigaReabastecimiento.h"
#include "NaveEnemigaTransporteDesplegable.h"
#include "NaveEnemigaTransporteInvisible.h"
#include "naveEnemigaCazaVeloz.h"
#include "naveEnemigaCazaSigilosa.h"
#include "NaveEnemigaEspiaPsicopata.h"
#include "NaveEnemigaEspiaSupremo.h"
#include "NaveEnemigaNodrizaComando.h"
#include "NaveEnemigaNodrizaFabrica.h"
#include "NaveEnemigaReabastecimientoPeke.h"
#include "NaveEnemigaReabastecimientoSupra.h"

AGalaga_USFX_L01GameMode::AGalaga_USFX_L01GameMode()
{
	 //set default pawn class to our character class
	 DefaultPawnClass = AGALAGA_USFX_L01Pawn::StaticClass();
	//NaveEnemiga01 = nullptr;
	 
}

void AGalaga_USFX_L01GameMode::BeginPlay()
{
	Super::BeginPlay();



	float x = 1200;
	float y = -1000;
	//Set the game state to playing

	FVector ubicacionNave01 = FVector(x, y, 250.0f);
	FVector ubicacionNave02 = FVector(x, y + 200, 244.0f);
	FVector ubicacionNave03 = FVector(x, y + 400, 244.0f);
	FVector ubicacionNave04 = FVector(x, y + 600, 244.0f);
	FVector ubicacionNave05 = FVector(x, y + 800, 244.0f);
	x = 1000;
	FVector ubicacionNave06 = FVector(x, y + 800, 244.0f);
	FVector ubicacionNave07 = FVector(x, y + 600, 244.0f);
	FVector ubicacionNave08 = FVector(x, y + 400, 244.0f);
	FVector ubicacionNave09 = FVector(x, y + 200, 244.0f);
	FVector ubicacionNave10 = FVector(x, y, 244.0f);

	FRotator rotacionNave = FRotator(0.0f, 180.0f, 0.0f);



	//FVector ubicacionInicioNavesEnemigasCaza = FVector(-500.0f, 500.0f, 250, 0f);



	UWorld* const World = GetWorld();
	if (World != nullptr)
	{

		// spawn the projectile
		//NaveEnemigaCaza01 = World->SpawnActor<AnaveEnemigaCaza>(FVector(200, 200, 250), rotacionNave);
		NaveEnemigaCazaSigilosa01 = World->SpawnActor<AnaveEnemigaCazaSigilosa>(ubicacionNave01, rotacionNave);
		NaveEnemigaCazaVeloz01 = World->SpawnActor<AnaveEnemigaCazaVeloz>(ubicacionNave02, rotacionNave);
		NaveEnemigaTransporteDesplegable01 = World->SpawnActor<ANaveEnemigaTransporteDesplegable>(ubicacionNave03, rotacionNave);
		NaveEnemigaTransporteInvisible01 = World->SpawnActor<ANaveEnemigaTransporteInvisible>(ubicacionNave04, rotacionNave);
		NaveEnemigaEspiaPsicopata01 = World->SpawnActor<ANaveEnemigaEspiaPsicopata>(ubicacionNave05, rotacionNave);
		NaveEnemigaEspiaSupremo01 = World->SpawnActor<ANaveEnemigaEspiaSupremo>(ubicacionNave06, rotacionNave);
		NaveEnemigaReabastecimientoPeke01 = World->SpawnActor<ANaveEnemigaReabastecimientoPeke>(ubicacionNave07, rotacionNave);
		NaveEnemigaReabastecimientoSupra01 = World->SpawnActor<ANaveEnemigaReabastecimientoSupra>(ubicacionNave08, rotacionNave);
		NaveEnemigaNodrizaComando01 = World->SpawnActor<ANaveEnemigaNodrizaComando>(ubicacionNave09, rotacionNave);
		NaveEnemigaNodrizaFabrica01 = World->SpawnActor<ANaveEnemigaNodrizaFabrica>(ubicacionNave10, rotacionNave);
		//AnaveEnemigaCaza* NaveEnemigaTemporal = World->SpawnActor<AnaveEnemigaCaza>(FVector(200, 200, 250), rotacionNave);




		float  xc = 200, yc = 120, zc = 250;

		for (int i = 0; i < 5; i++) {


			//AnaveEnemigaCazaVeloz* NaveEnemigaTemporal01 = World->SpawnActor<AnaveEnemigaCazaVeloz>(FVector(xc, yc, zc), rotacionNave);
			//TAnavesEnemigasCaza.Push(NaveEnemigaTemporal01);
			AnaveEnemigaCazaSigilosa* NaveEnemigaTemporal02 = World->SpawnActor<AnaveEnemigaCazaSigilosa>(FVector(xc, yc * -4, zc), rotacionNave);
			TAnavesEnemigasCaza.Push(NaveEnemigaTemporal02);
			ANaveEnemigaEspiaPsicopata* NaveEnemigaTemporal03 = World->SpawnActor<ANaveEnemigaEspiaPsicopata>(FVector(xc, yc * -2, zc), rotacionNave);
			TAnavesEnemigasEspia.Push(NaveEnemigaTemporal03);
			ANaveEnemigaEspiaSupremo* NaveEnemigaTemporal04 = World->SpawnActor<ANaveEnemigaEspiaSupremo>(FVector(xc, yc * 2, zc), rotacionNave);
			TAnavesEnemigasEspia.Push(NaveEnemigaTemporal04);
			ANaveEnemigaReabastecimientoPeke* NaveEnemigaTemporal05 = World->SpawnActor<ANaveEnemigaReabastecimientoPeke>(FVector(xc, yc * 4, zc), rotacionNave);
			TAnavesEnemigasReabastecimiento.Push(NaveEnemigaTemporal05);
			ANaveEnemigaReabastecimientoSupra* NaveEnemigaTemporal06 = World->SpawnActor<ANaveEnemigaReabastecimientoSupra>(FVector(xc, yc * 5, zc), rotacionNave);
			TAnavesEnemigasReabastecimiento.Push(NaveEnemigaTemporal06);
			ANaveEnemigaNodrizaComando* NaveEnemigaTemporal07 = World->SpawnActor<ANaveEnemigaNodrizaComando>(FVector(xc, yc * 6, zc), rotacionNave);
			TAnavesEnemigasNodriza.Push(NaveEnemigaTemporal07);
			yc += 80;



		}

		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Naves SPawn"));




	}


};
