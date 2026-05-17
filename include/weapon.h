#ifndef WEAPON_H
#define WEAPON_H

#include "item.h"
#include "entity.h"
#include "colors.h"
#include "text.h"

#include <iostream>
#include <string>

using namespace std;

class Weapon : public Item
{
private:
    int weapondmg;

public:
    Weapon(string name, int weapondmg);

    void use(Entity& e);
    int getweapondmg() const;

};

#endif
