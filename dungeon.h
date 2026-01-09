#include <string>
#include <iostream>
#include "item.h"
#include "scene.h"

using namespace std;

#ifndef DUNGEON_H
#define DUNGEON_H

class Dungeon
{
public:
    Player player;
    Room rooms[4];
    Dungeon(Player);
    int runDungeon();
    void enterRoom(Room * room);
    void handleEmptyRoom(Room * room);
    void handleRoomWithChest(Room * room);
    void handleRoomWithEnemy(Room * room);
    void handleLootActions(Room * room);
    void handleFightActions(GameCharacter * enemy);
    void handleMovementActions(Room * room);
    void printActions(int nbActions, string actions[]);
    void printActions(int nbActions, string actions[], int x, int y);
    int performEndGameLogic();
};


#endif