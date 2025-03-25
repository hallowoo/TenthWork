// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyIDPluginBPLibrary.h"
#include "MyIDPlugin.h"
#include "MyIDSubsystem.h"

UMyIDPluginBPLibrary::UMyIDPluginBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

float UMyIDPluginBPLibrary::MyIDPluginSampleFunction(float Param)
{
	return -1;
}

void UMyIDPluginBPLibrary::SetUserName(const FString& NewName)
{
    if (UWorld* World = GEngine->GetCurrentPlayWorld())  // 현재 월드 가져오기
    {
        if (UGameInstance* GameInstance = World->GetGameInstance())  // 가져온 월드와 연결된 게임 인스턴스 획득하기
        {
            if (UMyIDSubsystem* Subsystem = GameInstance->GetSubsystem<UMyIDSubsystem>()) // 게임 인스턴스에서 게임 인스턴스 서브시스템 가져오기
            {
                Subsystem->SetUserName(NewName);    // 정보(유저 이름) 저장
            }
        }
    }
}

FString UMyIDPluginBPLibrary::GetUserName()
{
    if (UWorld* World = GEngine->GetCurrentPlayWorld()) // 현재 월드 가져오기
    {
        if (UGameInstance* GameInstance = World->GetGameInstance()) // 가져온 월드와 연결된 게임 인스턴스 획득하기
        {
            if (UMyIDSubsystem* Subsystem = GameInstance->GetSubsystem<UMyIDSubsystem>())   // 게임 인스턴스에서 게임 인스턴스 서브시스템 가져오기
            {
                return Subsystem->GetUserName();     // 정보(유저 이름) 반환
            }
        }
    }
    return TEXT("Unknown"); // 가져오기 실패 시 반환값
}