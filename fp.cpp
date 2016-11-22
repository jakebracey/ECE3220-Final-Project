/*
 ============================================================================
 Name        : fp.cpp
 Author      : Jacob Bracey & Zach Shikles
 Description : ECE 3220: Final Project
 ============================================================================
 */
 #include "fp.frontend.h"
 #include "fp.user.class.h"
 #include "fp.admin.user.class.h"
 #include "fp.backend.h"


 
 int main(void){
	 
	 Database d1;
	 
	 d1.displayUsers();
	 
	 string num;
	 cout<<endl<<"Enter a ID number:";
	 cin>>num;
	 cout<<endl<<"User Location: "<<d1.searchUsers(num);
	 cout<<endl<<"Admin Location: "<<d1.searchAdmins(num);
	 
	 d1.Login();
	 
	 return 0;
	 
 }