#include "TaskBook.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>


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

        Task(const std::string& name_, const std::string& description_, int num_, int priority_)                            // Parameterized constructor    
            : name(name_), description(description_), num(num_), priority(priority_), completed(false) {}
    };

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

    public:
    static int taskCount;

    TaskBook()  tasks(nullptr), capacity(0), size(0) {}

    ~TaskBook() {
        delete[] tasks;
        std::cout << "TaskBook destructor called." << std::endl;
    }

    void AddTask(const std::string& name_, const std::string& description_, int priority_) {                                 // Add a new task to the task book + Ready
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

    void RemoveTask()                                                                                                       // Remove a task from the task book based on user input (by name or number)
    {

    }                                                                                                                       
    


    void DisplayTasks() {                                                                                                   // Display all tasks in the task book + Ready
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



    void SortTasks() {                                                                                                      // Sort tasks by priority (highest first) and then by number (lowest first) + Ready
        std::cout <<"\n" <<"===============================\n" << std::endl;
        std::cout << "Sorting tasks..." << std::endl;
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




    void FilterTasks()                                                                                                      // Filter tasks based on user input (name, description, priority, completion status, or number)
    {
        std::cout <<"\n" <<"===============================\n" << std::endl;
        std::string keyword;
        std::cout << "Filtering tasks..." << std::endl;
        std::cout << "===============================" << std::endl;
        std::cout << "Choice how to filter tasks:" << std::endl;
        std::cout << "1. Filter by name\n2. Filter by description\n3. Filter by priority\n4. Filter by completion status\n5. Filter by number\n";
        std::cout << "Enter keyword to filter tasks: ";
        std::cin >> keyword;
        switch(keyword[0]) {
            case '1':
                std::cout << "Filtering by name..." << std::endl;
                break;
            case '2':
                std::cout << "Filtering by number..." << std::endl;
                break;
            case '3':
                std::cout << "Filtering by priority..." << std::endl;
                break;
            case '4':
                std::cout << "Filtering by completion status..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
        std::cout <<"\n" <<"===============================\n" << std::endl;
    }


    void OverrideTask() {                                                                                                    // Override the last task in the task book with new details provided by the user   + Ready                                            
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
};

int TaskBook::taskCount = 0;                                                                                                // Initialize static member variable

void HelpFunction() {                                                                                                       // A help function to provide information about the TaskBook application
    std::cout << "This is a help function." << std::endl;
}

void DisplayMenu() {   
    std::cout <<"\n" <<"===============================\n" << std::endl;                                                                                             // Display the main menu of the TaskBook application                                              
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