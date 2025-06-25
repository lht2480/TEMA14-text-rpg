#pragma once
#include <iostream> 
#include <sstream>
#include "Character.h"
#include "GameManager.h"
#include "Item.h"
#include "GameLog.h"

using namespace std;

extern GameLog logger;

Character::Character(string n) : name(n) {}

void Character::showStatus()
{
    stringstream ss;
    ss << "[상태] 이름:  " << name << " | 레벨: " << level << " | 체력: " << health
        << "/" << maxHealth << " | 공격력: " << attack
        << " | 경험치: " << experience << "/100 | 골드: " << gold;
    logger.log(ss.str());
}

void Character::levelUp()
{
    while (experience >= 100 && level < 10)
    {
        experience -= 100;
        level++;
        health += level * 20;
        attack += level * 5;
        maxHealth = health;

        stringstream ss;
        ss << "레벨 업! 현재 레벨: " << level << ", 체력: " << health << ", 공격력: " << attack;
        logger.log(ss.str());
    }
}

void Character::useItem(int index)
{
    if (index >= 0 && index < inventory.size()) {
        inventory[index]->use(this);
        inventory.erase(inventory.begin() + index);
    }
}