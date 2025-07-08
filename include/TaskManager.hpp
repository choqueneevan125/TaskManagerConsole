#pragma once
#include <vector>
#include "Task.hpp"

class TaskManager {
public:
    TaskManager();

    void addTask(const std::string& description);
    bool removeTask(int id);
    bool markTaskDone(int id);
    void listTasks() const;

    const std::vector<Task>& getTasks() const;
    void clearTasks(); // Pour recharger depuis fichier
    void loadFromData(int id, const std::string& desc, bool done);

private:
    std::vector<Task> tasks;
    int nextId;
};
