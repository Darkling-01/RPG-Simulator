#ifndef CHARACTER_H
#define CHARACTER_H

#include "equip.hpp"
#include <iostream>


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

	if(enemy){
	   int updateHealth = target->get_hp() - get_attack();
	   // apply damage to target
	   target->set_hp(updateHealth);
	}

    }

    void special() override {
	std::cout << "Defualt Implementation\n";
    }

};



class Boss : public Character{

private:
     int hp = 250;
     Equip* currentEquipment;

public:
    virtual void equip(Equip* equipment) override{
 	//TODO equip weapon here
	currentEquipment = equipment;
	//set_attack(currentEquipment->get_attack_bonus);
    }
    
    virtual void attack(Character* target) override{
	//TODO implement damage and attack moves here
    }

    void stats(){
	Sythe sythe;
        set_hp(hp);
	std::cout << "\n\nBoss Health: " << get_hp() << "\n" << std::endl;
    	std::cout << "attack bonus: " << sythe.get_attack_bonus() << std::endl;
	std::cout << "defense bonus: " << sythe.get_defense_bonus() << "\n" << std::endl;
    }

    virtual void special() override{
        //special attacks go here
	std::cout << "Defualt Implementation\n";
    }

};


#endif
