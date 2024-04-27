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
public:
    virtual void equip(Equip* equipment){
	//code here
    }
    virtual void attack(Character* target){

	//bool enemy = target.. must be fixed..
	bool enemy = target;
	
        int updateHealth;
	set_attack(get_attack_bonus());
	set_hp(100);

	//change if statement to when player attacks boss it will return true...
	//parameters make no sense..
	if(enemy == true){
	   updateHealth = get_hp() - get_attack();
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
