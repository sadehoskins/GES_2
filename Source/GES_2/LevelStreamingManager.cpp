#include "LevelStreamingManager.h"
#include "TriggerDispatcherSubsystem.h"
#include "TriggerGameplayTags.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/LatentActionManager.h"

void ULevelStreamingManager::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);

    if (UTriggerDispatcherSubsystem* Dispatcher = GetGameInstance()->GetSubsystem<UTriggerDispatcherSubsystem>())
    {
        FTriggerListenerDelegate Cb;
        Cb.BindDynamic(this, &ULevelStreamingManager::OnTriggerReceived);
        ListenerHandle = Dispatcher->RegisterListener(
            FGameplayTag::RequestGameplayTag(FName("Trigger.Level")), Cb, /*bMatchChildren=*/true);
    }
}

void ULevelStreamingManager::Deinitialize()
{
    if (UTriggerDispatcherSubsystem* Dispatcher = GetGameInstance()->GetSubsystem<UTriggerDispatcherSubsystem>())
    {
        Dispatcher->UnregisterListener(ListenerHandle);
    }
    Super::Deinitialize();
}

void ULevelStreamingManager::OnTriggerReceived(const FTriggerActivationData& Data)
{
    if (Data.TriggerTag.MatchesTagExact(TriggerTags::TAG_Trigger_Level_Load))
        HandleLevelLoad(Data);
    else if (Data.TriggerTag.MatchesTagExact(TriggerTags::TAG_Trigger_Level_Unload))
        HandleLevelUnload(Data);
}

void ULevelStreamingManager::HandleLevelLoad(const FTriggerActivationData& Data)
{
    FLatentActionInfo Info;
    UGameplayStatics::LoadStreamLevel(this, Data.LevelName, true, true, Info);
}

void ULevelStreamingManager::HandleLevelUnload(const FTriggerActivationData& Data)
{
    FLatentActionInfo Info;
    UGameplayStatics::UnloadStreamLevel(this, Data.LevelName, Info, false);
}
