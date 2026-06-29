#include "TriggerDispatcherSubsystem.h"

FGuid UTriggerDispatcherSubsystem::RegisterListener(FGameplayTag Tag, FTriggerListenerDelegate Callback, bool bMatchChildren)
{
    FTriggerListenerEntry Entry;
    Entry.ListenerTag = Tag;
    Entry.Callback = Callback;
    Entry.bMatchChildren = bMatchChildren;
    Entry.Handle = FGuid::NewGuid();
    Listeners.Add(Entry);
    return Entry.Handle;
}

void UTriggerDispatcherSubsystem::UnregisterListener(FGuid Handle)
{
    Listeners.RemoveAll([Handle](const FTriggerListenerEntry& E) { return E.Handle == Handle; });
}

void UTriggerDispatcherSubsystem::Dispatch(const FTriggerActivationData& Data)
{
    for (const FTriggerListenerEntry& Entry : Listeners)
    {
        const bool bMatch = Entry.bMatchChildren
            ? Data.TriggerTag.MatchesTag(Entry.ListenerTag)
            : Data.TriggerTag.MatchesTagExact(Entry.ListenerTag);
        if (bMatch)
        {
            Entry.Callback.ExecuteIfBound(Data);
        }
    }
}
