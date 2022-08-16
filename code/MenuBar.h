//
// Created by hello on 10/25/2021.
//

#ifndef SFML_PROJECT_1_MENUBAR_H
#define SFML_PROJECT_1_MENUBAR_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <map>
#include "GUIComponent.h"
#include "Menu.h"

class MenuBar : public GUIComponent{

private:
    std::map<std::string, Menu> menubar;
    std::map<std::string, float> menuWidths;
    //since map sorts the menus in lexicographic order.
    //Besides, since they're just strings, iteration through map becomes easier
    std::vector<std::string> menuNames;
    sf::Vector2f position;
    std::string clicked = "";
public:
    MenuBar();
    void addMenu(std::string s);
    void removeMenu(std::string s);
    sf::FloatRect getTitleBounds();
    int size();
    std::string getClicked();
    void setSize(int size);
    void setTextSize(float s);
    sf::Vector2f getPosition();
    void setPosition(float x, float y);

    void setClicked(std::string s);
    void addItemtoMenu(std::string menuname, std::string item);

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


#endif //SFML_PROJECT_1_MENUBAR_H
