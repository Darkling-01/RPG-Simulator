#include <iostream>
#include <string>
#include <new>
#include <fstream>


#include "character.hpp"
#include "equip.hpp"
#include "game.cpp"



//macros

#define LOG(x) std::cout << x << std::endl;


using std::cout;
using std::endl;
using std::string;


class Menu{
private:
   
    Equip* equip;   //declare a pointer to equip

public:
    // contructor initializes the equip pointer
    Menu(Equip* item) : equip(item) {}
    
    //descontructor deletes dynamically allocated memory. Prevents memory leaks
    ~Menu() {
	delete equip;
     }

    int item_bonus() const{
      // check if equip is valid before accessing member
      if(equip){
        return equip->get_attack_bonus();
       }
      else{return 0;}  // or handles the situation differently
    
     }

    int item_defense() const{
      if(equip){
	return equip->get_defense_bonus();
      }
      else{return 0;}
     }
           

};


void characterClass(){
    Player player;

    int response;
    char changeInput;

    Staff* staff = new Staff();
    Book_Spells* book_spells = new Book_Spells();
    Sword* sword = new Sword();    
    Shield* shield = new Shield();

    Menu staff_menu(staff);
    Menu book_menu(book_spells);
    Menu sword_menu(sword);
    Menu shield_menu(shield);

    Equip* chosenWeapon = nullptr;

    do{
    LOG("--------------------------------------------")
    LOG("|            Choose Your Class             |")
    LOG("|    1-Staff  2-Book  3-Sword  4-Shield    |")
    LOG("--------------------------------------------")

    std::cin >> response;
    
    switch(response){
      case 1:
	cout << "Staff (DPS:" << staff_menu.item_bonus() << " DEF:" << staff_menu.item_defense() << ")" << endl;
	chosenWeapon = staff;
	break;
      case 2:
        cout << "Book of Spells (DPS:" << book_menu.item_bonus() << " DEF:" << book_menu.item_defense() << ")" << endl;
	chosenWeapon = book_spells;	
	break; 
      case 3:
	cout << "Sword (DPS:" << sword_menu.item_bonus() << " DEF:" << sword_menu.item_defense() << ")" << endl;
	chosenWeapon = sword;
	break;
      case 4:
	cout << "Shield (DPS:" << shield_menu.item_bonus() << " DEF:" << shield_menu.item_defense() << ")" << endl;
	chosenWeapon = shield;
	break;
      case 5:
      default:
        LOG("Invalid Input")
	break;
      }
     LOG("Do you want to pick a differnt class?(Y/N)")
     std::cin >> changeInput;
    }while(changeInput == 'Y' || changeInput == 'y');
    

    //equips weapon to player in class 
    player.equip(chosenWeapon);

    if(changeInput == 'N' || changeInput == 'n'){
	// 'playGame()' comes from game.cpp
	playGame();
    }else{LOG("Invalid Input")} 

}


void gameStory(){
   // open the file "story.txt" for reading
   std::ifstream inputFile("story.txt");

   // variable to store each line from the file
   string line;

   while(std::getline(inputFile, line)){

      cout << line << endl;
    }

  inputFile.close();

}


int main() 
{  
    int rpg_class;
    
    LOG("--------------------------------------------")
    LOG("|         WELCOME TO RPG-SIMULATOR         |")
    LOG("|     Options: 1-Game  2-Story  3-Exit     |")
    LOG("--------------------------------------------")
    std::cin >> rpg_class;

    switch(rpg_class){
      case 1:
	characterClass();
	break;
      case 2:
	gameStory();
	cout << endl;
	main();
	break;
      case 3:
	exit(0);
     }
    
    return 0;
}
