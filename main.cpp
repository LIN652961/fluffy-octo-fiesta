#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// Simple task manager - demonstrates basic C++ features

struct Task {
    int id;
    std::string name;
    bool completed;
};

class TaskManager {
private:
    std::vector<Task> tasks;
    int nextId = 1;

public:
    void addTask(const std::string& name) {
        tasks.push_back({nextId++, name, false});
        std::cout << "Task added: " << name << "\n";
    }

    void completeTask(int id) {
        auto it = std::find_if(tasks.begin(), tasks.end(),
            [id](const Task& t) { return t.id == id; });
        if (it != tasks.end()) {
            it->completed = true;
            std::cout << "Task completed: " << it->name << "\n";
        } else {
            std::cout << "Task not found (id=" << id << ")\n";
        }
    }

    void listTasks() const {
        std::cout << "\n--- Task List ---\n";
        for (const auto& t : tasks) {
            std::cout << "[" << t.id << "] " << t.name
                      << " - " << (t.completed ? "Done" : "Pending") << "\n";
        }
        if (tasks.empty()) {
            std::cout << "(no tasks)\n";
        }
        std::cout << "-----------------\n\n";
    }

    void removeCompleted() {
        auto it = std::remove_if(tasks.begin(), tasks.end(),
            [](const Task& t) { return t.completed; });
        int count = tasks.end() - it;
        tasks.erase(it, tasks.end());
        std::cout << "Removed " << count << " completed task(s)\n";
    }
};

int main() {
    TaskManager manager;

    manager.addTask("Learn C++ basics");
    manager.addTask("Practice STL containers");
    manager.addTask("Write a project");
    manager.listTasks();

    manager.completeTask(1);
    manager.completeTask(2);
    manager.listTasks();

    manager.removeCompleted();
    manager.listTasks();

    return 0;
}
