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

class Database{
	
	
	private:
	vector<user_c> user_group;
	vector<admin_user_c> admin_group;

	
	public:
	~Database();
	Database();
	void displayUsers();
	int searchUsers(string search_key);
	int searchAdmins(string search_key);
	void Login();

};

void Database::Login(){
	
	string terminal_input;
	int result;
	while (terminal_input!="-1"){
		cout<<endl<<endl<<"Please swipe your ID Card or enter -1 to quit:"<<endl;
		cin>>terminal_input;
		
		if (terminal_input=="-1"){
			cout<<endl<<"--------  Terminating Program  --------"<<endl;
			break;	
		}
		
		else if(searchAdmins(terminal_input)!=-1){
			result=searchAdmins(terminal_input);
			admin_group[result].displayMenu();
		}
		
		else if(searchUsers(terminal_input)!=-1){
			result=searchUsers(terminal_input);
			user_group[result].displayMenu();
		}
		
		else{
			cout<<endl<<"--------  User not found  --------"<<endl;
		}
	}
}
int Database::searchUsers(string search_key){
	int i;
	for(i=0;user_group.size()>i;i++){
		 if(user_group[i].ID==search_key)
			 return i;
	 }
	return -1;
	
}

int Database::searchAdmins(string search_key){
	int i;
	for(i=0;admin_group.size()>i;i++){
		 if(admin_group[i].ID==search_key)
			 return i;
	 }
	return -1;
	
}


Database::Database(){
/*	This is the constructor that initializes the program
	
	
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
					
					int access=1;//access level 1 gives the user full admin access
					//users with this level of access can also perform Box Office and Ticketer Applications
					
					admin_user_c user_temp(fname,lname,ID,password,access);
					admin_group.push_back(user_temp);
				break;}
				
				case 'b':{
					//this is the case that creates the box attendant user typede
					//after the box attendant user is created, the profile is added to the correct vector
					
					int access=2;//access level 2 gives the user Box Office Access
					
					admin_user_c user_temp(fname,lname,ID,password);
					admin_group.push_back(user_temp);
				break;}
				
				case 't':{
					//this is the case that creates the ticketer user type
					//after the ticketer user is created, the profile is added to the correct vector
					
					int access=3;//access level 3 gives the user Ticketer Access
					
					admin_user_c user_temp(fname,lname,ID);
					admin_group.push_back(user_temp);
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

void Database::displayUsers(){
	int i;
	 cout<<endl<<endl<<"----  User Group Members  ----";
	 for(i=0;user_group.size()>i;i++){
		 user_group[i].displayInfo();
	 }
	 
	 cout<<endl<<endl<<"----  Admin Group Members  ----";
	 for(i=0;admin_group.size()>i;i++){
		 admin_group[i].displayInfo();
	 }
	 cout<<endl<<endl;
}

Database::~Database(){
	cout<<endl<<"Database Destroyed"<<endl;
}

#endif
