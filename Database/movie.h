//movie class.
#include "media.h"

class movie : public media{
	private:
		char director[80]; //declare variables.
		char duration[80];
		double rating;
	public:
		movie(char t[80], int y, char di[80], char du[80], double r); //declare constructor.
		
		char* getDirector(); //declare functions.
		char* getDuration();
    	double getRating();
    
    	void printInfo();
};