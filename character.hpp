#ifndef CHARACTER_H
#define CHARACTER_H

#include "equip.hpp"
#include <iostream>

using std::cout;
using std::endl;


class Character {
private:
    int atk;
    int def;
    int hp;

public:

    virtual void equip(Equip* equipment) = 0;
    virtual void attack(Character* target) {};
    virtual void special() = 0;

    void set_attack(int new_atk){ atk = new_atk; } 
    int get_attack() { return atk; }

    void set_defense(int new_def){ def = new_def; } 
    int get_defense(){ return def; }

    void set_hp(int new_hp){ hp = new_hp; }
    int get_hp() { return hp; }

};



class Player : public Character{

private:
    Equip* currentEquipment;

public: 

    void equip(Equip* equipment) override{
	currentEquipment = equipment;
	set_attack(currentEquipment->get_attack_bonus());
        set_defense(currentEquipment->get_defense_bonus());

    }

    void attack(Character* target) override{	
	bool enemy;  // logic to determine if target is enemy
	int updateHealth;

	if(enemy){
	   updateHealth = target->get_hp() - target->get_attack();
	   // apply damage to target
	   target->set_hp(updateHealth);
	   cout << updateHealth << endl;
	}

    }

    void special() override {
	std::cout << "Defualt Implementation\n";
    }

};



class Boss : public Character{

private:
     Equip* currentEquipment;

public:

    void equip(Equip* equipment) override{
	currentEquipment = equipment;
	set_attack(currentEquipment->get_attack_bonus());
	set_defense(currentEquipment->get_defense_bonus());	
   
   }
    //overloading function
    // equip 'sythe' weapon to boss
    void equip(){
	Equip* sythe = new Sythe();
	equip(sythe);

	delete sythe;
    }
   
    void attack(Character* target) override{
	bool enemy;
	int updateHealth;
        equip();

	if(enemy){
	   updateHealth = target->get_hp() - get_attack();
	   target->set_hp(updateHealth);
	   cout << updateHealth << endl;
	}
    }

    void special() override{
        //special attacks go here
	std::cout << "Defualt Implementation\n";
    }

};


#endif
