#include "weapon.h"
#include "text.h"
#include "colors.h"

#include <iostream>
#include <string>

using namespace std;

Weapon::Weapon(string name, int weapondmg) : Item(name), weapondmg(weapondmg) {}

void Weapon::use(Entity& e)
{
    e.setbonusdmg(weapondmg);
    cout<<YELLOW;
    string s="You equipped "+name+". DMG increased by "+to_string(weapondmg)+".";
    writetext(s);
    cout<<WHITE;
}

int Weapon::getweapondmg() const
{
    return weapondmg;
}