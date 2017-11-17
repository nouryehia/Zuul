//parent class.

#ifndef ADD_H
#define ADD_H
#include <iostream>
#include <cstring> 

using namespace std;

class media{
	protected:
		char title[80]; //declare variables.
		int year;
		int type;
	public:
		media(char t[80], int y); //declare constructor
		
		char* getTitle(); //declare functions.
		int getYear();
		int getType();
};

#endif