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
           int atk = 5;
           std::cout << "damage: " << atk << std::endl;
           return atk;
	}
	int get_defense_bonus(){
	   int def = 16;
	   return def;
	}
};

class Book_Spells : public Equip{
public:
	int get_attack_bonus(){
	    int atk = 6;
	    return atk;
	}
	int get_defense_bonus(){
	    int def = 15;
	    return def;
	}
};

class Shield : public Equip{
public:
	int get_attack_bonus(){

	    int atk = 13;
	    return atk;
	}
	int get_defense_bonus(){
	    int def = 30;
	    return def;
	}
};

class Sword : public Equip{
public:
	int get_attack_bonus(){
	    int atk = 27;
	    return atk;
	}
	int get_defense_bonus(){
	    int def = 18;
	    return def;
	}
};

//intended for boss
class boss : public Equip{
public:
	int get_attack_bonus(){
	    int atk = 28;
	    return atk;
	}
	int get_defense_bonus(){
	    int def = 24;
	    return def;
	}

};


#endif
