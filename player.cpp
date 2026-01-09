#include "player.h"

Player::Player(string name, int type) : GameCharacter(name, "", 100, 10, 0, 0, 0, 100), type(type)
{
    switch (type)
    {
        case 0: // knight
        {
            cout << "it is ok \n";
            Item ironSword = Item("Iron sword", "An iron sword a bit dull.", 4, 0, 0, 20, 0, 0, 0, 10);
            addItem(ironSword);
            Item chainmail = Item("Chainmail", "Make a lot of noise when moving.", 1, 0, 0, 0, 10, -5, 0, 10);
            addItem(chainmail); 
            break;           
        };
        case 1: // assasin
        {
            cout << "not supposed to be here \n";
            Item knife = Item("Knife", "A knife from your kitchen.", 4, 1, 0, 10, 0, 10, 0, 10);
            addItem(knife);
            addItem(knife);
            break;
        };
        case 2: // mage
        {
            Item simpleMagicWand = Item("Simple magic wand", "A magic wand that let you cast simple spell.", 4, 2, 0, 10, 0, 0, 10, 10);
            addItem(simpleMagicWand);  
            break;          
        };
        case 3: // archer
        {
            Item woodenBow = Item("Wooden bow", "A bow that shoot arrow.", 4, 3, 0, 10, 0, 10, 0, 10);
            addItem(woodenBow);
            break;
        };
        default:
        {
            break;
        }
    }
};

void Player::addItem(Item item)
{
    inventory.push_back(item);
    if (item.type == type | item.type == -1) // item unique a la classe ou item toute classe
    {
        cout << "Debug: Types match! Increasing stats..." << endl;
        increaseStat(item.health, item.strength, item.defence, item.dexterity, item.chance);
    }
    else // range l'item sans ajouter les stats
    {
        cout << "Debug: Type mismatch. Item is " << item.type << " but Player is " << type << endl;
    }
};

/*
void Player::removeItem(Item item)
{
    inventory.erase(find(inventory.begin(), inventory.end(), item));
    if (item.type == type)
    {
        increaseStat(-item.health, -item.strength, -item.defence, -item.dexterity, -item.chance);
    }
};
*/

void Player::increaseStat(int _maxHealth, int _strength, int _defence, int _dexterity, int _chance)
{
    // maxHealth can't be lower than 1 else the player will die
    if (maxHealth <= -_maxHealth & _maxHealth < 0)
    {
        maxHealth = 1;
    }
    else
    {
        maxHealth += _maxHealth;
    }
    if (currentHealth > maxHealth)
    {
        currentHealth = maxHealth;
    }
    strength += _strength;
    defence += _defence;
    dexterity += _dexterity;
    chance += _chance;
};

void Player::lootRoom(Room * room)
{
    for (int i = 0 ; i < room->items.size() ; i++)
    {
        inventory.push_back(room->items[i]);
    }
    room->clearLoot();
};

void Player::changeRoom(Room * newRoom)
{
    room = newRoom;
};

bool Player::addMoney(int amount)
{
    if (amount < 0 )
    {
        if ( money < -amount)
        {
            return 0;
        }
        else
        {
            money += amount;
            return 1;
        }
    }
    else 
    {
        money += amount;
        return 1;
    }
};

void Player::printStat()
{   
    std::string class_list[] = {"Knight", "Assassin", "Mage", "Archer"};
    
    // Setup formatting constants
    const int labelW = 12; // Width for the "Health :" part
    const int valueW = 12; // Width for the actual numbers/names
    const std::string bar = "────────────────────────────"; // 28 chars

    // Helper for health string so we can right-align it nicely
    std::string healthStr = std::to_string(currentHealth) + "/" + std::to_string(maxHealth);

    std::cout << "┌" << bar << "┐\n"
              << "│ " << std::setw(27) << std::left << "Player Stats" << "│\n"
              << "├" << bar << "┤\n"
              << "│ " << std::left << std::setw(labelW) << "Class"     << ": " << std::setw(valueW) << class_list[type] <<  " │\n"  
              << "│ " << std::left << std::setw(labelW) << "Name"      << ": " << std::setw(valueW) << name <<              " │\n" 
              << "│ " << std::left << std::setw(labelW) << "Health"    << ": " << std::setw(valueW) << healthStr <<         " │\n" 
              << "│ " << std::left << std::setw(labelW) << "Strength"  << ": " << std::setw(valueW) << strength <<          " │\n"
              << "│ " << std::left << std::setw(labelW) << "Defence"   << ": " << std::setw(valueW) << defence <<           " │\n"
              << "│ " << std::left << std::setw(labelW) << "Dexterity" << ": " << std::setw(valueW) << dexterity <<         " │\n"
              << "│ " << std::left << std::setw(labelW) << "Chance"    << ": " << std::setw(valueW) << chance <<            " │\n"
              << "│ " << std::left << std::setw(labelW) << "Money"     << ": " << std::setw(valueW) << money <<             " │\n"
              << "└" << bar << "┘\n";
};


void Player::printStat(int x, int y)
{   
    std::string class_list[] = {"Knight", "Assassin", "Mage", "Archer"};
    
    // Setup formatting constants
    const int labelW = 12; // Width for the "Health :" part
    const int valueW = 12; // Width for the actual numbers/names
    const std::string bar = "────────────────────────────"; // 28 chars

    // Helper for health string so we can right-align it nicely
    std::string healthStr = std::to_string(currentHealth) + "/" + std::to_string(maxHealth);
    gotoxy(x,y);
    std::cout  << "┌" << bar << "┐\n";
    gotoxy(x,y+1);
    std::cout  << "│ " << std::setw(27) << std::left << name << "│\n";
    gotoxy(x,y+2);
    std::cout  << "├" << bar << "┤\n";
    gotoxy(x,y+3);
    std::cout  << "│ " << std::left << std::setw(labelW) << "Class"     << ": " << std::setw(valueW) << class_list[type] << " │\n";
    gotoxy(x,y+4);
    std::cout  << "│ " << std::left << std::setw(labelW) << "Health"    << ": " << std::setw(valueW) << healthStr << " │\n" ;
    gotoxy(x,y+5);
    std::cout  << "│ " << std::left << std::setw(labelW) << "Strength"  << ": " << std::setw(valueW) << strength << " │\n";
    gotoxy(x,y+6);
    std::cout  << "│ " << std::left << std::setw(labelW) << "Defence"   << ": " << std::setw(valueW) << defence << " │\n";
    gotoxy(x,y+7);
    std::cout  << "│ " << std::left << std::setw(labelW) << "Dexterity" << ": " << std::setw(valueW) << dexterity << " │\n";
    gotoxy(x,y+8);
    std::cout  << "│ " << std::left << std::setw(labelW) << "Chance"    << ": " << std::setw(valueW) << chance << " │\n";
    gotoxy(x,y+9);
    std::cout  << "│ " << std::left << std::setw(labelW) << "Money"     << ": " << std::setw(valueW) << money << " │\n";
    gotoxy(x,y+10);
    std::cout  << "└" << bar << "┘\n";
};


void Player::printInventory(int x,int y) const 
{
    const int width = 28; 
    const std::string bar = "────────────────────────────";
    gotoxy(x,y);
    cout << "┌" << bar << "┐\n";
    gotoxy(x,y + 1);
    cout << "│ " << setw(27) << left << "Inventory" << "│\n";
    gotoxy(x,y + 2);
    cout << "├" << bar << "┤\n";
    for (size_t i = 0; i < inventory.size(); ++i)
    {
        gotoxy(x,y + 3 + i);
        cout << "│ [" << i+1 << "] " << left << setw(23) << inventory[i].name << "│\n";
    }
    cout << "└" << bar << "┘\n";
}

void Player::printInventory() const 
{
    const int width = 28; 
    const std::string bar = "────────────────────────────"; 
    cout << "┌" << bar << "┐\n"
         << "│ " << setw(27) << left << "Inventory" << "│\n"
         << "├" << bar << "┤\n";
    for (size_t i = 0; i < inventory.size(); ++i)
    {
        cout << "│ [" << i+1 << "] " << left << setw(23) << inventory[i].name << "│\n";
    }
    cout << "└" << bar << "┘\n";
}