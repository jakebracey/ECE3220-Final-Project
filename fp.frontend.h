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
//#include <conio.h>
#include <cstdlib>
#include <ctime>


void clear_screen()
{
#ifdef _WIN32
    std::system("cls");
#else
    // Assume POSIX
    std::system ("clear");
#endif
}

void pause(int dur)
{
int temp = time(NULL) + dur;

while(temp > time(NULL));
}

#endif //end of fp.h
