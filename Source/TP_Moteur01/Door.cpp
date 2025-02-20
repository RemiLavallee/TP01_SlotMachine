// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"
#include "TP_Moteur01Character.h"

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();

	OnActorHit.AddDynamic(this, &ADoor::OnHit);
	
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADoor::OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse,
	const FHitResult& Hit)
{
	
	auto Player = Cast<ATP_Moteur01Character>(OtherActor);
	auto CoinsCounter = Player->CoinCounter;
	if(Player != nullptr)
	{
		if(MinimumCoinToOpen == CoinsCounter)
		{
			Destroy();
		}
	}

}

