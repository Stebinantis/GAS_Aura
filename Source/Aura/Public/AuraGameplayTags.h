// Copyright 703 Games

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h" 
/**
 *AuraGameplayTags
 *
 *Singleton containing native Gameplay Tags 
 */

struct FAuraGameplayTags
{
public:
    static const FAuraGameplayTags& Get() { return GameplayTags;}
    static void InitializeNativeGameplayTags();
	//Primary Attributes
	//Strength, Intelligence, Resillience, Vigor
	FGameplayTag Attributes_Primary_Strength;
	FGameplayTag Attributes_Primary_Intelligence;
	FGameplayTag Attributes_Primary_Resillience;
	FGameplayTag Attributes_Primary_Vigor;
	//Secondary Attributes
	//MaxMana, MaxHealth
	//Armor, ArmorPenetration, BlockChance, CriticalHitChance, CriticalHitDamage, CriticalHitResistance, HealthRegeneration, ManaRegeneration
	FGameplayTag Attributes_Secondary_MaxHealth;
	FGameplayTag Attributes_Secondary_MaxMana;
	
	FGameplayTag Attributes_Secondary_Armor;
	FGameplayTag Attributes_Secondary_ArmorPenetration;
	FGameplayTag Attributes_Secondary_BlockChance;
	FGameplayTag Attributes_Secondary_CriticalHitChance;
	FGameplayTag Attributes_Secondary_CriticalHitDamage;
	FGameplayTag Attributes_Secondary_CriticalHitResistance;
	FGameplayTag Attributes_Secondary_HealthRegeneration;
	FGameplayTag Attributes_Secondary_ManaRegeneration;

	
	
protected:

private:
    static FAuraGameplayTags GameplayTags;
};