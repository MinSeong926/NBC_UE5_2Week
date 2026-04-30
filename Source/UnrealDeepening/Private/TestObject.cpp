// Fill out your copyright notice in the Description page of Project Settings.


#include "TestObject.h"

void UTestObject::InitObject(FString InName)
{
	MemoName = InName;
}

void UTestObject::BeginDestroy()
{
	// 부모에서 만든 기능 실행
	Super::BeginDestroy();

	UE_LOG(LogTemp, Warning, TEXT("GC 시작 : %s 객체가 사라질 준비가 됐습니다."), *MemoName);
}

void UTestObject::FinishDestroy()
{
	Super::FinishDestroy();

	UE_LOG(LogTemp, Warning, TEXT("GC 시작 : %s 객체가 메모리에서 완전히 사라졌습니다."), *MemoName);
}
