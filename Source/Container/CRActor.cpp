#include "CRActor.h"
#include "Engine/Engine.h"

#pragma execution_character_set("utf-8")

ACRActor::ACRActor()
{
    PrimaryActorTick.bCanEverTick = false;
}

// 1. 인벤토리(TArray) 안의 아이템 정보를 Key(TMap)로 검색해 출력하는 함수
void ACRActor::ShowInventory()
{
    if (InventoryBag.Num() == 0)
    {
        if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, TEXT("가방이 비어있습니다."));
        UE_LOG(LogTemp, Warning, TEXT("가방이 비어있습니다."));
        return;
    }

    if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, TEXT("=== 현재 인벤토리 아이템 ==="));
    UE_LOG(LogTemp, Log, TEXT("=== 현재 인벤토리 아이템 ==="));

    for (const FName& ItemName : InventoryBag)
    {
        // TMap에서 Key값으로 아이템 정보 확인
        if (FItemData* ItemInfo = ItemDatabase.Find(ItemName))
        {
            FString TitleStr = ItemInfo->RequiredTitle.IsNone() ? TEXT("없음") : ItemInfo->RequiredTitle.ToString();
            FString Msg = FString::Printf(TEXT("[이름: %s] 정보: %s / 필요 칭호: %s"),
                *ItemName.ToString(), *ItemInfo->ItemDescription, *TitleStr);

            if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::White, Msg);
            UE_LOG(LogTemp, Log, TEXT("%s"), *Msg);
        }
    }
}

// 2. 칭호 보유 여부를 확인하고 아이템을 사용하는 함수
void ACRActor::UseItem(FName ItemName)
{
    if (!InventoryBag.Contains(ItemName))
    {
        FString Msg = TEXT("가방에 없는 아이템입니다: ") + ItemName.ToString();
        if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, Msg);
        UE_LOG(LogTemp, Warning, TEXT("%s"), *Msg);
        return;
    }

    if (FItemData* ItemInfo = ItemDatabase.Find(ItemName))
    {
        // 요구 칭호가 없거나, 획득한 칭호(TSet)에 해당 칭호가 포함되어 있는지 확인
        if (ItemInfo->RequiredTitle.IsNone() || AcquiredTitles.Contains(ItemInfo->RequiredTitle))
        {
            FString Msg = FString::Printf(TEXT("사용 성공! [%s]"), *ItemInfo->ItemDescription);
            if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, Msg);
            UE_LOG(LogTemp, Log, TEXT("%s"), *Msg);
        }
        else
        {
            FString Msg = FString::Printf(TEXT("실패! [%s] 칭호가 필요합니다."), *ItemInfo->RequiredTitle.ToString());
            if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, Msg);
            UE_LOG(LogTemp, Error, TEXT("%s"), *Msg);
        }
    }
}