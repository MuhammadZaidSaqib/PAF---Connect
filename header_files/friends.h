#ifndef FRIENDS_H
#define FRIENDS_H

#include "goback.h"


extern string frend;

void friends()
{
    cout << endl << "Your friends are :" << endl << string(18,'=') << endl;
    
    ifstream logUser;
    logUser.open(logname.c_str());
    while(!logUser.eof()) 
    {
        getline(logUser, frend); 
        cout << frend << endl;
    }
    goback();
}


#endif 
