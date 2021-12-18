//
// Created by hello on 10/23/2021.
//

#include "ItemList.h"

ItemList::ItemList()
{
    position.x = 0;
    position.y = 0;
    longestWidth = 0;
    longestHeight = 0;

    setNightView();
    //this->enableState(NIGHTVIEW);
    //this->disableState(LIGHTVIEW);
}

sf::Vector2f ItemList::getPosition() {
    return position;
}

void ItemList::setPosition(sf::Vector2f pos)
{
    if(itemlist.empty())
    {
        position.x = pos.x;
        position.y = pos.y;
        return;
    }
    if(itemlist.size()>=1) {
        itemlist.at(0).setPosition(pos);
        position.x = pos.x;
        position.y = pos.y;
    }
    for(int i=1;i<itemlist.size();i++)
    {
        itemlist.at(i).setPosition({itemlist.at(i-1).getPosition().x,
                                    itemlist.at(i-1).getPosition().y + itemlist.at(i).getBoxSize().y});
    }
}

void ItemList::addItem(std::string s)
{
    //TODO position for first more flexible
    Item item;


    if(itemlist.empty())
    {

        longest = s;
        Item temp;
        temp.setText(s);
        temp.setTextSize(temp.getTextSize());
        //box.setSize({text.getGlobalBounds().width+sidePadding, static_cast<float>(text.getCharacterSize())+topPadding});
        //recenter();
        longestWidth = temp.getBoxSize().x;
        longestHeight = temp.getBoxSize().y;
        item.setPosition({position.x,position.y});

    }
    else
    {
        if(s.length()>longest.length())
        {
            //std::cout << "longest: " << s << "\n";
            Item temp;
            temp.setText(s);
            temp.setTextSize(temp.getTextSize());
            longest = s;
            longestWidth = temp.getBoxSize().x;

        }
        item.setPosition({itemlist.at(itemlist.size()-1).getPosition().x,
                          itemlist.at(itemlist.size()-1).getPosition().y + itemlist.at(itemlist.size()-1).getBoxSize().y});
    }
    item.setText(s);
    item.recenter();

    //std::cout << "longest: " << longest << "\n";
    //std::cout << "longest w: " << longestWidth << "\n";

    itemlist.push_back(item);
}

void ItemList::removeItem(std::string s)
{
    for(int i=0;i<itemlist.size();i++)
    {
        if(itemlist.at(i).getText().getString()==s)
        {
            itemlist.erase(itemlist.begin()+i);
            return;
        }
    }
}

void ItemList::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    for(int i=0;i<itemlist.size();i++)
    {
        window.draw(itemlist.at(i));
    }
}

void ItemList::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    for(int i=0;i<itemlist.size();i++)
    {
        itemlist.at(i).addEventHandler(window,event);
        if(itemlist.at(i).isEnabled(CLICKED))
        {
            this->enableState(CLICKED);
            this->enableState(HIDDEN);
            clicked = itemlist.at(i).getText().getString();
            //std::cout << clicked << " clicked\n";
        }

//        else
//        {
//            this->disableState(HIDDEN);
//        }
//        if(MouseEvents<Item>::hovered(itemlist.at(i),window))
//        {
//            itemlist.at(i).setFillColor(sf::Color::Blue);
//            //std::string s = itemlist.at(i).getText().getString();
//            //std::cout << s << " hovered\n";
//            this->enableState(HOVERED);
//            if(MouseEvents<Item>::mouseClicked(itemlist.at(i),window))
//            {
//                clicked = itemlist.at(i).getText().getString();
//                //std::cout << clicked << " clicked\n";
//            }
//
//        }
//        else
//        {
//            this->disableState(HOVERED);
//            //itemlist.at(i).setFillColor(sf::Color::Black);
//            if(this->isEnabled(LIGHTVIEW))
//                itemlist.at(i).setLightView();
//            else
//                itemlist.at(i).setNightView();
//
//        }
    }
//    if(isEnabled(HIDDEN))
//        clicked = "";
}

void ItemList::update()
{
    //std::cout << "longest width: " << longestWidth <<"\n";
    for(int i=0;i<itemlist.size();i++)
    {
        itemlist.at(i).setBoxSize(longestWidth,longestHeight);
        //setPosition(itemlist.begin()->getPosition());
        //itemlist.at(i).setTextSize(itemlist.at(i).getTextSize());
        itemlist.at(i).recenter();
    }
}

Snapshot &ItemList::getSnapshot() {
    //return <#initializer#>;
}

void ItemList::applySnapshot(const Snapshot &snapshot) {

}

int ItemList::size() {
    return itemlist.size();
}

Item& ItemList::getItem(int i) {
    return itemlist.at(i);
}

void ItemList::setTextSize(float s)
{
    longestWidth = 0;
    for(int i=0;i<itemlist.size();i++)
    {
        itemlist.at(i).setTextSize(s);

        if(itemlist.at(i).getGlobalBounds().width > longestWidth)
        {
            longestWidth = itemlist.at(i).getGlobalBounds().width;
            longestHeight = itemlist.at(i).getGlobalBounds().height;
        }
    }
}

std::string ItemList::getClicked() {
    return clicked;
}

void ItemList::setLightView()
{
    this->disableState(NIGHTVIEW);
    this->enableState(LIGHTVIEW);
    for(int i=0;i<itemlist.size();i++)
    {
        itemlist[i].setLightView();
        if(itemlist[i].isEnabled(HOVERED))
        {
            itemlist[i].setFillColor(sf::Color::Blue);
        }
    }
}

void ItemList::setNightView()
{
    this->disableState(LIGHTVIEW);
    this->enableState(NIGHTVIEW);
    //bool flag= false;
//    for(int i=0;i<itemlist.size();i++)
//    {
//        if(itemlist[i].getBoxColor()==sf::Color::Blue)
//        {
//            flag = true;
//        }
//        itemlist[i].setNightView();
//        if(flag)
//        {
//            itemlist[i].setFillColor(sf::Color::Blue);
//        }
//    }
    for(int i=0;i<itemlist.size();i++)
    {
        itemlist[i].setNightView();
        if(itemlist[i].isEnabled(HOVERED))
        {
            itemlist[i].setFillColor(sf::Color::Blue);
        }
    }
}

void ItemList::setClicked(std::string s)
{
    clicked = s;
}
