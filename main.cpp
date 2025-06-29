
#include <sstream> 

#include "header_files/listusers.h"
#include "header_files/mainmenu.h"


string regname, regpass;  
string logname, logpass;  
string name, password;    
string namepost, reply;   
string posts;             
string friendname, frend; 
int numofusers = -1;      


int main()
{
    string graph_title = "||"+string(39,'=')+"||";
    cout << graph_title << endl;
    cout << "||"+string(9,' ')+"\e[1m PAF-IAST CONNECT \e[0m"+string(9,' ')+"||" << endl; 
    cout << "|| \e[3mA  social Media PlatForm in C++  +\e[0m ||" << endl;                 
    cout << graph_title << endl;
    listusers(); 
    
    ostringstream tstr; tstr << numofusers; string mystr = tstr.str();
    
    cout << "||    Number of registered users : " << numofusers << string(6-mystr.size(),' ')+"||" << endl; 
    cout << graph_title << endl;
    mainmenu(); 
}
