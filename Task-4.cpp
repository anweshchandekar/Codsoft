#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

vector<Task> taskList;

void displayTasks() {
    if (taskList.empty()) {
        cout << "No tasks in the list." << endl;
        return;
    }
    cout << "Tasks:" << endl;
    for (size_t i = 0; i < taskList.size(); ++i) {
        cout << i + 1 << ". " << taskList[i].description << " [" 
             << (taskList[i].completed ? "Completed" : "Pending") << "]" << endl;
    }
}

void addTask() {
    string taskDescription;
    cout << "Enter the task description: ";
    cin.ignore(); // To ignore the newline character left by previous input
    getline(cin, taskDescription);
    taskList.push_back({taskDescription, false});
    cout << "Task added successfully!" << endl;
}

void markTaskCompleted() {
    int taskIndex;
    displayTasks();
    cout << "Enter the number of the task to mark as completed: ";
    cin >> taskIndex;
    if (taskIndex < 1 || taskIndex > taskList.size()) {
        cout << "Invalid task number." << endl;
        return;
    }
    taskList[taskIndex - 1].completed = true;
    cout << "Task marked as completed!" << endl;
}

void removeTask() {
    int taskIndex;
    displayTasks();
    cout << "Enter the number of the task to remove: ";
    cin >> taskIndex;
    if (taskIndex < 1 || taskIndex > taskList.size()) {
        cout << "Invalid task number." << endl;
        return;
    }
    taskList.erase(taskList.begin() + taskIndex - 1);
    cout << "Task removed successfully!" << endl;
}

int main() {
    int choice;
    do {
        cout << "\nTo-Do List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                displayTasks();
                break;
            case 3:
                markTaskCompleted();
                break;
            case 4:
                removeTask();
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}