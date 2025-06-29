
#ifndef LOGIN_H
#define LOGIN_H

// Local header files
#include "menu2.h"

int mainmenu();

// Declaration of variables, defined in main.cpp
extern string password;
extern string logpass;

void login()
{
    ifstream data("database"); // Open database file with usernames and passwords

    // Check if user is already registered
    if (!data.is_open())
    {
        cout << endl;
        cout << "You have to register first!" << endl;
        mainmenu();
    }
     
    cout << endl << "Write your username : ";
    getline(cin, logname);  // User enters username to login

    cout << "Write your password : ";
    getline(cin, logpass); // User enters password to login

    int j;
    while(!data.eof()){
        getline(data, name, '\n');     // Reading the usernames from the database
        getline(data, password, '\n'); // Reading the passwords from the database

        // Check if username and password are correct
        if ( logname == name && logpass == password )
        {
            cout << endl;
            cout << "Successfully logged in!" << endl;
            cout << "\e[3mWelcome, \e[0m" << logname << "\e[3m !\e[0m" << endl;
            menu2();
            break;
        }
        else if (logname != name && logpass == password) {j=1;}
        else if (logname == name && logpass != password) {j=2;}
    }
    // Check for wrong username or password
    if(j==1)
    {
        cout << endl << "Wrong username!" << endl << "Try again..." << endl;
        login();
    }   
    else if (j==2)
    {
        cout << endl << "Wrong password!" << endl << "Try again..." << endl;
        login();
    }   
    data.close(); // Close database file
}


#endif // LOGIN_H
