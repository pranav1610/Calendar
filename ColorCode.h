//
// Created by hello on 10/6/2021.
//

#ifndef SFML_PROJECT_1_COLORCODE_H
#define SFML_PROJECT_1_COLORCODE_H

#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include "Letter.h"
#include "MultiText.h"

class ColorCode {

private:
    //std::map<std::string, sf::Color> keywords;
    sf::Color getColor(std::string word);
    std::string gC(std::string word);
public:
    //ColorCode();
    void changeColor(MultiText::iterator& begin, MultiText::iterator& end);
};


#endif //SFML_PROJECT_1_COLORCODE_H
