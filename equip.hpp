#ifndef EQUIP_HPP
#define EQUIP_HPP

#include <iostream>

class Equip {
public:
    virtual int get_attack_bonus() const = 0;		//pure virtual function
    virtual int get_defense_bonus() const = 0;	//pure virtual function
};

//intended for player
class Staff : public Equip{
public :
        int get_attack_bonus() const override{
           return 15;
	}
	int get_defense_bonus() const override{
	   return 16;
	}
};

class Book_Spells : public Equip{
public:
	int get_attack_bonus() const override{
	    return 16;
	}
	int get_defense_bonus() const override{
	    return 15;
	}
};

class Shield : public Equip{
public:
	int get_attack_bonus() const override{
	    return 13;
	}
	int get_defense_bonus() const override{
	    return 30;
	}
};

class Sword : public Equip{
public:
	int get_attack_bonus() const override{
	    return 27;
	}
	int get_defense_bonus() const override{
	    return 18;
	}
};

//intended for boss
class sythe : public Equip{
public:
	int get_attack_bonus() const override{
	    return 28;
	}
	int get_defense_bonus() const override{
	    return 24;
	}

};


#endif
