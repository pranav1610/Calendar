//
// Created by hello on 10/23/2021.
//

#include "DropdownMenu.h"

DropdownMenu::DropdownMenu()
{
    //set default position

    setPosition(0,0);
    //hide itemlist
    itemlist.enableState(HIDDEN);

    setNightView();

}

void DropdownMenu::draw(sf::RenderTarget &window, sf::RenderStates states) const
{

    window.draw(inputbox);
    if(!itemlist.isEnabled(HIDDEN))
        window.draw(itemlist);
}

void DropdownMenu::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    //itemlist.addEventHandler(window, event);

    if( MouseEvents<InputBox>::mouseClicked(inputbox, window))
    {
        //TODO display itemlist and use HIDDEN state
        itemlist.disableState(HIDDEN);
        //std::cout << "Item clicked\n";
        //this->disableState(HIDDEN);
        //itemlist.
    }
    else if(!itemlist.isEnabled(HIDDEN)) {
        itemlist.addEventHandler(window, event);
        if(itemlist.getClicked()!="")
        {
            //clicked = itemlist.getClicked();
            History::pushHistory({getSnapshot(), this});
            inputbox.setText(itemlist.getClicked());
            inputbox.setTextSize(inputbox.getTextSize());
            //inputbox.update();
            //recenter the item in the input box as all items may not be of the same length
            inputbox.recenter();
        }
        else if(MouseEvents<sf::RectangleShape>::mouseClicked(window,event)) {
            //this->enableState(HIDDEN);
            itemlist.enableState(HIDDEN);
        }
//        if(!itemlist.isEnabled(HIDDEN) && MouseEvents<Item>::mouseClicked(window,event)) {
//            //itemlist.enableState(HIDDEN);
//            menu.setFillColor(sf::Color::Black);
//        }
//        for (int i = 0; i < itemlist.size(); i++) {
//            if (MouseEvents<Item>::mouseClicked(itemlist.getItem(i), window)) {
//                History::pushHistory({getSnapshot(), this});
//                inputbox.setText(itemlist.getItem(i).getText().getString());
//                inputbox.setTextSize(inputbox.getTextSize());
//                //inputbox.update();
//                //recenter the item in the input box as all items may not be of the same length
//                inputbox.recenter();
//                //itemlist.enableState(HIDDEN);
//            }
//        }
//
//        if(MouseEvents<Item>::mouseClicked(window,event))
//            itemlist.enableState(HIDDEN);
    }
    itemlist.addEventHandler(window, event);
//    else
//    {
//        if(!itemlist.isEnabled(HIDDEN))
//        {
//            for(int i=0;i<itemlist.size();i++)
//            {
//                if(MouseEvents<Item>::mouseClicked(itemlist.getItem(i), window))
//                {
//                    History::pushHistory({getSnapshot(), this});
//                    inputbox.setText(itemlist.getItem(i).getText().getString());
//                    //recenter the item in the input box as all items may not be of the same length
//                    inputbox.recenter();
//                    itemlist.enableState(HIDDEN);
//                }
//            }
//        }
//        else if(MouseEvents<Item>::mouseClicked(window,event))
//            itemlist.enableState(HIDDEN);
//    }

}

void DropdownMenu::update()
{
    inputbox.update();
    itemlist.update();
}

Snapshot &DropdownMenu::getSnapshot() {

    std::string s = inputbox.getText().getString();
    //std::cout << "snapshot: " << s << "\n";
    snapshot.setObjectInfo(s);
    return snapshot;
}

void DropdownMenu::applySnapshot(const Snapshot &snapshot1)
{
    snapshot = snapshot1;
    std::string result = snapshot.getObjectInfo();
    //std::cout << "go back to: " << result << "\n";
    inputbox.setText(result);
    inputbox.recenter();

}

void DropdownMenu::addItem(std::string s)
{
    itemlist.addItem(s);
}

void DropdownMenu::setPosition(float x, float y) {
    inputbox.setPosition({x,y});
    itemlist.setPosition({inputbox.getPosition().x,
                          inputbox.getPosition().y+inputbox.getBoxSize().y});
}

void DropdownMenu::setDropdownMenuName(std::string s)
{
    inputbox.setText(s);
    inputbox.setTextSize(inputbox.getTextSize());
}

void DropdownMenu::setTextSize(float s)
{
    inputbox.setTextSize(s);
    itemlist.setTextSize(s);
    itemlist.setPosition({inputbox.getPosition().x,
                          inputbox.getPosition().y+inputbox.getBoxSize().y});
}

sf::FloatRect DropdownMenu::getInputBoxBounds() const {
    return inputbox.getGlobalBounds();
}

std::string DropdownMenu::getDropdownMenuChoice() const{
    return inputbox.getText().getString();
}

void DropdownMenu::setLightView()
{
    itemlist.setLightView();
    inputbox.setLightView();
}

void DropdownMenu::setNightView()
{
    itemlist.setNightView();
    inputbox.setNightView();
}
