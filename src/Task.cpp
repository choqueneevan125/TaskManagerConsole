#include "Task.hpp"
#include <sstream>

Task::Task(int id, const std::string& desc, bool done)
    : id(id), description(desc), done(done) {}

int Task::getId() const {
    return id;
}

std::string Task::getDescription() const {
    return description;
}

bool Task::isDone() const {
    return done;
}

void Task::markDone() {
    done = true;
}

void Task::markUndone() {
    done = false;
}

std::string Task::toString() const {
    std::ostringstream out;
    out << "[" << id << "] " << description << (done ? " (✓ terminé)" : " (non terminé)");
    return out.str();
}
