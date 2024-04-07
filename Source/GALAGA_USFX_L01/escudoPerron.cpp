// Fill out your copyright notice in the Description page of Project Settings.


#include "escudoPerron.h"
#include "GALAGA_USFX_L01Pawn.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SphereComponent.h"	

// Sets default values
AescudoPerron::AescudoPerron()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
	CollisionComponent->SetSphereRadius(100.0f); // Ajusta el radio según sea necesario
	CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &AescudoPerron::OnShieldOverlapBegin); // Configura el manejador de colisiones
	CollisionComponent->SetupAttachment(RootComponent);


	shieldMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh'/Game/IAaseet/d2cf564cea56_create_a_plasma_shi.d2cf564cea56_create_a_plasma_shi'"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/IAaseet/d2cf564cea56_create_a_plasma_shi.d2cf564cea56_create_a_plasma_shi'"));
	// Create the mesh component
	shieldMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	shieldMesh->SetStaticMesh(ShipMesh.Object);
	shieldMesh->SetupAttachment(RootComponent);
	RootComponent = shieldMesh;
	GetActorRelativeScale3D();
	//aumenta el tamano de la nave
	SetActorScale3D(FVector(3, 3, 3));

	DistanciaEscudoNave = 200.0f;



}



void AescudoPerron::desaparecer(float _coolTime)
{
	if (_coolTime > 10)
	{
		Destroy();
	}
	
}

// Called when the game starts or when spawned
void AescudoPerron::BeginPlay()
{
	Super::BeginPlay();
	//desaparecer(coolTime);
	//coolTime += GetWorld()->DeltaTimeSeconds;
	

}

void AescudoPerron::OnShieldOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
		// Si el actor colisionado no es tu nave, destrúyelo
		Destroy();

}




void AescudoPerron::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AGALAGA_USFX_L01Pawn* MyPawn = Cast<AGALAGA_USFX_L01Pawn>(UGameplayStatics::GetPlayerPawn(this, 0));

	if (MyPawn)
	{
		// Obtener la posición y la rotación de la nave
		FVector NavePosicion = MyPawn->GetActorLocation();
		FRotator NaveRotacion = MyPawn->GetActorRotation();

		// Calcular la dirección hacia adelante de la nave
		FVector ForwardVector = NaveRotacion.Vector();

		// Calcular la posición del escudo delante de la nave
		FVector ShieldPosition = NavePosicion + ForwardVector * DistanciaEscudoNave;

		// Establecer la posición del escudo
		SetActorLocation(ShieldPosition);
		SetActorRotation(NaveRotacion);
	}
	coolTime += GetWorld()->DeltaTimeSeconds;
	desaparecer(coolTime);

}








