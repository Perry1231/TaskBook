#include "TaskBook.h"
#include <iostream>

int main()
{
    TaskBook taskBook;

    while(true)
    {
        int choice;

        DisplayMenu();

        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input! Please enter a number." << std::endl;
            continue;
        }

        switch(choice) {
        case 1:
            taskBook.AddTask("New Task", "Description for new task", 1);
            break;
        case 2:
            std::cout << "Remove task not implemented yet." << std::endl;
            break;
        case 3:
            taskBook.DisplayTasks();
            break;
        case 4:
            std::cout << "Mark task completed not implemented yet." << std::endl;
            break;
        case 5:
            taskBook.SortTasks();
            break;
        case 6:
            taskBook.FilterTasks();
            break;
        case 7:
            taskBook.OverrideTask();
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

