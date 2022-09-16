#ifndef EQUIP_H
#define EQUIP_H

class Equip {
public:
    virtual int get_attack_bonus() = 0;
    virtual int get_defense_bonus() = 0;
};

#endif