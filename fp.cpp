/*
 ============================================================================
 Name        : fp.cpp
 Author      : Jacob Bracey & Zach Shikles
 Description : ECE 3220: Final Project
 ============================================================================
 */
 
 #include "fp.frontend.h"
 #include "fp.backend.h"

 
 int main(void){
	 vector<admin_user_c> admin_group;
	 vector<user_c> user_group;
	 
	 system_startup(admin_group,user_group);
	 admin_group[0].displayInfo();
	 user_group[0].displayInfo();
	 return 0;
	 
 }