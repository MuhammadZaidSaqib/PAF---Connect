
#ifndef VIEWPOSTS_H
#define VIEWPOSTS_H

// Local header files
#include "goback.h"

// Declaration of variables, defined in main.cpp
extern string name;
extern string posts;
extern string frend;
extern string namepost;

void viewposts()
{
    // Print all the posts of the logged in user
    cout << endl << "Your posts are :" << endl << string(16, '=') << endl;
    ifstream allposts;
    allposts.open("posts"); // Open file of posts
    
    int lineCount = 1;
    // Repeat process to print all of user's posts
    while(!allposts.eof())
    {
        getline(allposts, name, '\n');   // Read names from posts file
        getline(allposts, posts, '\n');  // Read posts from posts file
        if (name==logname)
        {
            cout << "[" << lineCount << "]" << " " << posts << endl;
            lineCount++;
        }
    }
    allposts.close(); // Close file of posts 
    
    // Print all posts that belong to friends of the logged in user
    cout << endl << "Your friends' posts are :" << endl << string(24, '=');
    bool same;
    ifstream user;
    user.open(logname.c_str()); // Open file of logged in user's friends
    
    // Check if a user is friend and then print all of his posts
    while(!user.eof())
    {
        int i=1; // Counter
        same = false;
        getline(user, frend, '\n');
        ifstream allposts;      
        allposts.open("posts"); // Open file of posts
        while(!allposts.eof())
        {
            getline(allposts, name, '\n');     // Read the names from posts file
            getline(allposts, posts, '\n');    // Read the posts from posts file
            if (frend == name && same == true)
            {
                cout << "  Post " << i << " : " << posts << endl; i++;
            }
            else if (frend == name && same == false && frend!="")
            {
                cout << endl << "Friend : " << name << endl;
                cout << "  Post " << i << " : " << posts << endl; i++;
                same = true;
            }
        }
        allposts.close(); // Close file of posts
    }
    user.close(); // Close logged in user's file
    
    // Print all conversations posts between logged in user and friends
    cout << endl << "Conversations :" << endl << string(15, '=') << endl;
    
    ifstream conversations;
    conversations.open("conversations"); // Open file of conversations
    
    while(!conversations.eof())
    {
		getline(conversations, namepost);
        
        if(namepost.substr(0, namepost.find(":")) == logname)
        {
			cout << namepost << endl;
			while(getline(conversations, namepost))
			{
				if(namepost.substr(0, 1) == " ")
					cout << namepost << endl;
				else
					break;
			}
		}
			      
        ifstream friends;
        friends.open(logname.c_str()); // Open file with friends of the logged in user
        string userfrend;
        
        while(getline(friends, userfrend))
        {
            if(userfrend == namepost.substr(0, namepost.find(":"))) // From the beginning of the line until ':' is found
            {
                cout << namepost << endl;
                do{
                    getline(conversations, namepost);
                    if(namepost.find(logname.c_str()) != std::string::npos)
                        cout << namepost << endl; 
                }while(namepost.substr(0,1)==" ");
            }
            else
                break;
        }
    }
    conversations.close(); // Close file of conversations
    
    
    // Number of LIKES : Count and print the number of likes for each of user's posts
    cout << endl << "Number of LIKES : " << endl << string(17, '=') << endl;
    
    ifstream likesnum;
    likesnum.open("likes"); // Open file of likes which contains the posts and the number of their likes
    int i=0;
    while(!likesnum.eof())
    {
        string mylikes;
        getline(likesnum, mylikes);
        int likecounter = 0; // Counter of likes for each post
        if(mylikes.find(":") != std::string::npos)
        {
            if(mylikes.substr(0, mylikes.find(":")) == logname)
            {
                i++;
                string upost = mylikes.substr(mylikes.find(" "), mylikes.find('\n'));
                cout << "[" << i << "]" << upost << " (#Likes : ";
				
				while (getline(likesnum, mylikes)){
					if(mylikes.find("LIKE") != std::string::npos) // While LIKE is beign found, increase the counter
						likecounter++;
					else
						break;
				}
				cout << likecounter << ")" << endl; // Print number of likes
			}
        }
    }
    likesnum.close(); // Close file of posts with likes
    goback(); // Check if user wants to continue or go back to main menu
}


#endif // VIEWPOSTS_H
