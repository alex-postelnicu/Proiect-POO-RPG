#ifndef ENEMY_FACTORY_H
#define ENEMY_FACTORY_H

#include "enemy.h"

#include <iostream>
#include <string>

using namespace std;

class Enemy_Factory
{
    //factory
public:
    static Enemy* create_enemy(const string& search_name);
};

#endif 
