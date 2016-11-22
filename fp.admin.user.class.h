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
	admin_user_c(string f, string l, string id);
	void displayInfo();
	void displayMenu();
};

void admin_user_c::displayMenu(){
	cout<<endl<<"Admin Menu";
}

admin_user_c::admin_user_c(){
	
}

admin_user_c::admin_user_c(string f, string l, string id, string pass,int access){
	//this constructor is used to create the admin with full rights user class
	
	//cout<<endl<<"Admin user created";
	fname=f;
	lname=l;
	ID=id;
	balance=0;
	password=pass;
	access_level=access;
}

admin_user_c::admin_user_c(string f, string l, string id, string pass){
	//this constructor is used to create the Box Office User class
	
	//cout<<endl<<"Box Office user created";
	fname=f;
	lname=l;
	ID=id;
	balance=0;
	password=pass;
	access_level=2;
}

admin_user_c::admin_user_c(string f, string l, string id){
	//this constructor is used to create the Ticketer user type
	//cout<<endl<<"Ticketer user created";
	fname=f;
	lname=l;
	ID=id;
	balance=0;
	access_level=3;
}

admin_user_c::~admin_user_c(){
	//cout<<endl<<"Admin/Box/Ticketer user destroyed";
}
void admin_user_c::displayInfo(){
	cout<<endl<<fname<< " "<<lname<< " " <<ID<< " "<<password;
}

#endif