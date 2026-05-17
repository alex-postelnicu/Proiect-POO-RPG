#include "consumable.h"
#include "text.h"
#include "colors.h"

#include <iostream>
#include <string>

using namespace std;

Consumable::Consumable(string name, int heal) : Item(name), heal(heal) {}

bool Consumable::isconsumable() const
{
    return true;
}

void Consumable::use(Entity& e)
{
    e+=heal;
    cout<<GREEN;
    string s="You used "+name+". HP restored by "+to_string(heal)+".";
    writetext(s);
    cout<<WHITE;
}