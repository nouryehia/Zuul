//cpp file for board class.

#include "board.h" //Include.

void board::addRoom(room r){ //Add room to map.
	m.push_back(r);
}
void board::print(){ //Print the map (for debugging purposes.
	for(vector<room>::iterator i = m.begin(); i != m.end(); i++){
		i->print();
	}
}
