#ifndef CHARACTER_H
#define CHARACTER_H

#include "equip.hpp"
#include <iostream>

int get_attack_bonus();
int get defense_bonus();

class Character {
    int atk;
    int def;
    int hp;

public:
    virtual void equip(Equip* equipment) = 0;
    virtual void attack(Character* target);
    virtual void special() = 0;

    int get_attack() {
        return atk;
    }

    int get_defense() {
        return def;
    }

    int get_hp() {
        return hp;
    }

};


//testing player
class Player : public Character{
public:
    virtual void equip(Equip* equipment){
	//code here
    }
    virtual void attack(Character* target){
	int damage = get_attack_bonus();
	std::cout << "Damage done = " << damage << std::endl;
    }
};

class Boss : public Character{
public:
    virtual void attack(Character* target){

    }    

};


#endif
