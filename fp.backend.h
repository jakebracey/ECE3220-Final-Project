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

int system_startup(vector<user_c> &user_group,vector<admin_user_c> &admin_group,vector<box_user_c> &box_group,vector<ticketer_user_c> &ticketer_group){
/*	This is the function that initializes the program
	
	
*/

	ifstream user_file("users.txt");
	
	string line;
	while (getline(user_file, line))
	{
		istringstream iss(line);
		string fname, lname, password,ID;
		char user_type;
		
		if ((iss >> fname >> lname >> ID >> user_type >> password)) {
			switch(user_type){
				
				case 'a':{
					//this is the case that creates the admin user typede
					//after the admin user is created, the profile is added to the correct vector
					admin_user_c user_temp(fname,lname,ID,password);
					admin_group.push_back(user_temp);
				break;}
				
				case 'b':{
					//this is the case that creates the box attendant user typede
					//after the box attendant user is created, the profile is added to the correct vector
					box_user_c user_temp(fname,lname,ID,password);
					box_group.push_back(user_temp);
				break;}
				
				case 't':{
					//this is the case that creates the ticketer user typede
					//after the ticketer user is created, the profile is added to the correct vector
					ticketer_user_c user_temp(fname,lname,ID,password);
					ticketer_group.push_back(user_temp);
				break;}
				
				default:{
					//this is the default case
					//if any 
					user_c user_temp(fname,lname,ID);
					user_group.push_back(user_temp);
				
				}
					
				
			
				
			}
		}
		else{
			user_c user_temp(fname,lname,ID);
			user_group.push_back(user_temp);
		}
	}
	
}


#endif
