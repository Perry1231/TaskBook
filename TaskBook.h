#ifndef TASKBOOK_H
#define TASKBOOK_H
#pragma once 
#include <string>

class TaskBook 
{
<<<<<<< ours
<<<<<<< ours
    void HelpFunction();
    void DisplayMenu();
    public:
=======
public:
>>>>>>> theirs
=======
public:
>>>>>>> theirs
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
    };

<<<<<<< ours
<<<<<<< ours
void DisplayTasks();
void SortTasks();
void FilterTasks();
void OverrideTask();
void ChoiceTask();
void RemoveTask();
void AddTask(const std::string& name_, const std::string& description_, int priority_);
void MarkTaskCompleted();
};

int TaskBook::taskCount = 0;
#endif
=======
=======
>>>>>>> theirs
    TaskBook();
    ~TaskBook();

    void AddTask(const std::string& name_, const std::string& description_, int priority_);
    void RemoveTask();
    void DisplayTasks();
    void SortTasks();
    void FilterTasks();
    void OverrideTask();
    void ChoiceTask();
    void MarkTaskCompleted();
    static int taskCount;

private:
    Task* tasks;
    int capacity;
    int size;

    void resize();
};

void DisplayMenu();
void HelpFunction();

#endif
<<<<<<< ours
>>>>>>> theirs
=======
>>>>>>> theirs
