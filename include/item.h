#ifndef ITEM_H
#define ITEM_H

#include "entity.h"

#include <iostream>
#include <string>

using namespace std;

class Item
{
protected:
    string name;

public:
    Item(const string& name);
    virtual ~Item();

    virtual bool isconsumable() const;
    virtual void use(Entity& e)=0;
    const string& getname() const;

};

#endif
