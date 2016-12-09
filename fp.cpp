/*
 ============================================================================
 Name        : fp.cpp
 Author      : Jacob Bracey & Zach Shikles
 Description : ECE 3220: Final Project
 ============================================================================
 */
 #include "fp.frontend.h"
 #include "fp.event.class.h"
 #include "fp.user.class.h"
 #include "fp.admin.user.class.h"
 #include "fp.backend.h"
 

 
 int main(void){
	 
	 Database d1;//initilizes the database and reads in from the input files

	 clear_screen();
	 d1.displayUsers();
	 d1.Login();//starts the login sequence
	 
	 return 0;
	 
 }