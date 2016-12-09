README File

Tiger Tickets

1. Components needed to run
	A. Required Files in Directory to run program.
		a) fp.cpp
		b) fp.frontend.h
		c) fp.backend.h
		d) fp.user.class.h
		e) fp.admin.user.class.h
		f) fp.event.class.h
	
	B. Optional Files in Directory to run program
		a) users.txt
			a1) User file should be in the following format
				
				To create user:
				   string      string      string
				<First Name> <Last Name> <ID number>
				
				To create admin:
				   string       string     string         int        string
				<First Name> <Last Name> <ID number> <Access Level> <Password>
				**If the last two parts are not contained in the line in the proper 
				  order then a regular user will be created
				Access Levels are as Follows:
					"0": Regular User
					"1": Admin User
					"2": Box Office User
					"3": Ticketer User
			
			a2) If no user file is included a default admin user will be created
				ID: 12345678
				Password: LetMeInNow
		
		b) events.txt
			b1) Event file should be in the following format
				To creat event:
				   string       double       unsigned int 
				<Event Name> <Event Price> <Event Capacity>
			b2) If no event file is present admin user will have to create an event

2. To use "Tiger Tickets"			
	A. Ensure all required files listed in section 1A are in directory before compiling
	B. Compile the program on your machine using command "g++ fp.cpp"
	C. Ensure any desired input files listed in section 1B are in the directory before 
	   initializing the program
	D. After Login sequence begins you can either swipe ID card using reader
	   or you can manually type in User ID using the keyboard
	E. Follow menu prompts which vary depending on user type you login with
	F. To terminate program and backup user and event data return to login screen
	   and, as instructed, type "-1" to quit