//
// Created by hello on 10/6/2021.
//

#include "Label.h"

Label::Label()
{
    label.setFont(Fonts::getFont());
    //label.setCharacterSize(30);
    //label.setPosition(100,100);
    //label.setLineSpacing();
}

void Label::setLabelSize(float s)
{
    label.setCharacterSize(s);
}

void Label::setLabelMargin(float t, float b, float l, float r)
{
    //label.
    //label.set
}

void Label::setLabel(std::string l)
{
    label.setString(l);
}

void Label::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(label);
}

void Label::addEventHandler(sf::RenderWindow &window, sf::Event event) {

}

void Label::update() {

}

Snapshot &Label::getSnapshot() {
    //return <#initializer#>;
}

void Label::applySnapshot(const Snapshot &snapshot) {

}

sf::FloatRect Label::getGlobalBounds() {
    return label.getGlobalBounds();
}

float Label::getLabelSize() {
    return label.getCharacterSize();
}

void Label::setLabelPosition(float x, float y)
{
    label.setPosition(x,y);
}

sf::Vector2f Label::getLabelPosition() {
    return label.getPosition();
}
