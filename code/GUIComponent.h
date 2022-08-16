//
// Created by hello on 10/3/2021.
//

#ifndef LETTER_CPP_GUICOMPONENT_H
#define LETTER_CPP_GUICOMPONENT_H

#include <SFML/Graphics.hpp>
#include "EventHandler.h"
#include "States.h"
#include "SnapshotInterface.h"

//sf::Transformable is optional
class GUIComponent : public EventHandler, public States,
        public SnapshotInterface, public sf::Drawable, public sf::Transformable {
private:

public:
    //from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const = 0;

    // from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;

    //from SnapshotInterface
    virtual Snapshot& getSnapshot() = 0;
    virtual void applySnapshot(const Snapshot& snapshot) = 0;
};


#endif //LETTER_CPP_GUICOMPONENT_H
