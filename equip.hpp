#ifndef EQUIP_HPP
#define EQUIP_HPP

#include <iostream>


class Equip {
public:
    virtual int get_attack_bonus() const = 0;		//pure virtual function
    virtual int get_defense_bonus() const = 0;		//pure virtual function
};

//intended for player
class Staff : public Equip{
public :
    // override - overriding virtual method of the base class and
    // not altering or adding new methods
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
        return 20;
    }
    int get_defense_bonus() const override{
        return 17;
    }
};

//intended for boss
class Sythe : public Equip{
public:
    int get_attack_bonus() const override{
        return 26;
    }
    int get_defense_bonus() const override{
        return 20;
    }

};


#endif
