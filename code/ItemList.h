//
// Created by hello on 10/23/2021.
//

#ifndef SFML_PROJECT_1_ITEMLIST_H
#define SFML_PROJECT_1_ITEMLIST_H

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "GUIComponent.h"
#include "MouseEvents.h"
#include "Item.h"

class ItemList : public GUIComponent{
private:
    std::vector<Item> itemlist;
    std::string longest;
    float longestWidth, longestHeight;
    sf::Vector2f position;
    std::string clicked = "";
public:
    ItemList();
    sf::Vector2f getPosition();
    void setTextSize(float s);
    void setPosition(sf::Vector2f pos);
    void addItem(std::string s);
    std::string getClicked();
    void removeItem(std::string s);
    int size();
    Item& getItem(int i);

    void setClicked(std::string s);
    //void updateItem(int i, std::string s);
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


#endif //SFML_PROJECT_1_ITEMLIST_H
