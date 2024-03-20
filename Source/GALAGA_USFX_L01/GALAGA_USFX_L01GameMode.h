// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "NaveEnemiga.h"
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Galaga_USFX_L01GameMode.generated.h"
class ALogros;
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

public:



	UPROPERTY(EditAnywhere)
	int escudo = 2;


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
	
	


private:

	int TiempoTranscurrido;

	ALogros* logro1;


	//TArray<AnaveEnemigaCaza* >TAnavesEnemigasCaza;
	//TArray<ANaveEnemigaTransporte* >TAnavesEnemigasTrasnporte;
	//TArray<ANaveEnemigaEspia* >TAnavesEnemigasEspia;
	//TArray<ANaveEnemigaReabastecimiento* >TAnavesEnemigasReabastecimiento;
	//TArray<ANaveEnemigaNodriza* >TAnavesEnemigasNodriza;
	TArray<ANaveEnemiga*> TANaveEnemigamulti;

};
