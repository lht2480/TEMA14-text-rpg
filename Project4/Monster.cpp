#include "Monster.h"
#include "GameLog.h"
#include <iostream>
#include <sstream>

extern GameLog logger;

bool Monster::isDead()
{
    return getHealth() <= 0;
}

Goblin::Goblin(int level)
{
    cout << "고블린 생성 완료 " << endl;
    name = "Goblin";
    health = 20 + level * 2;
    attack = 5 + level;
}
std::string Goblin::getName() const { return name; }
int Goblin::getHealth() const { return health; }
int Goblin::getAttack() const { return attack; }
void Goblin::takeDamage(int damage)
{
    health -= damage;
    if (health < 0) health = 0;

    stringstream ss;
    ss << name << "이(가) " << damage << " 피해를 입었습니다! 현재 체력: " << health;
    logger.log(ss.str());
}

Orc::Orc(int level)
{
    name = "Orc";
    health = 30 + level * 3;
    attack = 7 + level;
}
std::string Orc::getName() const { return name; }
int Orc::getHealth() const { return health; }
int Orc::getAttack() const { return attack; }
void Orc::takeDamage(int damage)
{
    health -= damage;
    if (health < 0) health = 0;

    stringstream ss;
    ss << name << "이(가) " << damage << " 피해를 입었습니다! 현재 체력: " << health;
    logger.log(ss.str());
}

Troll::Troll(int level)
{
    name = "Troll";
    health = 50 + level * 4;
    attack = 10 + level;
}
std::string Troll::getName() const { return name; }
int Troll::getHealth() const { return health; }
int Troll::getAttack() const { return attack; }
void Troll::takeDamage(int damage)
{
    health -= damage;
    if (health < 0) health = 0;

    stringstream ss;
    ss << name << "이(가) " << damage << " 피해를 입었습니다! 현재 체력: " << health;
    logger.log(ss.str());
}

Slime::Slime(int level)
{
    name = "Slime";
    health = 10 + level * 2;
    attack = 3 + level;
}
std::string Slime::getName() const { return name; }
int Slime::getHealth() const { return health; }
int Slime::getAttack() const { return attack; }
void Slime::takeDamage(int damage)
{
    health -= damage;
    if (health < 0) health = 0;

    stringstream ss;
    ss << name << "이(가) " << damage << " 피해를 입었습니다! 현재 체력: " << health;
    logger.log(ss.str());
}