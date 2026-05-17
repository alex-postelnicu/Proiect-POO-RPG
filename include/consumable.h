#ifndef OOP_EXAMPLE_H
#define OOP_EXAMPLE_H

#include "item.h"
#include "entity.h"

#include <iostream>
#include <string>

using namespace std;

class Consumable : public Item
{
private:
    int heal;

public:
    Consumable(string name, int heal);

    bool isconsumable() const override;
    void use(Entity& e) override;
};

#endif
