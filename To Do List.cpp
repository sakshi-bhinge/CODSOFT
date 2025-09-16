#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string description;
    bool completed;

    Task(string desc) {
        description = desc;
        completed = false;
    }
};

vector<Task> tasks;

void addTask() {
    cin.ignore();
    string task;
    cout << "Enter a new task: ";
    getline(cin, task);
    tasks.push_back(Task(task));
    cout << "Task added successfully!" << endl;
}

void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks available." <<endl;
        return;
    }
    cout << "Your Tasks:" <<endl;
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].description
             << " [" << (tasks[i].completed ? "? Completed" : "? Pending") << "]" <<endl;
    }
    cout << endl;
}

void markTaskCompleted() {
    viewTasks();
    if (tasks.empty()) return;

    int num;
    cout << "Enter task number to mark as completed: ";
    cin >> num;
    if (num >= 1 && num <= (int)tasks.size()) {
        tasks[num - 1].completed = true;
        cout << "Task marked as completed!" <<endl;
    } else {
        cout << "Invalid task number!" <<endl;
    }
}

void removeTask() {
    viewTasks();
    if (tasks.empty()) return;

    int num;
    cout << "Enter task number to remove: ";
    cin >> num;
    if (num >= 1 && num <= (int)tasks.size()) {
        cout << "Task '" << tasks[num - 1].description << "' removed successfully!" <<endl;
        tasks.erase(tasks.begin() + num - 1);
    } else {
        cout << "Invalid task number!" <<endl;
    }
}

void menu() {
    int choice;
    while (true) {
        cout << "====== To-Do List Manager ======" <<endl;
        cout << "1. Add Task" <<endl;
        cout << "2. View Tasks" <<endl;
        cout << "3. Mark Task as Completed" <<endl;
        cout << "4. Remove Task" <<endl;
        cout << "5. Exit" <<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: markTaskCompleted(); break;
            case 4: removeTask(); break;
            case 5: cout << "Exiting To-Do List Manager. Goodbye!" <<endl;
            
            return;
            default:
            	cout<<"Invalid Choice ! Please ty again." <<endl;
            	
        }
    }
}

int main(){
	menu();
	return 0;
}

