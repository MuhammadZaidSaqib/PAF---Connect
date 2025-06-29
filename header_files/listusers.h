
#ifndef LISTUSERS_H
#define LISTUSERS_H

// Header files
#include <fstream>
using namespace std;

// Declaration of variables, defined in main.cpp
extern string name;
extern string password;
extern int numofusers;

void listusers()
{
    ifstream data;
    data.open("database"); // Open file of all registered users
    // Process to count all registered users
    while(!data.eof())
    {
        getline(data, name, '\n');     // Reading the usernames from the database
        getline(data, password, '\n'); // Reading the passwords from the database
        numofusers++;
    }
    data.close();
}


#endif // LISTUSERS_H
