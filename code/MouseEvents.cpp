//
// Created by hello on 10/3/2021.
//

#ifndef LETTER_CPP_MOUSEEVENTS_CPP
#define LETTER_CPP_MOUSEEVENTS_CPP

#include "MouseEvents.h"

template <class T>
int MouseEvents<T>::clicks = 1;

template <class T>
sf::Clock MouseEvents<T>::clock;

template<class T>
bool MouseEvents<T>::mouseClicked(T &object, sf::RenderWindow &window)
{
    //MouseEvents::isInBounds(object, window)

    if(MouseEvents<T>::isInBounds(object, window) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        //countClicks(event) --> which event?
        //while(MouseEvents<T>::isInBounds(object, window) && sf::Mouse::isButtonPressed(sf::Mouse::Left));
            return true;
    }
    return false;
}
template <class T>
bool MouseEvents<T>::mouseClicked(sf::RenderWindow &window, sf::Event event) {
    if ((sf::Mouse::isButtonPressed(sf::Mouse::Left))
     && ((sf::Mouse::getPosition(window).x <= window.getSize().x) && (sf::Mouse::getPosition(window).x >=0)
     && (sf::Mouse::getPosition(window).y <= window.getSize().y) && (sf::Mouse::getPosition(window).y >=0))) {
        //std::cout << "\nLeft Mouse pressed inside window\n";

        MouseEvents<T>::countClicks(event);
        return true;

    }
    return false;
    //if((sf::Mouse::isButtonPressed(sf::Mouse::Left) && window.ge)



    //event.Mouse

    return false;
}


template <class T>
bool MouseEvents<T>::mouseDoubleClicked()
{
    return (MouseEvents<T>::clicks==2);
}
template <class T>
bool MouseEvents<T>::mouseTripleClicked() {
    return (MouseEvents::clicks==3);
}

template<class T>
bool MouseEvents<T>::draggedOver(T &object, sf::RenderWindow &window, sf::Event event) {
//    if(mouseClicked(object, window) && event.type == sf::Event::MouseMoved)
//    {
//        return true;
//    }
    return (MouseEvents<T>::mouseClicked(object, window) && event.type == sf::Event::MouseMoved);
}

template<class T>
bool MouseEvents<T>::hovered(T &object, sf::RenderWindow &window) {
    // event.Mouse
    return MouseEvents::isInBounds(object,window);
//    return MouseEvents::isInBounds(object,window) &&
//    !sf::Mouse::isButtonPressed(sf::Mouse::Left)
//    && !sf::Mouse::isButtonPressed(sf::Mouse::Right)
//    && !sf::Mouse::isButtonPressed(sf::Mouse::Middle);
}

template <class T>
void MouseEvents<T>::countClicks(sf::Event event)
{
    float milli = MouseEvents::clock.getElapsedTime().asMilliseconds();
    if(milli>=100 && milli<=500 && event.MouseButtonReleased) {
        MouseEvents::clicks++;
        MouseEvents::clock.restart();
    }
    if(milli>500)
    {
        MouseEvents::clicks=1;
        MouseEvents::clock.restart();
    }
    if(MouseEvents::clicks>=3)
        MouseEvents::clicks = 3;
}

//do we need window?
template<class T>
bool MouseEvents<T>::isInBounds(T &object, sf::RenderWindow &window) {

    //std::cout << "top: " << object.getGlobalBounds().top << ", height: " << object.getGlobalBounds().height;
    //std::cout << ", left: " << object.getGlobalBounds().left << ", width: " << object.getGlobalBounds().width << "\n";

    if(object.contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif //LETTER_CPP_MOUSEEVENTS_CPP

