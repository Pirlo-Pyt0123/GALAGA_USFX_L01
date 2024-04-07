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
#include "MunicionBeta.h"


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
		//AnaveEnemigaCazaSigilosa* NaveEnemiga01 = World->SpawnActor<AnaveEnemigaCazaSigilosa>(ubicacionNave01, rotacionNave);
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

		FVector posicionNave = FVector(rand() % 1000 - 500, rand() % 500 - 1000, 244);
		//se generan aleatoriamente las naves enemigas
		int tipNave = 0;
		for (int i = 0; i < 3; i++) {
			tipNave = rand() % 9;

			switch (tipNave) {
			case 0:

				for (int j = 0; j < 6; j++) {
					NaveEnemigaTBeto = World->SpawnActor<AnaveEnemigaCazaVeloz>(posicionNave + FVector(150 * i, 200 * j, 0), rotacionNave);
					Enemigos.Push(NaveEnemigaTBeto);
				}

				break;
			case 1:
				
				for (int j = 0; j < 6; j++) {
					NaveEnemigaTAlfredo = World->SpawnActor<AnaveEnemigaCazaSigilosa>(posicionNave + FVector(150 * i, 200 * j, 0), rotacionNave);
					Enemigos.Push(NaveEnemigaTAlfredo);
				}
				break;
			case 2:
				
				for (int j = 0; j < 6; j++) {
					NaveEnemigaTPirlo = World->SpawnActor<ANaveEnemigaTransporteDesplegable>(posicionNave + FVector(150 * i, 200 * j, 0), rotacionNave);
					Enemigos.Push(NaveEnemigaTPirlo);
				}
				break;
			case 3:
				
				for (int j = 0; j < 6; j++) {
					NaveEnemigaTTilin = World->SpawnActor<ANaveEnemigaTransporteInvisible>(posicionNave + FVector(150 * i, 200 * j, 0), rotacionNave);
					Enemigos.Push(NaveEnemigaTTilin);
				}
				break;
			case 4:
				
				for (int j = 0; j < 6; j++) {
					NaveEnemigaTSonso = World->SpawnActor<ANaveEnemigaEspiaPsicopata>(posicionNave + FVector(150 * i, 200 * j, 0), rotacionNave);
					Enemigos.Push(NaveEnemigaTSonso);
				}
				break;
			case 5:
				
				for (int j = 0; j < 6; j++) {
					NaveEnemigaTCausa = World->SpawnActor<ANaveEnemigaEspiaSupremo>(posicionNave + FVector(150 * i, 200 * j, 0), rotacionNave);
					Enemigos.Push(NaveEnemigaTCausa);
				}
				break;
			case 6:
				
				for (int j = 0; j < 6; j++) {
					NaveEnemigaTEljaja = World->SpawnActor<ANaveEnemigaNodrizaComando>(posicionNave + FVector(150 * i, 200 * j, 0), rotacionNave);
					Enemigos.Push(NaveEnemigaTEljaja);
				}
				break;
			case 7:
				
				for (int j = 0; j < 6; j++) {
					NaveEnemigaTGoku = World->SpawnActor<ANaveEnemigaNodrizaFabrica>(posicionNave + FVector(150 * i, 200 * j, 0), rotacionNave);
					Enemigos.Push(NaveEnemigaTGoku);
				}
				break;
			case 8:
				
				for (int j = 0; j < 6; j++) {
					NaveEnemigaTVegeta = World->SpawnActor<ANaveEnemigaReabastecimientoPeke>(posicionNave + FVector(150 * i, 200 * j, 0), rotacionNave);
					Enemigos.Push(NaveEnemigaTVegeta);
				}
				break;
			case 9:
				
				for (int j = 0; j < 6; j++) {
					NaveEnemigaTPepe = World->SpawnActor<ANaveEnemigaReabastecimientoSupra>(posicionNave + FVector(150 * i, 200 * j, 0), rotacionNave);
					Enemigos.Push(NaveEnemigaTPepe);
				}
				break;
			default: break;

			}
		}
		//TiempoTranscurrido = 0;





	}

	}





//FString ListarTmap(const TMap<FString, int>& Mapa) {
//	FString Resultado;
//	for (const TPair<FString, int>& Elemento : Mapa) {
//		FString Llave = Elemento.Key;
//		int Valor = Elemento.Value;
//		Resultado += FString::Printf(TEXT("Llave: %s, Valor: %d\n"), *Llave, Valor);
//	}
//	return Resultado;
//
//}
//
//void EliminarTmap(TMap<FString, int>& Mapa, const FString& Llave) {
//	Mapa.Remove(Llave);
//}



