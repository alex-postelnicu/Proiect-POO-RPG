#ifndef FIGHT_H
#define FIGHT_H

#include "player.h"
#include "enemy.h"

#include <iostream>
#include <string>
#include <deque>
#include <random>

using namespace std;

class Fight
{
    //singleton
private:
    Fight()=default;
    ~Fight()=default;
    Fight(const Fight&)=delete;
    Fight& operator=(const Fight&)=delete;

public:
    static Fight& getinstance();
    bool battle(Player& p, Enemy& e);

};


#endif 
