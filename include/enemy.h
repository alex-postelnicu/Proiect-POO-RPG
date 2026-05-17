#ifndef ENEMY_H
#define ENEMY_H

#include "entity.h"
#include "text.h"

#include <iostream>
#include <string>

using namespace std;

class Enemy : public Entity
{
public:
    Enemy(string name, int hp, int dmg);
    Enemy();
    Enemy(const Enemy& e);

};

#endif
