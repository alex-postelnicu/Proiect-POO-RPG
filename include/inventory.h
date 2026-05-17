#ifndef INVENTORY_H
#define INVENTORY_H

#include "text.h"
#include "colors.h"
#include "exceptions.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

template <typename T>
class Inventory
{
private:
    vector<T>objects;
    int mx;

public:
    Inventory(int mx=10) : mx(mx) {}

    ~Inventory()
    {
        for (auto it : objects)
        {
            delete it;
        }
        objects.clear();
    }

    void add(T obj)
    {
        if ((int)objects.size()<mx)
        {
            objects.push_back(obj);
        }
        else
        {
            throw InventoryFull();
        }
    }

    T get(int i)
    {
        if (i>=0 && i<(int)objects.size())
        {
            return objects[i];
        }
        else
        {
            return nullptr;
        }
    }

    void show() const
    {
        cout<<MAGENTA;
        writetext("--- BACKPACK ---");
        cout<<WHITE;
        if (objects.empty())
        {
            cout<<"Total emptiness\n";
        }
        else
        {
            int i=1;
            for_each(objects.begin(), objects.end(), [&i](const T& obj)
        {
            cout<<"["<<i<<"] "<<obj->getname()<<"\n";
            i++;
        });
        }
    }

    void del(int i)
    {
        if (i>=0 && i<(int)objects.size())
        {
            delete objects[i];
            objects.erase(objects.begin()+i);
        }
    }
};


#endif
