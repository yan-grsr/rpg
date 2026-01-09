#include "scene.h"

void clearScreen() 
{
    #ifdef _WIN32
        system("cls"); // Clear console for Windows
    #else
        system("clear"); // Clear console for Unix-based systems
    #endif
    cout << "\n";
}

// Moves the cursor to x, y position
void gotoxy(int x, int y) {
    std::cout << "\033[" << y << ";" << x << "H";
}

// Sets the text color to Bright Red
void setRed() {
    std::cout << "\033[1;31m";
}

// Resets terminal formatting
void resetColor() {
    std::cout << "\033[0m";
}

void drawSprite(const std::vector<std::string>& sprite, int x, int y) {
    for (int i = 0 ; i < sprite.size(); i++) {
        gotoxy(x, y + i);
        std::cout << sprite[i] << '\n';
    }
};

void drawItem(Item item, const std::vector<std::string>& sprite, int x, int y)
{
    
};

void fightingScene(Player player, GameCharacter enemy)
{
    clearScreen();
    player.printStat(0,1);
    enemy.printStat(31,1);
};