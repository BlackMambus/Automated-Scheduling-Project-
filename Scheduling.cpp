#include <iostream>
#include <vector>
#include <algorithm>

struct Task {
    std::string name;
    int startTime; // in 24-hour format, e.g., 1300 for 1:00 PM
    int endTime;

    bool overlapsWith(const Task& other) const {
        return !(endTime <= other.startTime || startTime >= other.endTime);
    }
};

class Scheduler {
private:
    std::vector<Task> tasks;

public:
    bool addTask(const Task& newTask) {
        for (const auto& task : tasks) {
            if (task.overlapsWith(newTask)) {
                std::cout << "❌ Conflict with task: " << task.name << "\n";
                return false;
            }
        }
        tasks.push_back(newTask);
        std::cout << "✅ Task added: " << newTask.name << "\n";
        return true;
    }

    void showSchedule() const {
        std::cout << "\n📋 Scheduled Tasks:\n";
        for (const auto& task : tasks) {
            std::cout << "- " << task.name << " [" << task.startTime << " - " << task.endTime << "]\n";
        }
    }
};

int main() {
    Scheduler scheduler;
    int choice;

    while (true) {
        std::cout << "\n1. Add Task\n2. Show Schedule\n3. Exit\nChoose an option: ";
        std::cin >> choice;

        if (choice == 1) {
            Task task;
            std::cout << "Enter task name: ";
            std::cin.ignore();
            std::getline(std::cin, task.name);
            std::cout << "Enter start time (e.g., 1300): ";
            std::cin >> task.startTime;
            std::cout << "Enter end time (e.g., 1400): ";
            std::cin >> task.endTime;

            scheduler.addTask(task);
        } else if (choice == 2) {
            scheduler.showSchedule();
        } else if (choice == 3) {
            break;
        } else {
            std::cout << "Invalid option. Try again.\n";
        }
    }

    return 0;
}
