/* Database
 * Author: Nour Yehia
 * Date: 11-16-17
 * This program allows the user to add songs, movies, and video games to a database.
   The user can later search for these items or delete them from the database. */

#include <vector> //Include all the classes.
#include "media.h"
#include "game.h"
#include "movie.h"
#include "music.h"

void add(vector<media*> *plist); //Declare all the functions.
void search(vector<media*> list);
void del(vector<media*> *plist);
bool quit();
char* upperCase(char input[80]);
void readInput(char input[7]);

int counternew = 0;

int main (){
	vector<media*> list; //Create media vector and pointer.
	vector<media*> *pList = &list;
	bool running = true;
	char* input = new char[7];
	while (running == true){
		cout << endl << "Enter 'ADD' to add an item." << endl //Prompt the user. 
			 << "Enter 'SEARCH' to search for an item." << endl 
			 << "Enter 'DELETE' to delete an item." << endl 
			 << "Enter 'QUIT' to end the program." << endl << endl;
		readInput(input);
		while (strcmp(input, "ADD") != 0 && strcmp(input, "SEARCH") != 0 &&
			   strcmp(input, "DELETE") != 0 && strcmp(input, "QUIT") != 0){
			cout << endl << "Please enter a valid command." << endl << endl;
      		readInput(input);
    	}
    	if (strcmp(input, "ADD") == 0) { //See which function to run.
      		add(pList);
    	}
    	else if (strcmp(input, "SEARCH") == 0) {
      		search(list);
    	}
    	else if (strcmp(input, "DELETE") == 0) {
      		del(pList);
    	}
    	else if (strcmp(input, "QUIT") == 0) {
      		running = quit();
    	}
	}
}

void add(vector<media*> *plist){ //Add an item. 
	char* input = new char[7];
	char* title = new char[80];
	int year;
	cout << endl << "Enter 'S' to add a song." << endl 
		 << "Enter 'M' to add a movie." << endl 
		 << "Enter 'G' to add a video game." << endl <<endl;

	readInput(input);
	while (strcmp(input, "S") != 0 && strcmp(input, "M") != 0 && strcmp(input, "G") != 0){
		cout << endl << "Please enter a valid command." << endl << endl;
      	readInput(input);
    }
    
    cout << endl;
    
    if (strcmp(input, "S") == 0){ //Add a song.
    	char* artist = new char[80];
    	char* publisher = new char[80];
    	char* duration = new char[80];
	
    	cout << "Enter the name of the song you would like to add." << endl;
    	cin >> title;
    	cin.ignore(80, '\n');
    	title = upperCase(title);
    	cout << endl << "Enter the year of release." << endl;
    	cin >> year;
    	cin.ignore(80, '\n');
    	cout << endl << "Enter the name of the artist." << endl;
    	cin >> artist;
    	cin.ignore(80, '\n');
    	cout << endl << "Enter the name of the publisher." << endl;
    	cin >> publisher;
    	cin.ignore(80, '\n');
    	cout << endl << "Enter the duration." << endl;
    	cin >> duration;
    	cin.ignore(80, '\n');
    	music* newMusic = new music(title, year, artist, publisher, duration);
    	counternew++;
    	cout << "new added" << endl;
    	plist->push_back(newMusic);
    	cout<< endl << "'"<< title << "' was added to your database." << endl;
    }
    else if (strcmp(input, "M") == 0){ //Add a movie.
    	char* director = new char[80];
    	char* duration = new char[80];
		double rating;
	
    	cout << "Enter the name of the movie you would like to add." << endl;
    	cin >> title;
    	cin.ignore(80, '\n');
    	title = upperCase(title);
    	cout << endl << "Enter the year of release." << endl;
    	cin >> year;
    	cin.ignore(80, '\n');
    	cout << endl << "Enter the name of the director." << endl;
    	cin >> director;
    	cin.ignore(80, '\n');
    	cout << endl << "Enter the duration." << endl;
    	cin >> duration;
    	cin.ignore(80, '\n');
    	cout << endl << "Enter the rating." << endl;
    	cin >> rating;
    	cin.ignore(80, '\n');
    	while (rating > 10 || rating < 0){
    		cout << "Movie must have a rating between 0 and 10." << endl;
    		cin >> rating;
    		cin.ignore(80, '\n');
    	}
    	movie* newMovie = new movie(title, year, director, duration, rating);
    	counternew++;
    	cout << "new added" << endl;
    	plist->push_back(newMovie);
    	cout<< endl << "'"<< title << "' was added to your database." << endl;    
    }
	else if (strcmp(input, "G") == 0) { //Add a video game.
		char* publisher = new char[80];
		double rating;
	
    	cout << "Enter the name of the game you would like to add." << endl;
    	cin >> title;
    	cin.ignore(80, '\n');
    	title = upperCase(title);
    	cout << endl << "Enter the year of release." << endl;
    	cin >> year;
    	cin.ignore(80, '\n');
    	cout << endl << "Enter the name of the publisher." << endl;
    	cin >> publisher;
    	cin.ignore(80, '\n');
    	cout << endl << "Enter the rating you would like to give it." << endl;
    	cin >> rating;
    	cin.ignore(80, '\n');
    	while (rating > 10 || rating < 0){
    		cout << "Game must have a rating between 0 and 10." << endl;
    		cin >> rating;
    		cin.ignore(80, '\n');
    	}
    	game* newGame = new game(title, year, publisher, rating);
    	counternew++;
    	cout << "new added" << endl;
    	plist->push_back(newGame);
    	cout<< endl << "'"<< title << "' was added to your database." << endl;
    }     
}

void search(vector<media*> list){ //Search for an item.
	char* input = new char[7];
	int counter = 0;
	
	cout << endl << "Enter 'T' to search your database by title." << endl 
		 << "Enter 'Y' to search your database by year." << endl << endl;
	readInput(input);
	while (strcmp(input, "T") != 0 && strcmp(input, "Y") != 0){
		cout << endl << "Please enter a valid command." << endl << endl;
      	readInput(input);
    }
    cout << endl;
    
	if (strcmp(input, "T") == 0){ //Search by title. 
		char* title = new char[80];
		cout << "Enter the title of the item you would like to search for." <<endl;
		cin >> title;
		cin.ignore(80, '\n');
		title = upperCase(title);
		cout << endl << "Here is the list of items entitled '" << title << "':" << endl;
		for (int i = 0; i < list.size(); i++) {
      		if (strcmp(title, list[i] -> getTitle()) == 0) {
        		if (list[i] -> getType() == 2) {
          			((music*) list[i]) -> printInfo();
          			counter++;
        		} else if (list[i] -> getType() == 1) {
          			((game*) list[i]) -> printInfo();
          			counter++;
        		} else if(list[i] -> getType() == 3) {
          			((movie*) list[i]) -> printInfo();
          			counter++;
        		}
      		}
    	}
    	if (counter ==0){
    		cout << endl << "List is empty." << endl;
    	}
	}
	else if (strcmp(input, "Y") == 0){ //Search by year.
		int year;
		cout << "Enter the year of release of the item you would like to search for." << endl;
		cin >> year;
		cin.ignore(80, '\n');
		cout << endl << "Here is the list of items released in " << year << ":" << endl << endl;
		for (int i = 0; i < list.size(); i++) {
      		if (year == list[i]->getYear()) {
        		if (list[i] -> getType() == 2) {
          			((music*) list[i]) -> printInfo();
          			counter++;
        		} else if (list[i] -> getType() == 1) {
          			((game*) list[i]) -> printInfo();
          			counter++;
        		} else if(list[i] -> getType() == 3) {
          			((movie*) list[i]) -> printInfo();
          			counter++;
        		}
      		}
    	}
    	if (counter ==0){
    		cout << endl << "List is empty." << endl;
    	}
	}
}

void del(vector<media*> *plist){ //Delete an item. 
	char* input = new char[7];
	char* yesno = new char[2];
	int counter = 0;
	int counter1 = 0;
	
	cout << endl << "Search for the item you want to delete." << endl
		 << "Enter 'T' to search your database by title." << endl 
		 << "Enter 'Y' to search your database by year." << endl << endl;
	readInput(input);
	while (strcmp(input, "T") != 0 && strcmp(input, "Y") != 0){
		cout << endl << "Please enter a valid command." << endl << endl;
      	readInput(input);
    }
    cout << endl;
    
	if (strcmp(input, "T") == 0){ //Delete by title. 
		char* title = new char[80];
		cout << "Enter the title of the item you would like to delete." <<endl;
		readInput(title);
		cout << endl << "This action will delete the following item(s):" << endl << endl;;
		for (int i = 0; i < plist->size(); i++) {
      		if (strcmp(title, plist->at(i) -> getTitle()) == 0) {
        		if (plist->at(i)->getType() == 2) {
          			((music*) plist->at(i)) -> printInfo();
          			counter1++;
        		} else if (plist->at(i)-> getType() == 1) {
          			((game*) plist->at(i)) -> printInfo();
          			counter1++;
        		} else if(plist->at(i) -> getType() == 3) {
          			((movie*) plist->at(i)) -> printInfo();
          			counter1++;
        		}
      		}
    	}
    	if (counter1 ==0){
    		cout << "List is empty." << endl;
    		cout << endl << "There is no item to delete." << endl;
    	}
    	else{
    		cout << endl <<"Are you sure you want to proceed?" << endl; //Confirm delete.
    		readInput(yesno);
    		while (strcmp(yesno, "Y") != 0 && strcmp(yesno, "N") != 0){
				cout << endl << "Enter 'Y' if you want to delete the items." << endl << "Enter 'N' if you do not." << endl;
      			readInput(yesno);
      		}
      		if (strcmp(yesno, "Y") == 0){
      			bool deleted = false;
      			while (deleted == false) {
      				deleted = true;
      				cout << endl << "You have deleted all items named " << title << " from your database." << endl;
      				for (vector<media*>::iterator i = plist->begin(); i != plist->end(); i++){
      					if (strcmp(title, (*i)->getTitle()) == 0){
      						if ((*i) -> getType() == 2) {
    							music* newMusic = (music*)(*i);					
    							if (strcmp(title, newMusic -> getTitle()) ==0){ //Delete songs.
    								delete (*plist->begin() + counter);
    								plist->erase(plist->begin() + counter);
    								deleted = false;
    								break;
    							}
    							else {
      								counter++;
    							}
  							}
      						if ((*i) -> getType() == 1) {
      							counter = 0;
    							game* newGame = (game*)(*i);					
    							if (strcmp(title, newGame -> getTitle()) ==0){ //Delete video games.
    								delete (*plist->begin() + counter);
    								plist->erase(plist->begin() + counter);
    								deleted = false;
    								break;
    							}
    							else {
      								counter++;
    							}
  							}
        					if ((*i) -> getType() == 3) {
        						counter = 0;
    							movie* newMovie = (movie*)(*i);					
    							if (strcmp(title, newMovie -> getTitle()) ==0){ //Delete movies.
    								delete (*plist->begin() + counter);
    								plist->erase(plist->begin() + counter);
    								
    								deleted = false;
    								break;
    							}
    							else {
      								counter++;
    							}
    						}
        				}
        			}
        		}
      		}
      	}
    }
	else if (strcmp(input, "Y") == 0){ //Delete by year.
		int year;
		cout << "Enter the year of release of the item you would like to delete." <<endl;
		cin >> year;
		cin.ignore(80, '\n'); 
		cout << "This action will delete the following item(s):" << endl;
		for (int i = 0; i < plist->size(); i++) {
      		if (year == plist->at(i)->getYear()){
        		if (plist->at(i) -> getType() == 2) {
          			((music*) plist->at(i)) -> printInfo();
          			counter1++;
        		} else if (plist->at(i) -> getType() == 1) {
          			((game*) plist->at(i)) -> printInfo();
          			counter1++;
        		} else if(plist->at(i) -> getType() == 3) {
          			((movie*) plist->at(i)) -> printInfo();
          			counter1++;
        		}
      		}
    	}
    	if (counter1 ==0){
    		cout << "List is empty." << endl;
    		cout << endl << "There is no item to delete." << endl;
    	}
    	else {
    		cout << "Are you sure you want to proceed?" << endl; //Confirm delete.
    		readInput(yesno);
    		while (strcmp(yesno, "Y") != 0 && strcmp(yesno, "N") != 0){
				cout << endl << "Enter 'Y' if you want to delete the items." << endl << "Enter 'N' if you do not." << endl;
      			readInput(yesno);
      		}
      		if (strcmp(yesno, "Y") == 0){
      			bool deleted = false;
      			while (deleted == false) {
      				deleted = true;
      				cout << endl << "You have deleted all items released in " << year << " from your database." << endl;
      				for (vector<media*>::iterator i = plist->begin(); i != plist->end(); i++){
      					if (year == (*i)->getYear()) {
      						if ((*i) -> getType() == 2) {
    							music* newMusic = (music*)(*i);					
    							if (year == newMusic->getYear()){ //Delete songs.
    								delete (*plist->begin() + counter);
    								plist->erase(plist->begin() + counter);
    								deleted = false;
    								break;
    							}
    							else {
      								counter++;
    							}
  							}
      						if ((*i) -> getType() == 1) {
      							counter = 0;
    							game* newGame = (game*)(*i);					
    							if (year == newGame->getYear()){ //Delete video games.
    								delete (*plist->begin() + counter);
    								plist->erase(plist->begin() + counter);
    								deleted = false;
    								break;
    							}
    							else {
      								counter++;
    							}
  							}
        					if ((*i) -> getType() == 3) {
        						counter = 0;
    							movie* newMovie = (movie*)(*i);					
    							if (year == newMovie -> getYear()){ //Delete movies.
    								delete (*plist->begin() + counter);
    								plist->erase(plist->begin() + counter);
    								
    								deleted = false;
    								break;
    							}
    							else {
      								counter++;
    							}
    						}
        				}
        			} 
        		}
      		}
      	}
	}
}
	
bool quit(){ //End program.
	return false;
}

char* upperCase(char input[80]) { //Turns input into upper case.
	for (int i = 0; i < strlen(input); i++){
    	input[i] = toupper(input[i]);
	}
	return input;
}

void readInput(char input[7]){ //Turns input into upper case and reads it.
  cin.getline(input, 80);
  upperCase(input);
}