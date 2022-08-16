//
// Created by hello on 9/22/2021.
//

#ifndef TYPINGINSFML_FONTS_H
#define TYPINGINSFML_FONTS_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Fonts {

private:
    static sf::Font font;
    bool static isLoadedBefore;
public:
    static void loadFont(const std::string& fileName);
    static sf::Font& getFont();
};


#endif //TYPINGINSFML_FONTS_H
