#include "TaskManager.hpp"
#include <iostream>

TaskManager::TaskManager() : nextId(1) {}

void TaskManager::addTask(const std::string& description) {
    tasks.emplace_back(nextId++, description);
    std::cout << "Tâche ajoutée.\n";
}

bool TaskManager::removeTask(int id) {
    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->getId() == id) {
            tasks.erase(it);
            std::cout << "Tâche supprimée.\n";
            return true;
        }
    }
    std::cout << "ID invalide.\n";
    return false;
}

bool TaskManager::markTaskDone(int id) {
    for (auto& task : tasks) {
        if (task.getId() == id) {
            task.markDone();
            std::cout << "Tâche marquée comme terminée.\n";
            return true;
        }
    }
    std::cout << "ID invalide.\n";
    return false;
}

void TaskManager::listTasks() const {
    if (tasks.empty()) {
        std::cout << "Aucune tâche.\n";
    } else {
        for (const auto& task : tasks) {
            std::cout << task.toString() << "\n";
        }
    }
}

const std::vector<Task>& TaskManager::getTasks() const {
    return tasks;
}

void TaskManager::clearTasks() {
    tasks.clear();
    nextId = 1;
}

void TaskManager::loadFromData(int id, const std::string& desc, bool done) {
    tasks.emplace_back(id, desc, done);
    if (id >= nextId) {
        nextId = id + 1;
    }
}
