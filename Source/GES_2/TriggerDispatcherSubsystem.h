#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GameplayTagContainer.h"
#include "TriggerTypes.h"
#include "TriggerDispatcherSubsystem.generated.h"   // LAST include

DECLARE_DYNAMIC_DELEGATE_OneParam(FTriggerListenerDelegate, const FTriggerActivationData&, Data);

USTRUCT()
struct FTriggerListenerEntry
{
    GENERATED_BODY()
    FGameplayTag ListenerTag;
    FTriggerListenerDelegate Callback;
    bool bMatchChildren = true;
    FGuid Handle;
};

UCLASS()
class GES_2_API UTriggerDispatcherSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()
public:
    FGuid RegisterListener(FGameplayTag Tag, FTriggerListenerDelegate Callback, bool bMatchChildren = true);
    void UnregisterListener(FGuid Handle);
    void Dispatch(const FTriggerActivationData& Data);

private:
    TArray<FTriggerListenerEntry> Listeners;
};
