#ifndef fp_admin_user_class_H_
#define fp_admin_user_class_H_
using namespace std;


class admin_user_c : public user_c{
	friend class Database;
	
	private:
	string password;
	int access_level;
	
	public:
	~admin_user_c();
	admin_user_c();
	admin_user_c(string f, string l, string id, string pass,int access);
	admin_user_c(string f, string l, string id, string pass);
	void displayInfo();
	unsigned int displayMenu(bool access_check);
	unsigned int displayUserMenu();
	//void displayAdminMenu();
	//void displayBoxMenu();
	//void displayTicketerMenu();
	string getpass(const char *prompt, bool show_asterisk);
};

unsigned int admin_user_c::displayMenu(bool access_check){
	string input_pass;
	int result=0;
	int input=0;
	
	if(access_check){
	input_pass=getpass("Please enter your password: ",true);
	
	if(input_pass!=password){
		cout<<endl<<"---------  Access Denied  ---------"<<endl<<
				    "     Invalid Password Entered    "<<endl<<endl;
					return 0;
	}	
	}
	cout<<endl<<lname<<", "<<fname<<endl;
	
	if(access_level==0){
		displayUserMenu();
		return 0;
	}
	
	if(access_level==1){//start of Admin User Level
		while(input!=-1){
			cout<<endl<<"-----------  Main Menu  -----------"<<endl<<
						"      Please Select an Option      "<<endl<<endl
			<<"[-1] Logout"<<endl		
			<<"[1]  Login as Regular User"<<endl
			<<"[2]  Login as Ticketer User"<<endl
			<<"[3]  Login as Box Office User"<<endl
			<<"[4]  Login as Admin User"<<endl;
			cin>>input;
			
			switch(input){
				case -1:{
					cout<<endl<<"....Logging Out"<<endl;
					return 0;
					break;
				}
				
				case 1:{
					displayUserMenu();
					return 1;
					break;
				}
				
				case 2:{
					return 2;
					break;
				}
				
				case 3:{
					return 3;
					break;
				}
				case 4:{
					return 4;
					break;
				}
				
				default:{
					cout<<endl<<"--------  Invalid Option Entered  --------"<<endl;
				}
				
			}
		}
	}//end of admin access level
	
	if(access_level==2){//start of Box Office Admin User Level
		while(input!=-1){
			cout<<endl<<"-----------  Main Menu  -----------"<<endl<<
						"      Please Select an Option      "<<endl<<endl
			<<"[-1] Logout"<<endl		
			<<"[1]  Login as Regular User"<<endl
			<<"[2]  Login as Ticketer User"<<endl
			<<"[3]  Login as Box Office User"<<endl;
			cin>>input;
			
			switch(input){
				case -1:{
					cout<<endl<<"....Logging Out"<<endl;
					return 0;
					break;
				}
				
				case 1:{
					displayUserMenu();
					break;
				}
				
				case 2:{
					return 2;
					break;
				}
				
				case 3:{
					return 3;
					break;
				}
				
				default:{
					cout<<endl<<"--------  Invalid Option Entered  --------"<<endl;
				}
				
			}
		}
	}//end of Box Office User access level
	
	if(access_level==3){//start of Ticketer Admin User Level
		while(input!=-1){
			cout<<endl<<"-----------  Main Menu  -----------"<<endl<<
						"      Please Select an Option      "<<endl<<endl
			<<"[-1] Logout"<<endl		
			<<"[1]  Login as Regular User"<<endl
			<<"[2]  Login as Ticketer User"<<endl;
			cin>>input;
			
			switch(input){
				case -1:{
					cout<<endl<<"....Logging Out"<<endl;
					return 0;
					break;
				}
				
				case 1:{
					displayUserMenu();
					break;
				}
				
				case 2:{
					return 2;
					break;
				}
				
				default:{
					cout<<endl<<"--------  Invalid Option Entered  --------"<<endl;
				}
				
			}
		}
	}//end of Ticketer User access level
	
	
}


admin_user_c::admin_user_c(){
	
}

admin_user_c::admin_user_c(string f, string l, string id, string pass,int access){
	//this constructor is used to create either Admin or Box Office Users
	
	fname=f;
	lname=l;
	ID=id;
	balance=0;
	password=pass;
	access_level=access;
}

admin_user_c::admin_user_c(string f, string l, string id, string pass){
	//this constructor is used to create the Ticketer User class
	
	fname=f;
	lname=l;
	ID=id;
	balance=0;
	password=pass;
	access_level=3;
}



admin_user_c::~admin_user_c(){
	//cout<<endl<<"Admin/Box/Ticketer user destroyed";
}
void admin_user_c::displayInfo(){
	cout<<endl<<fname<< " "<<lname<< " " <<ID<< " "<<password;
}

string admin_user_c::getpass(const char *prompt, bool show_asterisk){
//Copyright notice
//This program came from a lirary online
//cplusplus.com is the source with an unknown author
//To view the website go to http://www.cplusplus.com/articles/E6vU7k9E/

	const char BACKSPACE=8;
	const char RETURN=13;

	string password;
	unsigned char ch=0;

	cout <<prompt<<endl;

	while((ch=getch())!=RETURN)
	{
	   if(ch==BACKSPACE)
		 {
			if(password.length()!=0)
			  {
				 if(show_asterisk)
				 cout <<"\b \b";
				 password.resize(password.length()-1);
			  }
		 }
	   else if(ch==0 || ch==224) // handle escape sequences
		 {
			 getch(); // ignore non printable chars
			 continue;
		 }
	   else
		 {
			 password+=ch;
			 if(show_asterisk)
				 cout <<'*';
		 }
	}
	cout <<endl;
	return password;
}


unsigned int admin_user_c::displayUserMenu(){
	int input_u=0; 
	while(input_u!=-1){
		cout<<endl<<"-----------  User Menu  -----------"<<endl<<
					"      Please Select an Option      "<<endl<<endl
		<<"[-1] Return to Main Menu / Logout"<<endl
		<<"[1]  View Your Account Info"<<endl
		<<"[2]  See ticket options"<<endl;
		cin>>input_u;
		
		switch(input_u){
			case 1:{
				displayInfo();
				break;
			}
			
			case 2:{
				cout<<"Ticket options"<<endl;
				break;
			}
			
			case -1:{
				cout<<endl<<"....Returning to Main Menu / Logging out"<<endl;
				break;
			}
			
			default:{
				cout<<endl<<"--------  Invalid Option Entered  --------"<<endl;
			}
			
		}
	}
	
}
/* void admin_user_c::displayAdminMenu(){
	int input_a=0; 
	while(input_a!=-1){
		cout<<endl<<"-----------  Admin Menu  -----------"<<endl<<
					"      Please Select an Option      "<<endl<<endl
		<<"[-1] Return to Main Menu"<<endl
		<<"[1]  "<<endl
		<<"[2]  See ticket options"<<endl;
		cin>>input_a;
		
		switch(input_a){
			case 1:{
				displayInfo();
				break;
			}
			
			case 2:{
				cout<<"Ticket options"<<endl;
				//user_group[0].displayInfo();
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
void admin_user_c::displayBoxMenu(){
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
				displayInfo();
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
void admin_user_c::displayTicketerMenu(){
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
	
} */

#endif
