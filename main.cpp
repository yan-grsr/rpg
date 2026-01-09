#include <iostream>
#include "item.cpp" 
#include "gameCharacter.cpp"
#include "player.cpp"
#include "room.cpp"
#include "dungeon.cpp"
#include "scene.cpp"

Player createPlayer();

int main() 
{
    // Create player
    Player player = createPlayer();
    cout << "Player created\n";

    // create  1st room
    vector<int> connectedRoom = {1};
    Room firstRoom = Room(0,false,vector<Item>(),vector<GameCharacter>(),connectedRoom);
    cout << "First room created\n";

    // create 2nd room
    vector<Item> secondRoomItems;
    Item sword = Item("Iron sword", "Just a basic sword", 4, 0, 0, 20, 0, 0, 0, 10);
    secondRoomItems.push_back(sword);
    connectedRoom = {0,2};
    Room secondRoom = Room(1,false,secondRoomItems,vector<GameCharacter>(),connectedRoom);
    cout << "Second room created\n";

    // create third room
    GameCharacter skeleton = GameCharacter("Skeleton", "A low rank monster", 100, 10, 0, 0, 0, 10);
    vector<GameCharacter> thirdRoomEnemies;
    thirdRoomEnemies.push_back(skeleton);
    connectedRoom = {1,3};
    Room thirdRoom = Room(2,false,vector<Item>(),thirdRoomEnemies,connectedRoom);
    cout << "Third room created\n";
    connectedRoom = {2};
    // Create fourth room
    Room fourthRoom = Room(3,true,vector<Item>(),vector<GameCharacter>(),connectedRoom);
    cout << "Fourth room created\n";

    // Create dungeon 
    Dungeon dungeon = Dungeon(player);
    cout << "Dungeon created\n";
    dungeon.rooms[0] = firstRoom;
    cout << "First room added\n";
    dungeon.rooms[1] = secondRoom;
    cout << "Second room added\n";
    dungeon.rooms[2] = thirdRoom;
    cout << "Third room added\n";
    dungeon.rooms[3] = fourthRoom;
    cout << "Fourth room added to dungeon\n";
    // Game loop
    while (true)
    {
        int result = dungeon.runDungeon();
        if (result == 0)
        {
            break;
        }
    }
    clearScreen();
    cout << "Game fisnished" << endl;

    
    return 0;
}

Player createPlayer()
{
    cout << "Enter your name\n";
    string name;
    cin >> name;
    cout << "Choose your class.\n[1] Knight\n[2] Assassin\n[3] Mage\n[4] Archer\n";
    int classe = -1;
    while (classe > 4 | classe < 1)
    {
        cin >> classe;
    };
    return Player(name,classe - 1);
}