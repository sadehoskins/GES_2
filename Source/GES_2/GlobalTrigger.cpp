#include "GlobalTrigger.h"
#include "TriggerCondition.h"
#include "TriggerDispatcherSubsystem.h"
#include "TriggerGameplayTags.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"

void UGlobalTrigger::ExecuteTrigger(AActor* InInstigator)
{
    if (!bIsEnabled) return;

    const float Now = GetWorld()->GetTimeSeconds();
    if (CooldownTime > 0.f && LastTriggerTime >= 0.f && (Now - LastTriggerTime) < CooldownTime)
        return;

    if (!EvaluateConditions(InInstigator))
    {
        FTriggerActivationData Fail = BuildActivationData(InInstigator);
        Fail.TriggerTag = TriggerTags::TAG_Trigger_Validation_Failed;
        DispatchToSubsystem(Fail);
        return;
    }

    DispatchToSubsystem(BuildActivationData(InInstigator));
    LastTriggerTime = Now;
}

bool UGlobalTrigger::EvaluateConditions(AActor* InInstigator) const
{
    FTriggerEvaluationContext Ctx;
    Ctx.TriggeringActor = InInstigator;
    Ctx.OwnerActor = GetOwner();
    Ctx.TriggerTag = TriggerTag;
    Ctx.CurrentTime = GetWorld()->GetTimeSeconds();

    for (const UTriggerCondition* C : Conditions)
    {
        if (C && !C->Evaluate(Ctx)) return false;
    }
    return true;
}

FTriggerActivationData UGlobalTrigger::BuildActivationData(AActor* InInstigator) const
{
    FTriggerActivationData Data;
    Data.TriggerTag = TriggerTag;
    Data.ContextTags = ContextTags;
    Data.InstigatorActor = InInstigator;
    Data.TriggerOwner = GetOwner();
    Data.Timestamp = GetWorld()->GetTimeSeconds();
    Data.LevelName = LevelName;
    return Data;
}

void UGlobalTrigger::DispatchToSubsystem(const FTriggerActivationData& Data) const
{
    if (UGameInstance* GI = GetWorld()->GetGameInstance())
    {
        if (UTriggerDispatcherSubsystem* Dispatcher = GI->GetSubsystem<UTriggerDispatcherSubsystem>())
        {
            Dispatcher->Dispatch(Data);
        }
    }
}
