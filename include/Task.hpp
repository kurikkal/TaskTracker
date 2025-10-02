#ifndef TASK_H
#define TASK_H

#include <string>


enum TaskStatus {
    TODO,
    IN_PROGRESS,
    DONE
};

class Task {
    public:
        int id;
        std::string description;
        TaskStatus status;
        std::string createdAt;
        std::string updatedAt;

        Task(int id, const std::string& description, TaskStatus status, const std::string& createdAt, const std::string& updatedAt);
};

#endif
