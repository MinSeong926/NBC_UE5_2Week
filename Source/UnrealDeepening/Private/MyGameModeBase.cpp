
#include "MyGameModeBase.h"
#include "TestMyActor.h"

void AMyGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	ATestMyActor* ActorA = GetWorld()->SpawnActor<ATestMyActor>();
	if (ActorA)
	{
		UE_LOG(LogTemp, Warning, TEXT("ActorA Init Health : %d"), ActorA->Health);
		ActorA->Health = 50;
		UE_LOG(LogTemp, Warning, TEXT("ActorA Modi : %d"), ActorA->Health);
	}

	ATestMyActor* MyActorCDO = GetMutableDefault<ATestMyActor>();
	if (MyActorCDO)
	{
		UE_LOG(LogTemp, Warning, TEXT("CDO Init Health : %d"), MyActorCDO->Health);
		MyActorCDO->Health = 200;
		UE_LOG(LogTemp, Warning, TEXT("CDO Modfi Health : %d"), MyActorCDO->Health);
	}

	ATestMyActor* ActorB = GetWorld()->SpawnActor<ATestMyActor>();
	if (ActorB)
	{
		UE_LOG(LogTemp, Warning, TEXT("ActorB Init Health : %d"), ActorB->Health);
	}

	if (ActorA)
	{
		UE_LOG(LogTemp, Warning, TEXT("ActorA Current HP : %d"), ActorA->Health);
	}
}