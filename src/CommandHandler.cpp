#include "CommandHandler.hpp"
#include <sstream>
#include <iostream>

CommandHandler::CommandHandler(TaskManager& manager, FileManager& fileMgr)
    : taskManager(manager), fileManager(fileMgr) {}

void CommandHandler::handleCommand(const std::string& input) {
    std::istringstream iss(input);
    std::string command;
    iss >> command;

    if (command == "add") {
        std::string desc;
        std::getline(iss, desc);
        if (desc.empty()) {
            std::cout << "Usage : add <description>\n";
        } else {
            taskManager.addTask(desc.substr(1)); // ignore leading space
        }
    } else if (command == "list") {
        taskManager.listTasks();
    } else if (command == "done") {
        int id;
        if (iss >> id) {
            taskManager.markTaskDone(id);
        } else {
            std::cout << "Usage : done <id>\n";
        }
    } else if (command == "remove") {
        int id;
        if (iss >> id) {
            taskManager.removeTask(id);
        } else {
            std::cout << "Usage : remove <id>\n";
        }
    } else if (command == "save") {
        fileManager.saveTasks(taskManager);
    } else if (command == "load") {
        taskManager.clearTasks();
        fileManager.loadTasks(taskManager);
    } else if (command == "help") {
        printHelp();
    } else {
        std::cout << "Commande inconnue. Tapez 'help' pour l’aide.\n";
    }
}

void CommandHandler::printHelp() const {
    std::cout <<
        "Commandes disponibles :\n"
        "  add <desc>     : Ajouter une tâche\n"
        "  list           : Lister les tâches\n"
        "  done <id>      : Marquer une tâche comme terminée\n"
        "  remove <id>    : Supprimer une tâche\n"
        "  save           : Sauvegarder les tâches dans le fichier\n"
        "  load           : Charger les tâches depuis le fichier\n"
        "  exit           : Quitter l'application\n";
}
