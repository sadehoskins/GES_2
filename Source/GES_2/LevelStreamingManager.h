#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TriggerTypes.h"
#include "LevelStreamingManager.generated.h"  

UCLASS()
class GES_2_API ULevelStreamingManager : public UGameInstanceSubsystem
{
    GENERATED_BODY()
public:
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    virtual void Deinitialize() override;

    UFUNCTION()
    void OnTriggerReceived(const FTriggerActivationData& Data);

private:
    FGuid ListenerHandle;
    void HandleLevelLoad(const FTriggerActivationData& Data);
    void HandleLevelUnload(const FTriggerActivationData& Data);
};