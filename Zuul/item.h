//Item class for Zuul. (found it to be quite useless in the end.)

//Includes.
#ifndef ITEM__H_
#define ITEM__H_
#include <iostream>
#include <cstring> 

using namespace std;

class item { 
	private: //Create variables.
		char name[80];
	public: //Declare functions.
		item(char n[80]);
		item();
		char* getName();
};
#endif