#ifndef fp_user_class_H_
#define fp_user_class_H_
using namespace std;


class user_c{
	friend class Database;
	
	protected:
	string ID;//contains the user ID which is what is searched for
	string fname;//holds a user's first name
	string lname;//holds a user's last name
	double balance;//holds the user's balance that they owe
	vector<string> tickets;//a vector of strings which holds user's tickets that they have bought
	
	public:
	~user_c();
	user_c();
	user_c(string f, string l, string id);
	void virtual displayInfo();//displays user's info
	unsigned int displayUserMenu();//displays menu for a user to view their info and buy tickets for themselves
};

user_c::user_c(){

}

user_c::user_c(string f, string l, string id){
	fname=f;
	lname=l;
	ID=id;
	balance=0;
}

user_c::~user_c(){
	//no memory is malloced so there is no reason to free any memory here
}

void user_c::displayInfo(){
	//displays user's info
	cout<<endl<<fname<< " "<<lname<< " ID: " <<ID<<" Balance: $"<<balance;
	for(auto i:tickets){
		cout <<" -"<< i <<"- ";
	}
}

unsigned int user_c::displayUserMenu(){
	int input=0;
	cout<<endl<<lname<<", "<<fname<<endl;
	
	while(input!=3){
	
		cout<<endl<<"-----------  User Menu  -----------"<<endl<<
					"      Please Select an Option      "<<endl<<endl
		<<"[1] View Your Account Info"<<endl
		<<"[2] See ticket options"<<endl
		<<"[3] Log Out/Exit"<<endl;
		cin>>input;
		
		switch(input){
			case 1:{
				clear_screen();
				displayInfo();
				return 1;
				break;
			}
			
			case 2:{
				//returns to the database so it can have access to the events
				clear_screen();
				return 2;
				break;
			}
			
			case 3:{//option to logout
				return 3;
				break;
			}
			
			default:{
				clear_screen();
				cout<<endl<<"--------  Incorrect Option Entered  --------"<<endl;
			}
			
		}
	}
}

#endif
