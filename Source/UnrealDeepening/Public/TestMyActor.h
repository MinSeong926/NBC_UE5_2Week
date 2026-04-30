#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestMyActor.generated.h"

UCLASS()
class UNREALDEEPENING_API ATestMyActor : public AActor
{
	GENERATED_BODY()

public:
	ATestMyActor();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
	int32 Health = 100;
};