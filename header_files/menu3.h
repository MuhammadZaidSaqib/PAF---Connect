#ifndef MENU3_H
#define MENU3_H

// Local header files
#include "goback.h"

void menu3()
{
    string line;
    ofstream users("users"); // Create file to save the names (not the passwords) of all registered users
    
    ifstream data;
    data.open("database"); // Open database file with user names and passwords
    
    cout << endl << "Registered (non friends) users :" << endl << string(32, '=') << endl;
    int i = 0;
    // Save the names (not the passwords) of all registered users to "users" file
    while(!data.eof()){
        getline(data, line);
        if (i%2==0)
            users << line << endl;
        i++;
    }   
    users.close();
    data.close();
    
    int lineCount=1;
    
    ifstream regUsers;
    regUsers.open("users"); // Open users file
    
    ofstream nonFriends("Temp");  // Create temporary file to write all non-friend users
    
    string logline;
    while(getline(regUsers, line) && line!="")
    {
        if(line!=logname)
        {
            ifstream logUser(logname.c_str());
            bool exists = false;
            while(getline(logUser, logline))
            {
                    // Check if other user name exists already in logged in user firends file
                    if(logline.find(line) != std::string::npos)
                        exists = true;
                    else
                        continue;
            }
            logUser.close();
            if(exists==false)
            {
                cout << "[" << lineCount << "]" << " " << line << endl;
                nonFriends << line << endl;
            }
            else
                continue;
        }
        else
            continue;
        lineCount++;
    }
    // Close opened files
    nonFriends.close();
    regUsers.close();
    
    cout << endl << "Send Friend Request..." << endl;
    
    int friendNumber;
    string moreFriends = "Y";
    
    // Write inside the file of requests without deleting the existing text
    ofstream requests("Requests",  ios::app);
    
    // Process to send a friend request
    // User will type the number that corresponds to the user he wants to send a request
    while((moreFriends!="Y") || (moreFriends!="y")){
        cout << "Choose the number that corresponds to the desired friend : ";
        cin >> friendNumber;
        
        // Open file with all non friend registered users
        ifstream nonFriends;
        nonFriends.open("Temp");
        
        int j=0;
        while(getline(nonFriends, line) && line!=""){
            j++;
            if(friendNumber == j)
            {
                // Save the requests as "user_sent_request -> user_to_accept" to the file of requests
                requests << logname + " -> " + line << endl;
            }
            else
                continue;
        }
        // Choose whether to send or not more requests
        cout << endl << "Send more requests ? (Y/N) : ";
        cin >> moreFriends;
        if((moreFriends=="Y") || (moreFriends=="y"))
            continue;
        else
        {
            goback();
            break;
        }
    }
    // Close files
    requests.close();
    nonFriends.close();
    // Remove temporary file
    remove("Temp");
}


#endif // MENU3_H
