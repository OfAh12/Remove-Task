# "Remove Task" feature, allowing users to delete tasks by entering the task number.
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ToDoList {
private:
    vector<string> tasks;
public:
    void addTask(const string &task) {
        tasks.push_back(task);
        cout << "Task added!" << endl;
    }
    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks available." << endl;
            return;
        }
        cout << "Your tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i] << endl;
        }
    }
    void removeTask(int index) {
        if (index < 1 || index > tasks.size()) {
            cout << "Invalid task number." << endl;
            return;
        }
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task removed!" << endl;
    }
};

int main() {
    ToDoList list;
    int choice;
    string task;
    int taskNumber;
    
    while (true) {
        cout << "\n1. Add Task\n2. View Tasks\n3. Remove Task\n4. Exit\nChoose: ";
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case 1:
                cout << "Enter task: ";
                getline(cin, task);
                list.addTask(task);
                break;
            case 2:
                list.viewTasks();
                break;
            case 3:
                cout << "Enter task number to remove: ";
                cin >> taskNumber;
                list.removeTask(taskNumber);
                break;
            case 4:
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice, try again." << endl;
        }
    }
}