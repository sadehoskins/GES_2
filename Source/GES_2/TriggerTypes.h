#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "TriggerTypes.generated.h"

USTRUCT(BlueprintType)
struct FTriggerActivationData
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite) FGameplayTag TriggerTag;
    UPROPERTY(BlueprintReadWrite) FGameplayTagContainer ContextTags;
    UPROPERTY(BlueprintReadWrite) TObjectPtr<AActor> Instigator = nullptr;
    UPROPERTY(BlueprintReadWrite) TObjectPtr<AActor> TriggerOwner = nullptr;
    UPROPERTY(BlueprintReadWrite) float Timestamp = 0.f;

    UPROPERTY(BlueprintReadWrite) FName LevelName = NAME_None;
};

USTRUCT(BlueprintType)
struct FTriggerEvaluationContext
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite) TObjectPtr<AActor> TriggeringActor = nullptr;
    UPROPERTY(BlueprintReadWrite) TObjectPtr<AActor> OwnerActor = nullptr;
    UPROPERTY(BlueprintReadWrite) FGameplayTag TriggerTag;
    UPROPERTY(BlueprintReadWrite) float CurrentTime = 0.f;
};