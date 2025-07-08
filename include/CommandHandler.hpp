#pragma once
#include <string>
#include "TaskManager.hpp"
#include "FileManager.hpp"

class CommandHandler {
public:
    CommandHandler(TaskManager& manager, FileManager& fileMgr);

    void handleCommand(const std::string& input);

private:
    TaskManager& taskManager;
    FileManager& fileManager;

    void printHelp() const;
};
