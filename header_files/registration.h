#ifndef REGISTRATION_H
#define REGISTRATION_H

// Local header files
#include "login.h"

// Declaration of variables, defined in main.cpp
extern string password;
extern string regname;
extern string regpass;

int registration()
{
    ifstream data("database"); // Open database file
	
    cout << endl << "Write the desired username : ";
    getline(cin, regname); // User gives desired username

	// Check if given username already exists in database
	while(!data.eof())
	{
		getline(data, name, '\n');     // Reading the usernames from the database
		getline(data, password, '\n'); // Reading the passwords from the database
		while(regname == name)
		{
			 cout << "The username already exists! Try again..." << endl;
			 registration(); // If name already exists start process of registration again
		}
	}
	data.close(); // Close file
	
    cout << "Write the desired password : ";
    getline (cin, regpass); // User gives desired password

	// If password is less than 4 chars try another one
    while (regpass.length() < 4) 
    {
        cout << endl << "The chosen password is too short!" << endl;
        cout << "The password needs to be at least four (4) characters long." << endl << endl;
        cout << "Try another password : ";
        getline ( cin, regpass );
    }
    
	ofstream newData("database", ios::app);      // Open database file to write new username and password
	
	ofstream newfile(regname.c_str(), ios::app); // Create file of new user with his username as file name        
	newfile.close();
	
	// Add name and password of new user to the database file
	newData << regname << '\n';
	newData << regpass << '\n';
	newData.close(); // Close database file

	cout << endl;
	cout << regname+", you have successfully registered!" << endl << endl;
	cout << "What you'll like to do :" << endl << string(24, '=') << endl;
	cout << "[1] Log In" << endl;
	cout << "[2] Return to Main Menu" << endl;
	cout << "[3] Exit the program" << endl << endl;
	cout << "Choice : ";
	
	// Process after successful registration
	int regChoice;
	cin >> regChoice;
	cin.ignore();
	
	switch (regChoice)
	{
		case 1:
			login();
			break;
		case 2:
			mainmenu();
			break;
		case 3:
			exxit();
			break;
		default:
			cout << "Wrong choice! Try again..." << endl;
			mainmenu();
			break;
	}
    return 0;
}


#endif // REGISTRATION_H
