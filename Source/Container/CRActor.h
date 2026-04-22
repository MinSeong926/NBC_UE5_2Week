
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CRActor.generated.h"

// 아이템 상세 정보를 담을 구조체
USTRUCT(BlueprintType)
struct FItemData {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ItemDescription;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName RequiredTitle; // 아이템 사용에 필요한 칭호
};

UCLASS()
class CONTAINER_API ACRActor : public AActor
{
	GENERATED_BODY()
	
public:	
    // 기본 생성자
    ACRActor();

    // 1. 가방을 TArray로 구현
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
    TArray<FName> InventoryBag;

    // 2. 아이템 정보를 Key값(아이템 이름)으로 확인할 수 있는 TMap
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
    TMap<FName, FItemData> ItemDatabase;

    // 3. 획득한 칭호를 담는 TSet
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
    TSet<FName> AcquiredTitles;

    // 4. 칭호 확인 후 아이템 사용 로직
    UFUNCTION(BlueprintCallable, Category = "Inventory")
    void UseItem(FName ItemName);

    // 인벤토리 확인 함수
    UFUNCTION(BlueprintCallable, Category = "Inventory")
    void ShowInventory();
};
