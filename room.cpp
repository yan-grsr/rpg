#include "room.h"

Room::Room() {};
Room::Room(int id, bool isExit, vector<Item> items, vector<GameCharacter> enemies, vector<int> connectedRoom)
    : id(id), isExit(isExit), items(items), enemies(enemies), connectedRoom(connectedRoom)
{

};

void Room::clearLoot()
{
    items.clear();
};

void Room::clearEnemies()
{
    enemies.clear();
};