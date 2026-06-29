#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "TriggerTypes.h"
#include "GlobalTrigger.generated.h" 

class UTriggerCondition;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class GES_2_API UGlobalTrigger : public UActorComponent
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Category = "Trigger") FGameplayTag TriggerTag;
    UPROPERTY(EditAnywhere, Category = "Trigger") FGameplayTagContainer ContextTags;
    UPROPERTY(EditAnywhere, Category = "Trigger") bool bIsEnabled = true;
    UPROPERTY(EditAnywhere, Category = "Trigger") float CooldownTime = 0.f;
    UPROPERTY(EditAnywhere, Category = "Trigger") FName LevelName = NAME_None;
    UPROPERTY(EditAnywhere, Instanced, Category = "Trigger")
    TArray<TObjectPtr<UTriggerCondition>> Conditions;

    UFUNCTION(BlueprintCallable, Category = "Trigger")
    void ExecuteTrigger(AActor* InInstigator);

private:
    float LastTriggerTime = -1.f;
    bool EvaluateConditions(AActor* InInstigator) const;
    FTriggerActivationData BuildActivationData(AActor* InInstigator) const;
    void DispatchToSubsystem(const FTriggerActivationData& Data) const;
};
