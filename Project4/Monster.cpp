//#include "Monster.h"
//#include <iostream>
//
//using namespace std;
//
//Monster::Monster(string n, int h, int a) : name(n), health(h), attack(a) {}
//
//void Monster::takeDamage(int dmg) 
//{
//    health -= dmg;
//}

#include "Monster.h"
#include <iostream>

bool Monster::isDead()
{
    return getHealth() <= 0;
}

Goblin::Goblin(int level)
{
    name = "Goblin";
    health = 20 + level * 2;
    attack = 5 + level;
}
std::string Goblin::getName() const
{
    return name;
}
int Goblin::getHealth() const 
{
    return health;
}
int Goblin::getAttack() const 
{
    return attack;
}
void Goblin::takeDamage(int damage) 
{
    health -= damage;
    if (health < 0) health = 0;
}

Orc::Orc(int level) 
{
    name = "Goblin";
    health = 20 + level * 2;
    attack = 5 + level;
}
std::string Orc::getName() const 
{
    return name;
}
int Orc::getHealth() const
{
    return health;
}
int Orc::getAttack() const 
{
    return attack;
}
void Orc::takeDamage(int damage) 
{
    health -= damage;
    if (health < 0) health = 0;
}

Troll::Troll(int level) {
    name = "Goblin";
    health = 20 + level * 2;
    attack = 5 + level;
}
std::string Troll::getName() const {
    return name;
}
int Troll::getHealth() const {
    return health;
}
int Troll::getAttack() const {
    return attack;
}
void Troll::takeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;
}

Slime::Slime(int level) {
    name = "Goblin";
    health = 20 + level * 2;
    attack = 5 + level;
}
std::string Slime::getName() const {
    return name;
}
int Slime::getHealth() const {
    return health;
}
int Slime::getAttack() const {
    return attack;
}
void Slime::takeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;
}