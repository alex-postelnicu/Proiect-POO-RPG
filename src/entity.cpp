#include "entity.h"
#include "text.h"
#include "colors.h"

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

Entity::Entity(string name, int hp, int dmg) : name(name), hp(hp), maxhp(hp), dmg(dmg) {}

Entity::Entity() : name("???"), hp(1), maxhp(1), dmg(1) {}

Entity::Entity(const Entity& other)
{
    this->name=other.name;
    this->hp=other.hp;
    this->maxhp=other.maxhp;
    this->dmg=other.dmg;
}

Entity::~Entity() {}

ostream& operator<<(ostream& os, const Entity& e) //stats
{
    os<<CYAN;
    writetext("--- "+e.name+" ---");
    os<<WHITE;
    os<<RED;
    os<<"HP:  "<<e.hp<<" / "<<e.maxhp<<"\n";
    os<<WHITE;
    os<<YELLOW;
    os<<"DMG: "<<e.dmg<<"\n\n";
    os<<WHITE;
    return os;
}

istream& operator>>(istream& is, Entity& e)
{
    is>>e.name>>e.hp>>e.dmg;
    e.maxhp=e.hp;
    return is;
}

Entity& Entity::operator=(const Entity& other)
{
    this->name=other.name;
    this->hp=other.hp;
    this->maxhp=other.maxhp;
    this->dmg=other.dmg;
    this->bonusdmg=other.bonusdmg;
    return *this;
}

Entity& Entity::operator+=(int heal)
{
    this->hp=min(this->hp+heal,this->maxhp);
    return *this;
}

void Entity::takedmg(int hitdmg)
{
    if (getdefending())
    {
        hitdmg/=2;
    }
    hp-=hitdmg;
    if (hp<=0)
    {
        hp=0;
    }
}

void Entity::dodmg(Entity& target)
{
    int damage=this->dmg+this->bonusdmg;
    target.takedmg(damage);
}

void Entity::setbonusdmg(int weapondmg)
{
    this->bonusdmg=weapondmg;
}

void Entity::startdefending()
{
    defending=true;
}

void Entity::stopdefending()
{
    defending=false;
}

void Entity::special(Entity& target)
{
    target.takedmg(dmg*150/100);
}

bool Entity::alive() const
{
    if (hp>0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Entity::getdefending() const
{
    return defending;
}

const string& Entity::getname() const
{
    return name;
}

int Entity::gethp() const
{
    return hp;
}

int Entity::getmaxhp() const
{
    return maxhp;
}

int Entity::getdmg() const
{
    return dmg+bonusdmg;
}

bool operator<(const Entity& e1, const Entity& e2)
{
    return e1.gethp()*100/e1.getmaxhp()<e2.gethp()*100/e2.getmaxhp();
}