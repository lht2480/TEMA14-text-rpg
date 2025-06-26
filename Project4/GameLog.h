#pragma once
#include <string>
#include <vector>

class GameLog
{
public:
    void log(const std::string& msg);
    void saveToFile(const std::string& filename);
    void showLogs();

private:
    std::vector<std::string> logs;

};

extern GameLog logger;