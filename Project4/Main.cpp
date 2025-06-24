#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include "GameManager.h"
#include "Character.h"

using namespace std;


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
	srand(time(nullptr));
	GAME_STATE state = START;
	Character player(name);
	GameManager manager;
	int choice;


	while (state != QUIT)
	{
		switch (state)
		{
		case START:
			cout << "게임이 시작되었습니다!\n";
			cout << "캐릭터의 이름을 입력해주세요:";
			getline(cin, name);
			// 캐릭터를 생성한다.
			cout << "당신의 이름은: " << name << "입니다." << endl;

			cout << "\n";
			system("pause");
			state = PLAY;
			break;

		case PLAY:
			if (player.level >= 10)
			{
				system("cls");
				cout << "이미 만렙이라 게임이 끝납니다...\n";
				system("pause");
				state = END;
				break;
			}
			system("cls");
			cout << "무엇을 하시겠습니까?\n";
			cout << "\n1. 싸운다.\n2.상태창 확인.\n3.소지아이템 확인.\n";
			cout << "\n선택: ";
			cin >> choice;
			cin.ignore();

			if (choice == 1) // 몬스터와 싸움
			{
				state = FIGHT;
				break;
			}

			else if (choice == 2) // 스테이터스 확인
			{
				player.showStatus();

				cout << "\n";
				system("pause");
				state = PLAY;
				break;
			}

			else if (choice == 3) // 소지아이템 확인
			{
				manager.displayInventory(player);

				cout << "\n";
				system("pause");
				state = PLAY;
				break;
			}

			else
			{
				cout << "입력 실수\n";
				cout << "\n";
				system("pause");
				state = PLAY;
				break;
			}

		case FIGHT:
			system("cls");
			cout << "몬스터와의 전투가 시작되었습니다.\n";
			// 싸우는 함수

			if (manager.battle(player))
			{
				state = PLAY;

				cout << "\n";
				system("pause");
				break;
			}
			else
			{
				state = END;

				cout << "\n";
				system("pause");
				break;
			}

		case END:
			cout << "게임이 끝났습니다.\n";

			cout << "\n";
			system("pause");
			state = QUIT;
			break;

		default:
			cout << "잘못된 선택입니다.\n";
			cout << "\n";
			system("pause");
			state = PLAY;
			break;
		}
	}
	return 0;
}