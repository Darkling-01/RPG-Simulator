#include <iostream>
#include <string>
#include <new>

#include "character.hpp"
#include "equip.hpp"


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


void characterClass(int rpg_class){
    Staff* staff = new Staff();
    Book_Spells* book_spells = new Book_Spells();
    Sword* sword = new Sword();    
    Shield* shield = new Shield();

    Menu staff_menu(staff);
    Menu book_menu(book_spells);
    Menu sword_menu(sword);
    Menu shield_menu(shield);
    
    
    do{
    switch(rpg_class){
      case 1:
	cout << "Staff (DPS:" << staff_menu.item_bonus() << " DEF:" << staff_menu.item_defense() << ")" << endl; 
	break;
      case 2:
        cout << "Book of Spells (DPS:" << book_menu.item_bonus() << " DEF:" << book_menu.item_defense() << ")" << endl;
	break; 
      case 3:
	cout << "Sword (DPS:" << sword_menu.item_bonus() << " DEF:" << sword_menu.item_defense() << ")" << endl;
	break;
      case 4:
	cout << "Shield (DPS:" << shield_menu.item_bonus() << " DEF:" << shield_menu.item_defense() << ")" << endl;
	break;
      default:
        LOG("Wrong Input")
	break;
    }
}




int main() 
{      
    int rpg_class;

    do{
    LOG("WELCOME TO RPG-SIMULATOR")
    LOG("Choose a Weapon:\n1 - Game\n2 - Story\n3 - Exit\n")
    std::cin >> rpg_class;
    
    characterClass(rpg_class);
    } while(rpg_class == 'Y' || rpg_class == 'y');
    return 0;
}
