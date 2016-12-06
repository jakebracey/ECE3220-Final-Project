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
};

unsigned int admin_user_c::displayMenu(bool access_check){
	string input_pass;
	int result=0;
	int input=0;
	
	if(access_check){
	//input_pass=getpass("Please enter your password: ",true);
	cout<<"Please enter your password: ";
	cin>>input_pass;
	clear_screen();
	
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
					clear_screen();
					cout<<endl<<"....Logging Out"<<endl;
					return 0;
					break;
				}
				
				case 1:{
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
					clear_screen();
					cout<<endl<<"....Logging Out"<<endl;
					return 0;
					break;
				}
				
				case 1:{
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
					clear_screen();
					cout<<endl<<"....Logging Out"<<endl;
					return 0;
					break;
				}
				
				case 1:{
					return 1;
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
	for(auto i:tickets)
		cout <<" -"<< i <<"- ";
}



#endif
