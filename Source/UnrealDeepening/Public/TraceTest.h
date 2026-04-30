
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TraceTest.generated.h"

UCLASS()
class UNREALDEEPENING_API ATraceTest : public AActor
{
	GENERATED_BODY()
	
public:	
	ATraceTest();
	void FindPlayerAsync();

protected:
	virtual void BeginPlay() override;

private:
	// 비동기 작업이 끝났을 때 알림을 받을 "연락처(Delegate)" 변수
	FTraceDelegate AsyncTraceDelegate;

	// 연락을 받으면 실제로 실행될 함수 (콜백 함수)
	void OnAsyncTraceCompleted(const FTraceHandle& Handle, FTraceDatum& Data);
};
