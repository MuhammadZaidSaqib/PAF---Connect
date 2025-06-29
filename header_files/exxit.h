#ifndef EXXIT_H
#define EXXIT_H

#include <iostream>
#include <fstream>
#include <unistd.h>
using namespace std;

extern string logname;

int exxit()
{
    cout << endl << "Program Termination..." << endl;
    usleep(1000000); 
    cout << "Thanks for your visit "+logname+" !" << endl;
    return 0;
}


#endif 
