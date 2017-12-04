//cpp file for  item class.

#include "item.h" //Include.


item::item(char n[80]){ //Constructor.
	strcpy(name, n)	;
}

item::item(){ //Empty constructor (for debugging purposes).

}

char* item::getName(){ //Get item's name.
	return name;
}