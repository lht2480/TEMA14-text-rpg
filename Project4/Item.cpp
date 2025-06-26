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
    ss << character->name << "이(가) 체력 포션을 사용했습니다! 체력 +50";
    logger.log(ss.str());
}

void AttackBoost::use(Character* character)
{
    character->attack += 10;

    stringstream ss;
    ss << character->name << "이(가) 공격력 증가 포션을 사용했습니다! 공격력 +10";
    logger.log(ss.str());
}