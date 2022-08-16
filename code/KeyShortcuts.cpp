//
// Created by hello on 10/3/2021.
//

#include "KeyShortcuts.h"

//
bool KeyShortcuts::isUndo()
{
    //(sf::Keyboard::isKeyPressed(sf::Keyboard::)) && --> check if command is pressed(for mac)
    return ((sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) || sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)
    || sf::Keyboard::isKeyPressed(sf::Keyboard::LSystem) || sf::Keyboard::isKeyPressed(sf::Keyboard::RSystem)) &&
    (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)));

    //return (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl));
}

bool KeyShortcuts::isEntered() {
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter));
}
