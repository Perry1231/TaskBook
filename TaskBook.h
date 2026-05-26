#ifndef TASKBOOK_H
#define TASKBOOK_H
#pragma once 
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
 
        Task() : num(0), priority(0), completed(false) {}                                                                   // Default constructor

        Task(const std::string& name_, const std::string& description_, int num_, int priority_)                            // Parameterized constructor    
            : name(name_), description(description_), num(num_), priority(priority_), completed(false) {}
    };


void DisplayTasks();
void SortTasks();
void FilterTasks();
void OverrideTask();
void ChoiceTask();
void RemoveTask();
void AddTask(const std::string& name_, const std::string& description_, int priority_);
void DisplayMenu();
void MarkTaskCompleted();
 

void HelpFunction();
void DisplayMenu();

#endif