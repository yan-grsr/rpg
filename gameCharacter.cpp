#include "gameCharacter.h"

GameCharacter::GameCharacter(string name, string description, int maxHealth, int strength, int defence, int dexterity, int chance, int money)
    : name(name), description(description), maxHealth(maxHealth), currentHealth(maxHealth), 
      strength(strength), defence(defence), dexterity(dexterity), chance(chance), money(money)
{
};

int GameCharacter::takeDamage(int amount)
{
    int damage = amount - defence;
    if (damage < 0)
    {
        damage = 0;
    }
    currentHealth -= damage;
    return damage;
};

bool GameCharacter::dodge()
{
    return rand() % 100 <= dexterity;
};

bool GameCharacter::doCrit()
{
	return rand() % 100 <= chance;
};

bool GameCharacter::isDead()
{
    return currentHealth <= 0;
};

void GameCharacter::printStat()
{
    cout << name << "\n" 
         << description << "\n" 
         << "health : \t" << currentHealth << "/" << maxHealth << "\n" 
         << "strength : \t" << strength << "\n"
         << "defence : \t" << defence << "\n"
         << "dexterity : \t" << dexterity << "\n"
         << "chance : \t" << chance << endl;
};

void GameCharacter::printStat(int x, int y)
{
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
    std::cout  << "│ " << std::left << std::setw(labelW) << "Health"    << ": " << std::setw(valueW) << healthStr << " │\n" ;
    gotoxy(x,y+4);
    std::cout  << "│ " << std::left << std::setw(labelW) << "Strength"  << ": " << std::setw(valueW) << strength << " │\n";
    gotoxy(x,y+5);
    std::cout  << "│ " << std::left << std::setw(labelW) << "Defence"   << ": " << std::setw(valueW) << defence << " │\n";
    gotoxy(x,y+6);
    std::cout  << "│ " << std::left << std::setw(labelW) << "Dexterity" << ": " << std::setw(valueW) << dexterity << " │\n";
    gotoxy(x,y+7);
    std::cout  << "│ " << std::left << std::setw(labelW) << "Chance"    << ": " << std::setw(valueW) << chance << " │\n";
    gotoxy(x,y+8);
    std::cout  << "└" << bar << "┘\n";
};
