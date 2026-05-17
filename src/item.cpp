#include "item.h"

#include <iostream>
#include <string>

using namespace std;

Item::Item(string name) : name(name) {}

Item::~Item() {}

bool Item::isconsumable() const
{
    return false;
}

string Item::getname() const
{
    return name;
}