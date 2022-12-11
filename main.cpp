#include <iostream>
#include <string>
#include <new>

#include "character.hpp"
#include "equip.hpp"


//macros

#define LOG(x) std::cout << x << std::endl;

int main() {

    int rpg_Class;

    Equip* staff = new Staff();
    Equip* book_spells = new Book_Spells();
    Equip* shield = new Shield();
    Equip* sword = new Sword();

    LOG("Welcome to the RPG Sim.")
    LOG("Choose your class")
    LOG("1 - Mage \n2 - Healer \n3 - Tank \n4 - Warrior")

    std::cin >> rpg_Class;

    switch(rpg_Class){
        case 1:
            LOG("Available Weapon: \nStaff")
            staff -> get_attack_bonus();
            break;
        case 2:
            LOG("Available Weapon: \nBook of Spells")
            break;
        case 3:
            LOG("Available Weapon: \nShield")
            break;
        case 4:
            LOG("Available Weapon: \nSword")
            break;
        default:
            break;
     }

}
