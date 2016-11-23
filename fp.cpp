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
	
	 d1.Login();
	 
	 return 0;
	 
 }