//
// Created by hello on 9/28/2021.
//

#include "MultiText.h"

MultiText::MultiText()
{
    position = sf::Vector2f(0,0);
}

void MultiText::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    DoublyLinkedList<Letter>::iterator iter;
    for(iter = typing.cbegin();iter!=typing.cend();++iter)
    {
        window.draw(*iter);
    }

}

void MultiText::update()
{

}

void MultiText::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    windowWidth = window.getSize().x;
    Letter l;
    char c;

    //&& box.contains((cursor.getPosition().x+text.getFontSize()), (cursor.getPosition().y+text.getFontSize()))


    if (event.type == sf::Event::TextEntered)
    {
        if(event.text.unicode == 8)
        {
            if(typing.size()>0) {
                History::pushHistory({getSnapshot(), this});
                typing.removeTail();
            }
        }
        else if(event.text.unicode < 128 && !isEnabled(LIMITED))
        {
            //std::cout << "accept\n";
            //on pressing enter - text input box should not allow typing outside the box
            if(event.text.unicode == '\r')
            {
                c = '\n';
                //push_back(c, window.getSize().x);
            }
            else
            {
                History::pushHistory({getSnapshot(), this});
                c = static_cast<char>(event.text.unicode);
                push_back(c, window.getSize().x);
            }

        }

    }
}
sf::Vector2f MultiText::getPosition()
{
    return position;
}

void MultiText::setPosition(sf::Vector2f vec)
{
    position = vec;
}

void MultiText::push_back(char val, float windowWidth)
{
    Letter l;
    l.setCharacter(val);
    l.setLetterSize(fontSize);

    if(typing.is_empty())
    {
        //std::cout << "empty\n";
        l.setPosition(position);
    }

    else
    {
        DoublyLinkedList<Letter>::iterator iter;
        iter = typing.rbegin();

        //text input box should not allow typing outside the box
        if (val=='\n')
        {
            //std::cout << "\nenter\n";
//            l.setPosition(position.x, (*iter).getPosition().y + (*iter).getGlobalBounds().height + 10);
            //l.setPosition(position.x, (*iter).getGlobalBounds().top + (*iter).getGlobalBounds().height);
        }
        else{
            float newX = (*iter).getGlobalBounds().left + (*iter).getGlobalBounds().width;
            float newY = (*iter).getPosition().y;

            if((newX+l.getGlobalBounds().width)>=(windowWidth))
            {
                newX = position.x;
                newY = (*iter).getGlobalBounds().top + (*iter).getGlobalBounds().height;

            }
            textRightX = newX;
            textBottomY = newY + l.getCharacterSize();
            l.setPosition(newX, newY);
        }
    }
    //insert now
    typing.insertAfterTail(l);
}

MultiText::iterator MultiText::begin() {
    return typing.begin();
}

MultiText::iterator MultiText::cbegin() const {
    return typing.cbegin();
}

MultiText::iterator MultiText::end() {
    return typing.end();
}

MultiText::iterator MultiText::cend() const {
    return typing.cend();
}
MultiText::iterator MultiText::rbegin() {
    return typing.rbegin();
}

MultiText::iterator MultiText::crbegin() const {
    return typing.crbegin();
}

MultiText::iterator MultiText::rend() {
    return typing.rend();
}

MultiText::iterator MultiText::crend() const {
    return typing.crend();
}

int MultiText::length() {
    //std::cout << "size: " << typing.size();
    return typing.size();
}

Snapshot &MultiText::getSnapshot() {

    std::string input = toString();
    snapshot.setObjectInfo(input);
    //std::cout << "snapshot: " << snapshot.getObjectInfo() << "\n";

    return snapshot;
}

void MultiText::applySnapshot(const Snapshot &snap)
{
    snapshot = snap;

    if(!typing.is_empty())
        typing.clear();

    std::string result = snapshot.getObjectInfo();

    for(int i=0;i<result.length();i++)
    {
        push_back(result[i], windowWidth);
    }

}

void MultiText::setFontSize(float s)
{
    fontSize = s;
}

float MultiText::getFontSize() {
    return fontSize;
}

std::string MultiText::toString() {
    //apply snapshot before inserting
    MultiText::iterator iter;
    std::string input = "";
    for(iter=typing.begin();iter!=typing.end();++iter)
    {
        input += (*iter).getCharacter();
    }
    return input;
}

//bool TextBox::contains(float x, float y) {
//    return box.getGlobalBounds().contains(x,y);
//}
bool MultiText::contains(float x, float y) {

//    std::cout << "postition y: " << position.y<< "\n";
//    std::cout << "y: " << y << "\n";
//    std::cout << "textBottomY: " << textBottomY << "\n";
//
//    std::cout << "postition x: " << position.x<< "\n";
//    std::cout << "x: " << x << "\n";
//    std::cout << "textRightX: " << textRightX << "\n";

    std::string result = ((position.y<=y && y<=textBottomY)
                          && (position.x<=x && x<=textRightX)) ? "True" : "False";

    std::cout << result << std::endl;

    return (position.y<=y && y<=textBottomY)
            && (position.x<=x && x<=textRightX);
}
