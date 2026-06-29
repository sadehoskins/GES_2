#include "TriggerCondition.h"
#include "TriggerGameplayTags.h"

FGameplayTag UTriggerCondition::GetFailureTag() const
{
    return TriggerTags::TAG_Trigger_Validation_Failed;
}

FText UTriggerCondition::GetFailureMessage() const
{
    return FText::FromString(TEXT("Condition failed."));
}