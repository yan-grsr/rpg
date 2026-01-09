#include "dungeon.h"

Dungeon::Dungeon(Player player) : player(player)
{
};

int Dungeon::runDungeon()
{
    // Start Game
    clearScreen();
    cout << "You enter a dungeon filled with loots and monsters. Find the exit and stay alive.\n";
    player.room = &rooms[0];
    player.money = 100;
    // Game loop
    while (true)
    {
        // enter room and handle it
        enterRoom(player.room);
        // ckeck if the player is dead
        if (player.isDead())
        {
            clearScreen();
            cout << "You are dead. Try again ?\n";
            return performEndGameLogic();
        }
        else
        {
            if (player.room->isExit)
            {
                if (player.room->enemies.size() == 0)
                {
                    clearScreen();
                    cout << "You successfully clear the dungeon !\n";
                    cout << "Do you want to enter a new dungeon ?\n";
                    return performEndGameLogic();
                }
            }
        }
        // change room
        handleMovementActions(player.room);
    }
};

void Dungeon::enterRoom(Room * room)
{
    if (room->enemies.size() != 0)
    {
        // handle room whith enemies
        handleRoomWithEnemy(room);
    }
    else if (room->items.size() != 0)
    {
        // handle room with chest
        handleRoomWithChest(room);
    }
    else
    {
        // handle empty room
        handleEmptyRoom(room);
    }
};

void Dungeon::handleEmptyRoom(Room * room)
{
    clearScreen();
    cout << "You enter the room but it is empty." << endl;
    string action[] = {"[1] Move to another room"};
    while (true)
    {
        printActions(1, action);
        int input;
        cin >> input;
        if (input == 1)
        {
            return;
        }
        else
        {
            cout << "Incorrect choice" << endl;
        }

    }
};

void Dungeon::handleRoomWithChest(Room * room)
{
    clearScreen();
    cout << "You enter the room and see a chest." << endl;
    string action[] = {
        "[1] Open the chest",
        "[2] Move to another room"
        };
    while (true)
    {
        printActions(2, action);
        int input;
        cin >> input;
        if (input == 1)
        {
            // loot chest
            handleLootActions(room);
            return;
        }
        else if (input == 2)
        {
            return;
        }
        else
        {
            cout << "Incorrect choice" << endl;
        }

    }
};

void Dungeon::handleRoomWithEnemy(Room * room)
{
    GameCharacter enemy = room->enemies.front();
    clearScreen();
    cout << "You enter the room and see a " << enemy.name << endl;
    string action[] = {
        "[1] Fight the " + enemy.name,
        "[2] Go back to previous room"
        };
    while (true)
    {
        printActions(2, action);
        int input;
        cin >> input;
        if (input == 1)
        {
            // fight
            handleFightActions(&enemy);
            room->clearEnemies();
        }
        else if (input == 2)
        {
            enterRoom(player.room);
            return;
        }
        else
        {
            cout << "Incorrect choice" << endl;
        }

    }
};

void Dungeon::handleLootActions(Room * room)
{
    int size = room->items.size();
    string actions[] = {
        "[1] Yes",
        "[2] No"
    };
    for (int i = 0 ; i < size ; i++)
    {
        clearScreen();
        cout << "You open the chest and find " << "\n";
        room->items[i].printItem();
        int input = 0;
        bool itemIsTaken = 1;
        while (itemIsTaken)
        {
            cout << "Do you want to keep it ?\n";
            printActions(2,actions);
            cin >> input;
            if (input == 1)
            {
                player.addItem(room->items[i]);
                cout << "You have put " << room->items[i].name << " in your inventory\n";
                itemIsTaken = 0;
            }
            else if (input == 2)
            {
                cout << "You have throw away " << room->items[i].name << "\n";
                itemIsTaken = 0;
            }
            else
            {
                cout << "Incorrect choice\n";
            }
        }
    }
    room->clearLoot();
};

void Dungeon::handleFightActions(GameCharacter * enemy)
{
    string action[] = {
        "[1] Attack",
        "[2] Retreat"
        };
    while (true)
    {
        // handle player attack
        fightingScene(player, *enemy);
        printActions(2, action,0,13);
        int input;
        cin >> input;
        if (input == 1)
        {
            // attack
            int damage = enemy->takeDamage(player.strength);
            cout << "You attack does " << damage << "damage" << "\n"
                 << enemy->name << " has " << enemy->currentHealth << " hp left>\n";
        }
        else if (input == 2)
        {
            enterRoom(player.room);
            return;
        }
        else
        {
            cout << "Incorrect choice" << endl;
        }
        // check if enemy is dead
        if (enemy->isDead())
        {
            cout << "you have defeated the " << enemy->name << endl;
            player.increaseStat(10,5,5,2,0);
            player.room->clearEnemies();
            enterRoom(player.room);
            return;
        }
        // handle enemy attack 
        int damage = player.takeDamage(enemy->strength);
        cout << enemy->name << "'s attack does " << damage << "damage" << endl;
        cout << "You now have " << player.currentHealth << endl;
        if (player.isDead())
        {
            cout << "you have been defeated" << endl;
            player.addMoney(enemy->money);
            return;
        }
    }
};

void Dungeon::handleMovementActions(Room * room)
{
    while(true)
    {
        clearScreen();
        if (room->id == 0)
        {
            string actions[] = {
                "[1]. Move up",
            };
            printActions(1,actions);
            int input;
            cin >> input;
            if (input == 1)
            {
                player.changeRoom(&rooms[1]);
                return;
            }
            else
            {
                cout << "Incorrect choice" << endl;
            }
        }
        else if (room->id == 1)
        {
            string actions[] = {
                "[1] Move up",
                "[2] Move down"
            };
            printActions(2,actions);
            int input;
            cin >> input;
            if (input == 1)
            {
                player.changeRoom(&rooms[2]);
                return;
            }
            else if (input == 2)
            {
                player.changeRoom(&room[0]);
            }
            else
            {
                cout << "Incorrect choice" << endl;
            }
        }
        else if (room->id == 2)
        {
            string actions[] = {
                "[1] Move up",
                "[2] Move down"
            };
            printActions(2,actions);
            int input;
            cin >> input;
            if (input == 1)
            {
                player.changeRoom(&rooms[3]);
                return;
            }
            else if (input == 2)
            {
                player.changeRoom(&room[1]);
            }
            else
            {
                cout << "Incorrect choice" << endl;
            }
        }
    }
};

void Dungeon::printActions(int nbActions, string actions[])
{
    cout << "Choose an action:" << endl;
    for (int i = 0 ; i < nbActions ; i++)
    {
        cout << actions[i] << endl;
    }
};

void Dungeon::printActions(int nbActions, string actions[], int x, int y)
{
    gotoxy(x,y);
    cout << "Choose an action:" << endl;
    for (int i = 0 ; i < nbActions ; i++)
    {
        gotoxy(x,y+i+1);
        cout << actions[i] << endl;
    }
};

int Dungeon::performEndGameLogic()
{
    string actions[] = 
    {
        "[1] Yes",
        "[2] No"
    };
    while (true)
    {
        printActions(2,actions);
        int input;
        cin >> input;
        if (input == 1)
        {
            return 1;
        }
        else if (input == 2)
        {
            return 0;
        }
        else
        {
            cout << "Incorrect choice" << endl;
        }
    }
};