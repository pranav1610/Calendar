//
// Created by hello on 10/6/2021.
//

#ifndef SFML_PROJECT_1_TEXTBOX_H
#define SFML_PROJECT_1_TEXTBOX_H

#include <SFML/Graphics.hpp>

#include "GUIComponent.h"

class TextBox : public GUIComponent{
private:
    sf::RectangleShape box;
public:

    sf::Vector2f getSize();

    void setOutlineColor(sf::Color c);
    void setFillColor(sf::Color c);
    sf::Vector2f getBoxPosition();
    void setPosition(sf::Vector2f pos);
    void setSize(sf::Vector2f size);
    sf::FloatRect getGlobalBounds() const;
    bool contains(float x, float y);
    float getOutlineThickness();
    void setOutlineThickness(float t);

    //from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    // from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();

    //from SnapshotInterface
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);


};


#endif //SFML_PROJECT_1_TEXTBOX_H
