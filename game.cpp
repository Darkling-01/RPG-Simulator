#include <iostream>
#include <string>

#include "character.hpp"
#include "equip.hpp"


using std::cout;
using std::endl;
using std::string;


void fight();


void dungeonDirection(){
    // this function will give a random direction to the player
    // depending on the direction the player will have a possibility to find a  target
    
    Boss boss;

    int isFound, target;

    // initalized random seed
    srand(time(NULL));

    // if both match then enemy is found
    isFound = rand() % 6 + 1;
    target = rand() % 6 + 1;

    if(target == isFound){
	boss.stats();
	fight();
    }
    else{
	cout << "\n\nEmpty Area\n\n" << endl;
    }


}


void fight(){
    // when enemy is found, player can fight or run away...
    string response;
    cout << "Do you want to fight or run away?\n";
    std::cin >> response;

    if(response == "fight"){
	cout << "fight...\n";
    }
    else if(response == "run"){ cout << "Escaped!" << endl; }

}


void playGame(){

    char response;
    cout << "--------------------------------------------" << endl;
    cout << "|            Welcoome Adventure            |" << endl;;

    while(response != 'q' && response != 'Q'){

	cout << "--------------------------------------------" << endl;
	cout << "|     Chose a path within the dungeon.     |" << endl;
	cout << "|    (press 'q' or 'Q' to quit program)    |" << endl;
	cout << "--------------------------------------------" << endl;
        cout << "r = Right OR l = Left: ";
	std::cin >> response;

	if(response == 'l'){ 
	   dungeonDirection(); 
         }
	else if(response == 'r'){
	   dungeonDirection();
	}
	else if(response == 'q' || response == 'Q') { break; }

        else{cout << "\n\nInvalid. Try Again\n\n";}

    }
    

}

