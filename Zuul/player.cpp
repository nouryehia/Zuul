//cpp file for player class.

#include "player.h" //Include


player::player(room* initial) { //Constructor.
	currentroom = initial;
}

void player::move(Direction d){ //Move a player.
	currentroom = currentroom->getExit(d);
}

room* player::getCurrentRoom(){ //Get player's current room.
	return currentroom;
}

void player::pick(char* name){ //Pick an item.
	item it;
	it = currentroom->remove(item(name));
	if (strcmp("error", name) != 0){
		backpack.add(it);
	}
}

void player::print(player p){ //Print inventory.
	if (p.numBooks() == 0){
		cout << endl << "Your Inventory is empty." << endl;
	}
	else{
		cout<< endl << "Player Inventory:" << endl;
		backpack.print();
	}

}

void player::drop(char* name){ //Drop an item.
	item it;
	it = backpack.remove(name);
	if (strcmp("error", name) != 0){
		currentroom->add(it);
	}
}

int player::numBooks(){ //Count the number of books in inventory.
	return backpack.numItems((char*)"Book");
}




