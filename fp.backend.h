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
	vector<event_c> event_group;

	
	public:
	~Database();
	Database();
	void displayUsers();
	void displayEvents();
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
		cout<<endl<<"Please swipe your ID Card or enter -1 to quit:"<<endl;
		
		cin>>terminal_input;
		
		
		if (terminal_input=="-1"){
			clear_screen();
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
			unsigned int user_choice=0;
			while(user_choice!=3){
			
				user_choice=user_group[result].displayUserMenu();
				
				
				switch(user_choice){
					case 1:{
						break;
					}
					case 2:{
						displayEvents();
						int user_selection=0;
						while(user_selection!=-1){
							displayEvents();
							cout<<"Please enter the ticket you would like to purchase or [-1] to escape:"<<endl;
							cin>>user_selection;
							if(user_selection<0||user_selection>event_group.size())
								cout<<endl<<"Invalid option selected"<<endl;
							else{
								if(event_group[user_selection-1].capacity>0){//checks to make sure there are available tickets
								(user_group[result].tickets).push_back(event_group[user_selection-1].ename);
								user_group[result].balance+=event_group[user_selection-1].price;
								event_group[user_selection-1].capacity--;
								cout<<endl<<"A ticket for the event \""<<event_group[user_selection-1].ename<<"\" has been added to your account"<<endl
								<<"Your new account balance is: $"<<user_group[result].balance<<endl;
								}
								else
									cout<<"There are no tickets available for this event"<<endl;
							}	
							
						}
						
						
						break;
					}
					
					case 3:{
						clear_screen();
						cout<<endl<<"....Logging Out"<<endl;
						break;
					}
				}
			}
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



Database::Database(){//NEEDS ERROR CHECKING
/*	This is the constructor that initializes the program
	
	
*/
	
	ifstream file("users.txt");
	if(!file){
		ofstream("users.txt");
		ofstream file("users.txt");
		string standard = "Default Admin 123 a Pass";
		file << standard;
		file.flush();
	}
	ifstream user_file("users.txt");
	user_file.clear();

	string line;
	while (getline(user_file, line))
	{
		istringstream iss(line);
		string fname, lname, password,ID;
		char user_type;
		
		if ((iss >> fname >> lname >> ID >> user_type >> password)) {
			int access=0;//sets to 0 to ensure that if any errors occur, user will NOT be given admin rights
			switch(user_type){
				
				case 'a':{
					//this is the case that creates the admin user typede
					//after the admin user is created, the profile is added to the correct vector
					
					access=1;//access level 1 gives the user full admin access
					//users with this level of access can also perform Box Office and Ticketer Applications
					
					admin_user_c user_temp(fname,lname,ID,password,access);
					admin_group.push_back(user_temp);
				break;}
				
				case 'b':{
					//this is the case that creates the box attendant user typede
					//after the box attendant user is created, the profile is added to the correct vector
					
					int access=2;//access level 2 gives the user Box Office Access
					
					admin_user_c user_temp(fname,lname,ID,password,access);
					admin_group.push_back(user_temp);
				break;}
				
				case 't':{
					//this is the case that creates the ticketer user type
					//after the ticketer user is created, the profile is added to the correct vector
					
					int access=3;//access level 3 gives the user Ticketer Access
					
					admin_user_c user_temp(fname,lname,ID,password);
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
	
	ifstream events_file("events.txt");
	string line_e;
	istringstream iss_events(line_e);
		
		while(getline(events_file, line_e))
		{
			istringstream iss_events(line_e);
			string ename;
			double price;
			unsigned int capacity;
			if((iss_events>>ename>>price>>capacity)){
				event_c event_temp(ename, price,capacity);
				event_group.push_back(event_temp);
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
void Database::displayEvents(){
	int i;
	cout<<endl<<endl<<"----  Current Events  ----";
	 for(i=0;event_group.size()>i;i++){
		 cout<<endl<<"#"<<i+1<<": ";
		 event_group[i].displayInfo();
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
			case 1:{//User management option
				
				string terminal_input,new_info;
				int new_access_level=0;
				int result,confirmation=0;
				int input=0;
				while (terminal_input!="-1"){
					cout<<endl<<endl<<"Please swipe ID Card, enter ID number, or enter -1 to exit: "<<endl;
					cin>>terminal_input;
					
					if (terminal_input=="-1"){
						cout<<endl<<"....Exiting"<<endl;
						break;	
					}
					
					else if(searchAdmins(terminal_input)!=-1){
						user_2_admin:
						result=searchAdmins(terminal_input);
						while(input!=-1){
							cout<<endl<<"Please select the item you would like to modify, [-1] to exit"<<endl
								<<"[1] First  name:  "<<admin_group[result].fname<<endl
								<<"[2] Last  name :  "<<admin_group[result].lname<<endl
								<<"[3] ID  number :  "<<admin_group[result].ID<<endl
								<<"[4] Access Level: "<<admin_group[result].access_level<<endl
								<<"[5] Password  :   "<<admin_group[result].password<<endl;
							cin>>input;
						
							switch(input){
								case -1:{
									cout<<endl<<"....Exiting"<<endl;
									break;
								}
								
								case 1:{
									cout<<"Please enter a new First Name: ";
									cin>>new_info;
									cout<<"New First Name: "<<new_info<<endl
										<<"Please select an option, [0] Confirm, [-1] Cancel"<<endl;
									cin>>confirmation;
									if(confirmation==0)
										admin_group[result].fname=new_info;
									break;
								}
								
								case 2:{
									cout<<"Please enter a new Last Name: ";
									cin>>new_info;
									cout<<"New Last Name: "<<new_info<<endl
										<<"Please select an option, [0] Confirm, [-1] Cancel"<<endl;
									cin>>confirmation;
									if(confirmation==0)
										admin_group[result].lname=new_info;
									break;
								}
								
								case 3:{
									cout<<"Please enter a new ID number: ";
									cin>>new_info;
									cout<<"New ID number: "<<new_info<<endl
										<<"Please select an option, [0] Confirm, [-1] Cancel"<<endl;
									cin>>confirmation;
									if(confirmation==0)
										admin_group[result].ID=new_info;
									break;
								}
								case 4:{
									cout<<"Please enter a new Access Level: "<<endl;
									cout<<"[0]  Regular User"<<endl
										<<"[1]  Admin User"<<endl
										<<"[2]  Box Office User"<<endl
										<<"[3]  Ticketer User"<<endl;
									cin>>new_access_level;
									if(new_access_level<0||new_access_level>3){
										cout<<"Invalid access Level entered"<<endl;
										break;
									}
										
									cout<<"New Access Level: "<<new_access_level<<endl
										<<"Please select an option, [0] Confirm, [-1] Cancel"<<endl;
									cin>>confirmation;
									if(confirmation==0)
										admin_group[result].access_level=new_access_level;
									break;
								}
								case 5:{
									cout<<"Please enter a new Password: ";
									cin>>new_info;
									cout<<"New Password: "<<new_info<<endl
										<<"Please select an option, [0] Confirm, [-1] Cancel"<<endl;
									cin>>confirmation;
									if(confirmation==0)
										admin_group[result].password=new_info;
									break;
								}
								
								default:{
									cout<<endl<<"--------  Invalid Option Entered  --------"<<endl;
								}
								
							}//end of SWITCH
						}//end of WHILE for changing user info
					}//end of ELSE IF for Admin result
					
					
					else if(searchUsers(terminal_input)!=-1){
						result=searchUsers(terminal_input);
						while(input!=-1){
							cout<<endl<<"Please select the item you would like to modify, [-1] to exit"<<endl
								<<"[1] First  name:  "<<user_group[result].fname<<endl
								<<"[2] Last  name :  "<<user_group[result].lname<<endl
								<<"[3] ID  number :  "<<user_group[result].ID<<endl
								<<"[4] Access Level: 0"<<endl;
							cin>>input;
						
							switch(input){
								case -1:{
									cout<<endl<<"....Exiting"<<endl;
								break;
								}
								
								case 1:{
									cout<<"Please enter a new First Name: ";
									cin>>new_info;
									cout<<"New First Name: "<<new_info<<endl
										<<"Please select an option, [0] Confirm, [-1] Cancel"<<endl;
									cin>>confirmation;
									if(confirmation==0)
										user_group[result].fname=new_info;
								break;
								}
								
								case 2:{
									cout<<"Please enter a new Last Name: ";
									cin>>new_info;
									cout<<"New Last Name: "<<new_info<<endl
										<<"Please select an option, [0] Confirm, [-1] Cancel"<<endl;
									cin>>confirmation;
									if(confirmation==0)
										user_group[result].lname=new_info;
								break;
								}
								
								case 3:{
									cout<<"Please enter a new ID number: ";
									cin>>new_info;
									cout<<"New ID number: "<<new_info<<endl
										<<"Please select an option, [0] Confirm, [-1] Cancel"<<endl;
									cin>>confirmation;
									if(confirmation==0)
										user_group[result].ID=new_info;
								break;
								}
								case 4:{
									cout<<"Please enter a new Access Level: "<<endl;
									cout<<"[0]  Regular User"<<endl
										<<"[1]  Admin User"<<endl
										<<"[2]  Box Office User"<<endl
										<<"[3]  Ticketer User"<<endl;
									cin>>new_access_level;
									if(new_access_level<0||new_access_level>3){
										cout<<"Invalid access Level entered"<<endl;
										break;
									}
									cout<<"New Access Level: "<<new_access_level<<endl
										<<"Please select an option, [0] Confirm, [-1] Cancel"<<endl;
									cin>>confirmation;
									if(confirmation==0){
										cout<<"Please set a Password: ";
									cin>>new_info;
									cout<<"New Password: "<<new_info<<endl
										<<"Please select an option, [0] Confirm, [-1] Cancel"<<endl;
									cin>>confirmation;
									if(confirmation==0){
										
										admin_user_c user_temp(user_group[result].fname,user_group[result].lname,user_group[result].ID,new_info,new_access_level);
										user_group.erase (user_group.begin()+result);
										admin_group.push_back(user_temp);
										goto user_2_admin;
									}
									}
								break;
								}
								
								default:{
									cout<<endl<<"--------  Invalid Option Entered  --------"<<endl;
								}
								
							}//end of SWITCH
						}//end of WHILE for changing user info
					}//end of ELSE IF for User result
				
					
					else{
						cout<<endl<<"Unable to find user";
					}
				}
				
			break;
			}//END of User management option
			
			case 2:{//Display Current Users option
				
				displayUsers();
				break;
			}//END of Display Current Users option
			
			case 3:{//Create New User option
			
				string temp_fn, temp_ln, temp_ID,temp_password;
				int temp_access_level;
				cout<<"Please enter a first name: ";
				cin>>temp_fn;
				cout<<"Please enter a last name: ";
				cin>>temp_ln;
				cout<<"Please enter an ID number: ";
				cin>>temp_ID;
				cout<<"[0]  Regular User"<<endl
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
			}//END of Create New User option
			
			case 4:{
				int terminal_input=0;
				while(terminal_input!=-1){
					displayEvents();
					cout<<endl<<"Please select an event number to edit, [-1] to exit"<<endl;
					cin>>terminal_input;
					if(terminal_input<0||terminal_input>event_group.size()){
						cout<<endl<<"Invalid option selected"<<endl;
					}
					else{
						while(input!=-1){
							cout<<endl<<"Please select the item you would like to modify, [-1] to exit"<<endl
								<<"[1] Event  Name : "<<event_group[terminal_input-1].ename<<endl
								<<"[2] Event  Price: $"<<event_group[user_selection-1].price<<endl
								<<"[3] Open Tickets: "<<event_group[user_selection-1].price<<endl
						
					}
					
					
				}
				
				break;
			}
			case 5:{//Display Current Events option
				displayEvents();
				break;
			}//END of Display Current Events
			
			case 6:{//Add New Event option
				string temp_event_name;
				double temp_price;
				cout<<"Please enter a event name: ";
				cin>>temp_event_name;
				
				
				break;
			}
			
			case -1:{
				cout<<endl<<"....Returning to Main Menu"<<endl;
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
				cout<<endl<<"....Returning to Main Menu"<<endl;
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
				cout<<endl<<"....Returning to Main Menu"<<endl;
				break;
			}
			
			default:{
				cout<<endl<<"--------  Invalid Option Entered  --------"<<endl;
			}
			
		}
	}
	
}
	

#endif
