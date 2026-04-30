#include "TraceTest.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Engine/DamageEvents.h"
#include "GameFramework/Character.h"

ATraceTest::ATraceTest()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ATraceTest::BeginPlay()
{
	Super::BeginPlay();

	// AEnemyCharacter가 아닌 ATraceTest로 바인딩 수정
	AsyncTraceDelegate.BindUObject(this, &ATraceTest::OnAsyncTraceCompleted);
}

void ATraceTest::FindPlayerAsync()
{
	FVector StartLocation = GetActorLocation();
	FVector EndLocation = StartLocation + (GetActorForwardVector() * 1500.0f);

	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);

	GetWorld()->AsyncLineTraceByChannel(
		EAsyncTraceType::Single,
		StartLocation,
		EndLocation,
		ECC_Visibility,
		Params,
		FCollisionResponseParams::DefaultResponseParam,
		&AsyncTraceDelegate
	);
}

void ATraceTest::OnAsyncTraceCompleted(const FTraceHandle& Handle, FTraceDatum& Data)
{
	if (Data.OutHits.Num() > 0)
	{
		FHitResult Hit = Data.OutHits[0];

		if (AActor* HitActor = Hit.GetActor())
		{
			if (HitActor->IsA(ACharacter::StaticClass()))
			{
				UE_LOG(LogTemp, Warning, TEXT("비동기 트레이스: 플레이어 발견! - %s"), *HitActor->GetName());
			}
		}
	}
}