#ifndef CHARACTER_H
#define CHARACTER_H

#include "equip.hpp"

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



class Player : public Character{
public:
    void equip(Equip* equipment){
	int atk = 0;
	
    }
};

class Boss : public Character{
public:
    
};


#endif
