#include <vector>
#include "item.h"
#include "gameCharacter.h"
#include "scene.h"

#ifndef ROOM_H
#define ROOM_H


class Room
{
public:
    int id = -1;
    bool isExit = false;
    vector<Item> items;
    vector<GameCharacter> enemies;
    vector<int> connectedRoom;
    Room();
    Room(int id, bool isExit, vector<Item> items, vector<GameCharacter> enemies, vector<int> connectedRoom);
    void clearLoot();
    void clearEnemies();
};


#endif