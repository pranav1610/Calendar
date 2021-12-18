//
// Created by hello on 9/28/2021.
//

#ifndef MULTITEXT_MULTITEXT_H
#define MULTITEXT_MULTITEXT_H

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "LinkedList/DoublyLinkedList.h"
#include "Letter.h"
#include "Fonts.h"
#include "GUIComponent.h"
#include "HistoryNode.h"
#include "History.h"
#include "MouseEvents.h"


class MultiText : public GUIComponent{
private:
    DoublyLinkedList<Letter> typing;
    float fontSize;
    sf::Vector2f position;
    Snapshot snapshot;
    float windowWidth;

    //text properties
    float textBottomY = 0;
    float textRightX = 0;


public:
    typedef typename DoublyLinkedList<Letter>::iterator iterator;


    MultiText();
    //This function is to draw your text
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    //This function should be called outside of the pollEvent loop and is used for updates,
    // if any, needed after an event is handled and before the object is drawn on the screen
    void update();

    //This function should be in the pollEvent loop and is used to detect when a key is
    // pressed on the keyboard and concatenates the character to the sf::Text object
    void addEventHandler(sf::RenderWindow& window, sf::Event event);

    float getFontSize();
    void setFontSize(float s);

    float getWindowWidth();
    sf::Vector2f getPosition();
    int length();

    void setPosition(sf::Vector2f vec);

    //multitext list to string
    std::string toString();

    //true if x and y are inbounds of the multitext input
    bool contains(float x, float y);

    void push_back(char val, float windowWidth);

    iterator begin();

    iterator cbegin() const;

    iterator end();

    iterator cend() const;

    iterator rbegin();

    iterator crbegin() const;

    iterator rend();

    iterator crend() const;


    //from the sf::Drawable class
    //virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    // from EventHandler
    //virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    //virtual void update();

    //from SnapshotInterface
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snap);



};


#endif //MULTITEXT_MULTITEXT_H
