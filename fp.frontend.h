/*
 ============================================================================
 Name        : fp.h
 Author      : Jacob Bracey & Zach Shikles
 Description : ECE 3220: Final Project Header File
			   This file contains all libraries
			   This file also contains user related funcitons and classes
 ============================================================================
 */
using namespace std;

#ifndef fp_frontend_H_
#define fp_frontend_H_

//this file contains all the headers we need as well as a few global functions
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>

//this is a function that ensures compilation on both windows and linux manchines
void clear_screen(){
#ifdef _WIN32
    std::system("cls");
#else
    std::system ("clear");
#endif
}

//a function that I found a user post on stackoverflow.com
//it is essentially a sleep() function that works on any system
void pause(int dur)
{
int temp = time(NULL) + dur;

while(temp > time(NULL));
}

#endif //end of fp.h
