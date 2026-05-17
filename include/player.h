#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"
#include "text.h"
#include "inventory.h"
#include "item.h"
#include "exceptions.h"

#include <iostream>
#include <string>

using namespace std;

class Player : public Entity
{
private:
    Inventory<Item*>inv;

public:
    Player(string name, int hp, int dmg);
    Player();

    void take_item(Item* i); //add in inv
    void use_item(int i);
    void open_inv();

};

#endif