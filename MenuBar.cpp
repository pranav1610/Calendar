//
// Created by hello on 10/25/2021.
//

#include "MenuBar.h"

MenuBar::MenuBar()
{
    //position.x = 0;

    setPosition(0,0);
}

void MenuBar::addMenu(std::string s)
{
    float newX = position.x;
    float newY = position.y;

    for(std::string name: menuNames)
    {
        newX += menuWidths[name];
    }

    Menu menu;
    menu.setMenuName(s);
    menubar[s] = menu;
    menuNames.push_back(s);


    //float newX = position.x + menubar.begin()->second.getGlobalBounds().width*(menubar.size()-1);
    //float newY = position.y;

    menubar[s].setTitleBoxPosition({newX, newY});


    menuWidths[s] = menubar[s].getTitleboxSize().x;
//    if(menubar.size()==1)
//    {
//        std::cout << "First menu\n";
//        menu.setTitleBoxPosition(position);
//    }
//    else
//    {
//        std::cout << "2 or more menus\n";
//        std::map<std::string, Menu>::reverse_iterator iter = menubar.rbegin();
//        //float newX = (*iter).second.getGlobalBounds().left + (*iter).second.getGlobalBounds().width;
//        //float newY = (*iter).second.getGlobalBounds().top;
//        std::cout << "position after " << (*iter).first << "\n";
//        float newX = (*iter).second.getTitleBoxPosition().x + (*iter).second.getTitleboxSize().x;
//        float newY = (*iter).second.getTitleBoxPosition().y;
//        std::cout << "x: " << (*iter).second.getTitleBoxPosition().x << ", size: " << (*iter).second.getTitleboxSize().x << "\n";
//        //std::cout << "position at x: " << newX << ", y: " << newY << "\n";
//        menu.setTitleBoxPosition({newX, newY});
//    }

    //menu already exists in menubar, so just add item to the menu
//    if(!menubar.empty() && menubar.count(s)>0)
//    {
//        std::cout << "Error: Menus must be unique!";
//    }
//    else if
//    //no instance of menu
//    else{
//        Menu menu;
//        menu.setMenuName(s);
//        if(menubar.size()==0)
//        {
//            std::cout << "First menu\n";
//            menu.setTitleBoxPosition(position);
//        }
//        else
//        {
//            std::cout << "2 or more menus\n";
//            std::map<std::string, Menu>::reverse_iterator iter = menubar.rbegin();
//            //float newX = (*iter).second.getGlobalBounds().left + (*iter).second.getGlobalBounds().width;
//            //float newY = (*iter).second.getGlobalBounds().top;
//            std::cout << "position after " << (*iter).first << "\n";
//            float newX = (*iter).second.getTitleBoxPosition().x + (*iter).second.getTitleboxSize().x;
//            float newY = (*iter).second.getTitleBoxPosition().y;
//            std::cout << "position at x: " << newX << ", y: " << newY << "\n";
//            menu.setTitleBoxPosition({newX, newY});
//        }
//        menubar[s] = menu;
//    }

}

void MenuBar::removeMenu(std::string s) {

}

int MenuBar::size() {
    return 0;
}

void MenuBar::setSize(int size) {

}

sf::Vector2f MenuBar::getPosition() {
    return position;
}

void MenuBar::setPosition(float x, float y)
{
    position.x = x;
    position.y = y;

//    std::map<std::string, Menu>::iterator iter;
//    int i = 0;
//    for(iter = menubar.begin();iter!=menubar.end();++iter)
//    {
//        float newX = position.x + menubar.begin()->second.getGlobalBounds().width*i;
//        float newY = position.y;
//
//        menubar[(iter->second).getMenuName()].setTitleBoxPosition({newX, newY});
//        ++i;
//    }

    //int i=0;
    //float newX = position.x;
    //float newY = position.y;

//    for(std::string s : menuNames)
//    {
//        newX += menubar[s].getGlobalBounds().width;
//
//        menubar[s].setTitleBoxPosition({newX, newY});
//        ++i;
//    }
    //for(std::string s: me)
}

void MenuBar::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    std::map<std::string, Menu>::const_iterator iter;
    for(iter=menubar.cbegin();iter!=menubar.cend();++iter)
    {
        window.draw((*iter).second);
    }
}

void MenuBar::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    std::map<std::string, Menu>::iterator iter;
    for(iter=menubar.begin();iter!=menubar.end();++iter)
    {
        (*iter).second.addEventHandler(window,event);

        if(iter->second.isEnabled(CLICKED))
        {
            clicked = iter->second.getClicked();
            iter->second.disableState(CLICKED);
            this->enableState(CLICKED);
            //std::cout << clicked << " clicked\n";
        }
    }

}

void MenuBar::update() {
    std::map<std::string, Menu>::iterator iter;
    for(iter=menubar.begin();iter!=menubar.end();++iter)
    {
        (*iter).second.update();
    }
}

Snapshot &MenuBar::getSnapshot() {
    //return <#initializer#>;
}

void MenuBar::applySnapshot(const Snapshot &snapshot) {

}

void MenuBar::addItemtoMenu(std::string menuname, std::string item)
{
    if(menubar.count(menuname)>0)
    {
        menubar[menuname].addItem(item);
        //std::cout << menuname << "\n";
    }
    else
    {
        std::cout << "Error: Key " << menuname << " doesnt exist";
        std::string i = std::string(menuname.length(), '~');
        std::cout << "\n\t   " << i << "\n\n";
    }
}

void MenuBar::setTextSize(float s)
{
    std::map<std::string, Menu>::iterator iter;
    for(iter=menubar.begin();iter!=menubar.end();++iter) {
        (*iter).second.setTextSize(s);
    }
    //setPosition(position.x, position.y);

    for(std::string name: menuNames)
    {
        menuWidths[name] = menubar[name].getTitleboxSize().x;
    }

//    int i=0;
//    for(std::string s: menuNames)
//    {
//        if(i>0)
//            menubar[s].setTitleBoxPosition({position.x+menuWidths[s], position.y});
//        i++;
//    }
    float newX = position.x;
    for(int i=1;i<menuNames.size();i++)
    {
        //std::cout << menuNames[i-1] << "\n";
        newX += menuWidths[menuNames[i-1]];
        menubar[menuNames[i]].setTitleBoxPosition({newX, position.y});
    }
    //setPosition(menubar.begin()->second.getPosition().x, menubar.begin()->second.getPosition().y);
}

std::string MenuBar::getClicked() {
    return clicked;
}

void MenuBar::setLightView()
{
    for(int i=0;i<menuNames.size();i++)
    {
        menubar[menuNames[i]].setLightView();
    }
}

void MenuBar::setNightView()
{
    for(int i=0;i<menuNames.size();i++)
    {
        menubar[menuNames[i]].setNightView();
    }
}

sf::FloatRect MenuBar::getTitleBounds() {
    return menubar.at(menuNames[0]).getTitleBounds();
}

void MenuBar::setClicked(std::string s)
{
    clicked = s;

}

