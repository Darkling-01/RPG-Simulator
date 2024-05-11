#include <iostream>
#include <string>

#include "character.hpp"
#include "equip.hpp"


using std::cout;
using std::endl;
using std::string;

constexpr int PLAYER_HEALTH = 100;
constexpr int BOSS_HEALTH = 200;


void fight();
void boss_stats();
int main();


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
	boss_stats();
	fight();
    }
    else{
	cout << "\n\nEmpty Area\n\n" << endl;
    }


}
void boss_stats(){
    Boss boss;
    boss.set_hp(BOSS_HEALTH);
    Sythe sythe;

    cout << "\nHealth: " << boss.get_hp() << endl;
    cout << "attack bonus: " << sythe.get_attack_bonus() << endl;
    cout << "defense bonus: " << sythe.get_defense_bonus() << "\n" << endl;

}



void fight(){
    // when enemy is found, player can fight or run away...
    Player player;
    Boss boss;

    // setting the health to player and enemy
    player.set_hp(PLAYER_HEALTH);
    boss.set_hp(BOSS_HEALTH);
 
    
    string response;
    int hit;

    do{
    boss.attack(&player);
    player.attack(&boss);

    cout << "Do you want to fight or run away?\n";
    std::cin >> response;

    if(response == "fight"){

	cout << "################" << endl;	
	cout << "Player Health: " << player.get_hp() << endl;
	cout << "Boss Health: " << boss.get_hp() << endl;
        cout << "################" << endl;

    }

    else if(response == "run"){ 

	srand(time(NULL));
	hit = rand() % 2 + 1;

	if (hit == 1){ 
	   cout << "\n-> Damage took when escaping: " << player.get_hp()  << endl;
        }
	
	else{ cout << "\n-> Took no damage when escaping." << endl; }
      }

   }while(player.get_hp() > 0 && player.get_hp() > 0 && response != "run");


    if(player.get_hp() <= 0){ cout << "Game Over! You Died!" << endl; main();}

    else if(boss.get_hp() <= 0){ cout << "Congrats! You Defeated the Boss!" << endl;}

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

