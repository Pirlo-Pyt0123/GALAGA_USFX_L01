// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GALAGA_USFX_L01GameMode.generated.h"

class ANaveEnemiga;
UCLASS(MinimalAPI)
class AGALAGA_USFX_L01GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGALAGA_USFX_L01GameMode();
public:
	 ANaveEnemiga*NaveEnemiga01;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};



