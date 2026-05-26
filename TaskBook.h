#ifndef TASKBOOK_H
#define TASKBOOK_H

#include <string>

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

        Task();
        Task(const std::string& name_, const std::string& description_, int num_, int priority_);
    };

    static int taskCount;

    TaskBook();
    ~TaskBook();

    void AddTask(const std::string& name_, const std::string& description_, int priority_);
    void RemoveTask();
    void DisplayTasks();
    void SortTasks();
    void FilterTasks();
    void OverrideTask();
    void MarkTaskCompleted();

private:
    Task* tasks;
    int capacity;
    int size;

    void resize();
};

void HelpFunction();
void DisplayMenu();

#endif