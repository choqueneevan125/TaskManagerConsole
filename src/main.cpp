#include <iostream>
#include "CommandHandler.hpp"
#include "VersionInfo.hpp"

int main(int argc, char* argv[]) {
    if (argc > 1 && std::string(argv[1]) == "--version") {
        VersionInfo::printVersion();
        return 0;
    }

    TaskManager taskManager;
    FileManager fileManager("tasks.txt");
    CommandHandler commandHandler(taskManager, fileManager);

    fileManager.loadTasks(taskManager); // Charger les tâches au démarrage

    std::string input;
    std::cout << "Bienvenue dans le gestionnaire de tâches ! Tapez 'help' pour la liste des commandes.\n";

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, input);

        if (input == "exit") break;

        commandHandler.handleCommand(input);
    }

    fileManager.saveTasks(taskManager); // Sauvegarder à la fin
    std::cout << "Tâches sauvegardées. À bientôt !\n";
    return 0;
}
