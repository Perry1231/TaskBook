#ifndef TASKBOOK_H
#define TASKBOOK_H
#include <string>
#include <iostream>


class TaskBook 
{
    public: 
    class Task 
    {
    public:
        std::string name;
        std::string description;
        int num;
        int priority;
        bool completed;
 
        Task() : num(0), priority(0), completed(false) , description(""), name(""){}                                          // Default constructor

        Task(const std::string& name_, const std::string& description_, int num_, int priority_)                            // Parameterized constructor    
            : name(name_), description(description_), num(num_), priority(priority_), completed(false) {}

             static int taskCount;

    };
    public:
    
    TaskBook();
    ~TaskBook();
        
void Resize();
void DisplayTasks();
void SortTasks();
void FilterTasks();
void OverrideTask();
void ChoiceTask();
void RemoveTask();
void AddTask(const std::string& name_, const std::string& description_, int priority_);
void MarkTaskCompleted();
void CopyTask(int size, int capacity);
TaskBook &operator = (const TaskBook &other);

 private:
    Task* tasks;
    int capacity;                   //This variable keeps track of the current capacity of the tasks array, allowing for dynamic resizing when adding new tasks.
    int size;                       //This variable keeps track of the current number of tasks in the task book, allowing for proper management of the tasks array and ensuring that operations like adding, removing, and displaying tasks are performed correctly based on the actual number of tasks present.
};


void HelpFunction();
void DisplayMenu();


#endif