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
	TArray<TSubclassOf<ANaveEnemiga>> TipoNaves;

	TMap<TSubclassOf<ANaveEnemiga>, int> MaxNav;

	TipoNaves.Add(AnaveEnemigaCaza::StaticClass());
	TipoNaves.Add(AnaveEnemigaCazaVeloz::StaticClass());
	TipoNaves.Add(AnaveEnemigaCazaSigilosa::StaticClass());
	TipoNaves.Add(ANaveEnemigaTransporte::StaticClass());
	TipoNaves.Add(ANaveEnemigaTransporteDesplegable::StaticClass());
	TipoNaves.Add(ANaveEnemigaTransporteInvisible::StaticClass());
	TipoNaves.Add(ANaveEnemigaEspia::StaticClass());
	TipoNaves.Add(ANaveEnemigaEspiaSupremo::StaticClass());
	TipoNaves.Add(ANaveEnemigaEspiaPsicopata::StaticClass());
	TipoNaves.Add(ANaveEnemigaReabastecimiento::StaticClass());
	TipoNaves.Add(ANaveEnemigaReabastecimientoPeke::StaticClass());
	TipoNaves.Add(ANaveEnemigaReabastecimientoSupra::StaticClass());
	TipoNaves.Add(ANaveEnemigaNodriza::StaticClass());

	//Añadimos cada clase de nave y la cantidad maximas que podemos generar.
	//La estrutura seria: (ClaseNave, CantidadMaxima)=(llave, valor).
	MaxNav.Add(AnaveEnemigaCaza::StaticClass(), 5);
	MaxNav.Add(AnaveEnemigaCazaVeloz::StaticClass(), 5);
	MaxNav.Add(AnaveEnemigaCazaSigilosa::StaticClass(), 5);
	MaxNav.Add(ANaveEnemigaTransporte::StaticClass(), 5);
	MaxNav.Add(ANaveEnemigaTransporteDesplegable::StaticClass(), 5);
	MaxNav.Add(ANaveEnemigaTransporteInvisible::StaticClass(), 5);
	MaxNav.Add(ANaveEnemigaEspia::StaticClass(), 5);
	MaxNav.Add(ANaveEnemigaEspiaSupremo::StaticClass(), 5);
	MaxNav.Add(ANaveEnemigaEspiaPsicopata::StaticClass(), 5);
	MaxNav.Add(ANaveEnemigaReabastecimiento::StaticClass(), 5);
	MaxNav.Add(ANaveEnemigaReabastecimientoPeke::StaticClass(), 5);
	MaxNav.Add(ANaveEnemigaReabastecimientoSupra::StaticClass(), 5);
	MaxNav.Add(ANaveEnemigaNodriza::StaticClass(), 1);

	/*FString DatosMapa = ListarTmap(MaxNav);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, DatosMapa);*/

	FVector UIniNaves = FVector(0.0f, -1000.0f, 250.0f);
	//No tocaremos la rotacion porque no nos interesa por ahora la rotacion de los objetos.
	FRotator rotacionNave = FRotator(0.0f, 0.0f, 0.0f);

	UWorld* const World = GetWorld(); //Estamos obteniendo una direccion (puntero) de la clase UWorld (Escenario del juego).
	if (World != nullptr) //Verificamos si el puntero obtenido es valido.
	{
		//Numero de filas.
		for (int i = 0; i < 3; i++) {
			//Numero de Naves por fila.
			for (int j = 0; j < 10; j++) {
				//Recordemos declarar a 'TipoNavAlea' como referencia de las subclases de 'AEnemy'.
				TSubclassOf<ANaveEnemiga>TipoNavAlea = TipoNaves[FMath::RandRange(0, TipoNaves.Num() - 1)];//Esto asigna una nave aleatoria de nuestro array de naves.
				//Verificamos si el Tmap tiene la llave (TipoNavAlea) que recordemos que es una subclase especifica de 'Enemy'.
				//Contains es un metodo que se llama en un TMap para verificar si contiene una clave específica (TipoNavAlea).
				if (MaxNav.Contains(TipoNavAlea)) {
					int NavesGeneradas = MaxNav[TipoNavAlea];//Asignanos la nave aleatoria como un entero a la variable 'NavesGeneradas'.
					if (NavesGeneradas > 0) {
						FVector PActualNaves = FVector(UIniNaves.X + i * 150, UIniNaves.Y + j * 105, UIniNaves.Z);//Esto solo controla la distancia entre las naves
						ANaveEnemiga* NavesInst = World->SpawnActor<ANaveEnemiga>(TipoNavAlea, PActualNaves, rotacionNave);//Esto spawnea las naves en el mundo.
						Enemigos.Push(NavesInst);//Esto añade las naves al array de enemigos.
						NavesGeneradas--;//Cada vez que se crea una nave, se reduce el contador de naves disponibles para ese tipo.
					}
				}
			}
		}
	}

	


	//float x = 1200;
	//float y = -1000;
	////Set the game state to playing

	//FVector ubicacionNave01 = FVector(x, y, 250.0f);
	//FVector ubicacionNave02 = FVector(x, y + 200, 244.0f);
	//FVector ubicacionNave03 = FVector(x, y + 400, 244.0f);
	//FVector ubicacionNave04 = FVector(x, y + 600, 244.0f);
	//FVector ubicacionNave05 = FVector(x, y + 800, 244.0f);
	//x = 1000;
	//FVector ubicacionNave06 = FVector(x, y + 800, 244.0f);
	//FVector ubicacionNave07 = FVector(x, y + 600, 244.0f);
	//FVector ubicacionNave08 = FVector(x, y + 400, 244.0f);
	//FVector ubicacionNave09 = FVector(x, y + 200, 244.0f);
	//FVector ubicacionNave10 = FVector(x, y, 244.0f);



	//FRotator rotacionNave = FRotator(0.0f, 180.0f, 0.0f);


	//FVector ubicacionInicioNavesEnemigasCaza = FVector(-500.0f, 500.0f, 250, 0f);




	/*UWorld* const World = GetWorld();
	if (World != nullptr)
	{





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
		ANaveEnemigaReabastecimientoSupra* NaveEnemigaTPepe;*/






		// Agrega más posiciones para otros tipos de naves aquí

	//	int tipNave = 0;
	//	bool nodrizaComandoSpawned = false;
	//	bool nodrizaFabricaSpawned = false;
	//	for (int i = 0; i < 30; i++) {
	//		tipNave = rand() % 9;
	//		FVector posicionNave = FVector(rand() % 3000 - 1000, rand() % 2000 - 1000, 244.0f);
	//		// Se verifica si ya se ha spawneado alguna de las nodrizas
	//		if (!nodrizaComandoSpawned && tipNave == 6) {
	//			NaveEnemigaTEljaja = World->SpawnActor<ANaveEnemigaNodrizaComando>(posicionNave, rotacionNave);
	//			TAnaveEnemigaPerronas.Push(NaveEnemigaTEljaja);
	//			nodrizaComandoSpawned = true;
	//		}
	//		else if (!nodrizaFabricaSpawned && tipNave == 7) {
	//			NaveEnemigaTGoku = World->SpawnActor<ANaveEnemigaNodrizaFabrica>(posicionNave, rotacionNave);
	//			TAnaveEnemigaPerronas.Push(NaveEnemigaTGoku);
	//			nodrizaFabricaSpawned = true;
	//		}
	//		else {
	//			switch (tipNave) {
	//			case 0:
	//				NaveEnemigaTBeto = World->SpawnActor<AnaveEnemigaCazaVeloz>(posicionNave, rotacionNave);
	//				TAnavesEnemigasCaza.Push(NaveEnemigaTBeto);
	//				break;
	//			case 1:
	//				NaveEnemigaTAlfredo = World->SpawnActor<AnaveEnemigaCazaSigilosa>(posicionNave, rotacionNave);
	//				TAnaveEnemigaPerronas.Push(NaveEnemigaTAlfredo);
	//				break;
	//			case 2:
	//				NaveEnemigaTPirlo = World->SpawnActor<ANaveEnemigaTransporteDesplegable>(posicionNave, rotacionNave);
	//				TAnaveEnemigaPerronas.Push(NaveEnemigaTPirlo);
	//				break;
	//			case 3:
	//				NaveEnemigaTTilin = World->SpawnActor<ANaveEnemigaTransporteInvisible>(posicionNave, rotacionNave);
	//				TAnaveEnemigaPerronas.Push(NaveEnemigaTTilin);
	//				break;
	//			case 4:
	//				NaveEnemigaTSonso = World->SpawnActor<ANaveEnemigaEspiaPsicopata>(posicionNave, rotacionNave);
	//				TAnaveEnemigaPerronas.Push(NaveEnemigaTSonso);
	//				break;
	//			case 5:
	//				NaveEnemigaTCausa = World->SpawnActor<ANaveEnemigaEspiaSupremo>(posicionNave, rotacionNave);
	//				TAnaveEnemigaPerronas.Push(NaveEnemigaTCausa);
	//				break;
	//			case 8:
	//				NaveEnemigaTVegeta = World->SpawnActor<ANaveEnemigaReabastecimientoPeke>(posicionNave, rotacionNave);
	//				TAnaveEnemigaPerronas.Push(NaveEnemigaTVegeta);
	//				break;
	//			case 9:
	//				NaveEnemigaTPepe = World->SpawnActor<ANaveEnemigaReabastecimientoSupra>(posicionNave, rotacionNave);
	//				TAnaveEnemigaPerronas.Push(NaveEnemigaTPepe);
	//				break;
	//			default: break;
	//			}
	//		}
	//	}
	//	//TiempoTranscurrido = 0;





	//}

	//}



}

FString ListarTmap(const TMap<FString, int>& Mapa) {
	FString Resultado;
	for (const TPair<FString, int>& Elemento : Mapa) {
		FString Llave = Elemento.Key;
		int Valor = Elemento.Value;
		Resultado += FString::Printf(TEXT("Llave: %s, Valor: %d\n"), *Llave, Valor);
	}
	return Resultado;

}

void EliminarTmap(TMap<FString, int>& Mapa, const FString& Llave) {
	Mapa.Remove(Llave);
}



