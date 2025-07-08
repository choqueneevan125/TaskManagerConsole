#pragma once
#include <string>

class Task {
public:
    Task(int id, const std::string& desc, bool done = false);

    int getId() const;
    std::string getDescription() const;
    bool isDone() const;

    void markDone();
    std::string toString() const;

private:
    int id;
    std::string description;
    bool done;
};
