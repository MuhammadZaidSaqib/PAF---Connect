#ifndef DELETEFRIENDS_H
#define DELETEFRIENDS_H

#include "goback.h"


extern string frend;

void deletefriends()
{
	string delmoreFriends = "Y";
    while(delmoreFriends=="Y" || delmoreFriends=="y")
    {
		cout << endl << "\e[1mDELETE FRIEND\e[0m" << endl;
		ifstream myfile;
		myfile.open(logname.c_str()); 

		int lineCount = 1;
		cout << "Your friends are :" << endl << string(18, '=') << endl;
		
		while(getline(myfile, frend) && frend != ""){
				cout << "[" << lineCount << "] " << frend << endl;
				lineCount++;
		}
		myfile.close();
		
		int friendNumber;
		
		ofstream temp1; 
		temp1.open("temp1", ios::app);

		ofstream temp2; 
		temp2.open("temp2", ios::app);

		ifstream Myfile;
		Myfile.open(logname.c_str());

		cout << endl << "\e[3m(Type the number of your choice)\e[0m" << endl;
		cout << "Choice : ";
		cin >> friendNumber;
		
		int j=0;
		
		while(getline(Myfile, frend) && frend!=""){
			j++;
			if(friendNumber != j)
				temp1 << frend << endl;
			else
			{
                
				ifstream myuserfriend(frend.c_str());
				string muf;
				while(getline(myuserfriend, muf))
				{
                    if(muf!=logname)
                        temp2 << muf << endl;
                    else
                        continue;
				}
				remove(frend.c_str());
                rename("temp2", frend.c_str()); 
            }
		}
		Myfile.close();
		// Close files
		temp1.close();
		temp2.close();
		remove(logname.c_str());
		rename("temp1", logname.c_str()); 
		
		cout << endl << "Delete more friends ? (Y/N) : ";
		
		cin >> delmoreFriends;
		if(delmoreFriends=="Y" || delmoreFriends=="y")
			deletefriends();
		else
		{
			goback();
			break;
		}
    }
}


#endif // DELETEFRIENDS_H
