#include "TriggerGameplayTags.h"

namespace TriggerTags
{
    UE_DEFINE_GAMEPLAY_TAG_COMMENT(TAG_Trigger_Level_Load, "Trigger.Level.Load", "Streams in a level");
    UE_DEFINE_GAMEPLAY_TAG_COMMENT(TAG_Trigger_Level_Unload, "Trigger.Level.Unload", "Streams out a level");
    UE_DEFINE_GAMEPLAY_TAG_COMMENT(TAG_Trigger_Validation_Failed, "Trigger.Validation.Failed", "Condition check failed");
}