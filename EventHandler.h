//
// Created by hello on 10/3/2021.
//

#ifndef LETTER_CPP_EVENTHANDLER_H
#define LETTER_CPP_EVENTHANDLER_H

class EventHandler{
private:
public:
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;
};

#endif //LETTER_CPP_EVENTHANDLER_H
