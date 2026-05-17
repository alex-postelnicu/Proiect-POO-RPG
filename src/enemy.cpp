#include "enemy.h"
#include "colors.h"

#include <iostream>
#include <string>

using namespace std;

Enemy::Enemy(const string& name, int hp, int dmg) : Entity(name, hp, dmg) {}

Enemy::Enemy() : Entity() {}

Enemy::Enemy(const Enemy& e) : Entity(e) {}