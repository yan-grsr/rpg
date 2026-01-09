#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <cstdlib> 
#include "item.h"
#include "gameCharacter.h"
#include "player.h"

#define WIDTH 236
#define HEIGTH 64


void clearScreen();

void gotoxy(int x, int y);

// Sets the text color to Bright Red
void setRed();

// Resets terminal formatting
void resetColor();

void drawSprite(const std::vector<std::string>& sprite, int x, int y);

void drawItem(Item item, const std::vector<std::string>& sprite, int x, int y);

void fightingScene(Player player, GameCharacter enemy);

#endif