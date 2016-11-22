#ifndef fp_ticketer_user_class_H_
#define fp_ticketer_user_class_H_

class ticketer_user_c : public user_c{
	friend class admin_user_c;
	
	private:
	string password;
	
	public:
	void displayMenu();
	void displayInfo();
	ticketer_user_c();
	~ticketer_user_c();
	ticketer_user_c(string f, string l, string id, string pass);
};

ticketer_user_c::ticketer_user_c(){
	
}

ticketer_user_c::ticketer_user_c(string f, string l, string id, string pass){
	cout<<endl<<"ticketer user created";
	fname=f;
	lname=l;
	ID=id;
	password=pass;
}

ticketer_user_c::~ticketer_user_c(){
	cout<<endl<<"ticketer user destroyed";
}
void ticketer_user_c::displayInfo(){
	cout<<endl<<fname<< " "<<lname<< " " <<ID<< " "<<password;
}

#endif