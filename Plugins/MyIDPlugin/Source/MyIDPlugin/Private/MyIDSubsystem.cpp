// Fill out your copyright notice in the Description page of Project Settings.


#include "MyIDSubsystem.h"

void UMyIDSubsystem::SetUserName(const FString& NewName)
{
    UserName = NewName;
    UE_LOG(LogTemp, Log, TEXT("[MyIDSubsystem] UserName set to: %s"), *UserName);
}

FString UMyIDSubsystem::GetUserName() const
{
    return UserName;
}