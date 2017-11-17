//cpp file for music class.
#include "music.h"

music::music(char t[80], int y, char a[80], char p[80], char d[80]) : media(t, y){ //constructor.
	strcpy(artist, a);
	strcpy(publisher, p);
	strcpy(duration, d);
	type = 2;
}

char* music::getArtist(){ //get artist.
  return artist;
}

char* music::getPublisher(){ //get publisher.
  return publisher;
}

char* music::getDuration(){ //get duration.
  return duration;
}

void music::printInfo(){ //print info.
	cout << endl << title << " (Song)" << endl
		 << "Year: " << year << endl
		 << "Artist: " << artist << endl
		 << "Publisher: " << publisher << endl
		 << "Duration: " << duration << endl;
}