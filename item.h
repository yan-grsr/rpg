#include <string>
#include <iostream>
#include <bits/stdc++.h>
//#include "scene.h"

using namespace std;

#ifndef ITEM_H
#define ITEM_H

class Item 
{
public:
    string name;
    string description;
    int type, classe, health, strength, defence, dexterity, chance, value ;
    Item(string name, string description , int type, int classe, int health, int strength, int defence, int dexterity, int chance, int value); // Ok
    void printItem(); // Ok
};


#endif