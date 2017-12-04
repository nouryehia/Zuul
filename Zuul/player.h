//Player class for Zuul.

//Includes
#include "inventory.h"
#include "room.h"

class player{
	private: //Create variables.
		room* currentroom;
		inventory backpack;
	public: //Declare functions.
		player(room* initial);
		void move(Direction d);
		room* getCurrentRoom();
		void print(player p);
		void pick(char* name);
		void drop(char* name);
		int numBooks();
};