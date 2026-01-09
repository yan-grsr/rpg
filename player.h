#include "gameCharacter.h"
#include "room.h"
#include "item.h"
#include <vector>
#include <bits/stdc++.h>
#include "scene.h"
#include <iomanip>

#ifndef PLAYER_H
#define PLAYER_H


class Player : public GameCharacter
{
public:
    Room * room;
    vector<Item> inventory;
    int money;
    int type;
    Player(string name, int type); // Ok
    void addItem(Item item); // Ok
    //void removeItem(Item item);
    void increaseStat(int maxHealth, int strength, int defence, int dexterity, int chance); // Ok
    void lootRoom(Room * room);
    void changeRoom(Room * room);
    bool addMoney(int amount); // Ok
    void printStat(); // Ok
    void printStat(int x, int y); // Ok
    void printInventory() const; // Ok
    void printInventory(int x,int y) const ;
};


#endif