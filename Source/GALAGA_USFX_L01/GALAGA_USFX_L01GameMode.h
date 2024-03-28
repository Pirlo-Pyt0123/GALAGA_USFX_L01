// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "NaveEnemiga.h"
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Galaga_USFX_L01GameMode.generated.h"
class Avidas;
class ANaveEnemiga;
class ANaveEnemigaCazaVeloz;
class ANaveEnemigaReabastecimiento;
class ANaveEnemigaNodriza;
class ANaveEnemigaTransporte;
class AnaveEnemigaCaza;
class ANaveEnemigaEspia;

UCLASS(MinimalAPI)
class AGalaga_USFX_L01GameMode : public AGameModeBase
{
	GENERATED_BODY()
	

public:
	AGalaga_USFX_L01GameMode();

	//ANaveEnemiga* NaveEnemiga01;
	ANaveEnemigaTransporte* NaveEnemigaTransporte01;
	//AnaveEnemigaCaza* NaveEnemigaCaza01;
	ANaveEnemigaEspia* NaveEnemigaEspia01;
	ANaveEnemigaNodriza* NaveEnemigaNodriza01;
	ANaveEnemigaReabastecimiento* NaveEnemigaReabastecimiento01;
	//Hijas Cazas
	AnaveEnemigaCaza* NaveEnemigaCazaSigilosa01;
	AnaveEnemigaCaza* NaveEnemigaCazaVeloz01;
	//hijas Espia
	ANaveEnemigaEspia* NaveEnemigaEspiaPsicopata01;
	ANaveEnemigaEspia* NaveEnemigaEspiaSupremo01;
	//hijas Nodriza 
	ANaveEnemigaNodriza* NaveEnemigaNodrizaComando01;
	ANaveEnemigaNodriza* NaveEnemigaNodrizaFabrica01;
	//hijas Reabastecimiento
	ANaveEnemigaReabastecimiento* NaveEnemigaReabastecimientoPeke01;
	ANaveEnemigaReabastecimiento* NaveEnemigaReabastecimientoSupra01;
	// hijas Transporte
	ANaveEnemigaTransporte* NaveEnemigaTransporteDesplegable01;
	ANaveEnemigaTransporte* NaveEnemigaTransporteInvisible01;

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//virtual void Tick(float DeltaTime) override;
	
	


public:

	int TiempoTranscurrido;

	Avidas* vidas01;


	TArray<AnaveEnemigaCaza* >TAnavesEnemigasCaza;
	//TArray<ANaveEnemigaTransporte* >TAnavesEnemigasTrasnporte;
	//TArray<ANaveEnemigaEspia* >TANavesEnemigasEspia;
	//TArray<ANaveEnemigaReabastecimiento* >TANavesEnemigasReabastecimiento;
	TArray<ANaveEnemigaNodriza* >TANavesEnemigasNodriza;
	TArray<ANaveEnemiga*> TAnaveEnemigaPerronas;
	TArray<ANaveEnemiga*> Enemigos;
	

	//TMap uso para coordenadas de las naves enemigas
private:
	TMap<int32, TTuple<TArray<ANaveEnemigaEspia*>, float>> ColumnaNavesEnemigasEspia;
	UPROPERTY(EditAnywhere, Category = "Configuración de Naves Enemigas")
	float VelocidadNavesEnemigasEspia;

	

};
