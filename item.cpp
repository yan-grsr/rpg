#include "item.h"


Item::Item(string name, string description, int classe, int type, int health, int strength, int defence, int dexterity, int chance, int value)
    : name(name), description(description), classe(classe), type(type), health(health), 
      strength(strength), defence(defence), dexterity(dexterity), chance(chance), value(value)
{
    
}


void Item::printItem()
{
    string classes[] = {
        "sword",
        "dagger", 
        "magic wand", 
        "bow"
    };

    string types[] = {
        "helmet",
        "chesplate",
        "leggings",
        "boots",
        "weapon",
        "second hand",
        "potion"
    };

    // Setup formatting constants
    const int labelW = 12; // Width for the "Health :" part
    const int valueW = 12; // Width for the actual numbers/names
    const std::string bar = "────────────────────────────"; // 28 chars

    std::cout << "┌" << bar << "┐\n"
            << "│ " << std::setw(27) << std::left << name << "│\n"
            << "├" << bar << "┤\n"
            << "│ " << std::left << std::setw(labelW) << "Description" << ": " << std::setw(valueW) << description     << " │\n" 
            << "│ " << std::left << std::setw(labelW) << "Class"       << ": " << std::setw(valueW) << "a reparer"/*classes[classe]*/ << " │\n" 
            << "│ " << std::left << std::setw(labelW) << "Type"        << ": " << std::setw(valueW) << types[type]     << " │\n" 
            << "│ " << std::left << std::setw(labelW) << "Health"      << ": " << std::setw(valueW) << health          << " │\n" 
            << "│ " << std::left << std::setw(labelW) << "Strength"    << ": " << std::setw(valueW) << strength        << " │\n"
            << "│ " << std::left << std::setw(labelW) << "Defence"     << ": " << std::setw(valueW) << defence         << " │\n"
            << "│ " << std::left << std::setw(labelW) << "Dexterity"   << ": " << std::setw(valueW) << dexterity       << " │\n"
            << "│ " << std::left << std::setw(labelW) << "Chance"      << ": " << std::setw(valueW) << chance          << " │\n"
            << "└" << bar << "┘\n";
}