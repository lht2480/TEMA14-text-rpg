#include "Item.h"
#include "Character.h"
#include "GameLog.h"
#include <iostream>
#include <sstream>

extern GameLog logger;

void HealthPotion::use(Character* character)
{
    character->health += 50;
    if (character->health > character->maxHealth)
        character->health = character->maxHealth;

    stringstream ss;
    ss << character->name << "��(��) ü�� ������ ����߽��ϴ�! ü�� +50";
    logger.log(ss.str());
}

void AttackBoost::use(Character* character)
{
    character->attack += 10;

    stringstream ss;
    ss << character->name << "��(��) ���ݷ� ���� ������ ����߽��ϴ�! ���ݷ� +10";
    logger.log(ss.str());
}