#ifndef fp_admin_user_class_H_
#define fp_admin_user_class_H_
using namespace std;


class admin_user_c : public user_c{
	private:
	string password;
	
	public:
	void displayMenu();
	void displayInfo();
	admin_user_c();
	~admin_user_c();
	admin_user_c(string f, string l, string id, string pass);
};

admin_user_c::admin_user_c(){
	
}

admin_user_c::admin_user_c(string f, string l, string id, string pass){
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

#endif