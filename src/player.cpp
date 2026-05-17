#include "player.h"

#include <iostream>
#include <string>

using namespace std;

Player::Player(const string& name, int hp, int dmg) : Entity(name, hp, dmg), inv() {}

Player::Player() : Entity() {}

void Player::take_item(Item* i)
{
    inv.add(i);
}

void Player::use_item(int i)
{
    Item* item=inv.get(i-1);
    if (item!=nullptr)
    {
        item->use(*this);
        if (item->isconsumable())
        {
            inv.del(i-1);
        }
    }
    else
    {
        throw InvalidItem(i);
    }
}

void Player::open_inv()
{
    inv.show();
}