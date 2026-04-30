// Fill out your copyright notice in the Description page of Project Settings.


#include "Deep.h"

// Sets default values
ADeep::ADeep()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADeep::BeginPlay()
{
	Super::BeginPlay();
	
	TArray<int32> IntArray;

	while (IntArray.Num() < 30) {
		int32 randA = FMath::RandRange(0, 1000);

		if (randA <= 100) {
			IntArray.Add(randA);
		}
	}

	IntArray.RemoveAll([](int32 x) {
		return x < 50;
	});

	IntArray.Sort();
}

// Called every frame
void ADeep::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

} 

