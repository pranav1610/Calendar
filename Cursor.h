//
// Created by hello on 10/6/2021.
//

#ifndef SFML_PROJECT_1_CURSOR_H
#define SFML_PROJECT_1_CURSOR_H

#include <SFML/Graphics.hpp>
#include "States.h"
#include "GUIComponent.h"
#include "Letter.h"

class Cursor : public GUIComponent{
private:
    //sf::Text cursor;
    Letter cursor;
    sf::Clock clock;
public:
    Cursor();

    void setCursorSize(float s);

    sf::Vector2f getPosition();

    void setPosition(sf::Vector2f pos);

    void blinkCursor();

    //from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    // from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();

    //from SnapshotInterface
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);


};


#endif //SFML_PROJECT_1_CURSOR_H
