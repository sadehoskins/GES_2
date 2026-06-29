#pragma once
#include "CoreMinimal.h"
#include "TriggerCondition.h"
#include "GameplayTagContainer.h"
#include "TriggerConditionTag.generated.h"

UCLASS()
class GES_2_API UTriggerConditionTag : public UTriggerCondition
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Category = "Trigger") FGameplayTagContainer RequiredTags;
    UPROPERTY(EditAnywhere, Category = "Trigger") FGameplayTagContainer ForbiddenTags;

    virtual bool Evaluate(const FTriggerEvaluationContext& Context) const override;
};