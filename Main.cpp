#include "TaskBook.h"
#include <iostream>
#include <limits>

int main()
{
    int choice;  
    TaskBook taskBook;

    while(true)
    {
        DisplayMenu();

        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input! Please enter a number." << std::endl;
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch(choice) {
        case 1: {
            std::string name, description;
            int priority=0;
            std::cout << "Enter task name: ";
            std::getline(std::cin, name);
            std::cout << "Enter task description: ";
            std::getline(std::cin, description);
            std::cout << "Enter task priority: ";
            std::cin >> priority;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Invalid priority." << std::endl;
                break;
            }
            taskBook.AddTask(name, description, priority);                  //Ready
            break;
        }
        case 2:
            taskBook.RemoveTask();                                          //Ready
            break;
        case 3:
            taskBook.DisplayTasks();                                         //Ready         
            break;
        case 4:
            taskBook.MarkTaskCompleted();                                   //Ready
            break;      
        case 5:
            taskBook.CopyTask();                                            //Ready
            break;
        case 6:
            taskBook.SortTasks();                                           //Ready
            break;
        case 7:
            taskBook.FilterTasks();                                         //Not Ready
            break;
        case 8: 
            taskBook.OverrideTask();                                        //Ready
            break;
        case 9:
            taskBook.ChoiceTask();                                          //Ready         
            break;
        case 0:
            std::cout << "Exiting..." << std::endl;
            return 0;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
