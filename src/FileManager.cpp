#include "FileManager.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

FileManager::FileManager(const std::string& filename) : filename(filename) {}

void FileManager::saveTasks(const TaskManager& manager) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Erreur d’écriture dans le fichier.\n";
        return;
    }

    for (const auto& task : manager.getTasks()) {
        file << task.getId() << ";" 
             << (task.isDone() ? 1 : 0) << ";" 
             << task.getDescription() << "\n";
    }
    std::cout << "Tâches sauvegardées.\n";
}

void FileManager::loadTasks(TaskManager& manager) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Fichier introuvable ou vide.\n";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string idStr, doneStr, desc;
        if (std::getline(iss, idStr, ';') &&
            std::getline(iss, doneStr, ';') &&
            std::getline(iss, desc)) {
            int id = std::stoi(idStr);
            bool done = (doneStr == "1");
            manager.loadFromData(id, desc, done);
        }
    }
    std::cout << "Tâches chargées.\n";
}
