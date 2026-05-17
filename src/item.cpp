#include "item.h"

#include <iostream>
#include <string>

using namespace std;

Item::Item(const string& name) : name(name) {}

Item::~Item() {}

bool Item::isconsumable() const
{
    return false;
}

const string& Item::getname() const
{
    return name;
}