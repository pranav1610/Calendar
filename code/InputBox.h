//
// Created by hello on 10/23/2021.
//

#ifndef SFML_PROJECT_1_INPUTBOX_H
#define SFML_PROJECT_1_INPUTBOX_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "GUIComponent.h"
#include "Item.h"

class InputBox : public Item{
private:
    //Item inputbox;
public:
    InputBox();

    void setLightView();
    void setNightView();

    //from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    // from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();

    //from SnapshotInterface
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);

};


#endif //SFML_PROJECT_1_INPUTBOX_H
