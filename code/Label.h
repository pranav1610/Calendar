//
// Created by hello on 10/6/2021.
//

#ifndef SFML_PROJECT_1_LABEL_H
#define SFML_PROJECT_1_LABEL_H

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Fonts.h"
#include "GUIComponent.h"

class Label : public GUIComponent{

private:
    sf::Text label;
public:
    Label();
    float getLabelSize();
    void setLabelSize(float s);
    sf::Vector2f getLabelPosition();
    void setLabelPosition(float x, float y);
    void setLabelMargin(float t, float b, float l, float r);
    void setLabel(std::string l);
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


#endif //SFML_PROJECT_1_LABEL_H
