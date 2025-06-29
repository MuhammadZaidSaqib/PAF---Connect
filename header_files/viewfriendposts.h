
#ifndef VIEWFRIENDPOSTS_H
#define VIEWFRIENDPOSTS_H

// Local header files
#include "menu2.h"
#include "goback.h"

void viewfriendposts()
{
    cout << endl << "\e[1mYOUR FRIENDS WALLS\e[0m" << endl << "\e[3m(Type the number of your choice)\e[0m" << endl << string(33, '=') << endl;
    // Options for friend's wall
    cout << "[1] Post a message on your wall" << endl;
    cout << "[2] Reply to a post" << endl;
    cout << "[3] Leave a Like" << endl;
    cout << "[4] Main menu" << endl << endl;
    cout << "Choice : ";
    int choiceType;
    cin >> choiceType;
    
    if(choiceType==1) // Post a message on your wall
    {
        string post;
        // Creat file to save user's posts, without deleting the existed ones
        ofstream newPost("posts", ios::app);
        
        cout << "Write the post you want :" << endl;
        cin.ignore();
        getline(cin, post);
        
        // Write inside posts's file the logged in user's name and his post under it
        newPost << logname << '\n';
        newPost << post << '\n';
        newPost.close(); // Close file of posts
        goback();
    }
    else if(choiceType==2) // Reply to a friend's post  
    {
        string myChoice="Y";
        // Repeat process to choose friend and check his posts
        while(myChoice=="Y" || myChoice=="y")
        {   
            ifstream friends;
            friends.open(logname.c_str()); // Open file of logged in user's friends
            
            cout << endl << "Your friends are : " << endl << string(19, '=') << endl;
            int j=1;
            // Process to print a numbered list of user's friends
            while(getline(friends, frend) && frend!="")
            {
                cout << "[" << j << "] " << frend << endl;
                j++;
            }
            friends.close(); // Close file of friends
            
            string tempFriend;
            
            cout << endl << "Choose the number of friend you want to view his posts : ";
            int friendNum;
            cin >> friendNum;
            
            int l=0;
            ifstream myFriends(logname.c_str()); // Open file of logged in user
            ofstream postTemp("Temp"); // Open a temporary file to write on it
            
            while(!myFriends.eof()){
                l++;
                getline(myFriends, frend);
                // Check the number that user typed
                if(friendNum == l)
                {
                    cout << endl << "Friend : " << frend << endl << string(frend.size(), '=')+"==========" << endl;
                    int i=1; // Counter for posts
                    ifstream allPosts;
                    allPosts.open("posts"); // Open file of all posts
                    
                    while(!allPosts.eof())
                    {
                        getline(allPosts, name, '\n');  // Read user's name
                        getline(allPosts, posts, '\n'); // Read user's post
                        // Check if friend's name exists on posts file
                        // and print all of the friend posts
                        if (name == frend)
                        {   
                            cout << "  Post " << i << " : " << posts << endl; 
                            postTemp << posts << endl;
                            i++;
                        }
                        tempFriend = frend; // Save current friend in tempFriend string
                    }
                    allPosts.close(); // Close file of posts
                }
                else
                    continue;
            }
            postTemp.close();
            string moreReplies="Y";
            
            // Process to reply on a friend's post
            while(moreReplies=="Y" || moreReplies=="y")
            {
                cout << endl << "Choose the post you wish to reply on \e[3m(type it's number)\e[0m : ";
                int numReply;
                cin >> numReply;
                    
                ifstream posttemp("Temp"); // Open temporary file of posts
                int a=0; // Variable to keep count of lines 
                while(!posttemp.eof())
                {
                    a++;
                    getline(posttemp, posts);
                    if(numReply == a)
                    {
                        ifstream repost;
                        repost.open("conversations"); // Open file of conversations
                        
                        ofstream temprepost("TempRePost"); // Open temporary file to write on it
                        bool b=false; // Variable to check if friend and posts exists on file
                        while(!repost.eof())
                        {
                            getline(repost, namepost);
                            if(namepost.substr(0, namepost.find(":"))==tempFriend && namepost.find(posts) != std::string::npos )
                                b = true;
                            temprepost << namepost << endl;
                        }
                        temprepost.close();
                        
                        ifstream tempPosts;
                        tempPosts.open("TempRePost");
                        
                        ofstream postreplies("conversations"); // Open file of conversations to write a reply
                        string post;
                        cout << "Enter your reply..." << endl;
                        cin.ignore();
                        string userReply;
                        getline(cin, userReply); // Logged in user enters his reply to post
                        while(getline(tempPosts, post) && post!="")
                        {
                            // Check if friend's post already exists. Then leave a post under the name and before the latest reply
                            if(b==true)
                            {
                                if(post.substr(0, post.find(":"))==tempFriend && post.find(posts) != std::string::npos )
                                {
                                    postreplies << post << endl << string((tempFriend.size()+2) ,' ') << userReply << " ("+logname+")" << endl;
                                    continue;
                                }
                                else
                                    postreplies << post << endl;
                            }
                            // If friend's post doesn't exists write the name of friend and his post to leave a reply under it
                            else if(b==false)
                                postreplies << post << endl;
                        }
                        if(b==false)
                            postreplies << tempFriend+": " << posts << endl << string((tempFriend.size()+2) ,' ') << userReply  << " ("+logname+")" << endl;
						// Close files
                        temprepost.close();
                        postreplies.close();
                        remove("TempRePost");
                    }
                }
                cout << endl << "Reply to other posts of the same friend ? (Y/N) : ";
                cin >> moreReplies;
                // Choose whether to reply to more posts of the same friend or not
                if(moreReplies=="Y" || moreReplies=="y")
                    continue;
                else
                {
                    posttemp.close();
                    remove("Temp");
                    break;
                }
            }
            // Check if user wants to see other walls
            cout << endl << "See other friend's wall ? (Y/N) : ";
            cin >> myChoice;
            // Choose whether to view or not other friends' walls
            if((myChoice=="Y") || (myChoice=="y"))
                continue;
            else
            {   
                myFriends.close();
                goback();
                break;
            }
        }
    }
    else if(choiceType==3)
    {   
        string myChoice="Y";
        // Repeat process to choose friend to view posts
        while(myChoice=="Y" || myChoice=="y")
        {   
            ifstream friends;
            friends.open(logname.c_str()); // Open file of logged in user's friends
            
            cout << "Your friends are : " << endl << string(19, '=') << endl;
            int j=1;
            // Process to print a numbered list of logged in user's friends
            while(getline(friends, frend) && frend!="")
            {
                cout << "[" << j << "] " << frend << endl;
                j++;
            }
            friends.close();
            
            string tempFriend;
            cout << endl << "Choose the number of friend you want to view his posts : ";
            int friendNum;
            cin >> friendNum; // Enter number of friend
            ifstream myFriends(logname.c_str());
            ofstream postTemp("Temp");
            
            int l=0;
            while(!myFriends.eof()){
                l++;
                getline(myFriends, frend);
                // Check the number that user typed
                if(friendNum == l)
                {
                    cout << endl << "Friend : " << frend << endl << string(frend.size(), '=')+"=========" << endl;
                    int i=1;
                    ifstream allPosts;
                    allPosts.open("posts"); // Open file of all posts
                    while(!allPosts.eof())
                    {
                        getline(allPosts, name, '\n');  // Read user name
                        getline(allPosts, posts, '\n'); // Read user post
                        // Check if friend's name exists on posts file
                        // and print all friend's posts
                        if (name == frend)
                        {   
                            cout << "  Post " << i << " : " << posts << endl; 
                            postTemp << posts << endl;
                            i++;
                        }
                        tempFriend = frend;
                    }
                    allPosts.close(); // Close file with posts
                }
                else
                    continue;
            }
            postTemp.close();
            string moreReplies="Y";
            
            // Process to leave a LIKE on a friend's post
            while((moreReplies=="Y") || (moreReplies=="y"))
            {
                cout << endl << "Choose the post you wish to leave a LIKE \e[3m(type it's number)\e[0m : ";
                int numReply;
                cin >> numReply;
                
                ifstream posttemp("Temp"); // Open temporary file of posts
                int a=0; // Variable to keep count of lines
                while(!posttemp.eof())
                {
                    a++;
                    getline(posttemp, posts);
                    if(numReply == a)
                    {
                        ifstream likes;
                        likes.open("likes");
                        string namepost;
                        
                        ofstream templikes("TempLikes");
                        bool b=false; // Variable to check if friend and posts exists on file
                        while(!likes.eof())
                        {
                            getline(likes, namepost);
                            if(namepost.substr(0, namepost.find(":"))==tempFriend && namepost.find(posts) != std::string::npos )
                                b = true;
                            templikes << namepost << endl;
                        }
                        templikes.close();
                        
                        ifstream tempLikes;
                        tempLikes.open("TempLikes");
                        ofstream replies("likes");
                        string like;
                        while(getline(tempLikes, like) && like!="")
                        {
                            // Check if friend's post already exists. Then leave a like under the post and before the latest likes
                            if(b==true)
                            {
                                if(like.substr(0, like.find(":"))==tempFriend && like.find(posts) != std::string::npos )
                                {
                                    replies << like << endl << string((tempFriend.size()+2) ,' ') << "LIKE!" << " ("+logname+")" << endl;
                                    continue;
                                }
                                else
                                    replies << like << endl;
                            }
                            else if(b==false)// If friend's post doesn't exists write the name of friend and his post to leave a like under it
                                replies << like << endl;
                        }
                        if(b==false)
                            replies << tempFriend+": " << posts << endl << string((tempFriend.size()+2) ,' ') << "LIKE!" << " ("+logname+")" << endl;

                        templikes.close();
                        replies.close();
                        remove("TempLikes");
                    }
                }
                cout << endl << "Leave a LIKE to other posts of the same friend ? (Y/N) : ";
                cin >> moreReplies;
                // Choose whether to leave a like or not to other posts of the same friend
                if((moreReplies=="Y") || (moreReplies=="y"))
                    continue;
                else
                {
                    posttemp.close();
                    remove("Temp");
                    break;
                }
            }
            
            // Check if user wants to see other walls
            cout << endl << "See other friend wall ? (Y/N) : ";
            cin >> myChoice;
            // Choose whether to view or not other friends' walls
            if((myChoice=="Y") || (myChoice=="y"))
            {
                cout << endl;
                continue;
            }
            else
            {
                myFriends.close();
                goback();
            }
        }
    }
    else
        menu2();
}


#endif // VIEWFRIENDPOSTS_H
