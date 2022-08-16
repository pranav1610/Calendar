//
// Created by hello on 10/21/2021.
//

#include "Item.h"

Item::Item() {
    sidePadding = 200;
    topPadding = 10;

    box.setFillColor(sf::Color::Transparent);
    //box.setOutlineColor(sf::Color::White);
    //box.setOutlineThickness(2);

    text.setFont(Fonts::getFont());
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(20);
    //box.setSize({150, 40});
    text.setString("Item");

    sideRatio = sidePadding/text.getCharacterSize();
    topRatio = topPadding/text.getCharacterSize();

    //text.setPosition({100,100});
    box.setPosition(0,0);
    box.setSize({text.getGlobalBounds().width+sidePadding, static_cast<float>(text.getCharacterSize())+topPadding});
    //text.setPosition(box.getGlobalBounds().left + box.getGlobalBounds().width/2-text.getGlobalBounds().width/2,
                  //box.getGlobalBounds().top + box.getGlobalBounds().height/2-text.getGlobalBounds().height/2);
    recenter();
    //text.setPosition(box.)
    this->disableState(VISIBLE);

    setNightView();

}

void Item::setBoxSize(float w, float h)
{
//    //sidePadding = 1.5*text.getGlobalBounds().width;
//    //topPadding = 1.5*text.getGlobalBounds().height;
//    box.setSize({text.getGlobalBounds().width+sidePadding, text.getGlobalBounds().height+topPadding});
    box.setSize({w,h});
}

void Item::setTextSize(float s)
{
    //std::cout << "here\n";
    text.setCharacterSize(s);
    //sidePadding = 1.5*text.getGlobalBounds().width;
    //sidePadding = sideRatio*text.getCharacterSize();
    //box.setSize({text.getGlobalBounds().width+sidePadding, (static_cast<float>(text.getCharacterSize())+topPadding)});
    //box.setSize({text.+sidePadding, (static_cast<float>(text.getCharacterSize())+topPadding)});
    box.setSize({text.getGlobalBounds().width+sidePadding, static_cast<float>(s)+topPadding});
    recenter();
    //topPadding = 1.5*text.getGlobalBounds().height;
    //box.setSize({text.getGlobalBounds().width+sidePadding, s+topPadding});
}

void Item::setText(std::string s)
{
    text.setString(s);
    //sidePadding = 1.5*text.getGlobalBounds().width;
    //sidePadding = sideRatio*text.getCharacterSize();
    //topPadding = 0.5*text.getGlobalBounds().height;
//    box.setSize({text.getGlobalBounds().width+sidePadding, static_cast<float>(text.getCharacterSize())+topPadding});
//    recenter();
}

void Item::setPosition(sf::Vector2f pos) {
    position = pos;
    box.setPosition(pos);
    //text.setPosition(box.getGlobalBounds().left + box.getGlobalBounds().width/2-text.getGlobalBounds().width/2,
     //                box.getGlobalBounds().top + box.getGlobalBounds().height/2-text.getGlobalBounds().height/2);
    recenter();
}

sf::Vector2f Item::getPosition() {
    return box.getPosition();
}

sf::Vector2f Item::getBoxSize() {
    return box.getSize();
}

float Item::getTextSize() {
    return text.getCharacterSize();
}

void Item::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(box);
    //std::string s = text.getString();
    //std::cout << s << "\n";
    window.draw(text);
}

void Item::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    if(MouseEvents<Item>::hovered(*this,window))
    {
        this->setFillColor(sf::Color::Blue);
        //std::string s = itemlist.at(i).getText().getString();
        //std::cout << s << " hovered\n";
        this->enableState(HOVERED);
        if(MouseEvents<Item>::mouseClicked(*this,window))
        {
            //clicked = this->getText().getString();
            //std::cout << clicked << " clicked\n";
            this->enableState(CLICKED);
        }
        else
        {
            this->disableState(CLICKED);
        }


    }
    else
    {
        this->disableState(HOVERED);
        this->disableState(CLICKED);
        //itemlist.at(i).setFillColor(sf::Color::Black);
        if(this->isEnabled(LIGHTVIEW))
            setLightView();
        else
            setNightView();

    }
}

void Item::update() {

}

Snapshot &Item::getSnapshot() {
    //return <#initializer#>;
}

void Item::applySnapshot(const Snapshot &snapshot) {

}

sf::Text Item::getText() const{
    return text;
}

bool Item::contains(float x, float y) {
    //std::cout << "checking x: " << x << ", y: " << y << "\n";

    return box.getGlobalBounds().contains(x,y);
}

void Item::setFillColor(sf::Color c) {
    box.setFillColor(c);
}

void Item::recenter()
{
    text.setPosition(box.getGlobalBounds().left + box.getGlobalBounds().width/2-text.getGlobalBounds().width/2,
                     box.getGlobalBounds().top + box.getGlobalBounds().height/2-text.getGlobalBounds().height/2);
}

sf::FloatRect Item::getGlobalBounds() const{
    return box.getGlobalBounds();
}

void Item::setTextPosition(sf::Vector2f pos)
{
    text.setPosition(pos);
}

void Item::setLightView()
{
    this->enableState(LIGHTVIEW);
    this->disableState(NIGHTVIEW);
    text.setFillColor(sf::Color::Black);
    sf::Color c(209,209,209);
    box.setFillColor(c);
}

void Item::setNightView()
{
    this->enableState(NIGHTVIEW);
    this->disableState(LIGHTVIEW);
    //sf::Color c = sf::Color(91,91,91);
    box.setFillColor(sf::Color::Black);
    text.setFillColor(sf::Color::White);
}

sf::Color Item::getTextColor() {
    return text.getFillColor();
}

sf::Color Item::getBoxColor() {
    return box.getFillColor();
}
