// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyGCObserver.generated.h"

UCLASS()
class UNREALDEEPENING_API AMyGCObserver : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyGCObserver();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:

	UPROPERTY()
	class UTestObject* SafeObject;

	// 스마트 포인터
	TWeakObjectPtr<class UTestObject> DangerObject;

	//class UTestObject* DangerObject;

	
};
