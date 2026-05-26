#include <iostream>
#include <string>
#include <algorithm>
#include "TaskBook.h"

TaskBook::Task::Task() : num(0), priority(0), completed(false) {}

TaskBook::Task::Task(const std::string& name_, const std::string& description_, int num_, int priority_)
    : name(name_), description(description_), num(num_), priority(priority_), completed(false) {}

void TaskBook::resize() {
    int newCap = (capacity == 0) ? 4 : capacity * 2;
    Task* newTasks = new Task[newCap];
    for (int i = 0; i < size; i++)
        newTasks[i] = tasks[i];
    delete[] tasks;
    tasks = newTasks;
    capacity = newCap;
}

TaskBook::TaskBook() : tasks(nullptr), capacity(0), size(0) {}

TaskBook::~TaskBook() {
    delete[] tasks;
    std::cout << "TaskBook destructor called." << std::endl;
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
    std::string input;
    std::cout << "Enter task name or number to remove: ";
    std::cin >> input;

    int removeIndex = -1;
    if (input[0] >= '0' && input[0] <= '9') {
        int num = std::stoi(input);
        for (int i = 0; i < size; i++) {
            if (tasks[i].num == num) {
                removeIndex = i;
                break;
            }
        }
    } else {
        for (int i = 0; i < size; i++) {
            if (tasks[i].name == input) {
                removeIndex = i;
                break;
            }
        }
    }

    if (removeIndex == -1) {
        std::cout << "Task not found." << std::endl;
        return;
    }

    for (int i = removeIndex; i < size - 1; i++)
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

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (tasks[j].priority < tasks[j + 1].priority ||
                (tasks[j].priority == tasks[j + 1].priority && tasks[j].num > tasks[j + 1].num)) {
                Task temp = tasks[j];
                tasks[j] = tasks[j + 1];
                tasks[j + 1] = temp;
            }
        }
    }

    std::cout << "Tasks sorted by priority (highest first)." << std::endl;
    DisplayTasks();
}

void TaskBook::FilterTasks() {
    std::cout <<"\n" <<"===============================\n" << std::endl;
    std::cout << "Filtering tasks..." << std::endl;
    std::cout << "===============================" << std::endl;
    std::cout << "Choice how to filter tasks:" << std::endl;
    std::cout << "1. Filter by name\n2. Filter by description\n3. Filter by priority\n4. Filter by completion status\n5. Filter by number\n";
    std::cout << "Enter your choice: ";
    int filterChoice;
    std::cin >> filterChoice;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid input." << std::endl;
        std::cout <<"\n" <<"===============================\n" << std::endl;
        return;
    }
    switch(filterChoice) {
        case 1:
            std::cout << "Filtering by name..." << std::endl;
            break;
        case 2:
            std::cout << "Filtering by description..." << std::endl;
            break;
        case 3:
            std::cout << "Filtering by priority..." << std::endl;
            break;
        case 4:
            std::cout << "Filtering by completion status..." << std::endl;
            break;
        case 5:
            std::cout << "Filtering by number..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
    }
    std::cout <<"\n" <<"===============================\n" << std::endl;
}

void TaskBook::MarkTaskCompleted() {
    if (size == 0) {
        std::cout << "No tasks to mark." << std::endl;
        return;
    }
    std::string input;
    std::cout << "Enter task name or number to mark as completed: ";
    std::cin >> input;

    if (input[0] >= '0' && input[0] <= '9') {
        int num = std::stoi(input);
        for (int i = 0; i < size; i++) {
            if (tasks[i].num == num) {
                tasks[i].completed = true;
                std::cout << "Task " << num << " marked as completed." << std::endl;
                return;
            }
        }
    } else {
        for (int i = 0; i < size; i++) {
            if (tasks[i].name == input) {
                tasks[i].completed = true;
                std::cout << "Task \"" << input << "\" marked as completed." << std::endl;
                return;
            }
        }
    }
    std::cout << "Task not found." << std::endl;
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
    std::cout <<"\n" <<"===============================\n" << std::endl;
    std::cout << "Overriding the last task: " << othername << std::endl;
    tasks[size - 1].name = othername;
    tasks[size - 1].description = description;
    tasks[size - 1].priority = priority;
    tasks[size - 1].completed = false;
}

int TaskBook::taskCount = 0;

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
