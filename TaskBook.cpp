#include "TaskBook.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

int TaskBook::Task::taskCount = 0;
    TaskBook::TaskBook() : tasks(nullptr), capacity(0), size(0) {}


// Destructor
TaskBook::~TaskBook() {
    delete[] tasks;
    std::cout << "\n\nTaskBook destructor called." << std::endl;
}


TaskBook &TaskBook::operator = (const TaskBook &other)                                          // Assignment operator to copy the contents of one TaskBook to another, ensuring proper memory management and deep copying of tasks
{
    this -> size = other.size;
    this -> capacity = other.capacity;
    if(this -> tasks != nullptr) delete[] this -> tasks;
    this -> tasks = new Task[this ->capacity];
    for(int i = 0; i < this -> size; i++)
    {
        this -> tasks[i] = other.tasks[i];
    }
        return *this;
}



void TaskBook::Resize() {  
    int newCapacity = (capacity == 0) ? 10 : capacity * 2;
    Task* newTasks = new Task[newCapacity];
    for (int i = 0; i < size; ++i)
        newTasks[i] = tasks[i];
    delete[] tasks;
    tasks = newTasks;
    capacity = newCapacity;
}


    void TaskBook::AddTask(const std::string& name_, const std::string& description_, int priority_) {                                 // Add a new task to the task book + Ready
        std::cout <<"\n" <<"===============================\n" << std::endl;
        if (size >= capacity) TaskBook::Resize(); 
        TaskBook::Task::taskCount++;
        tasks[size++] = Task(name_, description_, TaskBook::Task::taskCount, priority_);
        std::cout << "Adding task: " << name_ << std::endl;
        std::cout << "===============================" << std::endl;
        std::cout << "Description: " << description_ << std::endl;
        std::cout << "Number: " << TaskBook::Task::taskCount << std::endl;
        std::cout << "Priority: " << priority_ << std::endl;
        std::cout << "Completed: false" << std::endl;
        std::cout << "Task added successfully!" << std::endl;
        std::cout <<"\n" <<"===============================\n" << std::endl;
    }

    void TaskBook::RemoveTask()                                                                                                       // Remove a task from the task book based on user input (by name or number)
    {
        std::cout <<"\n" <<"===============================\n" << std::endl; 
        if (size == 0) {
            std::cout << "No tasks to remove." << std::endl;
            return;
        }
        else if (size == 1) {
            std::cout << "Removing the only task: " << tasks[0].name << std::endl;
            size = 0;
            return;
        }
        else if(size > 1) {
            std::string keyw;
            std::cout << "Enter task name or number to remove: ";
            std::cin >> keyw;
            for (int i = 0; i < size; ++i) {
                if (tasks[i].name == keyw || std::to_string(tasks[i].num) == keyw) {
                    std::cout << "Removing task: " << tasks[i].name << std::endl;
                    for (int j = i; j < size - 1; ++j)
                        tasks[j] = tasks[j + 1];
                    size--;
                    std::cout << "Task removed successfully!" << std::endl;
                    return;
                }
            }
            std::cout << "Task not found." << std::endl;
        }
    }                                                                                                                       
    


    void TaskBook::DisplayTasks() {                                                                                                   // Display all tasks in the task book + Ready
        std::cout <<"\n" <<"===============================\n" << std::endl;                                                // Display all tasks in the task book                                   
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

void TaskBook::CopyTask() 
{                     
    int num, num_c;         
    std::cout <<"\n" <<"===============================\n" << std::endl; 
    std::cout << "Copying a task..." << std::endl;
    std::cout << "===============================" << std::endl;
    std::cout << "Enter task number to be copied: ";
     std::cin >> num;
    std::cout << "Enter task number to write copy in: ";
    std::cin >> num_c;
    for (int i = 0; i < size; ++i) {
        if (tasks[i].num == num) {
            if (size >= capacity) TaskBook::Resize();
            tasks[num_c] = tasks[num];
            std::cout << "Task " << num << " copied successfully!" << std::endl;
            return;
        }
        else if (tasks[i].num == num_c) {
            std::cout << "Task number " << num_c << " already exists. Please choose a different number." << std::endl;
            return;
        }
    }
    std::cout << "Task not found." << std::endl;                     
}



//=============================================Sorters======================================================================================

    void TaskBook::SortTasksNum() {                                                                                                      // Sort tasks by priority (highest first) and then by number (lowest first) + Ready
        std::cout <<"\n" <<"===============================\n" << std::endl;
        std::cout << "Sorting tasks by number..." << std::endl;
        std::cout << "===============================" << std::endl;
        if (size == 0) {
            std::cout << "No tasks to sort." << std::endl;
            return;
        }
        for (int i = 0; i < size; i++) {
            std::cout << "Task " << tasks[i].num << ": " << tasks[i].name << std::endl;
        }
        std::cout <<"\n" <<"===============================\n" << std::endl;
    }


void TaskBook ::SortTasksStatus() {                                                                                                      // Sort tasks by priority (highest first) and then by number (lowest first) + Ready
        std::cout <<"\n" <<"===============================\n" << std::endl;
        std::cout << "Sorting tasks by status..." << std::endl;
        std::cout << "===============================" << std::endl;
        if (size == 0) {
            std::cout << "No tasks to sort." << std::endl;
            return;
        }
        for (int i = 0; i < size; i++) {
            std::cout << "Task " << tasks[i].completed << ": " << tasks[i].name << std::endl;
        }
        std::cout <<"\n" <<"===============================\n" << std::endl;
    }



    void TaskBook::SortTasksPriority() {                                                                                                      // Sort tasks by priority (highest first) and then by number (lowest first) + Ready
        std::cout <<"\n" <<"===============================\n" << std::endl;
        std::cout << "Sorting tasks by priority..." << std::endl;
        std::cout << "===============================" << std::endl;
        if (size == 0) {
            std::cout << "No tasks to sort." << std::endl;
            return;
        }
        for (int i = 0; i < size; i++) {
            std::cout << "Task " << tasks[i].priority << ": " << tasks[i].name << std::endl;
        }
        std::cout <<"\n" <<"===============================\n" << std::endl;
    }

//==========================================================================================================================================




    void TaskBook::FilterTasks()                                                                                                      // Filter tasks based on user input (name, description, priority, completion status, or number)
    {
        std::cout <<"\n" <<"===============================\n" << std::endl;
        std::string keyword;
        std::cin >> keyword;
        std::cout << "Filtering tasks..." << std::endl;
        std::cout << "===============================" << std::endl;
        std::cout << "Choice how to filter tasks:" << std::endl;
        std::cout << "1. Filter by number\n2. Filter by completion status\n3. Filter by priority\n";
        std::cout << "Enter keyword to filter tasks: ";
        std::cin >> keyword;
        switch(keyword[0]) {
           
            case '1':
                TaskBook::SortTasksNum();
                break;
            case '2':
                TaskBook::SortTasksStatus();
                break;
            case '3':
                TaskBook::SortTasksPriority();
                break;
            default:
                std::cout << "Invalid filter choice." << std::endl;
                break;
        }
    }


    void TaskBook::OverrideTask() 
    {                                                                                                  // Override the last task in the task book with new details provided by the user   + Ready                                            
        if (size == 0) {
            std::cout << "No tasks to override." << std::endl;
            return;
        }
        else 
        {
        std::string othername, odescription;
        int priority;
        std::cout << "Enter new task name, description, and priority: ";
        std::cin >> othername >> odescription >> priority;
        std::cout <<"\n" <<"===============================\n" << std::endl;
        std::cout << "Overriding the last task: " << othername << std::endl;
        tasks[size - 1].num = tasks[size - 1].num; 
        tasks[size - 1].name = othername;
        tasks[size - 1].description = odescription;
        tasks[size - 1].priority = priority;
        tasks[size - 1].completed = false;
        }
    }

           
    void TaskBook::ChoiceTask()                                                                                                      // Allow the user to choose a task by name or number and display its details + Ready
    {
        std::cout <<"\n" <<"===============================\n" << std::endl;
        std::string keyw;
        std::cout << "Enter task name or number to view details: ";
        std::cin >> keyw;
        for (int i = 0; i < size; ++i) {
            if (tasks[i].name == keyw || std::to_string(tasks[i].num) == keyw) {
                std::cout << "Task " << tasks[i].num << ": " << tasks[i].name << std::endl;
                std::cout << "Description: " << tasks[i].description << std::endl;
                std::cout << "Priority: " << tasks[i].priority << std::endl;
                std::cout << "Completed: " << (tasks[i].completed ? "Yes" : "No") << std::endl;
                return;
            }
            else if (tasks[i].name == keyw || std::to_string(tasks[i].num) == keyw) {
                std::cout << "Task not found." << std::endl;
                continue;
            }
        }

        std::cout << "Task not found." << std::endl;
    }



void TaskBook::MarkTaskCompleted() {
    int num;
    std::cout << "Enter task number to mark completed: ";
    std::cin >> num;
    for (int i = 0; i < size; ++i) {
        if (tasks[i].num == num) {
            tasks[i].completed = true;
            std::cout << "Task " << num << " completed!\n";
            return;
        }
    }
    std::cout << "Task not found.\n";
}



//==========================================Other functions====================================================================================
void HelpFunction() {    
    std::cout <<"\n" <<"===============================\n" << std::endl;                                                                                             // Display the main menu of the TaskBook application                                                                                                                          // A help function to provide information about the TaskBook application
    std::cout << "This is a help function." << std::endl;
    std::cout << "You can use this application to manage your tasks." << std::endl;
    std::cout << "You can add, remove, display, mark as completed, copy, sort, filter, override, and choose tasks." << std::endl;
    std::cout <<"\n" <<"===============================\n" << std::endl;
}

void DisplayMenu() {   
    std::cout <<"\n" <<"===============================\n" << std::endl;                                                                                             // Display the main menu of the TaskBook application                                              
    std::cout << "TaskBook Menu:" << std::endl;
    std::cout << "1. Add Task" << std::endl;
    std::cout << "2. Remove Task" << std::endl;
    std::cout << "3. Display Tasks" << std::endl;
    std::cout << "4. Mark Task Completed" << std::endl;
    std::cout << "5. Copy Task" << std::endl;
    std::cout << "5. Sort Tasks" << std::endl;
    std::cout << "6. Filter Tasks" << std::endl;
    std::cout << "7. Override Task" << std::endl;
    std::cout << "8. Choice Task" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout <<"\n" <<"===============================\n" << std::endl;
}

//==========================================================================================================================================