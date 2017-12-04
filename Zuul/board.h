//Board class for Zuul.

#include "room.h" //Include.

class board{
	private: //Create variable.
		vector<room> m;
	public: //declare functions.
		void addRoom(room r);
		void print();
};