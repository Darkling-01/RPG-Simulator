#include <iostream>
#include <string>

#include "character.hpp"
#include "equip.hpp"


using std::cout;
using std::endl;
using std::string;


void dungeonDirection(){
    // depending on the direction the player will find enemy 
    // or find an empty cave and continue roaming...
    cout << "just wait" << endl;
    

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

