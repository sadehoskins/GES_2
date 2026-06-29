#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "TriggerTypes.h"
#include "TriggerCondition.generated.h"

UCLASS(Abstract, EditInlineNew, DefaultToInstanced, BlueprintType)
class GES_2_API UTriggerCondition : public UObject
{
    GENERATED_BODY()
public:
    virtual bool Evaluate(const FTriggerEvaluationContext& Context) const PURE_VIRTUAL(UTriggerCondition::Evaluate, return false;);
    virtual FGameplayTag GetFailureTag() const;
    virtual FText GetFailureMessage() const;
};
