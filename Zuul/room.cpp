//cpp file for room class.

#include "room.h" //Include.

room::room(char nD[80], char d[180], char n[80]){ //Constructor.
	strcpy(nameD, nD);
	strcpy(description, d);
	strcpy(name, n);
}

void room::print(){ //Print room's description, exits, and items.
	cout << endl << "You are currently " << nameD << description << endl
		 << "There are exits:" << endl;
	for(map<Direction, room*>::iterator i = exits.begin(); i !=exits.end(); i++){
		cout << "  " << dirToChar(i->first) << " (to " << i->second->name << ")" << endl;
	}
	if (numBooks() == 0){
		cout << "There are no items." << endl << endl;
	}
	else {
		cout << "There is an item:" << endl;
		inv.print();
		cout << endl; 
	}
}

void room::setExit(Direction NESW, room* exit){ //Set room's exits.
	exits[NESW] = exit;
}

char* room::getName(){ //Get room's name.
	return name;
}

char* room::dirToChar(Direction d){ //Converts enum Direction into a char.
	switch(d){
		case NORTH: return (char*)"North"; break;
		case EAST: return (char*)"East"; break;
		case SOUTH: return (char*)"South"; break;
		case WEST: return (char*)"West"; break;
	}
}

room* room::getExit(Direction d){ //Get room's exits.
	if (exits.find(d) == exits.end()){ //If no exits.
		cout << "There are no exits this direction." << endl;
		return this;
	}
	else{
		return exits[d];
	}
}

void room::add(item i){ //Add an item to room.
	inv.add(i);
}

item room::remove(item i){ //Remove an item from room.
	return inv.remove(i.getName());
}

int room::numBooks(){ //Count number of books in room.
	return inv.numItems((char*)"Book");
}


