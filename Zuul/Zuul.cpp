/* Zuul
 * Author: Nour Yehia
 * Date: 12-3-17
 * This program allows the user to play a text-based adventure games. */

//Includes.
#include "board.h"
#include "player.h"


void readInput(char input[6]); //Declare readInput.

int main() {

	//Declare variables.
	char input[80];
	char command[10];
	bool win = false;
	bool lose = false;
	int moveCount = 0;

	//Create rooms.
	room onetwenty((char*)"in 1-20. ", (char*)"All the cool people hang out here.", (char*)"1-20");
	room studentstore((char*)"in the student store. ", (char*)"Why is the cashier on his phone?", (char*)"student store");
	room library((char*)"in the library. ", (char*)"Eat at your own risk.", (char*)"library");
	room courtyard((char*)"in the courtyard. ", (char*)"It's not very dry.", (char*)"courtyard");
	room tenniscourts((char*)"at the tennis courts. ", (char*)"The season doesn't start until May.", (char*)"tennis courts");
	room roboticslab((char*)"in the robotics lab. ", (char*)"What are all these wires for?", (char*)"robotics lab");
	room mainoffice((char*)"in the main office. ", (char*)"The staff seems to be very busy today.", (char*)"main office");
	room commons((char*)"in the commons. ", (char*)"It's way too loud to study.", (char*)"commons");
	room cafeteria((char*)"in the cafeteria. ", (char*)"Sadly you can't buy food until lunch time.", (char*)"cafeteria");
	room parkinglot((char*)"in the parking lot. ", (char*)"Make sure you have a pass to park.", (char*)"parking lot");	
	room gym((char*)"in the gym. ", (char*)"Are they setting up for an assembly?", (char*)" gym");
	room weightroom((char*)"in the weight room. ", (char*)"Look at all the football players!", (char*)"weight room");
	room baseballfield((char*)"at the baseball field. ", (char*)"Wait... How do you play this sport again?", (char*)" baseball field");
	room footballfield((char*)"at the football field. ", (char*)"Look at the brand new grass!", (char*)"football field");
	room track((char*)"at the the track. ", (char*)"People are running.", (char*)"track");

	//Set exits.
	onetwenty.setExit(NORTH, &studentstore); //1-20.
	onetwenty.setExit(EAST, &courtyard);
	onetwenty.setExit(SOUTH, &roboticslab);
	onetwenty.setExit(WEST, &cafeteria);
	studentstore.setExit(NORTH, &library); //Student store.
	studentstore.setExit(SOUTH, &onetwenty);
	studentstore.setExit(WEST, &commons);
	library.setExit(SOUTH, &studentstore); //Library.
	library.setExit(WEST, &mainoffice);
	courtyard.setExit(SOUTH, &tenniscourts); //Courtyard.
	courtyard.setExit(WEST, &onetwenty);
	tenniscourts.setExit(NORTH, &courtyard); //Tennis courts.
	roboticslab.setExit(NORTH, &onetwenty); //Robotics lab.
	mainoffice.setExit(EAST, &library); //Main office.
	mainoffice.setExit(SOUTH, &commons);
	commons.setExit(NORTH, &mainoffice); //Commons.
	commons.setExit(EAST, &studentstore);
	commons.setExit(SOUTH, &commons);
	commons.setExit(WEST, &parkinglot);
	cafeteria.setExit(NORTH, &commons); //Cafeteria.
	cafeteria.setExit(EAST, &onetwenty);
	cafeteria.setExit(WEST, &gym);
	parkinglot.setExit(EAST, &commons); //Parking lot.
	parkinglot.setExit(SOUTH, &gym);
	parkinglot.setExit(WEST, &footballfield);
	gym.setExit(NORTH, &parkinglot); //Gym.
	gym.setExit(EAST, &cafeteria);
	gym.setExit(SOUTH, &weightroom);
	gym.setExit(WEST, &track);
	weightroom.setExit(NORTH, &gym); //Weight room.
	baseballfield.setExit(SOUTH, &footballfield); //Baseball field.
	footballfield.setExit(NORTH, &baseballfield); //Football field.
	footballfield.setExit(EAST, &parkinglot); 
	footballfield.setExit(SOUTH, &track);
	track.setExit(NORTH, &footballfield); //Track.
	track.setExit(EAST, &gym);

	//Add rooms to map. 
	board schoolMap;
	schoolMap.addRoom(onetwenty);
	schoolMap.addRoom(studentstore);
	schoolMap.addRoom(library);
	schoolMap.addRoom(courtyard);
	schoolMap.addRoom(tenniscourts);
	schoolMap.addRoom(roboticslab);
	schoolMap.addRoom(mainoffice);
	schoolMap.addRoom(commons);
	schoolMap.addRoom(cafeteria);
	schoolMap.addRoom(parkinglot);
	schoolMap.addRoom(gym);
	schoolMap.addRoom(weightroom);
	schoolMap.addRoom(baseballfield);
	schoolMap.addRoom(footballfield);
	schoolMap.addRoom(track);

	//Scatter items across the map. 
	cafeteria.add(item((char*)"Book"));
	footballfield.add(item((char*)"Book"));
	studentstore.add(item((char*)"Book"));
	weightroom.add(item((char*)"Book"));
	tenniscourts.add(item((char*)"Book"));

	player p(&onetwenty); //Create player.

	//Print out intro.
	cout << endl << "Welcome to ZUUL!"
		 << endl << endl << "A student has lost five books in various rooms. Find them and drop them in the library to win the game."
		 << endl << "You lose the game if you move more than 30 times in order to do so."
		 << endl << endl << "Commands:"
		 << endl << "Enter 'MOVE' to take an exit." 
		 << endl << "Enter 'PICK' to put an item from the room in your inventory." 
		 << endl << "Enter 'DROP' to put an item from your inventory in a room"
		 << endl << "Enter 'PRINT' to print your inventory." << endl; 

	while (!win && !lose){ //While no end game conditions are met.
		p.getCurrentRoom()->print(); //Print initial description.

		readInput(command); 
		while (strcmp(command, "MOVE") != 0 && strcmp(command, "PICK") != 0 && //Make sure input is valid. 
	   		   strcmp(command, "DROP") != 0 && strcmp(command, "PRINT") != 0){
      		cout << endl << "Please enter a valid command." << endl << endl;
      		readInput(command);
    	}

    	if (strcmp(command, "MOVE") == 0){ //If user moves.
    		cout << endl << "Which exit would you like to take?" << endl << endl;
    		readInput(input); 
    		while (strcmp(input, "NORTH") != 0 && strcmp(input, "EAST") != 0 && //Make sure input is valid. 
	   		   	strcmp(input, "SOUTH") != 0 && strcmp(input, "WEST") != 0){
      			cout << endl << "Please enter a valid command." << endl << endl;
      			readInput(input);
    		}

    		if(strcmp(input, "NORTH") == 0){ //If user goes north.
				p.move(NORTH);
				moveCount++;
			}
			else if(strcmp(input, "EAST") == 0){ //If user goes east.
				p.move(EAST);
				moveCount++;
			}
			else if(strcmp(input, "SOUTH") == 0){ //If user goes south.
				p.move(SOUTH);
				moveCount++;
			}
			else if(strcmp(input, "WEST") == 0){ //If user goes west.
				p.move(WEST);
				moveCount++;
			}
    	}
    	else if (strcmp(command, "PICK") == 0){ //If user picks an item.
    		if (p.getCurrentRoom()->numBooks() == 0) { //If there are no items in room.
    			cout << endl << "There are no items to be picked." << endl;
    		}
    		else {
    			p.pick((char*)"Book");
    			cout << endl << "You have picked up a book." << endl;
    		}
    	}
    	else if (strcmp(command, "DROP") == 0){ //If user drops an item.
  			if (p.numBooks() == 0){
  				cout << endl << "Your inventory is empty." << endl;
  			}
  			else{
  				p.drop((char*)"Book");
  				cout << endl << "You have dropped a book." << endl;
  			}
    	}
    	else if (strcmp(command, "PRINT") == 0){ //if user prints inventory. 
    		p.print(p);
    	}


		if (moveCount > 30) { //Loss.
			cout << endl <<  "You took more than 30 turns. You lost :(" << endl << endl;
			lose = true;
		}

		if(library.numBooks()>=5){ //Win.
			cout << endl << "Congratulations! You Won!" << endl << endl ;
			win=true;
		}
	}
}

void readInput(char input[6]){ //Turns input to upper case. 
  cin >> input;
  for (int i = 0; i < strlen(input); i++){
    input[i] = toupper(input[i]);
  }
}