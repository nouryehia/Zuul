//cpp file for inventory class.

#include "inventory.h" //Include.

void inventory::add(item i){ //Add an item to inventory.
	in.push_back(i);
}

item inventory::remove(char* name){ //Remove an item from inventory.
	item result((char*)"error");
	for (vector<item>::iterator i = in.begin(); i != in.end(); i++){
		if (strcmp(name, i->getName())==0){
			result = *i;
			in.erase(i);
			return result;
		}
	}
	cout << "Item not found." << endl;
	return result;
}

void inventory::print(){ //Print inventory.
	for(vector<item>::iterator i = in.begin(); i != in.end(); i++){
		cout << "  " << i->getName() << endl;
	}
}

int inventory::numItems(char* name){ //Count number of items in inventory. 
	int counter = 0;
	for(vector<item>::iterator i = in.begin(); i != in.end(); i++){
		if (strcmp(name, i->getName())==0){
			counter++;
		}
	}
	return counter;
}
