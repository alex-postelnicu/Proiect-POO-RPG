#include "enemy.h"
#include "colors.h"

#include <iostream>
#include <string>

using namespace std;

Enemy::Enemy(const string& name, int hp, int dmg) : Entity(name, hp, dmg) {}

Enemy::Enemy() : Entity() {}

Enemy::Enemy(const Enemy& e) : Entity(e) {}

Enemy::~Enemy()
{
    delete loot;
}

Item* Enemy::steal()
{
    Item* i=loot;
    loot=nullptr;
    return i;
}

void Enemy::setloot(Item* i)
{
    loot=i;
}

bool Enemy::hasloot() const
{
    if (loot==nullptr)
    {
        return false;
    }
    else
    {
        return true;
    }
}