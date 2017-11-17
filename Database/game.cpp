//cpp file for game class. 
#include "game.h"

game::game(char t[80], int y, char p[80], double r) : media(t, y){ //Constructor.
	strcpy(publisher, p);
	rating = r;
	type = 1;
}

char* game::getPublisher(){ //get publisher.
  return publisher;
}

double game::getRating(){ //get rating. 
  return rating;
}

void game::printInfo(){ //print info.
	cout << endl << title << " (Video Game)" << endl
		 << "Year: " << year << endl
		 << "Publisher: " << publisher << endl
		 << "Rating: " << rating << endl;
}