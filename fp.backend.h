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
	friend class admin_user_c;
	
	
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
	void displayAdminMenu();
	void displayBoxMenu();
	void displayTicketerMenu();

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
			unsigned int admin_choice=1;
			bool access_check=true;
			while(admin_choice!=0){
			
				admin_choice=admin_group[result].displayMenu(access_check);
				
				if(admin_choice!=0)
					access_check=false;
				
				switch(admin_choice){
					case 0:{
						break;
					}
					case 1:{
						break;
					}
					
					case 2:{
						displayTicketerMenu();
						break;
					}
					
					case 3:{
						displayBoxMenu();
						break;
					}
					case 4:{
						displayAdminMenu();
						break;
					}
					
					default:{
						cout<<endl<<"--------  Access Error  --------"<<endl;
						break;
					}
					
				}
			
			}
		}
		
		else if(searchUsers(terminal_input)!=-1){
			result=searchUsers(terminal_input);
			user_group[result].displayUserMenu();
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



void Database::displayAdminMenu(){
	int input_a=0; 
	while(input_a!=-1){
		cout<<endl<<"-----------  Admin Menu  -----------"<<endl<<
					"      Please Select an Option      "<<endl<<endl
		<<"[-1] Return to Main Menu"<<endl
		<<"[1]  Manage Current Users"<<endl
		<<"[2]  View All Users"<<endl
		<<"[3]  Create New User"<<endl
		<<"[4]  Manage Current Events"<<endl
		<<"[5]  View All Events"<<endl
		<<"[6]  Create New Event"<<endl;
		cin>>input_a;
		
		switch(input_a){
			case 1:{
				
				break;
			}
			
			case 2:{
				displayUsers();
				break;
			}
			case 3:{
				string temp_fn, temp_ln, temp_ID,temp_password;
				int temp_access_level;
				cout<<"Please enter a first name: ";
				cin>>temp_fn;
				cout<<"Please enter a last name: ";
				cin>>temp_ln;
				cout<<"Please enter an ID number: ";
				cin>>temp_ID;
				cout<<"[0]: Regular User"<<endl
					<<"[1]  Admin User"<<endl
					<<"[2]  Box Office User"<<endl
					<<"[3]  Ticketer User"<<endl;
				cin>>temp_access_level;
				if(temp_access_level==0){
					cout<<endl<<"Please confirm the following information is correct"<<endl
					<<"First Name: "<<temp_fn<<endl
					<<"Last Name: "<<temp_ln<<endl
					<<"Student ID: "<<temp_ID<<endl
					<<"Access Level: "<<temp_access_level<<endl<<endl
					<<"Please select an option, [0] Create user, [-1] Escape: ";
					int confirmation=1;
					cin>>confirmation;
					if(confirmation==0){
						user_c user_temp(temp_fn,temp_ln,temp_ID);
						user_group.push_back(user_temp);
					}
					break;	
				}
				else if(temp_access_level>0||temp_access_level<4){
					cout<<"Please enter a user password: ";
					cin>>temp_password;
					cout<<endl<<"Please confirm the following information is correct"<<endl
					<<"First Name: "<<temp_fn<<endl
					<<"Last Name: "<<temp_ln<<endl
					<<"Student ID: "<<temp_ID<<endl
					<<"Access Level: "<<temp_access_level<<endl
					<<"Password: "<<temp_password<<endl<<endl
					<<"Please select an option, [0] Create user, [-1] Escape: ";
					int confirmation=1;
					cin>>confirmation;
					if(confirmation==0){
						admin_user_c user_temp(temp_fn,temp_ln,temp_ID,temp_password,temp_access_level);
						admin_group.push_back(user_temp);
					}
				}
				
				break;
			}
			
			case 4:{
				
				break;
			}
			case 5:{
				
				break;
			}
			
			case 6:{
				
				break;
			}
			
			case -1:{
				cout<<endl<<"------  Returning to Main Menu  ------"<<endl;
				break;
			}
			
			default:{
				cout<<endl<<"--------  Invalid Option Entered  --------"<<endl;
			}
			
		}
	}	
	
}
void Database::displayBoxMenu(){
int input_b=0; 
	while(input_b!=-1){
		cout<<endl<<"---------  Box Office Menu  ---------"<<endl<<
					"       Please Select an Option       "<<endl<<endl
		<<"[-1] Return to Main Menu"<<endl
		<<"[1]  View "<<endl
		<<"[2]  See"<<endl
		<<"[3]  View "<<endl;
		cin>>input_b;
		
		switch(input_b){
			case 1:{
				
				break;
			}
			
			case 2:{
				cout<<"Ticket options"<<endl;
				break;
			}
			case 3:{
				
				break;
			}
			
			case -1:{
				cout<<endl<<"------  Returning to Main Menu  ------"<<endl;
				break;
			}
			
			default:{
				cout<<endl<<"--------  Invalid Option Entered  --------"<<endl;
			}
			
		}
	}
	
}
void Database::displayTicketerMenu(){
	int input_t=0; 
	while(input_t!=-1){
		cout<<endl<<"---------  Ticketer Menu  ---------"<<endl<<
					"      Please Select an Option      "<<endl<<endl
		<<"[-1] Return to Main Menu"<<endl
		<<"[1]  Vi"<<endl
		<<"[2]  See"<<endl;
		cin>>input_t;
		
		switch(input_t){
			case 1:{
				
				break;
			}
			
			case 2:{
				
				break;
			}

			
			case -1:{
				cout<<endl<<"------  Returning to Main Menu  ------"<<endl;
				break;
			}
			
			default:{
				cout<<endl<<"--------  Invalid Option Entered  --------"<<endl;
			}
			
		}
	}
	
}
	

#endif
