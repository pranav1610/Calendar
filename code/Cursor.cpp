//
// Created by hello on 10/6/2021.
//

#include "Cursor.h"

Cursor::Cursor()
{

    cursor.setString("|");
    //disableState(HIDDEN);
    //cursor.setPosition();
}


void Cursor::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    if(isEnabled(BLINKING) && !isEnabled(HIDDEN))
        window.draw(cursor);
}

void Cursor::addEventHandler(sf::RenderWindow &window, sf::Event event)
{

}

void Cursor::update() {
    //set amount of time and turn on/off
    float milli = clock.getElapsedTime().asMilliseconds();
    //default cursor blinking rate - 2 twice in a second
    if(milli>=500)
    {
        blinkCursor();
        clock.restart();
    }

}

Snapshot &Cursor::getSnapshot() {
    //return <#initializer#>;
}

void Cursor::applySnapshot(const Snapshot &snapshot) {

}

void Cursor::blinkCursor()
{
    if(isEnabled(BLINKING))
    {
        disableState(BLINKING);
    }
    else {
        enableState(BLINKING);
    }
}

void Cursor::setPosition(sf::Vector2f pos)
{
    cursor.setPosition(pos);
}

void Cursor::setCursorSize(float s)
{
    cursor.setLetterSize(s);
}

sf::Vector2f Cursor::getPosition() {
    return cursor.getPosition();
}
