// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TestObject.generated.h"

UCLASS()
class UNREALDEEPENING_API UTestObject : public UObject
{
	GENERATED_BODY()

public:

	void InitObject(FString InName);

	// 객체가 사라질 준비..
	virtual void BeginDestroy() override;

	// 가비지 컬렉션이 날 지움
	virtual void FinishDestroy() override;
	
private:
	FString MemoName;
};
