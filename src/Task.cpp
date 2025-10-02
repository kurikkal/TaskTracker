#include "Task.hpp"

Task::Task(int id, const std::string& description, TaskStatus status, const std::string& createdAt, const std::string& updatedAt)
: id(id), description(description), status(status), createdAt(createdAt), updatedAt(updatedAt) {}