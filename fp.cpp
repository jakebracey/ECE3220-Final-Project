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
 #include "fp.ticketer.user.class.h"
 #include "fp.box.user.class.h"
 #include "fp.backend.h"


 
 int main(void){
	 vector<user_c> user_group;
	 vector<admin_user_c> admin_group;
	 vector<box_user_c> box_group;
	 vector<ticketer_user_c> ticketer_group;
	 
	 system_startup(user_group,admin_group,box_group,ticketer_group);
	 
	 int i;
	 cout<<endl<<endl<<"----  User Group Members  ----";
	 for(i=0;user_group.size()>i;i++){
		 user_group[i].displayInfo();
	 }
	 
	 cout<<endl<<endl<<"----  Admin Group Members  ----";
	 for(i=0;admin_group.size()>i;i++){
		 admin_group[i].displayInfo();
	 }
	 
	 cout<<endl<<endl<<endl<<"----  Box Group Members  ----";
	 for(i=0;box_group.size()>i;i++){
		 box_group[i].displayInfo();
	 }
	 
	 cout<<endl<<endl<<endl<<"----  Ticketer Group Members  ----";
	 for(i=0;ticketer_group.size()>i;i++){
		 ticketer_group[i].displayInfo();
	 }
	 cout<<endl<<endl;
	 
	 return 0;
	 
 }