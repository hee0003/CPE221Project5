#include "druid.hpp"


Druid::Druid(JsonEntityBuilder &builder, JsonItemBuilder & inventory, uint32_t uid) : 
    Entity(builder, inventory, uid)
{
    std::cout << Name() << " the druid has entered the battle" << std::endl;
}


void Druid::FlamingSphere(Entity * target)
{
    Attack(target, GetAgility() * 1.0, "Flaming Sphere");
}


void Druid::HealingWord(Entity *target)
{
    Heal(target, GetAgility() * 2.0, "Healing Word");
}


void Druid::OutputStatus() const
{
    std::cout << Class() << ": " << this->Name()
                << "\n\tCurrent HP: " << this->CurrentHP()
                << "\n\tWisdom: " << this->GetWisdom()
                << std::endl;
                
    PrintInventory();
}

void Druid::WeaponAttack(Entity * target)
{
    Attack(target, 4.0, "Dagger Attack");
}

void Druid::UseAction(Entity * target, const std::string& spellName, const std::string & args)
{
    if(spellName == "weapon_attack")
    {
        WeaponAttack(target);
        return;
    }
    if(spellName == "flaming_sphere")
    {
        FlamingSphere(target);
        return;
    }
    if(spellName == "healing_word")
    {
        HealingWord(target);
        return;
    }
    errorFindingAbility(spellName);

}