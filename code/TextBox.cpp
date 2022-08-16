//
// Created by hello on 10/6/2021.
//

#include "TextBox.h"

void TextBox::setPosition(sf::Vector2f pos)
{
    box.setPosition(pos);
}

void TextBox::setSize(sf::Vector2f size)
{
    box.setSize(size);
}

void TextBox::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(box);
}

void TextBox::addEventHandler(sf::RenderWindow &window, sf::Event event) {

}

void TextBox::update() {

}

Snapshot &TextBox::getSnapshot() {
    //return <#initializer#>;
}

void TextBox::applySnapshot(const Snapshot &snapshot) {

}

void TextBox::setOutlineColor(sf::Color c)
{
    box.setOutlineColor(c);

}

void TextBox::setFillColor(sf::Color c)
{
    box.setFillColor(c);
}

sf::FloatRect TextBox::getGlobalBounds() const{
    //std::cout << "bounds height: " << box.getGlobalBounds().height << "\n";
    return box.getGlobalBounds();
}

void TextBox::setOutlineThickness(float t)
{
    box.setOutlineThickness(t);
}

sf::Vector2f TextBox::getSize() {
    return box.getSize();
}

bool TextBox::contains(float x, float y) {
    //std::cout << "checking x: " << x << ", y: " << y << "\n";

    return box.getGlobalBounds().contains(x,y);
}

sf::Vector2f TextBox::getBoxPosition() {
    return box.getPosition();
}

float TextBox::getOutlineThickness() {
    return box.getOutlineThickness();
}
