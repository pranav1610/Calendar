//
// Created by hello on 9/22/2021.
//

#include "Fonts.h"

sf::Font Fonts::font;

//default font not already loaded
bool Fonts::isLoadedBefore = false;

void Fonts::loadFont(const std::string& fileName) {
    if(!isLoadedBefore) {
        isLoadedBefore = font.loadFromFile(fileName);
        if(!isLoadedBefore)
        {
            std::cout << "\nFont not loaded\n";
            exit(1);
        }
    }
}

sf::Font &Fonts::getFont()
{
    loadFont("OpenSans-Bold.ttf");
    return font;
}
