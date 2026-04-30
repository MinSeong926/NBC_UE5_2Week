
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Shotgun.generated.h"

UCLASS()
class UNREALDEEPENING_API AShotgun : public AActor
{
	GENERATED_BODY()
	
public:	
	AShotgun();

public:
	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void FireShotgun();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Shotgun")
	int32 PelletCount = 8; // 한 번에 발사되는 총알(펠릿) 개수

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Shotgun")
	float SpreadAngle = 5.0f; // 퍼지는 각도 (도 단위)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Recoil")
	float RecoilPitchAmount = -1.5f; // 수직 반동 (음수면 카메라가 위로 들림)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon|Recoil")
	float RecoilYawRange = 1.0f; // 좌우 반동이 무작위로 튀는 범위

};
