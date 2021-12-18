//
// Created by hello on 10/25/2021.
//

#ifndef SFML_PROJECT_1_MENU_H
#define SFML_PROJECT_1_MENU_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "GUIComponent.h"
#include "Item.h"
#include "ItemList.h"

class Menu : public GUIComponent{
private:
    Item menu;
    ItemList itemlist;
    std::string clicked="";

public:
    Menu();
    sf::FloatRect getTitleBounds();
    std::string getMenuName();
    void setMenuName(std::string s);
    void addItem(std::string s);
    std::string getClicked();
    void setTextSize(float s);

    void setLightView();
    void setNightView();

    void setTitleBoxPosition(sf::Vector2f pos);
    sf::Vector2f getTitleBoxPosition();

    sf::Vector2f getTitleboxSize();


    sf::FloatRect getGlobalBounds();

    //from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    // from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();

    //from SnapshotInterface
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);

};


#endif //SFML_PROJECT_1_MENU_H
