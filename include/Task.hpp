#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
    public:
        int id;
        std::string description;
        std::string status;
        std::string createdAt;
        std::string updatedAt;

        Task(int& id, std::string& description, std::string& status, std::string& createdAt, std::string& updatedAt);
};

#endif
