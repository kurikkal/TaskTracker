#ifndef TASKTRACKER_H
#define TASKTRACKER_H

#include "Task.hpp"
#include <vector>
#include <string>

class TaskTracker {
    private:
        std::vector<Task> tasks;
        int nextId;
    
    public:
        TaskTracker();
        void addTask(const std::string& description);
        void updateTask(int id, const std::string& description);
        void updateStatus(int id, const std::string& status);
        void deleteTask(int id);
        void listTasks();
        void listTasksByStatus(const std::string& status);
};

#endif
