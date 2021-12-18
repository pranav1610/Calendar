//
// Created by hello on 10/23/2021.
//

#include "InputBox.h"

InputBox::InputBox()
{
    this->setText("Input");
    this->setBoxSize(200, 50);
    sf::Color color(112, 107, 105);
    this->setFillColor(color);
}

void InputBox::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    Item::draw(window, states);
    //w.draw(inputbox);
}

void InputBox::addEventHandler(sf::RenderWindow &window, sf::Event event) {
}

void InputBox::update() {
    this->setTextSize(this->getTextSize());
}

Snapshot &InputBox::getSnapshot() {

}

void InputBox::applySnapshot(const Snapshot &snapshot) {

}

void InputBox::setLightView()
{
    Item::setLightView();
    sf::Color c(196,196,196);
    this->setFillColor(c);
}

void InputBox::setNightView() {

    Item::setNightView();
    sf::Color c(91,91,91);
    this->setFillColor(c);

}
