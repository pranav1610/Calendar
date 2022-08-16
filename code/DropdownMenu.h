//
// Created by hello on 10/23/2021.
//

#ifndef SFML_PROJECT_1_DROPDOWNMENU_H
#define SFML_PROJECT_1_DROPDOWNMENU_H

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "GUIComponent.h"
#include "History.h"
#include "Item.h"
#include "ItemList.h"
#include "InputBox.h"
#include "MouseEvents.h"
class DropdownMenu :public GUIComponent{

private:
    ItemList itemlist;
    InputBox inputbox;
    Snapshot snapshot;
public:
    DropdownMenu();

    std::string getDropdownMenuChoice() const;
    void setDropdownMenuName(std::string);

    void addItem(std::string s);

    void setTextSize(float s);

    sf::FloatRect getInputBoxBounds() const;

    void setPosition(float x, float y);

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


#endif //SFML_PROJECT_1_DROPDOWNMENU_H
