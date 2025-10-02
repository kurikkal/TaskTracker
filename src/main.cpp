#include "TaskTracker.hpp"
#include <iostream>
#include <string>

void showUsage(const std::string& programName) {
    std::cout << "Usage: " << programName << " <command> [arguments]" << std::endl;
    std::cout << "\nCommands:" << std::endl;
    std::cout << "  add <description>           - Add a new task" << std::endl;
    std::cout << "  update <id> <description>   - Update task description" << std::endl;
    std::cout << "  delete <id>                 - Delete a task" << std::endl;
    std::cout << "  mark-in-progress <id>       - Mark task as in-progress" << std::endl;
    std::cout << "  mark-done <id>              - Mark task as done" << std::endl;
    std::cout << "  mark-todo <id>              - Mark task as todo" << std::endl;
    std::cout << "  list                        - List all tasks" << std::endl;
    std::cout << "  list <status>               - List tasks by status" << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        showUsage(argv[0]);
        return 1;
    }
    
    TaskTracker tracker;
    std::string command = argv[1];
    
    try {
        if (command == "add") {
            if (argc < 3) {
                std::cerr << "Error: Missing task description" << std::endl;
                return 1;
            }
            tracker.addTask(argv[2]);
            std::cout << "Task added successfully" << std::endl;
            
        } else if (command == "list") {
            if (argc == 2) {
                tracker.listTasks();
            } else if (argc == 3) {
                tracker.listTasksByStatus(argv[2]);
            }
            
        } else if (command == "update") {
            if (argc < 4) {
                std::cerr << "Error: Missing task ID or description" << std::endl;
                return 1;
            }
            int id = std::stoi(argv[2]);
            tracker.updateTask(id, argv[3]);
            std::cout << "Task updated successfully" << std::endl;
            
        } else if (command == "delete") {
            if (argc < 3) {
                std::cerr << "Error: Missing task ID" << std::endl;
                return 1;
            }
            int id = std::stoi(argv[2]);
            tracker.deleteTask(id);
            std::cout << "Task deleted successfully" << std::endl;
            
        } else if (command == "mark-done") {
            if (argc < 3) {
                std::cerr << "Error: Missing task ID" << std::endl;
                return 1;
            }
            int id = std::stoi(argv[2]);
            tracker.updateStatus(id, "done");
            std::cout << "Task marked as done" << std::endl;
            
        } else if (command == "mark-in-progress") {
            if (argc < 3) {
                std::cerr << "Error: Missing task ID" << std::endl;
                return 1;
            }
            int id = std::stoi(argv[2]);
            tracker.updateStatus(id, "in-progress");
            std::cout << "Task marked as in-progress" << std::endl;
            
        } else if (command == "mark-todo") {
            if (argc < 3) {
                std::cerr << "Error: Missing task ID" << std::endl;
                return 1;
            }
            int id = std::stoi(argv[2]);
            tracker.updateStatus(id, "todo");
            std::cout << "Task marked as todo" << std::endl;
            
        } else {
            std::cerr << "Error: Unknown command '" << command << "'" << std::endl;
            showUsage(argv[0]);
            return 1;
        }
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
