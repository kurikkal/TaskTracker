#include "TaskTracker.hpp"
#include "Task.hpp"
#include <ctime>
#include <iomanip>
#include <vector>
#include <chrono>
#include <sstream>
#include <iostream>
#include <algorithm>

/*
Initialise TaskTracker with ID 0
*/
TaskTracker::TaskTracker() : nextId(0) {}

std::string TaskTracker::getCurrentDateTime(){
    auto now = std::chrono::system_clock::now();
    auto current_time = std::chrono::system_clock::to_time_t(now);

    std::ostringstream oss;
    oss << std::put_time(std::localtime(&current_time),"%Y-%m-%d %H:%M:%S");
    return oss.str();
}

void TaskTracker::addTask(const std::string& description) {
    std::string time_stamp = getCurrentDateTime();
    tasks.push_back(Task(nextId++,description,TaskStatus::TODO,time_stamp,time_stamp));
}

void TaskTracker::updateTask(int id, const std::string& description) {
    // TODO: Implement updateTask functionality
}

void TaskTracker::updateStatus(int id, const std::string& status) {
    // TODO: Implement updateStatus functionality
}

void TaskTracker::deleteTask(int id) {
    // TODO: Implement deleteTask functionality
}

void TaskTracker::listTasks() {
    // TODO: Implement listTasks functionality
}

void TaskTracker::listTasksByStatus(const std::string& status) {
    // TODO: Implement listTasksByStatus functionality
}
