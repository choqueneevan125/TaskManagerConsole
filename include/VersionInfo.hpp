#pragma once

#include <string>

namespace VersionInfo {
    std::string getAppName();
    std::string getVersion();
    std::string getAuthor();
    void printVersion(); // Affiche nom + version
}
