#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "MyIDSubsystem.generated.h"

UCLASS()
class MYIDPLUGIN_API UMyIDSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	void SetUserName(const FString& NewName);
	FString GetUserName() const;

private:
	FString UserName;
};
