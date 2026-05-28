#ifndef TASKBOOK_H
#define TASKBOOK_H
#include <string>
#include <vector>

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
 
        Task() : num(0), priority(0), completed(false) {}

        Task(const std::string& name_, const std::string& description_, int num_, int priority_)
            : name(name_), description(description_), num(num_), priority(priority_), completed(false) {}

             static int taskCount;
    };
    public:
    
    TaskBook() = default;

void DisplayTasks();
void SortTasks();
void FilterTasks();
void OverrideTask();
void ChoiceTask();
void RemoveTask();
void AddTask(const std::string& name_, const std::string& description_, int priority_);
void MarkTaskCompleted();

 private:
    std::vector<Task> tasks;
};


void HelpFunction();
void DisplayMenu();


#endif
