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
#include "vidas.h"


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

		//vidas01 = World->SpawnActor<Avidas>(FVector(200, 200, 250), FRotator(0, 0, 0));

		//vidas01->ModificarVida("escudo", escudo);
		AnaveEnemigaCazaSigilosa* NaveEnemiga01 = World->SpawnActor<AnaveEnemigaCazaSigilosa>(ubicacionNave01, rotacionNave);
		AnaveEnemigaCazaVeloz* NaveEnemigaTBeto;
		AnaveEnemigaCazaSigilosa* NaveEnemigaTAlfredo;
		ANaveEnemigaTransporteDesplegable* NaveEnemigaTPirlo;
		ANaveEnemigaTransporteInvisible* NaveEnemigaTTilin;
		ANaveEnemigaEspiaPsicopata* NaveEnemigaTSonso;
		ANaveEnemigaEspiaSupremo* NaveEnemigaTCausa;
		ANaveEnemigaNodrizaComando* NaveEnemigaTEljaja;
		ANaveEnemigaNodrizaFabrica* NaveEnemigaTGoku;
		ANaveEnemigaReabastecimientoPeke* NaveEnemigaTVegeta;
		ANaveEnemigaReabastecimientoSupra* NaveEnemigaTPepe;






		// Agrega más posiciones para otros tipos de naves aquí

		int tipNave = 0;
		bool nodrizaComandoSpawned = false;
		bool nodrizaFabricaSpawned = false;
		for (int i = 0; i < 30; i++) {
			tipNave = rand() % 9;
			FVector posicionNave = FVector(rand() % 2000 - 1000, rand() % 2000 - 1000, 244.0f);
			// Se verifica si ya se ha spawneado alguna de las nodrizas
			if (!nodrizaComandoSpawned && tipNave == 6) {
				NaveEnemigaTEljaja = World->SpawnActor<ANaveEnemigaNodrizaComando>(posicionNave, rotacionNave);
				TAnaveEnemigaPerronas.Push(NaveEnemigaTEljaja);
				nodrizaComandoSpawned = true;
			}
			else if (!nodrizaFabricaSpawned && tipNave == 7) {
				NaveEnemigaTGoku = World->SpawnActor<ANaveEnemigaNodrizaFabrica>(posicionNave, rotacionNave);
				TAnaveEnemigaPerronas.Push(NaveEnemigaTGoku);
				nodrizaFabricaSpawned = true;
			}

			else {
				switch (tipNave) {
				case 0:
					NaveEnemigaTBeto = World->SpawnActor<AnaveEnemigaCazaVeloz>(posicionNave, rotacionNave);
					TAnavesEnemigasCaza.Push(NaveEnemigaTBeto);
					break;
				case 1:
					NaveEnemigaTAlfredo = World->SpawnActor<AnaveEnemigaCazaSigilosa>(posicionNave, rotacionNave);
					TAnaveEnemigaPerronas.Push(NaveEnemigaTAlfredo);
					break;
				case 2:
					NaveEnemigaTPirlo = World->SpawnActor<ANaveEnemigaTransporteDesplegable>(posicionNave, rotacionNave);
					TAnaveEnemigaPerronas.Push(NaveEnemigaTPirlo);
					break;
				case 3:
					NaveEnemigaTTilin = World->SpawnActor<ANaveEnemigaTransporteInvisible>(posicionNave, rotacionNave);
					TAnaveEnemigaPerronas.Push(NaveEnemigaTTilin);
					break;
				case 4:
					NaveEnemigaTSonso = World->SpawnActor<ANaveEnemigaEspiaPsicopata>(posicionNave, rotacionNave);
					TAnaveEnemigaPerronas.Push(NaveEnemigaTSonso);
					break;
				case 5:
					NaveEnemigaTCausa = World->SpawnActor<ANaveEnemigaEspiaSupremo>(posicionNave, rotacionNave);
					TAnaveEnemigaPerronas.Push(NaveEnemigaTCausa);
					break;
				case 8:
					NaveEnemigaTVegeta = World->SpawnActor<ANaveEnemigaReabastecimientoPeke>(posicionNave, rotacionNave);
					TAnaveEnemigaPerronas.Push(NaveEnemigaTVegeta);
					break;
				case 9:
					NaveEnemigaTPepe = World->SpawnActor<ANaveEnemigaReabastecimientoSupra>(posicionNave, rotacionNave);
					TAnaveEnemigaPerronas.Push(NaveEnemigaTPepe);
					break;
				default: break;
				}
			}
		}
		//TiempoTranscurrido = 0;





	}

}
