//cpp file for parent class. 
#include "media.h"

media::media(char t[80], int y){ //constructor.
	strcpy(title, t);
	year = y;
	type = 0;
}

char* media::getTitle(){ //get title.
	return title;
}

int media::getYear(){ //get year.
	return year;
}

int media::getType(){ //get type.
	return type;
}

