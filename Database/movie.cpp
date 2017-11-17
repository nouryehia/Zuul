//cpp class for movie class.
#include "movie.h"

movie::movie(char t[80], int y, char di[80], char du[80], double r) : media(t, y){ //constructor.
	strcpy(director, di);
	strcpy(duration, du);
	rating = r;
	type = 3;
}

char* movie::getDirector(){ // get director.
  return director;
}

char* movie::getDuration(){ //get duration.
  return duration;
}

double movie::getRating(){ //get rating.
  return rating;
}

void movie::printInfo(){ //print info.
	cout << endl << title << " (Movie)" << endl
		 << "Year: " << year << endl
		 << "Director: " << director << endl
		 << "Duration: " << duration << endl
		 << "Rating: " << rating << endl;
}