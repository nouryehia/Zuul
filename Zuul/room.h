//Room class for Zuul.

//Includes.
#ifndef ROOM_H
#define ROOM_H
#include "inventory.h"
#include <map>

enum Direction {NORTH, EAST, SOUTH, WEST}; //Declare directions (Read about enums on StackOverflow and figured it was useful for my program.)


class room{
	private: //Create variables.
		char nameD[80];
		char description[180];
		char name[80];
		map<Direction, room*> exits;
		char* dirToChar(Direction d);
		inventory inv;
	public: //Declare functions.
		room(char nD[80], char d[180], char n[80]);
		void print();
		void setExit(Direction NESW, room* exit);
		char* getName();
		room* getExit(Direction d);
		void add(item i);
		item remove(item i);
		int numBooks();
}; 
#endif