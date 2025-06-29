#ifndef GOBACK_H
#define GOBACK_H

// Local header files
#include "exxit.h"

void menu2(); 

void goback()
{
    cout << endl << "Go back to main menu ? (Y/N) : ";
    string choice;
    cin >> choice;
    if(choice=="Y" || choice=="y")
        menu2();
    else
        exxit();
}


#endif 
