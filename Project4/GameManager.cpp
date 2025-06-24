#include "GameManager.h"
#include "Monster.h"
#include "Character.h"
#include "Item.h"
#include <iostream>
#include <cstdlib>

using namespace std;

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
    cout << "[�κ��丮 ���]" << endl;
    for (size_t i = 0; i < player.inventory.size(); ++i) 
    {
        cout << i + 1 << ". " << player.inventory[i]->getName() << endl;
    }
}

bool GameManager::battle(Character& player) 
{
    unique_ptr<Monster> monster = generateMonster(player.level);
    cout << "\n���� " << monster->getName() << " ����! ü��: " << monster->getHealth() << ", ���ݷ�: " << monster->getAttack() << endl;

    while (player.health > 0 && !monster->isDead())
    {
        cout << "\n--- ���� ���� ---" << endl;
        cout << "| �� ���� |" << "ü��: " << player.health << " | ���ݷ�: " << player.attack << endl;
        cout << "| ���� ���� |" << "ü��: " << monster->getHealth() << " | ���ݷ�: " << monster->getAttack() << endl;
        while (true)
        {
            cout << "\n[�� ����] ������ �Ͻðڽ��ϱ�?\n1. ����\n2. ������ ���" << endl;
            int choice;
            cin >> choice;

            switch (choice)
            {        
                case 1:
                    monster->takeDamage(player.attack);
                    cout << player.name << "�� " << monster->getName() << "��(��) �����մϴ�! ���� ü��: " << max(0, monster->getHealth()) << endl;
                    break;
            
                case 2:
                    if (!player.inventory.empty())
                    {
                        int itemIdx = -1;
                        while (true)
                        {
                            displayInventory(player);
                            cout << "����� ������ ��ȣ�� �Է��ϼ��� (0: ���): ";
                            cin >> itemIdx;
                            if (itemIdx == 0)
                            {
                                cout << "������ ����� ����߽��ϴ�." << endl;
                                break;
                            }
                            else if (itemIdx >= 1 && itemIdx <= player.inventory.size())
                            {
                                player.useItem(itemIdx - 1);
                                break;
                            }
                            else
                            {
                                cout << "�߸��� �Է��Դϴ�. �ٽ� �������ּ���." << endl;
                            }
                        }
                    }  
                    else
                    {
                        cout << "����� �� �ִ� �������� �����ϴ�." << endl;
                        break;
                    }
                    break;
 
                default:
                cout << "�߸��� �Է��Դϴ�. �ٽ� �������ּ���." << endl;
                continue;
            }
            break;
        }
        
        if (monster->isDead()) break;

        player.health -= monster->getAttack();
        cout << monster->getName() << "��(��) " << player.name << "��(��) �����մϴ�! ���� ü��: " << max(0, player.health) << endl;
    }

    if (player.health <= 0) 
    {
        cout << player.name << "�� ����߽��ϴ�. ���� ����!\n";
        return false;
    }
    else 
    {
        int exp = 50;
        int gold = rand() % 11 + 10;
        player.experience += exp;
        player.gold += gold;
        cout << player.name << "�� �������� �¸��߽��ϴ�! ����ġ: " << exp << " ���: " << gold << "\n";

        if (rand() % 100 < 30) 
        {
            if (rand() % 2 == 0)
            {
                player.inventory.push_back(make_unique<HealthPotion>());
                cout << "[ȹ�� ������] ü�� ����\n";
            }
            else
            {
                player.inventory.push_back(make_unique<AttackBoost>());
                cout << "[ȹ�� ������] ���ݷ� ����\n";
            }
        }

        player.levelUp();
        return true;
    }
}