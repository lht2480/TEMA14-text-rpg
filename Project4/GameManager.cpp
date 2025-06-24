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
    cout << "[인벤토리 목록]" << endl;
    for (size_t i = 0; i < player.inventory.size(); ++i) 
    {
        cout << i + 1 << ". " << player.inventory[i]->getName() << endl;
    }
}

bool GameManager::battle(Character& player) 
{
    unique_ptr<Monster> monster = generateMonster(player.level);
    cout << "\n몬스터 " << monster->getName() << " 등장! 체력: " << monster->getHealth() << ", 공격력: " << monster->getAttack() << endl;

    while (player.health > 0 && !monster->isDead())
    {
        cout << "\n--- 현재 상태 ---" << endl;
        cout << "| 내 상태 |" << "체력: " << player.health << " | 공격력: " << player.attack << endl;
        cout << "| 몬스터 상태 |" << "체력: " << monster->getHealth() << " | 공격력: " << monster->getAttack() << endl;
        while (true)
        {
            cout << "\n[턴 선택] 무엇을 하시겠습니까?\n1. 공격\n2. 아이템 사용" << endl;
            int choice;
            cin >> choice;

            switch (choice)
            {        
                case 1:
                    monster->takeDamage(player.attack);
                    cout << player.name << "가 " << monster->getName() << "을(를) 공격합니다! 남은 체력: " << max(0, monster->getHealth()) << endl;
                    break;
            
                case 2:
                    if (!player.inventory.empty())
                    {
                        int itemIdx = -1;
                        while (true)
                        {
                            displayInventory(player);
                            cout << "사용할 아이템 번호를 입력하세요 (0: 취소): ";
                            cin >> itemIdx;
                            if (itemIdx == 0)
                            {
                                cout << "아이템 사용을 취소했습니다." << endl;
                                break;
                            }
                            else if (itemIdx >= 1 && itemIdx <= player.inventory.size())
                            {
                                player.useItem(itemIdx - 1);
                                break;
                            }
                            else
                            {
                                cout << "잘못된 입력입니다. 다시 선택해주세요." << endl;
                            }
                        }
                    }  
                    else
                    {
                        cout << "사용할 수 있는 아이템이 없습니다." << endl;
                        break;
                    }
                    break;
 
                default:
                cout << "잘못된 입력입니다. 다시 선택해주세요." << endl;
                continue;
            }
            break;
        }
        
        if (monster->isDead()) break;

        player.health -= monster->getAttack();
        cout << monster->getName() << "이(가) " << player.name << "을(를) 공격합니다! 남은 체력: " << max(0, player.health) << endl;
    }

    if (player.health <= 0) 
    {
        cout << player.name << "가 사망했습니다. 게임 오버!\n";
        return false;
    }
    else 
    {
        int exp = 50;
        int gold = rand() % 11 + 10;
        player.experience += exp;
        player.gold += gold;
        cout << player.name << "가 전투에서 승리했습니다! 경험치: " << exp << " 골드: " << gold << "\n";

        if (rand() % 100 < 30) 
        {
            if (rand() % 2 == 0)
            {
                player.inventory.push_back(make_unique<HealthPotion>());
                cout << "[획득 아이템] 체력 포션\n";
            }
            else
            {
                player.inventory.push_back(make_unique<AttackBoost>());
                cout << "[획득 아이템] 공격력 포션\n";
            }
        }

        player.levelUp();
        return true;
    }
}