#pragma once
#include <string>
#include <sstream>
using namespace std;

class Character;

class Item 
{
public:
    virtual string getName() = 0;
    virtual void use(Character* character) = 0;
    virtual ~Item() {}
};

class HealthPotion : public Item
{
public: 
    string getName() override 
    {
        return "ü�� ����";
    }

    void use(Character* character) override;
};

class AttackBoost : public Item 
{
public:
    string getName() override
    {
        return "���ݷ� ���� ����";
    }

    void use(Character* character) override;
};