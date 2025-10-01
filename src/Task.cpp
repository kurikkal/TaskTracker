#include "Task.hpp"

Task::Task(int& id, std::string& description, std::string& status, std::string& createdAt, std::string& updatedAt)
: id(id), description(description), status(status), createdAt(createdAt), updatedAt(updatedAt) {}