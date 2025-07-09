#include "VersionInfo.hpp"
#include <iostream>

namespace VersionInfo {
    std::string getAppName() {
        return "TaskManagerConsole";
    }

    std::string getVersion() {
        return "2.0.1";
    }

    std::string getAuthor() {
        return "Choquené Evan";
    }

    void printVersion() {
        std::cout << getAppName() << " version " << getVersion() << "\n";
        std::cout << "By " << getAuthor() << "\n";
    }
}
