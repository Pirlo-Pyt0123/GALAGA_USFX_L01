// Fill out your copyright notice in the Description page of Project Settings.


#include "MunicionBeta.h"
#include "Engine/StaticMesh.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/CollisionProfile.h"


AMunicionBeta::AMunicionBeta()
{
	PrimaryActorTick.bCanEverTick = true;
	auto MeshAsset =ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/Capsule/fc871d94bebe_crea_una_capsula_de.fc871d94bebe_crea_una_capsula_de'"));

	if (MeshAsset.Object != nullptr)
	{
		GetStaticMeshComponent()->SetStaticMesh(MeshAsset.Object);
		GetStaticMeshComponent()->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	}
	GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable);
	SetActorEnableCollision(true);
}




void AMunicionBeta::PickUp()
{
	SetActorTickEnabled(false);
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
}



void AMunicionBeta::PutDown(FTransform TargetLocation)
{
	SetActorTickEnabled(true);
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
	SetActorLocation(TargetLocation.GetLocation());
}



