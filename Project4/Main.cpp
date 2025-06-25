#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include "GameManager.h"
#include "Character.h"
#include "GameLog.h"

using namespace std;

extern GameLog logger;

enum GAME_STATE
{
    START,
    PLAY,
    FIGHT,
    END,
    QUIT
};

int main()
{
    string name;
    srand(static_cast<unsigned int>(time(nullptr)));
    GAME_STATE state = START;
    GameManager manager;
    Character player("");
    int choice;

    while (state != QUIT)
    {
        switch (state)
        {
        case START:
            logger.log("게임이 시작되었습니다!");
            logger.log("캐릭터의 이름을 입력해주세요:");
            cout << "이름: ";
            getline(cin, name);
            player = Character(name);

            logger.log("당신의 이름은: " + name + "입니다.");
            system("pause");
            state = PLAY;
            break;

        case PLAY:
            if (player.level >= 10)
            {
                system("cls");
                logger.log("이미 만렙이라 게임이 끝납니다...");
                system("pause");
                state = END;
                break;
            }
            system("cls");
            logger.log("무엇을 하시겠습니까?");
            logger.log("1. 싸운다.  2. 상태창 확인.  3. 소지아이템 확인.  4. 로그 확인.");
            logger.log("선택: ");
            cin >> choice;
            cin.ignore();

            if (choice == 1)
            {
                logger.log("플레이어가 전투를 선택함");
                state = FIGHT;
                break;
            }
            else if (choice == 2)
            {
                logger.log("플레이어가 상태창 확인을 선택함");
                player.showStatus();

                system("pause");
                state = PLAY;
                break;
            }
            else if (choice == 3)
            {
                logger.log("플레이어가 인벤토리 확인을 선택함");
                manager.displayInventory(player);

                system("pause");
                state = PLAY;
                break;
            }
            else if (choice == 4)
            {
                logger.log("플레이어가 로그 확인을 선택함");
                logger.showLogs();

                system("pause");
                state = PLAY;
                break;
            }

            else
            {
                logger.log("잘못된 입력 시도");

                system("pause");
                state = PLAY;
                break;
            }

        case FIGHT:
            system("cls");
            logger.log("몬스터와의 전투가 시작되었습니다.");

            if (manager.battle(player))
            {
                logger.log("전투 승리 → 다음 상태: PLAY");

                state = PLAY;
            }

            else
            {
                logger.log("전투 패배 → 게임 종료 상태로 이동");

                state = END;
            }
            system("pause");
            break;

        case END:
            logger.log("게임이 끝났습니다.");

            system("pause");
            state = QUIT;
            break;

        default:
            logger.log("알 수 없는 상태 처리");

            system("pause");
            state = PLAY;
            break;
        }
    }

    return 0;
}