// Copyright 703 Games


#include "Actor/AuraEffectActor.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "Components/SphereComponent.h"

AAuraEffectActor::AAuraEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SetRootComponent(CreateDefaultSubobject<USceneComponent>("SceneRoot"));
}

void AAuraEffectActor::BeginPlay()
{
	Super::BeginPlay();


}

// Define a method called ApplyEffecttoTarget, taking in a AActor pointer and a gameplay effect class
void AAuraEffectActor::ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass)
{
    // Get the Ability System Component of the target Actor
    UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
   
    // If the Ability System Component doesn't exist, stop the function
    if (TargetASC == nullptr)
        return;
	
    // Check that the gameplay effect class is valid, if not the engine will crash
    check(GameplayEffectClass);

    // Make an effect context for the ability system, used to apply effects under certain conditions
    FGameplayEffectContextHandle EffectContextHandle = TargetASC->MakeEffectContext();

    // Associate the current AuraEffectActor instance to the effect context
    EffectContextHandle.AddSourceObject(this);

    // Create a specification or "spec" for the gameplay effect with the desired class, magnitude, and context
    const FGameplayEffectSpecHandle EffectSpecHandle = TargetASC->MakeOutgoingSpec(GameplayEffectClass, 1.f, EffectContextHandle);

    // Apply the gameplay effect (as per the spec) to the target's Ability System Component
    // This means the effect is applied to the target itself
    TargetASC->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());
}


