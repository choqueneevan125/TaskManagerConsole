#pragma once
#include <string>
#include "TaskManager.hpp"

class FileManager {
public:
    FileManager(const std::string& filename);

    void saveTasks(const TaskManager& manager);
    void loadTasks(TaskManager& manager);

private:
    std::string filename;
};
