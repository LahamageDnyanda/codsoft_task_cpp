#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;
};

class TodoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& description) {
        Task newTask = {description, false};
        tasks.push_back(newTask);
        std::cout << "Task added: " << description << std::endl;
    }

    void viewTasks() const {
        if (tasks.empty()) {
            std::cout << "No tasks in the list." << std::endl;
            return;
        }

        std::cout << "Todo List:" << std::endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i].description
                      << (tasks[i].completed ? " [Completed]" : " [Pending]") << std::endl;
        }
    }

    void markTaskCompleted(int index) {
        if (index < 1 || index > tasks.size()) {
            std::cout << "Invalid task number." << std::endl;
            return;
        }

        tasks[index - 1].completed = true;
        std::cout << "Task " << index << " marked as completed." << std::endl;
    }

    void removeTask(int index) {
        if (index < 1 || index > tasks.size()) {
            std::cout << "Invalid task number." << std::endl;
            return;
        }

        tasks.erase(tasks.begin() + index - 1);
        std::cout << "Task " << index << " removed." << std::endl;
    }
};

int main() {
    TodoList todoList;
    int choice;
    std::string taskDescription;
    int taskNumber;

    do {
        std::cout << "\nTo do List Manager Menu:" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. View Tasks" << std::endl;
        std::cout << "3. Mark Task as Completed" << std::endl;
        std::cout << "4. Remove Task" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter task description: ";
                std::cin.ignore();
                std::getline(std::cin, taskDescription);
                todoList.addTask(taskDescription);
                break;
            case 2:
                todoList.viewTasks();
                break;
            case 3:
                std::cout << "Enter task number to mark as completed: ";
                std::cin >> taskNumber;
                todoList.markTaskCompleted(taskNumber);
                break;
            case 4:
                std::cout << "Enter task number to remove: ";
                std::cin >> taskNumber;
                todoList.removeTask(taskNumber);
                break;
            case 5:
                std::cout << "Exiting program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 5);

    return 0;
}
