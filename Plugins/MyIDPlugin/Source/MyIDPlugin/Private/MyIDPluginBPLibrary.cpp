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
    if (UWorld* World = GEngine->GetCurrentPlayWorld())
    {
        if (UGameInstance* GameInstance = World->GetGameInstance())
        {
            if (UMyIDSubsystem* Subsystem = GameInstance->GetSubsystem<UMyIDSubsystem>())
            {
                Subsystem->SetUserName(NewName);
            }
        }
    }
}

FString UMyIDPluginBPLibrary::GetUserName()
{
    if (UWorld* World = GEngine->GetCurrentPlayWorld())
    {
        if (UGameInstance* GameInstance = World->GetGameInstance())
        {
            if (UMyIDSubsystem* Subsystem = GameInstance->GetSubsystem<UMyIDSubsystem>())
            {
                return Subsystem->GetUserName();
            }
        }
    }
    return TEXT("Unknown");
}