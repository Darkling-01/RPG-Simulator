#ifndef CHARACTER_H
#define CHARACTER_H

#include "equip.hpp"
#include <iostream>

int get_attack_bonus();
int get_defense_bonus();



class Character {

private:
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
    void set_attack(int atk){
	atk = atk;
    }

    int get_defense() {
        return def;
    }
    void set_defense(int def){
	def = def;
    }

    int get_hp() {
        return hp;
    }
    void set_hp(int hp){
	hp = hp;
    }

};



class Player : public Character{

private:
    Equip* currentEquipment;


public:

    virtual void equip(Equip* equipment) override{
	set_attack(currentEquipment->get_attack_bonus());
        set_defense(currentEquipment->get_defense_bonus());
    }

    virtual void attack(character* target) override{
	bool enemy;  // logic to determine if target is enemy

	if(enemy){
	   int updateHealth = target->get_hp() - get_attack();
	   // apply damage to target
	   target->set_hp(updateHealth);
	}

    }

};



class Boss : public Character{

public:
    //Boss already has weapon equip
    virtual void equip(Equip* equipment){
	//code here
    }
    virtual void attack(Character* target){
	
	bool enemy = target;
	set_attack(get_attack_bonus());
	set_hp(250);
    }    

};


#endif
