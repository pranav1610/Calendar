//
// Created by hello on 11/6/2021.
//

#ifndef FILETREE_FILEITEM_H
#define FILETREE_FILEITEM_H

#include <SFML/Graphics.hpp>
#include "Image.h"
#include "Item.h"

class FileItem: public Item{
private:
    //this is the folder or file icon
    sf::Sprite icon;
    float padding = 5;
    std::string value;
    //Position of FileItem
    sf::Vector2f position;
public:
    //Constructors
    FileItem();
    FileItem(Image::imageOf iconType, std::string text, sf::Vector2f size, sf::Vector2f pos);

    std::string getValue() const;

    //GUIComponent pure virtual functions, refer to the TextInput Project for Info
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    //I use this function to highlight the item when clicked, and unhighlight when something
    //else is clicked
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    //Returns the bounds of the item
    sf::FloatRect getGlobalBounds() const;
    //returns the size of the item
    sf::Vector2f getSize();
    //returns the size of the item
    sf::Vector2f getPosition() const;
    //sets the position of the item
    void setPosition(sf::Vector2f pos);
    //uses an enum to change the icon to a folder or file
    void setIcon(Image::imageOf iconType);
    void setIconSize(Image::imageOf iconType);
    void resize();
    void update();
    void setFillColor(sf::Color c);
    void leftAlign(sf::Vector2f pos);

    void setNightView();
    void setLightView();

};


#endif //FILETREE_FILEITEM_H
