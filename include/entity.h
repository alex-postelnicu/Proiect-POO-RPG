#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>
using namespace std;

class Entity
{
protected:
    string name;
    int hp,maxhp,dmg,bonusdmg=0;
    bool defending=false;

public:
    Entity(string name, int hp, int dmg);
    Entity();
    Entity(const Entity& other);
    virtual ~Entity();

    friend ostream& operator<<(ostream& os, const Entity& e); //stats
    friend istream& operator>>(istream& is, Entity& e);
    Entity& operator=(const Entity& other);
    Entity& operator+=(int heal);
    virtual void takedmg(int hitdmg);
    virtual void dodmg(Entity& target);
    virtual void setbonusdmg(int weapondmg);
    virtual void special(Entity& target);
    void startdefending();
    void stopdefending();
    bool alive() const;
    bool getdefending() const;
    string getname() const;
    int gethp() const;
    int getmaxhp() const;
    int getdmg() const;
};

bool operator<(const Entity& e1, const Entity& e2);

#endif
