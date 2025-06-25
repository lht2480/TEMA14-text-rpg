#include "GameManager.h"
#include "Monster.h"
#include "Character.h"
#include "Item.h"
#include "GameLog.h"
#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace std;

extern GameLog logger;

unique_ptr<Monster> GameManager::generateMonster(int level)
{
    int type = rand() % 4;

    switch (type) {
    case 0: return std::make_unique<Goblin>(level);
    case 1: return std::make_unique<Orc>(level);
    case 2: return std::make_unique<Troll>(level);
    case 3: return std::make_unique<Slime>(level);
    default: return std::make_unique<Goblin>(level);
    }
}

void GameManager::displayInventory(Character& player)
{
    logger.log("[�κ��丮 ���]");
    for (size_t i = 0; i < player.inventory.size(); ++i)
    {
        stringstream ss;
        ss << i + 1 << ". " << player.inventory[i]->getName();
        logger.log(ss.str());
    }
}

bool GameManager::battle(Character& player)
{
    unique_ptr<Monster> monster = generateMonster(player.level);
    {
        stringstream ss;
        ss << "\n���� " << monster->getName() << " ����! ü��: " << monster->getHealth()
            << ", ���ݷ�: " << monster->getAttack();
        logger.log(ss.str());
    }

    while (player.health > 0 && !monster->isDead())
    {


        stringstream status;
        status << "\n--- ���� ���� ---\n"
            << "| �� ���� | ü��: " << player.health << " | ���ݷ�: " << player.attack << "\n"
            << "| ���� ���� | ü��: " << monster->getHealth() << " | ���ݷ�: " << monster->getAttack();
        logger.log(status.str());

        while (true)
        {

            logger.log("\n[�� ����] ������ �Ͻðڽ��ϱ�?\n1. ����\n2. ������ ���");
            int choice;
            cin >> choice;

            switch (choice)
            {
            case 1:
            {
                monster->takeDamage(player.attack);
                stringstream ss;
                ss << player.name << "�� " << monster->getName()
                    << "��(��) �����մϴ�! ���� ü��: " << max(0, monster->getHealth());
                logger.log(ss.str());
                break;
            }

            case 2:
            {
                if (!player.inventory.empty())
                {
                    int itemIdx = -1;
                    while (true)
                    {
                        displayInventory(player);
                        logger.log("����� ������ ��ȣ�� �Է��ϼ��� (0: ���): ");
                        cin >> itemIdx;

                        if (itemIdx == 0)
                        {
                            logger.log("������ ����� ����߽��ϴ�.");
                            break;
                        }
                        else if (itemIdx >= 1 && itemIdx <= player.inventory.size())
                        {
                            player.useItem(itemIdx - 1);
                            break;
                        }
                        else
                        {
                            logger.log("�߸��� �Է��Դϴ�. �ٽ� �������ּ���.");
                        }
                    }
                }
                else
                {
                    logger.log("����� �� �ִ� �������� �����ϴ�.");
                }
                break;
            }

            default:
                logger.log("�߸��� �Է��Դϴ�. �ٽ� �������ּ���.");
                continue;
            }
            break;
        }

        if (monster->isDead()) break;

        player.health -= monster->getAttack();
        stringstream ss;
        ss << monster->getName() << "��(��) " << player.name
            << "��(��) �����մϴ�! ���� ü��: " << max(0, player.health);
        logger.log(ss.str());
    }

    if (player.health <= 0)
    {
        string msg = player.name + "�� ����߽��ϴ�. ���� ����!";
        logger.log(msg);
        return false;
    }
    else
    {
        int exp = 50;
        int gold = rand() % 11 + 10;
        player.experience += exp;
        player.gold += gold;

        stringstream ss;
        ss << player.name << "�� �������� �¸��߽��ϴ�! ����ġ: " << exp << " ���: " << gold;
        logger.log(ss.str());

        if (rand() % 100 < 30)
        {
            if (rand() % 2 == 0)
            {
                player.inventory.push_back(make_unique<HealthPotion>());
                logger.log("[ȹ�� ������] ü�� ����");
            }
            else
            {
                player.inventory.push_back(make_unique<AttackBoost>());
                logger.log("[ȹ�� ������] ���ݷ� ����");
            }
        }

        player.levelUp();
        return true;
    }
}