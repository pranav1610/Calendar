//
// Created by hello on 9/28/2021.
//

#ifndef MULTITEXT_LETTER_H
#define MULTITEXT_LETTER_H

#include <SFML/Graphics.hpp>
#include <string>
#include "Fonts.h"
#include "LinkedList/Node.h"
#include "LinkedList/DoublyLinkedList.h"
#include "LinkedList/Node_Iterator.h"

class Letter : public sf::Text{
private:

public:
    Letter();
    Letter(std::string str);
    void setLetterSize(float s);
    void setCharacter(char val);
    void setCharacterColor(sf::Color c);
    std::string getCharacter() const;

};


#endif //MULTITEXT_LETTER_H
