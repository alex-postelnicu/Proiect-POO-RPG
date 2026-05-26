#ifndef ENEMY_H
#define ENEMY_H

#include "entity.h"
#include "text.h"
#include "item.h"

#include <iostream>
#include <string>

using namespace std;

class Enemy : public Entity
{
private:
    Item* loot=nullptr;

public:
    Enemy(const string& name, int hp, int dmg);
    Enemy();
    Enemy(const Enemy& e);
    ~Enemy();

    Item* steal();
    void setloot(Item* i);
    bool hasloot() const;
};

#endif
