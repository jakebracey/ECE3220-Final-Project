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
	//vectors of class type
	vector<user_c> user_group;//vector contains all standard user information which is stored in a class
	vector<admin_user_c> admin_group;//vector contains all admin user information which is stored in a class
	vector<event_c> event_group;//vector contains all event information which is stored in a class

	
	public:
	~Database();
	Database();
	void displayUsers();//prints out all users' info, both admin and regular
	void displayEvents();//prints all events' info
	int searchUsers(string search_key);//searches the user vector and returns an index to that user
	int searchAdmins(string search_key);//searches the admin vector and returns an index to that user
	int searchEvents(string search_key);//searches the event vector and returns an index to that event
	void Login();//initiates the UI which starts on the login screen
	void displayAdminMenu();//displays options that are only available to admins
	void displayBoxMenu();//displays the Box user interface
	void displayTicketerMenu();//displays the ticketer user interface

};



void Database::Login(){
	//start of the Login sequence. This is first part that the user interacts with. 
	//this method transfers users to the part of the program they are supposed to access
	
	string terminal_input;
	int result;
	while (terminal_input!="-1"){
		cout<<endl<<"Please swipe your ID Card or enter -1 to quit:"<<endl;
		
		cin>>terminal_input;
		
		
		if (terminal_input=="-1"){//'-1' is what is checked to end the program
			clear_screen();
			cout<<endl<<"--------  Terminating Program  --------"<<endl;
			break;	
		}
		
		else if(searchAdmins(terminal_input)!=-1){
			//start of the menus if the user is found to be an admin
			result=searchAdmins(terminal_input);
			unsigned int admin_choice=1;
			unsigned int user_sel=0;
			bool access_check=true;//used so password is not checked continuously, after password is confirmed, this is turned to false
			while(admin_choice!=0){
			
				admin_choice=admin_group[result].displayMenu(access_check);//calls the menu function for the admin user that was located
				
				if(admin_choice!=0)
					access_check=false;
				
				switch(admin_choice){
					case 0:{
						break;
					}
					
					case 1:{//start of admin option to display user menu
						clear_screen();
						unsigned int user_choice=0;
							while(user_choice!=3){
							
								user_choice=admin_group[result].displayUserMenu();
								
								
								switch(user_choice){
									case 1:{//lets the user display their info
										break;
									}
									case 2:{//lets the admin view and edit their own info
										int user_selection=0;
										while(user_selection!=-1){
											displayEvents();
											cout<<"Please enter the ticket you would like to purchase or [-1] to escape:"<<endl;
											cin>>user_selection;
											if(user_selection==-1){
												clear_screen();
												cout<<endl<<".....Returning";
											}
											else{
												if(user_selection<=0||user_selection>event_group.size()){
													clear_screen();
													cout<<endl<<"Invalid option selected"<<endl;
												}
												else{
													if(event_group[user_selection-1].capacity>0){//checks to make sure there are available tickets
													(admin_group[result].tickets).push_back(event_group[user_selection-1].ename);
													admin_group[result].balance+=event_group[user_selection-1].price;
													event_group[user_selection-1].capacity--;
													clear_screen();
													cout<<endl<<"A ticket for the event \""<<event_group[user_selection-1].ename<<"\" has been added to your account"<<endl
													<<"Your new account balance is: $"<<admin_group[result].balance<<endl;
													}
													else
														cout<<"There are no tickets available for this event"<<endl;
												}	
												
											}
										}
										
										break;
									}
									case 3:{//lets the user break out of the user menu
										clear_screen();
										cout<<endl<<"....Returning to Main Menu"<<endl;
										break;
									}
								}
							}
						break;
					}//END of admin option to display user menu
					
					case 2:{
							clear_screen();
							displayTicketerMenu();
							break;
					}
					case 3:{
						clear_screen();
						displayBoxMenu();
						break;
					}
					case 4:{
						clear_screen();
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
			clear_screen();
			while(user_choice!=3){
			
				user_choice=user_group[result].displayUserMenu();
				
				
				switch(user_choice){
					case 1:{//lets users print out their own info
						break;
					}
					case 2:{//lets users see and buy new tickets
						int user_selection=0;
						while(user_selection!=-1){
							displayEvents();
							cout<<"Please enter the ticket you would like to purchase or [-1] to escape:"<<endl;
							cin>>user_selection;
							if(user_selection==-1){
								clear_screen();
								cout<<endl<<".....Returning";
							}
							else{
							if(user_selection<=0||user_selection>event_group.size()){
								clear_screen();
								cout<<endl<<"Invalid option selected"<<endl;	
							}
								
							else{
								if(event_group[user_selection-1].capacity>0){//checks to make sure there are available tickets
								(user_group[result].tickets).push_back(event_group[user_selection-1].ename);
								user_group[result].balance+=event_group[user_selection-1].price;
								event_group[user_selection-1].capacity--;
								clear_screen();
								cout<<endl<<"A ticket for the event \""<<event_group[user_selection-1].ename<<"\" has been added to your account"<<endl
								<<"Your new account balance is: $"<<user_group[result].balance<<endl;
								}
								else
									cout<<"There are no tickets available for this event"<<endl;
							}	
							
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
			clear_screen();
			cout<<endl<<"--------  User not found  --------"<<endl;
		}
	}//end of first while which essentially ends the program after it is exited
}//end of Login()
int Database::searchUsers(string search_key){
	//goes through all the user classes in search of the ID that it is given
	int i;
	for(i=0;user_group.size()>i;i++){
		 if(user_group[i].ID==search_key)
			 return i;
	 }
	return -1;
	
}

int Database::searchAdmins(string search_key){
	//goes through all the admin user classes in search of the ID that it is given
	int i;
	for(i=0;admin_group.size()>i;i++){
		 if(admin_group[i].ID==search_key)
			 return i;
	 }
	return -1;
	
}

int Database::searchEvents(string search_key){
	//goes through all the admin user classes in search of the ID that it is given
	int i;
	for(i=0;event_group.size()>i;i++){
		 if(event_group[i].ename==search_key)
			 return i;
	 }
	return -1;
	
}





Database::Database(){
/*	This is the constructor that initializes the program
	It reads in a user and event input filebuf
	If they are not present, a default one is created
		
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
		//reads an entire input line in, iss essentially parses this string as defined in the IF statement
		istringstream iss(line);
		string fname, lname, password,ID;
		int user_type;
		
		if ((iss >> fname >> lname >> ID >> user_type >> password)) {
			int access=0;//sets to 0 to ensure that if any errors occur, user will NOT be given admin rights
			switch(user_type){
				
				case 1:{
					//this is the case that creates the admin user type
					//after the admin user is created, the profile is added to the correct vector
					
					access=1;//access level 1 gives the user full admin access
					//users with this level of access can also perform Box Office and Ticketer Applications
					
					admin_user_c user_temp(fname,lname,ID,password,access);
					admin_group.push_back(user_temp);
				break;}
				
				case 2:{
					//this is the case that creates the box attendant user typede
					//after the box attendant user is created, the profile is added to the correct vector
					
					int access=2;//access level 2 gives the user Box Office Access
					
					admin_user_c user_temp(fname,lname,ID,password,access);
					admin_group.push_back(user_temp);
				break;}
				
				case 3:{
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
	
	//part of the code to read in the events
	//since the events are much less complex, this part is much smaller
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
	//method to display all users and their info, both admin and not
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
	//method to display all events, both admin and not
	int i;
	cout<<endl<<endl<<"----  Current Events  ----";
	 for(i=0;event_group.size()>i;i++){
		 cout<<endl<<"#"<<i+1<<": ";
		 event_group[i].displayInfo();
	 }
	 cout<<endl<<endl;
}

Database::~Database(){
	//the destructor is where we backup our data. We do this because when using large file sizes it would take too long to write all updated info to a file each time it is changed
	//user and event data are saved to their respective files 
	
	int i;
	std::ofstream file;
	file.open("users.txt", std::ofstream::out | std::ofstream::trunc);
	for(i=0;user_group.size()>i;i++){//writes data to file
		 file << user_group[i].fname << " " << user_group[i].lname << " " << user_group[i].ID << endl;
	 }
	for(i=0;admin_group.size()>i;i++){//writes data to file
		file << admin_group[i].fname << " " << admin_group[i].lname << " " << admin_group[i].ID <<" "<< admin_group[i].access_level << " " << admin_group[i].password << endl;
	}
	file.close();
	
	std::ofstream event_file;
	event_file.open("events.txt", std::ofstream::out | std::ofstream::trunc);
	for(i=0;event_group.size()>i;i++){//writes data to file
		 event_file << event_group[i].ename << " " << event_group[i].price << " " << event_group[i].capacity << endl;
	 }

	event_file.close();
	
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
				//this option enables the admin to print out the current users and their info
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
						int sub_input=0;
						while(sub_input!=-1){
							cout<<endl<<"Please select the item you would like to modify, [-1] to exit"<<endl
								<<"[1] Event  Name : "<<event_group[terminal_input-1].ename<<endl
								<<"[2] Event  Price: $"<<event_group[terminal_input-1].price<<endl
								<<"[3] Spots  Left : "<<event_group[terminal_input-1].capacity<<endl;
							cin>>sub_input;
						
							switch(sub_input){
								case -1:{
									cout<<endl<<"....Exiting"<<endl;
								break;
								}
								
								case 1:{
									string new_name;
									int confirmation=0;
									int confirmation_inital=0;
									cout<<endl<<"---------- WARNING ----------"<<endl
											  <<"Changing event name will VOID any previously purchased ticket"<<endl
											  <<"Ensure that no user has purchased a ticket before modifying"<<endl
											  <<"[0] to proceed, [-1] to cancel"<<endl;
									cin>>confirmation_inital;
									if(confirmation_inital==0){
									cout<<"Please enter a new Event Name: ";
									cin>>new_name;
									cout<<"New First Name: "<<new_name<<endl
										<<"Please select an option, [0] Confirm, [-1] Cancel"<<endl;
									cin>>confirmation;
									if(confirmation==0)
										event_group[terminal_input-1].ename=new_name;
									}
								break;
								}
								
								case 2:{
									int confirmation=0;
									double new_price;
									cout<<"Please enter a new Event Price: ";
									cin>>new_price;
									cout<<"The Price for the Event "<<event_group[terminal_input-1].ename<<" will be changed from: $"<<event_group[terminal_input-1].price<<" to $"<<new_price<<endl
										<<"Please select an option, [0] Confirm, [-1] Cancel"<<endl;
									cin>>confirmation;
									if(confirmation==0)
										event_group[terminal_input-1].price=new_price;
								break;
								}
								
								case 3:{
									int confirmation=0;
									int new_capacity=-1;
									cout<<endl<<"Please enter a new event capacity: ";
									cin>>new_capacity;
									while (new_capacity<0){
										cout<<endl<<"Capactity cannot be negative"<<endl<<"Please enter a new event capacity: ";
										cin>>new_capacity;
									}
									cout<<"Available tickets for the Event "<<event_group[terminal_input-1].ename<<" will be changed from: "<<event_group[terminal_input-1].capacity<<" to "<<new_capacity<<endl
										<<"Please select an option, [0] Confirm, [-1] Cancel"<<endl;
									cin>>confirmation;
									if(confirmation==0)
										event_group[terminal_input-1].capacity=new_capacity;
								break;
								}
						
							}//end of switch
					
						}
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
				int temp_capacity=-1;
				int cap_or_no=-1;
				
				cout<<"Please enter a event name: ";
				cin>>temp_event_name;
				cout<<"Please enter a event Price: $";
				cin>>temp_price;
				
				cout<<"Does this event have a limited number of available tickets?"<<endl
					<<"[0]NO -or- [1]YES"<<endl;
					cin>>cap_or_no;
				if(cap_or_no==0){
				cout<<endl<<"Please confirm the following information is correct"<<endl
					<<"Event  Name : "<<temp_event_name<<endl
					<<"Event  Price: $"<<temp_price<<endl
					<<"Event Capacity: UNLIMITED"<<endl
					<<"Please select an option, [0] Create event, [-1] Escape:"<<endl;
					int confirmation=1;
					cin>>confirmation;
					if(confirmation==0){
						event_c event_temp(temp_event_name,temp_price);
						event_group.push_back(event_temp);
					}
					
				}
				else if(cap_or_no==1){
					cout<<"Please enter an event capacity: ";
					cin>>temp_capacity;
					if(temp_capacity<0){
						while (temp_capacity<0){
							cout<<endl<<"Capactity cannot be negative"<<endl<<"Please enter an event capacity: ";
							cin>>temp_capacity;
							}
					}
					
					cout<<endl<<"Please confirm the following information is correct"<<endl
						<<"Event  Name : "<<temp_event_name<<endl
						<<"Event  Price: $"<<temp_price<<endl
						<<"Event Capacity: "<<temp_capacity<<endl
						<<"Please select an option, [0] Create event, [-1] Escape: "<<endl;
					int confirmation=1;
					cin>>confirmation;
					if(confirmation==0){
						event_c event_temp(temp_event_name,temp_price,temp_capacity);
						event_group.push_back(event_temp);
					}
					
					}
				break;
			}
			
			case -1:{
				clear_screen();
				cout<<endl<<"....Returning to Main Menu"<<endl;
				break;
			}
			
			default:{
				cout<<endl<<"--------  Invalid Option Entered  --------"<<endl;
			}
			
		}
	}//end of while
}//end of case 4	
	
void Database::displayBoxMenu(){

string terminal_input;
	int result;
	while (terminal_input!="-1"){
		clear_screen();
		cout<<endl<<"---------  Box Office Menu  ---------";
		cout<<endl<<"Swipe ID Card or [-1] to exit:"<<endl;
		cin>>terminal_input;
		int user_selection=0;
		clear_screen();
		
		
		if (terminal_input=="-1"){
			clear_screen();
			cout<<endl<<"....Returning to Main Menu"<<endl;
			break;	
		}
		
		else if(searchAdmins(terminal_input)!=-1){
			result=searchAdmins(terminal_input);
			while(user_selection!=-1){
				cout<<endl<<admin_group[result].fname<<" "<<admin_group[result].lname;
				displayEvents();
				cout<<"Select a ticket number, [0] for refunds, [-1] to return:"<<endl;
				cin>>user_selection;
				if(user_selection==-1){
				break;	
				}
				else if(user_selection==0){
					//code for option to return a user's ticket
					int cnt=0;
					int return_selection=0;
					for(auto i:admin_group[result].tickets){
						cnt++;
						cout <<endl<<cnt<<": "<< i;
						}
					if(cnt==0){
						clear_screen();
						cout<<endl<<"User has no tickets to return"<<endl<<endl;
					}
					else{
					cout<<endl<<"Ticket # to refund, [-1] to escape: ";
					cin>>return_selection;
						if(return_selection>0&&return_selection<=(admin_group[result].tickets).size()){
							int event_index;
							event_index=searchEvents((admin_group[result].tickets)[return_selection-1]);
							cout<<(admin_group[result].tickets)[return_selection-1]<<endl;
							
							(admin_group[result].tickets).erase ((admin_group[result].tickets).begin()+return_selection-1);
							admin_group[result].balance-=event_group[event_index].price;
							event_group[event_index].capacity++;
							clear_screen();
							cout<<endl<<admin_group[result].fname<<" "<<admin_group[result].lname<<" has been credited $ "<<event_group[event_index].price<<" for the event: \""<<event_group[event_index].ename<<"\" Admin's Account Balance: $"<<admin_group[result].balance<<endl;
						
						}
						else{
							clear_screen();
							cout<<endl<<"Ticket Return Aborted";
						}
					}
				
				}
				
				else if(user_selection<=0||user_selection>event_group.size())
					cout<<endl<<"Invalid option selected"<<endl;
				else{
					if(event_group[user_selection-1].capacity>0){//checks to make sure there are available tickets
					(admin_group[result].tickets).push_back(event_group[user_selection-1].ename);
					admin_group[result].balance+=event_group[user_selection-1].price;
					event_group[user_selection-1].capacity--;
					clear_screen();
					cout<<endl<<"A ticket for the event \""<<event_group[user_selection-1].ename<<"\" has been added to the account"<<endl
					<<"Their new account balance is: $"<<admin_group[result].balance<<endl;
					}
					else
						cout<<"There are no tickets available for this event"<<endl;	
				}
			}
		}
		else if(searchUsers(terminal_input)!=-1){
			result=searchUsers(terminal_input);
			while(user_selection!=-1){
				cout<<endl<<user_group[result].fname<<" "<<user_group[result].lname;
				displayEvents();
				cout<<"Select a ticket number, [0] for refunds, [-1] to return:"<<endl;
				cin>>user_selection;
				if(user_selection==-1){
				break;	
				}
				else if(user_selection==0){
					//code for option to return a user's ticket
					int cnt=0;
					int return_selection=0;
					for(auto i:user_group[result].tickets){
						cnt++;
						cout <<endl<<cnt<<": "<< i;
						}
					if(cnt==0){
						clear_screen();
						cout<<endl<<"User has no tickets to return"<<endl<<endl;
						
					}
					else{
					cout<<endl<<"Ticket # to refund, [-1] to escape: ";
					cin>>return_selection;
						if(return_selection>0&&return_selection<=(user_group[result].tickets).size()){
							int event_index;
							event_index=searchEvents((user_group[result].tickets)[return_selection-1]);
							cout<<(user_group[result].tickets)[return_selection-1]<<endl;
							
							(user_group[result].tickets).erase ((user_group[result].tickets).begin()+return_selection-1);
							user_group[result].balance-=event_group[event_index].price;
							event_group[event_index].capacity++;
							clear_screen();
							cout<<endl<<user_group[result].fname<<" "<<user_group[result].lname<<" has been credited $ "<<event_group[event_index].price<<" for the event \""<<event_group[event_index].ename<<"\" User's Account Balance: $"<<user_group[result].balance<<endl;
						
						}
						else{
							clear_screen();
							cout<<endl<<"Ticket Return Aborted";
						}
					}
				
				}
				
				else if(user_selection<=0||user_selection>event_group.size())
					cout<<endl<<"Invalid option selected"<<endl;
				else{
					if(event_group[user_selection-1].capacity>0){//checks to make sure there are available tickets
					(user_group[result].tickets).push_back(event_group[user_selection-1].ename);
					user_group[result].balance+=event_group[user_selection-1].price;
					event_group[user_selection-1].capacity--;
					clear_screen();
					cout<<endl<<"A ticket for the event \""<<event_group[user_selection-1].ename<<"\" has been added to the account"<<endl
					<<"Their new account balance is: $"<<user_group[result].balance<<endl;
					}
					else
						cout<<"There are no tickets available for this event"<<endl;	
				}
			}
		}
			
			
			
			else{
				cout<<endl<<"--------  User not found  --------"<<endl;
			}
		}
	}
	
	
	


	

void Database::displayTicketerMenu(){
	int result;
	int user_input=0;

	while (user_input!=-1){
		string terminal_input;
		cout<<endl<<"---------  Ticketer Menu  ---------";
		displayEvents();
		cout<<endl<<"Please select an Event Number to begin or [-1] to exit:"<<endl;
		cin>>user_input;
		
		
		if (user_input==-1){
			clear_screen();
			cout<<endl<<"....Returning to Main Menu"<<endl;
			break;	
		}
		
		if(user_input<=0||user_input>event_group.size()){
			clear_screen();
			cout<<endl<<"Invalid option selected"<<endl;
			
		}
		else{
			clear_screen();
			while (terminal_input!="-1"){
				
				cout<<event_group[user_input-1].ename<<" Event Ticketing"<<endl
				<<"Please slide ID card or [-1] to Exit:"<<endl;
				cin>>terminal_input;
				
				
				if (terminal_input=="-1"){
					clear_screen();
					cout<<endl<<"....Returning to Ticketer Menu"<<endl;
					break;	
				}
				
				else if(searchAdmins(terminal_input)!=-1){
					result=searchAdmins(terminal_input);
					int success=0;
					int cnt=0;
					for(auto i:admin_group[result].tickets){
						cnt++;
						if(i==event_group[user_input-1].ename){
							(admin_group[result].tickets).erase ((admin_group[result].tickets).begin()+cnt-1);
							clear_screen();
							success=1;
							cout<<"+++CONFIRMED+++ "<<admin_group[result].fname<< " "<<admin_group[result].lname<<endl;
						}
					}
					if(success==0){
						clear_screen();
						cout<<"--DENIED-- "<<admin_group[result].fname<<" "<<admin_group[result].lname<<" --DENIED--"<<endl<<endl;
					}
				}
					
			

				else if(searchUsers(terminal_input)!=-1){
					result=searchUsers(terminal_input);
					int success=0;
					int cnt=0;
					for(auto i:user_group[result].tickets){
						cnt++;
						if(i==event_group[user_input-1].ename){
							(user_group[result].tickets).erase ((user_group[result].tickets).begin()+cnt-1);
							clear_screen();
							success=1;
							cout<<"+++CONFIRMED+++ "<<user_group[result].fname<< " "<<user_group[result].lname<<endl;
						}
					}
					if(success==0){
						clear_screen();
						cout<<"--DENIED-- "<<user_group[result].fname<<" "<<user_group[result].lname<<" --DENIED--"<<endl<<endl;
					}
				}
				else{
				clear_screen();	
				cout<<"User Could not be found"<<endl;
				}
			pause(1);
			}
		}
	}
}

	

#endif
