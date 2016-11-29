#ifndef fp_user_class_H_
#define fp_user_class_H_
using namespace std;


class user_c{
	friend class Database;
	
	protected:
	string ID;
	string fname;
	string lname;
	double balance;
	vector<string> tickets;
	vector<string> tickets_used;
	
	public:
	~user_c();
	user_c();
	user_c(string f, string l, string id);
	void virtual displayInfo();
	void virtual displayUserMenu();
};

user_c::user_c(){
	//ID="-1";
	//fname="ERROR";
	//lname="ERROR";
	//tickets.push_back("ERROR");
	//tickets_used.push_back("ERROR");

}

user_c::user_c(string f, string l, string id){
	//cout<<endl<<"User created";
	fname=f;
	lname=l;
	ID=id;
	balance=0;
}

user_c::~user_c(){
	//cout<<endl<<"User destroyed";
}

void user_c::displayInfo(){
	cout<<endl<<fname<< " "<<lname<< " " <<ID;
}

void user_c::displayUserMenu(){
	int input=0;
	cout<<endl<<"Welcome your account "<<fname<<" "<<lname<<endl;
	
	
	while(input!=3){
		cout<<endl<<"-----------  Main Menu  -----------"<<endl<<
					"      Please Select an Option      "<<endl<<endl
		<<"[1] View Your Account Info"<<endl
		<<"[2] See ticket options"<<endl
		<<"[3] Log Out"<<endl;
		cin>>input;
		
		switch(input){
			case 1:{
				displayInfo();
				break;
			}
			
			case 2:{
				cout<<"Ticket options"<<endl;
				break;
			}
			
			case 3:{
				cout<<endl<<"--------  Logging Out  --------"<<endl;
				break;
			}
			
			default:{
				cout<<endl<<"--------  Incorrect Option Entered  --------"<<endl;
			}
			
		}
	}
}

#endif