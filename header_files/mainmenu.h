
#ifndef MAINMENU_H
#define MAINMENU_H

// Local header files
#include "registration.h"

int mainmenu()
{
    // Main Menu Options
    cout << endl << "\e[1mMAIN MENU\e[0m" << endl << "\e[3m(Type the number of your choice)\e[0m" << endl << string(33, '=') << endl;
    cout << "[1] Register" << endl;
    cout << "[2] Log In" << endl;
    cout << "[3] Exit the Program" << endl << endl;

    // Choose one from the available numbers (1,2,3)
    int choice;
    cout << "Choice: ";
    cin >> choice; // User enters the desired number
    cin.ignore();

    switch (choice)
    {
        case 1:
            registration();
            break;
        case 2:
            login();
            break;
        case 3:
            exxit();
            break;
        default:
            cout << "Wrong choice! Try again..." << endl << endl;
            mainmenu();
    }
    return 0;
}


#endif // MAINMENU_H
