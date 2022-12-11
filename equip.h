#ifndef EQUIP_H
#define EQUIP_H

class Equip {
public:
    virtual int get_attack_bonus() = 0;
    virtual int get_defense_bonus() = 0;
};

//intended for boss
class Sythe : public Equip{
    
};

//intended for player
class fireSword : public Equip{

};

class Sword : public Equip{

};


#endif