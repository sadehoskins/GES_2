#include "TriggerConditionTag.h"
#include "GameplayTagAssetInterface.h"

bool UTriggerConditionTag::Evaluate(const FTriggerEvaluationContext& Context) const
{
    const IGameplayTagAssetInterface* TagActor =
        Cast<IGameplayTagAssetInterface>(Context.TriggeringActor);
    if (!TagActor) return RequiredTags.IsEmpty();

    FGameplayTagContainer ActorTags;
    TagActor->GetOwnedGameplayTags(ActorTags);

    if (!ActorTags.HasAll(RequiredTags)) return false;
    if (ActorTags.HasAny(ForbiddenTags)) return false;
    return true;
}