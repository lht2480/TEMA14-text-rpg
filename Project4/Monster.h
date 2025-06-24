//#pragma once
//#include <string>
//
//using namespace std;
//
//class Monster 
//{
//public:
//    string name;
//    int health;
//    int attack;
//
//    Monster(string n, int h, int a);
//    void takeDamage(int dmg);
//    bool isDead();
//    virtual ~Monster() {}
//};

#pragma once
#include <string>

class Monster
{
public:
    virtual ~Monster() = default;

    virtual std::string getName() const = 0;
    virtual int getHealth() const = 0;
    virtual int getAttack() const = 0;
    virtual void takeDamage(int damage) = 0;
    bool isDead();
};

class Goblin : public Monster 
{
private:
    std::string name;
    int health;
    int attack;

public:
    Goblin(int level);

    std::string getName() const override;
    int getHealth() const override;
    int getAttack() const override;
    void takeDamage(int damage) override;
};

class Orc : public Monster 
{
private:
    std::string name;
    int health;
    int attack;

public:
    Orc(int level);

    std::string getName() const override;
    int getHealth() const override;
    int getAttack() const override;
    void takeDamage(int damage) override;
};

class Troll : public Monster 
{
private:
    std::string name;
    int health;
    int attack;

public:
    Troll(int level);

    std::string getName() const override;
    int getHealth() const override;
    int getAttack() const override;
    void takeDamage(int damage) override;
};

class Slime : public Monster 
{
private:
    std::string name;
    int health;
    int attack;

public:
    Slime(int level);

    std::string getName() const override;
    int getHealth() const override;
    int getAttack() const override;
    void takeDamage(int damage) override;
};

