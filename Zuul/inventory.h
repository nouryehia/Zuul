//Inventory class for Zuul.

//Includes.
#ifndef INVENTORY_H
#define INVENTORY_H
#include "item.h"
#include <vector>

class inventory{
	private: //Create variables.
		vector<item> in;
	public: //Declare functions.
		void print();
		void add(item i);
		item remove(char* name);
		int numItems(char* name);
};
#endif

