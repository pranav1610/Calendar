//
// Created by hello on 10/21/2021.
//

#ifndef SFML_PROJECT_1_ITEM_H
#define SFML_PROJECT_1_ITEM_H

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "GUIComponent.h"
#include "MouseEvents.h"
#include "Fonts.h"


class Item : public GUIComponent{
private:
    sf::RectangleShape box;
    sf::Text text;
    sf::Vector2f position;

    float sidePadding;
    float sideRatio;

    float topPadding;
    float topRatio;
public:
    Item();
    void setTextSize(float s);
    void setBoxSize(float w, float h);

    void setText(std::string s);
    void setTextPosition(sf::Vector2f pos);
    void setPosition(sf::Vector2f pos);
    void recenter();

    sf::Vector2f getPosition();
    sf::FloatRect getGlobalBounds() const;
    sf::Vector2f getBoxSize();
    sf::Text getText() const;
    float getTextSize();

    bool contains(float x, float y);

    sf::Color getTextColor();
    sf::Color getBoxColor();

    void setLightView();
    void setNightView();

    void setFillColor(sf::Color c);

    //from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    // from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();

    //from SnapshotInterface
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);

};


#endif //SFML_PROJECT_1_ITEM_H
