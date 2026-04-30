#include "MyGCObserver.h"
#include "TestObject.h"
#include "Engine/Engine.h"

AMyGCObserver::AMyGCObserver()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMyGCObserver::BeginPlay()
{
	Super::BeginPlay();

	SafeObject = NewObject<UTestObject>(this);
	SafeObject->InitObject(TEXT("SafeObject_Member"));

	DangerObject = NewObject<UTestObject>(this);
	DangerObject->InitObject(TEXT("DangerObject_Member"));

	UE_LOG(LogTemp, Log, TEXT("가비지 컬렉션 작동시작.."));
}

void AMyGCObserver::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	bool bSafeIf = SafeObject != nullptr;
	bool bSafeValid = bSafeIf ? SafeObject->IsValidLowLevel() : false;

	bool bDangerIf = DangerObject.IsValid();
	bool bDangerValid = bDangerIf ? DangerObject->IsValidLowLevel() : false;

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Green, FString::Printf(TEXT("Safe(UPROPERTY) -> if : %s, IsValid : %s"), bSafeIf ? TEXT("True") : TEXT("False"), bSafeValid ? TEXT("True") : TEXT("False")));
		GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Red, FString::Printf(TEXT("Danger(UPROPERTY) -> if : %s, IsValid : %s"), bDangerIf ? TEXT("True") : TEXT("False"), bDangerValid ? TEXT("True") : TEXT("False")));
	}
}