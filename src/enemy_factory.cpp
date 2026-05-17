#include "enemy_factory.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Enemy* Enemy_Factory::create_enemy(const string& search_name)
{
    ifstream fin("enemies.txt");
    if (!fin.is_open())
    {cout<<"NU MERGE";
    return new Enemy();}
    Enemy aux;
    while (fin>>aux)
    {
        if (aux.getname()==search_name)
        {
            fin.close();
            return new Enemy(aux);
        }
    }
    fin.close();
    return new Enemy(); //default daca nu gaseste in fisier
}