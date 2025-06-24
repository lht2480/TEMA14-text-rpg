#include "Item.h"
#include "Character.h"
#include <iostream>

void HealthPotion::use(Character* character) 
{
    character->health += 50;
    if (character->health > character->maxHealth)
        character->health = character->maxHealth;
    cout << character->name << "��(��) ü�� ������ ����߽��ϴ�! ü�� +50\n";
}

void AttackBoost::use(Character* character) 
{
    character->attack += 10;
    cout << character->name << "��(��) ���ݷ� ���� ������ ����߽��ϴ�! ���ݷ� +10\n";
}
