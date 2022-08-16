//
// Created by hello on 9/28/2021.
//

#include "Letter.h"

Letter::Letter()
{
    //font of text
    this->setFont(Fonts::getFont());
    this->setFillColor(sf::Color::White);
    this->setCharacterSize(20);
    this->setLineSpacing(1.5);
}

Letter::Letter(std::string str)
{
    this->setString(str);

}

void Letter::setCharacter(char val)
{
    std::string str = "";
    str += val;
    this->setString(str);
}

std::string Letter::getCharacter() const{
    return this->getString();
}

void Letter::setCharacterColor(sf::Color c) {
    this->setFillColor(c);
}

void Letter::setLetterSize(float s)
{
    if(s>0)
        this->setCharacterSize(s);

}
