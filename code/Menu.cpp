//
// Created by hello on 10/25/2021.
//

#include "Menu.h"

Menu::Menu()
{
    //default Menubar position
    setTitleBoxPosition({0,0});
    menu.setTextSize(20);
    //hide itemlist
    itemlist.enableState(HIDDEN);
    menu.enableState(NIGHTVIEW);
    menu.disableState(LIGHTVIEW);
    setNightView();
    //setNightView();
}

void Menu::addItem(std::string s) {
    itemlist.addItem(s);
}

void Menu::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(menu);
    if(!itemlist.isEnabled(HIDDEN))
        window.draw(itemlist);
}

void Menu::addEventHandler(sf::RenderWindow &window, sf::Event event) {

//    clicked = itemlist.getClicked();
//    std::cout << "clicked:" << clicked << std::endl;
    if(!itemlist.isEnabled(HIDDEN)) {
        itemlist.addEventHandler(window, event);

    }
    if( MouseEvents<Item>::mouseClicked(menu, window))
    {
        //TODO display itemlist and use HIDDEN state
        menu.setFillColor(sf::Color::Blue);
        itemlist.disableState(HIDDEN);
        //std::cout << "menu clicked\n";

        //itemlist.
    }
    else if(!MouseEvents<Item>::hovered(menu, window) && itemlist.isEnabled(HIDDEN))
    {
        //itemlist.enableState(HIDDEN);

        //menu.setFillColor(sf::Color::Black);
        if(menu.isEnabled(NIGHTVIEW))
        {
            menu.setNightView();
        }
        else
        {
            menu.setLightView();
        }
        //cl
//        clicked = itemlist.getClicked();
//
//        std::cout << "clicked:" << clicked << std::endl;
//        itemlist.setClicked("");
    }
    if(itemlist.isEnabled(CLICKED))
    {
        clicked = itemlist.getClicked();

        //std::cout << "clicked:" << clicked << std::endl;
        itemlist.setClicked("");
        itemlist.disableState(CLICKED);
        this->enableState(CLICKED);
    }
    //if(!itemlist.isEnabled(HIDDEN))

//        for (int i = 0; i < itemlist.size(); i++) {
//            if (MouseEvents<Item>::mouseClicked(itemlist.getItem(i), window)) {
//                clicked = itemlist.getItem(i).getText().getString();
//                //std::cout << clicked << " clicked\n";
//                itemlist.enableState(HIDDEN);
//                menu.setFillColor(sf::Color::Black);
//            }
//        }
//        if(!itemlist.isEnabled(HIDDEN) && MouseEvents<Item>::mouseClicked(window,event)) {
//            itemlist.enableState(HIDDEN);
//            menu.setFillColor(sf::Color::Black);
//        }
       // itemlist.addEventHandler(window, event);
//        if(itemlist.getClicked()!="")
//        {
//            clicked = itemlist.getClicked();
//            std::cout << clicked << " clicked\n";
//            //itemlist.enableState(HIDDEN);
//            menu.setFillColor(sf::Color::Black);
//        }
//        else if(!itemlist.isEnabled(HIDDEN) && MouseEvents<Item>::mouseClicked(window,event)) {
//            itemlist.enableState(HIDDEN);
//            menu.setFillColor(sf::Color::Black);
//            //clicked = "";
//        }
    //}
    //itemlist.addEventHandler(window, event);
//    if(!itemlist.isEnabled(HIDDEN) && clicked!="")
//    {
//        std::cout << clicked << " clicked\n";
//        clicked = itemlist.getClicked();
//    }

}

void Menu::update() {
    itemlist.update();
}

Snapshot &Menu::getSnapshot() {

}

void Menu::applySnapshot(const Snapshot &snapshot) {

}

void Menu::setMenuName(std::string s)
{
    menu.setText(s);
    menu.setTextSize(menu.getTextSize());

}

sf::Vector2f Menu::getTitleboxSize() {
    return menu.getBoxSize();
}

void Menu::setTitleBoxPosition(sf::Vector2f pos)
{
    menu.setPosition({pos.x,pos.y});
    itemlist.setPosition({menu.getPosition().x,
                          menu.getPosition().y+menu.getBoxSize().y});
}

sf::Vector2f Menu::getTitleBoxPosition() {
    return menu.getPosition();
}

sf::FloatRect Menu::getGlobalBounds() {
    return menu.getGlobalBounds();
}

std::string Menu::getMenuName() {
    return menu.getText().getString();
}

void Menu::setTextSize(float s)
{
    menu.setTextSize(s);
    itemlist.setTextSize(s);
    setTitleBoxPosition(menu.getPosition());
    //itemlist.set
}

std::string Menu::getClicked() {
    return clicked;
}

void Menu::setLightView()
{
    menu.enableState(LIGHTVIEW);
    menu.disableState(NIGHTVIEW);
    menu.setLightView();
    itemlist.setLightView();
}

void Menu::setNightView()
{
    menu.enableState(NIGHTVIEW);
    menu.disableState(LIGHTVIEW);
    menu.setNightView();
    itemlist.setNightView();
}

sf::FloatRect Menu::getTitleBounds() {
    return menu.getGlobalBounds();
}
