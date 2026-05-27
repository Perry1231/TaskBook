#include "TaskBook.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

<<<<<<< ours

TaskBook::TaskBook()
{
    class Task 
    {
    public:
        std::string name;
        std::string description;
        int num;
        int priority;
        bool completed;
 
        Task() : num(0), priority(0), completed(false) {}                                                                   // Default constructor
=======
int TaskBook::taskCount = 0;
>>>>>>> theirs

TaskBook::TaskBook() : tasks(nullptr), capacity(0), size(0) {}

<<<<<<< ours
    private:
    Task* tasks;
    int capacity;
    int size;

    void resize() 
    {                                                                                                         // Resize the tasks array when capacity is reached
        int newCap = (capacity == 0) ? 4 : capacity * 2;                                                                    // Double the capacity when resizing
        Task* newTasks = new Task[newCap];
        for (int i = 0; i < size; i++)
            newTasks[i] = tasks[i];
        delete[] tasks;
        tasks = newTasks;
        capacity = newCap;
    }
=======
TaskBook::~TaskBook() {
    delete[] tasks;
    std::cout << "TaskBook destructor called." << std::endl;
}
>>>>>>> theirs

void TaskBook::resize() {
    int newCap = (capacity == 0) ? 4 : capacity * 2;
    Task* newTasks = new Task[newCap];
    for (int i = 0; i < size; i++)
        newTasks[i] = tasks[i];
    delete[] tasks;
    tasks = newTasks;
    capacity = newCap;
}

void TaskBook::AddTask(const std::string& name_, const std::string& description_, int priority_) {
    std::cout <<"\n" <<"===============================\n" << std::endl;
    if (size >= capacity) resize();
    taskCount++;
    tasks[size++] = Task(name_, description_, taskCount, priority_);
    std::cout << "Adding task: " << name_ << std::endl;
    std::cout << "===============================" << std::endl;
    std::cout << "Description: " << description_ << std::endl;
    std::cout << "Number: " << taskCount << std::endl;
    std::cout << "Priority: " << priority_ << std::endl;
    std::cout << "Completed: false" << std::endl;
    std::cout << "Task added successfully!" << std::endl;
    std::cout <<"\n" <<"===============================\n" << std::endl;
}

void TaskBook::RemoveTask() {
    if (size == 0) {
        std::cout << "No tasks to remove." << std::endl;
        return;
    }
    int num;
    std::cout << "Enter task number to remove: ";
    std::cin >> num;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid input." << std::endl;
        return;
    }
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (tasks[i].num == num) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        std::cout << "Task not found." << std::endl;
        return;
    }
    for (int i = index; i < size - 1; i++)
        tasks[i] = tasks[i + 1];
    size--;
    std::cout << "Task removed successfully." << std::endl;
}

void TaskBook::DisplayTasks() {
    std::cout <<"\n" <<"===============================\n" << std::endl;
    if (size == 0) {
        std::cout << "No tasks to display." << std::endl;
        return;
    }
    for (int i = 0; i < size; i++) {
        std::cout << "Task " << tasks[i].num << ": " << tasks[i].name
                  << " | Priority: " << tasks[i].priority
                  << " | Completed: " << (tasks[i].completed ? "Yes" : "No") << std::endl;
    }
    std::cout <<"\n" <<"===============================\n" << std::endl;
}

void TaskBook::SortTasks() {
    std::cout <<"\n" <<"===============================\n" << std::endl;
    std::cout << "Sorting tasks..." << std::endl;
    std::cout << "===============================" << std::endl;
    if (size == 0) {
        std::cout << "No tasks to sort." << std::endl;
        return;
    }
    std::sort(tasks, tasks + size, [](const Task& a, const Task& b) {
        if (a.priority != b.priority)
            return a.priority > b.priority;
        return a.num < b.num;
    });
    for (int i = 0; i < size; i++) {
        std::cout << "Task " << tasks[i].num << ": " << tasks[i].name << std::endl;
    }
    std::cout <<"\n" <<"===============================\n" << std::endl;
}

void TaskBook::FilterTasks() {
    std::cout <<"\n" <<"===============================\n" << std::endl;
    std::cout << "Filtering tasks..." << std::endl;
    std::cout << "===============================" << std::endl;
    std::cout << "Choice how to filter tasks:" << std::endl;
    std::cout << "1. Filter by name\n2. Filter by description\n3. Filter by priority\n4. Filter by completion status\n5. Filter by number\n";
    std::cout << "Enter keyword to filter tasks: ";
    std::string keyword;
    std::cin >> keyword;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return;
    }
    std::cout << "\nResults:\n";
    bool found = false;
    for (int i = 0; i < size; i++) {
        bool match = false;
        switch (keyword[0]) {
            case '1':
                match = (tasks[i].name.find(keyword.substr(1)) != std::string::npos);
                break;
            case '2':
                match = (tasks[i].description.find(keyword.substr(1)) != std::string::npos);
                break;
            case '3': {
                int p = std::atoi(keyword.c_str() + 1);
                match = (tasks[i].priority == p);
                break;
            }
            case '4':
                match = (tasks[i].completed == (keyword.size() > 1 && keyword[1] == '1'));
                break;
            case '5': {
                int n = std::atoi(keyword.c_str() + 1);
                match = (tasks[i].num == n);
                break;
            }
            default:
                std::cout << "Invalid filter choice." << std::endl;
                return;
        }
        if (match) {
            found = true;
            std::cout << "Task " << tasks[i].num << ": " << tasks[i].name
                      << " | Priority: " << tasks[i].priority
                      << " | Completed: " << (tasks[i].completed ? "Yes" : "No") << std::endl;
        }
    }
    if (!found) std::cout << "No matching tasks found." << std::endl;
    std::cout <<"\n" <<"===============================\n" << std::endl;
}

void TaskBook::OverrideTask() {
    if (size == 0) {
        std::cout << "No tasks to override." << std::endl;
        return;
    }
    std::string othername, description;
    int priority;
    std::cout << "Enter new task name, description, and priority: ";
    std::cin >> othername >> description >> priority;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid input." << std::endl;
        return;
    }
    std::cout <<"\n" <<"===============================\n" << std::endl;
    std::cout << "Overriding the last task: " << othername << std::endl;
    tasks[size - 1].name = othername;
    tasks[size - 1].description = description;
    tasks[size - 1].priority = priority;
    tasks[size - 1].completed = false;
}

void TaskBook::ChoiceTask() {
    if (size == 0) {
        std::cout << "No tasks available." << std::endl;
        return;
    }
    int choice;
    std::cout << "Choose task by number (1 to " << size << "): ";
    std::cin >> choice;
    if (std::cin.fail() || choice < 1 || choice > size) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid choice." << std::endl;
        return;
    }
    Task& t = tasks[choice - 1];
    std::cout << "\nSelected task:\n";
    std::cout << "Name: " << t.name << "\nDescription: " << t.description
              << "\nNumber: " << t.num << "\nPriority: " << t.priority
              << "\nCompleted: " << (t.completed ? "Yes" : "No") << std::endl;
}

void TaskBook::MarkTaskCompleted() {
    if (size == 0) {
        std::cout << "No tasks to mark as completed." << std::endl;
        return;
    }
    int num;
    std::cout << "Enter task number to mark as completed: ";
    std::cin >> num;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid input." << std::endl;
        return;
    }
    for (int i = 0; i < size; i++) {
        if (tasks[i].num == num) {
            tasks[i].completed = true;
            std::cout << "Task \"" << tasks[i].name << "\" marked as completed." << std::endl;
            return;
        }
<<<<<<< ours
        std::string othername, description;
        int priority;
        std::cout << "Enter new task name, description, and priority: ";
        std::cin >> othername >> description >> priority;
        std::cout <<"\n" <<"===============================\n" << std::endl;
        std::cout << "Overriding the last task: " << othername << std::endl;
        tasks[size - 1].name = othername;
        tasks[size - 1].description = description;
        tasks[size - 1].priority = priority;
        tasks[size - 1].completed = false;
    }
};

int TaskBook::taskCount = 0;                                                                                                // Initialize static member variable
=======
    }
    std::cout << "Task not found." << std::endl;
}
>>>>>>> theirs

void HelpFunction() {
    std::cout << "This is a help function." << std::endl;
}

void DisplayMenu() {
    std::cout <<"\n" <<"===============================\n" << std::endl;
    std::cout << "TaskBook Menu:" << std::endl;
    std::cout << "1. Add Task" << std::endl;
    std::cout << "2. Remove Task" << std::endl;
    std::cout << "3. Display Tasks" << std::endl;
    std::cout << "4. Mark Task Completed" << std::endl;
    std::cout << "5. Sort Tasks" << std::endl;
    std::cout << "6. Filter Tasks" << std::endl;
    std::cout << "7. Override Task" << std::endl;
    std::cout << "8. Choice Task" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout <<"\n" <<"===============================\n" << std::endl;
}
