#include "TaskTracker.hpp"
#include "Task.hpp"
#include <ctime>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <vector>
#include <chrono>
#include <sstream>
#include <iostream>
#include <fstream>
#include <algorithm>

/*
Initialise TaskTracker with ID 0
*/
TaskTracker::TaskTracker() : nextId(1), taskFile("tasks.txt") {
    tasks = loadTasksFromFile();
}

void TaskTracker::saveTasksToFile(){
    std::ofstream file(taskFile);
    if(file.is_open()){
        // Save nextId first
        file << "NEXTID:" << nextId << std::endl;
        
        for(const Task& task: tasks){
            file << task.id << "|" << task.description << "|" << statusToString(task.status) << "|" << task.createdAt << "|" << task.updatedAt << std::endl;
        }
    }
    file.close();
}

std::vector<Task> TaskTracker::loadTasksFromFile(){
    std::vector<Task> tasks;
    std::ifstream file(taskFile);
    if(!file.is_open()){
        return tasks;
    }
    
    std::string line;
    // Read nextId first
    if(std::getline(file, line) && line.find("NEXTID:") == 0) {
        nextId = std::stoi(line.substr(7));
    }
    
    while(std::getline(file, line)){
        std::stringstream ss(line);
        std::string id, description, status, createdAt, updatedAt;
        std::getline(ss,id,'|');
        std::getline(ss,description,'|');
        std::getline(ss,status,'|');
        std::getline(ss,createdAt,'|');
        std::getline(ss,updatedAt,'|');
        tasks.push_back(Task(std::stoi(id),description,stringToStatus(status),createdAt,updatedAt));
    }
    file.close();
    return tasks;
}

TaskStatus TaskTracker::stringToStatus(const std::string& input){
    if(input == "todo" || input == "TODO"){
        return TaskStatus::TODO;
    } else if (input == "in-progress" || input == "IN_PROGRESS") {
        return TaskStatus::IN_PROGRESS;
    } else if (input == "done" || input == "DONE") {
        return TaskStatus::DONE;
    }
    throw std::invalid_argument("Invalid status: " + input + ". Should be either 'todo', 'in-progress' or 'done'");
}

std::string TaskTracker::statusToString(const TaskStatus& input){
    switch (input) {
        case TaskStatus::TODO: return "todo";
        case TaskStatus::IN_PROGRESS: return "in-progress";
        case TaskStatus::DONE: return "done";
        default: return "unknown";
    }
}


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
    saveTasksToFile();
}

void TaskTracker::updateTask(int id, const std::string& description) {
    for (Task& task : tasks){
        if (task.id == id){
            task.description = description;
            task.updatedAt = getCurrentDateTime();
            saveTasksToFile();
            return;
        }
    }
    throw std::runtime_error("Task with ID " + std::to_string(id) + " not found");
}

void TaskTracker::updateStatus(int id, const std::string& status) {
    for (Task& task: tasks){
        if (task.id == id){
            task.status = stringToStatus(status);
            task.updatedAt = getCurrentDateTime();
            saveTasksToFile();
            return;
        }
    }
    throw std::runtime_error("Task with ID " + std::to_string(id) + " not found");
}

void TaskTracker::deleteTask(int id) {
    for (auto it =tasks.begin();it !=tasks.end();++it){
        if (it->id == id){
            tasks.erase(it);
            saveTasksToFile();
            return;
        }
    }
    throw std::runtime_error("Task with ID " + std::to_string(id) + " not found");
}

void TaskTracker::listTasks() {
    for (Task& task: tasks){
        std::cout << "Task ID: " << task.id 
                  << " | Description: " << task.description 
                  << " | Status: " << statusToString(task.status) 
                  << " | Created: " << task.createdAt 
                  << " | Updated: " << task.updatedAt << std::endl;
    }
}

void TaskTracker::listTasksByStatus(const std::string& status) {
    for (Task& task: tasks){
        if (task.status == stringToStatus(status)){
            std::cout << "Task ID: " << task.id 
                      << " | Description: " << task.description 
                      << " | Status: " << statusToString(task.status) 
                      << " | Created: " << task.createdAt 
                      << " | Updated: " << task.updatedAt << std::endl;
        }
    }
}
