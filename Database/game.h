//game class. 
#include "media.h"

class game : public media{
	private: 
		char publisher[80];//declare variables.
		double rating;
	public:
		game(char t[80], int y, char p[80], double r); //declare constructor.
		
		char* getPublisher(); //declare functions.
    	double getRating();
    
    	void printInfo();
};