/*
 ============================================================================
 Name        : fp.backend.h
 Author      : Jacob Bracey & Zach Shikles
 Description : ECE 3220: Final Project Header File
			   This file classes and functions relating to system functunality
 ============================================================================
 */
using namespace std;

#ifndef fp_backend_H_
#define fp_backend_H_

#include <fstream>
#include <sstream>

int system_startup(vector<admin_user_c> &admin_group,vector<user_c> &user_group){
/*	This is the function that initializes the program
	
	
*/

	ifstream user_file("users.txt");
	
	string line;
	while (getline(user_file, line))
	{
		istringstream iss(line);
		string fname, lname, password;
		char user_type;
		int ID;
		
		if ((iss >> fname >> lname >> ID >> user_type >> password)) {
			switch(user_type){
				case 'a':
					admin_user_c user_temp(fname,lname,ID,password);
					admin_group.push_back(user_temp);
					break;
			

			
				
			}
		}
		else{
			user_c user_temp(fname,lname,ID);
			user_group.push_back(user_temp);
		}
	}
	
}


#endif
