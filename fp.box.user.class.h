#ifndef fp_box_user_class_H_
#define fp_box_user_class_H_

class box_user_c : public user_c{
	friend class admin_user_c;
	
	private:
	string password;
	
	public:
	void displayMenu();
	void displayInfo();
	box_user_c();
	~box_user_c();
	box_user_c(string f, string l, string id, string pass);
};

box_user_c::box_user_c(){
	
}

box_user_c::box_user_c(string f, string l, string id, string pass){
	cout<<endl<<"box user created";
	fname=f;
	lname=l;
	ID=id;
	password=pass;
}

box_user_c::~box_user_c(){
	cout<<endl<<"box user destroyed";
}
void box_user_c::displayInfo(){
	cout<<endl<<fname<< " "<<lname<< " " <<ID<< " "<<password;
}


#endif