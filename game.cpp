#include <iostream>
#include <string>

#include "character.hpp"
#include "equip.hpp"


using std::cout;
using std::endl;
using std::string;


void dungeonDirection(){
    // this function will give a random direction to the player
    // depending on the direction the player will have a possibility to find a  target
    
    Boss boss;

    int isFound, target;

    // initalized random seed
    srand(time(NULL));

    // if both match then enemy is found
    isFound = rand() % 4 + 1;
    target = rand() % 4 + 1;

    if(target == isFound){
	boss.stats();
    }
    else{
	cout << "Empty Area" << endl;
    }


}


int fight(){
    // when enemy found, player can fight or run away...

}


void playGame(){

    char response;

    cout << "Welcoome adventure. ";

    while(response != 'q' && response != 'Q'){

	cout << "Chose a path within the dungeon..(press 'q' or 'Q' to quit program)";
	cout << endl;
        cout << "Right = r\nLeft = l" <<endl;
	std::cin >> response;

	if(response == 'l'){ 
	   dungeonDirection(); 
         }
	else if(response == 'r'){
	   dungeonDirection();
	}
	else if(response == 'q' || response == 'Q') { break; }

        else{cout << "Invalid";}

    }
    

}

