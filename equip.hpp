#ifndef EQUIP_HPP
#define EQUIP_HPP

#include <iostream>

class Equip {
public:
    virtual int get_attack_bonus() = 0;		//pure virtual function
    virtual int get_defense_bonus() = 0;	//pure virtual function
};

//intended for player
class Staff : public Equip{
public :
        int get_attack_bonus(){
           int attack = 5;
           std::cout << "damage: " << attack << std::endl;
        }
	int get_defense_bonus(){
	   int defense = 16;
	}
};

class Book_Spells : public Equip{
	int get_attack_bonus(){
	    int attack = 6;
	}
	int get_defense_bonus(){
	    int defense = 15;
	}
};

class Shield : public Equip{
	int get_attack_bonus(){
	    int attack = 13;
	}
	int get_defense_bonus(){
	    int defense = 30;
	}
};

class Sword : public Equip{
	int get_attack_bonus(){
	    int attack = 27;
	}
	int get_defense_bonus(){
	    int defense = 18;
	}
};

//intended for boss



#endif
