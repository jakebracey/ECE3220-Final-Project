/*
 ============================================================================
 Name        : fp.h
 Author      : Jacob Bracey & Zach Shikles
 Description : ECE 3220: Final Project Header File
			   This file contains all libraries
			   This file also contains user related funcitons and classes
 ============================================================================
 */
using namespace std;

#ifndef fp_frontend_H_
#define fp_frontend_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>



class user_c{
	
	
	protected:
	int ID;
	string fname;
	string lname;
	vector<string> tickets;
	vector<string> tickets_used;
	
	public:
	
	//void virtual displayMenu();
	void virtual displayInfo();
	user_c(string f, string l, int id);
	user_c();
	~user_c();
};
user_c::user_c(){

}

user_c::user_c(string f, string l, int id){
	cout<<endl<<"User created";
	fname=f;
	lname=l;
	ID=id;
}

user_c::~user_c(){
	cout<<endl<<"User destroyed";
}

void user_c::displayInfo(){
	cout<<endl<<fname<< " "<<lname<< " " <<ID;
}


class admin_user_c : public user_c{
	private:
	string password;
	
	public:
	void displayMenu();
	void displayInfo();
	admin_user_c();
	~admin_user_c();
	admin_user_c(string f, string l, int id, string pass);
};

admin_user_c::admin_user_c(){
	
}

admin_user_c::admin_user_c(string f, string l, int id, string pass){
	cout<<endl<<"Admin user created";
	fname=f;
	lname=l;
	ID=id;
	password=pass;
}

admin_user_c::~admin_user_c(){
	cout<<endl<<"Admin user destroyed";
}
void admin_user_c::displayInfo(){
	cout<<endl<<fname<< " "<<lname<< " " <<ID<< " "<<password;
}






#endif //end of fp.h
