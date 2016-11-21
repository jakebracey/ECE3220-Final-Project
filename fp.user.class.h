#ifndef fp_user_class_H_
#define fp_user_class_H_
using namespace std;


class user_c{
	friend class admin_user_c;
	friend class ticket_user_c;
	friend class box_user_c;
	
	protected:
	string ID;
	string fname;
	string lname;
	vector<string> tickets;
	vector<string> tickets_used;
	
	public:
	
	//void virtual displayMenu();
	void virtual displayInfo();
	user_c(string f, string l, string id);
	user_c();
	~user_c();
};
user_c::user_c(){

}

user_c::user_c(string f, string l, string id){
	cout<<endl<<"User created";
	fname=f;
	lname=l;
	ID=id;
}

user_c::~user_c(){
	cout<<endl<<"User destroyed";
}

void user_c::displayInfo(){
	cout<<endl<<fname<< " "<<lname<< " " <<ID;
}

#endif