//
// Created by hello on 11/6/2021.
//

#include "FileItem.h"

FileItem::FileItem(Image::imageOf iconType, std::string text, sf::Vector2f size, sf::Vector2f pos)
{
    value = text;
    this->position = pos;
    //std::cout << "before set pos\n";
    Item::setPosition(pos);
    //std::cout << "after set pos\n";

    //TODO use the size parameter
    this->setBoxSize(size.x, size.y);


    icon.setTexture(Image::getImage(iconType));
    //this->setIconSize(iconType);
    icon.setPosition({pos.x+padding, pos.y+padding});

    //set the text of File Item
    this->setText(text);

    this->setIconSize(iconType);
    //take care of positioning of FileItem
    //Item::setTextSize(Item::getTextSize());
    //Item::setBoxSize(Item::getBoxSize().x+icon.getGlobalBounds().width+padding,Item::getBoxSize().y);
    //leftAlign(pos);
}
FileItem::FileItem() : FileItem(Image::FILE, "Default.txt", {100, 25}, {0, 0}) {

}

void FileItem::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    Item::draw(window, states);
    window.draw(icon);
}

void FileItem::addEventHandler(sf::RenderWindow &window, sf::Event event) {

    if( MouseEvents<FileItem>::mouseClicked(*this, window))
    {
        //std::cout << "fileitem event\n";
        //TODO display itemlist and use HIDDEN state
        //Item::setFillColor(sf::Color::Blue);
        Item::enableState(HIGHLIGHTED);
        //this->disableState(HIDDEN);
        //std::cout << "menu clicked\n";
        //itemlist.
    }
    else if(MouseEvents<FileItem>::mouseClicked(window, event))
    {
        Item::disableState(HIGHLIGHTED);
        //Item::setFillColor(sf::Color::Transparent);
    }
}

sf::FloatRect FileItem::getGlobalBounds() const{
    return Item::getGlobalBounds();
}

sf::Vector2f FileItem::getSize(){
    //return Item::getSize();
}

sf::Vector2f FileItem::getPosition() const {
    return position;
}

void FileItem::setPosition(sf::Vector2f pos) {
    //Item::setPosition(pos);
    Item::setPosition(pos);
    icon.setPosition({pos.x+padding, pos.y+padding});
    leftAlign(pos);
}

void FileItem::setIcon(Image::imageOf iconType)
{

//    sf::Texture &texture = Image::getImage(iconType);
//    //icon.setPosition({100,100});
//    icon.setTexture(texture);
    //
    icon.setTexture(Image::getImage(iconType));
//    if(iconType==Image::FOLDER)
//        icon.setScale({0.01, 0.007});
//    else
//        icon.setScale({0.004, 0.004});

    //icon.setPosition(position);
}

std::string FileItem::getValue() const{
    return value;
}


void FileItem::resize()
{
    //Item::setBoxSize()
}

void FileItem::leftAlign(sf::Vector2f pos) {
    Item::setTextPosition({icon.getGlobalBounds().left+icon.getGlobalBounds().width+padding, pos.y});
}

void FileItem::setIconSize(Image::imageOf iconType) {
    //std::cout << value << " icon width before: " << icon.getGlobalBounds().width << "\n";
    if(iconType==Image::FOLDER)
        icon.setScale({0.1, 0.1});
    else
        icon.setScale({0.1, 0.1});


    //std::cout << value << "icon width after: " << icon.getGlobalBounds().width << "\n";
    Item::setTextSize(Item::getTextSize());
    Item::setBoxSize(Item::getBoxSize().x+icon.getGlobalBounds().width+padding,Item::getBoxSize().y);
//    //setPosition(Item::getPosition());
    Item::setTextPosition({icon.getGlobalBounds().left+icon.getGlobalBounds().width+padding,
                       Item::getPosition().y});
    //leftAlign(Item::getPosition());
}

void FileItem::setFillColor(sf::Color c) {
    Item::setFillColor(c);
}

void FileItem::update() {
    //Item::update();
    if(isEnabled(HIGHLIGHTED))
    {
        //std::cout << "coloring: " << data.getValue() << "\n";
        Item::setFillColor(sf::Color::Blue);
    }
    else
    {
        //std::cout << "uncoloring: " << data.getValue() << "\n";
        Item::setFillColor(sf::Color::Transparent);
    }

}

void FileItem::setNightView() {
    Item::setNightView();
}

void FileItem::setLightView() {
    Item::setLightView();
}
