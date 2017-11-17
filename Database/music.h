//music class.
#include "media.h"

class music : public media{
	private:
	
		char artist[80]; //declare variables.
		char publisher[80];
		char duration[80];
		
	public:
		music(char t[80], int y, char a[80], char p[80], char d[80]); //declare constructor.
		
		char* getArtist(); //declare functions.
    	char* getPublisher();
    	char* getDuration();
    
    	void printInfo();
};