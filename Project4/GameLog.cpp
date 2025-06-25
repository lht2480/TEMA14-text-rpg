#include "GameLog.h"
#include <iostream>
#include <fstream>

using namespace std;

GameLog logger;

void GameLog::log(const string& msg)
{
    logs.push_back(msg);
    cout << msg << endl;
}

void GameLog::saveToFile(const string& filename)
{
    ofstream file(filename);
    for (const auto& msg : logs)
    {
        file << msg << '\n';
    }
    file.close();
}

void GameLog::showLogs()
{
    cout << "\n===== 로그 내용 확인 =====\n";
    for (const auto& msg : logs)
    {
        cout << msg << endl;
    }
    cout << "==========================\n";
}