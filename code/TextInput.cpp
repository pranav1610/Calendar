//
// Created by hello on 10/6/2021.
//

#include "TextInput.h"

void TextInput::setPosition(float x, float y)
{
    label.setLabelPosition(x,y);
    //std::cout << "label x: " << label.getPosition().x << ", label y: " << label.getPosition().y << "\n";
    //std::cout << "label left: " << label.getGlobalBounds().left << ", label top: " << label.getGlobalBounds().top << "\n";
    //std::cout << "label width: " << label.getGlobalBounds().width << ", label height: " << label.getGlobalBounds().height << "\n";

    //std::cout << "box x: " << box.getGlobalBounds().left << ", box y: " << box.getGlobalBounds().top << "\n";
    box.setPosition({label.getGlobalBounds().left + label.getGlobalBounds().width + 5,
                     label.getGlobalBounds().top + box.getOutlineThickness()});

    //text.setPosition({box.getGlobalBounds().left+5, box.getGlobalBounds().top+5});
    text.setPosition({box.getGlobalBounds().left + 5, box.getGlobalBounds().top +box.getOutlineThickness()});

    //when no text entered, cursor and first letter entered start from the same spot
    //cursor.setPosition({box.getGlobalBounds().left+5, box.getGlobalBounds().top+5});
    //cursor.setPosition({box.getGlobalBounds().left, box.getGlobalBounds().top +box.getOutlineThickness()});
    cursor.setPosition({box.getBoxPosition().x, box.getBoxPosition().y});
}

void TextInput::setLabelSize(float s)
{
    label.setLabelSize(s);
    text.setFontSize(s);

    //cursor little smaller than box to give it an elegant look!
    cursor.setCursorSize(s-3);

    //5 is just a hardcoded for the small margins above and below text
    box.setSize({300, s+5});
}

void TextInput::setLabelMargin(float t, float b, float l, float r)
{

}

void TextInput::setLabel(std::string l)
{
    label.setLabel(l);
}

void TextInput::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(label);
    window.draw(box);
    window.draw(text);
    window.draw(cursor);
}

void TextInput::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    if(MouseEvents<TextBox>::mouseClicked(box,window))
    {
        cursor.disableState(HIDDEN);
        cursor.enableState(BLINKING);

        //cursor.enableState(HIDDEN);
        //std::cout << "\nclicked in box\n";
    }
    else if(MouseEvents<sf::RectangleShape>::mouseClicked(window,event) )
    {
        cursor.enableState(HIDDEN);
        cursor.disableState(BLINKING);
        //cursor.disableState(HIDDEN);

        //std::cout << "\nclicked outside box\n";
    }
    //std::cout << box.getGlobalBounds().left << ", " << box.getGlobalBounds().top << "\n";
    //std::cout << box.getPosition().x << ", " << box.getPosition().y << "\n";
    //std::cout << "cursor x: " << cursor.getPosition().x << ", y: " << cursor.getPosition().y << "\n";
    //std::cout << "font size: " << text.getFontSize() << "\n";

    if(box.contains((cursor.getPosition().x+text.getFontSize()), (cursor.getPosition().y+text.getFontSize())))
    {
        text.disableState(LIMITED);
    }
    else
    {
        text.enableState(LIMITED);
    }

    //&& box.contains((cursor.getPosition().x+text.getFontSize()), (cursor.getPosition().y+text.getFontSize()))
    if(!cursor.isEnabled(HIDDEN))
        text.addEventHandler(window,event);

    //hovered on input box
//    if(MouseEvents<TextBox>::hovered(box, window))
//    {
//        std::cout << "\nhovered on input box\n";
//    }

    //dragged on Multitext(or input) -- needed for highlighting
//    if(MouseEvents<MultiText>::draggedOver(text, window, event))
//    {
//        std::cout << "\ndragged over text\n";
//    }

//    if(MouseEvents<TextBox>::draggedOver(box, window, event))
//    {
//        std::cout << "\ndragged over box\n";
//    }

}

void TextInput::update()
{
    //cursor.update();


    //color code:
    MultiText::iterator iterB = text.begin();
    MultiText::iterator iterE = text.end();

    //std::cout << "\ntext size: " << text.length();

    colorCode.changeColor(iterB, iterE);

    //cursor position
    MultiText::iterator iter = text.rbegin();
    if(text.length()==0)
    {
        //std::cout << "empty here\n";
        cursor.setPosition({box.getBoxPosition().x, box.getBoxPosition().y});
        //cursor.setPosition({207,10});
        //cursor.setPosition({box.getGlobalBounds().left, box.getGlobalBounds().top +box.getOutlineThickness()});
        //std::cout << "cursor x1: ";
        //std::cout << "cursor y1: \n";
    }
    else if(iter!=text.end())
    {
        float cursorX = (*iter).getGlobalBounds().left + (*iter).getGlobalBounds().width;
        float cursorY = (*iter).getPosition().y;

        cursor.setPosition({cursorX,cursorY});
        //std::cout << "cursor x2: " << cursorX;
        //std::cout << "cursor y2: " << cursorY << "\n";
    }
    cursor.update();

}


Snapshot &TextInput::getSnapshot() {
    //return <#initializer#>;
}

void TextInput::applySnapshot(const Snapshot &snapshot) {

}

TextInput::TextInput()
{
    //default values in case the user doesnt pass in anything
    setLabel("Enter here: ");
    setLabelSize(10);

    //box.setSize({200, label.getLabelSize()+5});
    box.setFillColor(sf::Color::Black);
    box.setOutlineThickness(2);

    sf::Color c(255, 94, 110);
    box.setOutlineColor(c);


    //default in case the user doesnt set the postion
    setPosition(0,0);


}
//The Node's global bounds, including those changed by its children based on its state
sf::FloatRect TextInput::getGlobalBounds() const
{
    return box.getGlobalBounds();
}

std::string TextInput::tostring() {
    return text.toString();
}
