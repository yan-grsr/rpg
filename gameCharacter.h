#include <string>
#include <iostream>
#include <cstdlib>
#include "item.h"
#include "scene.h"

#ifndef GAMECHARACTER_H
#define GAMECHARACTER_H

using namespace std;



class GameCharacter
{
public:
    string name;
    string description;
    int maxHealth, currentHealth, strength, defence, dexterity, chance, money;
    GameCharacter(string name, string description , int maxHealth, int strength, int defence, int dexterity, int chance, int money); // Ok
    int takeDamage(int amount); // Ok
    bool dodge();
    bool doCrit();
    bool isDead(); // Ok
    void printStat(); // Ok
    void printStat(int x, int y); // Ok

};


#endif
