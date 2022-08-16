//
// Created by hello on 11/6/2021.
//

#include "FileNode.h"

FileNode::FileNode()
{
    //data.enableState(SHOWCHILDREN);
    //disableState(VISIBLE);
}

FileNode::FileNode(Image::imageOf icon, std::string text,
                   sf::Vector2f size, sf::Vector2f position) : data(icon, text, size, position){

    if(icon==Image::FILE)
    {
        textInput = new TextInput();
    }
}

void FileNode::toggleSelf()
{
    if(this->isEnabled(VISIBLE))
    {
        this->disableState(VISIBLE);
        //std::cout << "hide " << data.getValue() << "\n";
        toggleChildren();
    }

    else {
        this->enableState(VISIBLE);
        //std::cout << "show " << data.getValue() << "\n";
        //std::cout << "show " << data.getValue() << "'s children\n";
    }
    //toggleChildren();
}


//TODO
//this tells the draw function whether or not to show the node's children
//this is done by toggling a state on and off
void FileNode::toggleChildren()
{
    //if(!this->isEnabled(VISIBLE) && this->isEnabled(HIGHLIGHTED))
        //if(!this->isEnabled(VISIBLE) || this->isEnabled(HIGHLIGHTED))
    //if(this->isEnabled(HIGHLIGHTED))
    //if(!this->isEnabled(VISIBLE) || this->isEnabled(HIGHLIGHTED))
    {
        for(auto iter=children.begin();iter!=children.end();++iter)
        {
            //std::cout << "toggle unhighliting " << data.getValue() << "\n";
            //iter->second->disableState(VISIBLE);
            iter->second->disableState(HIGHLIGHTED);
            iter->second->toggleChildren();
        }
        //std::cout << "show " << data.getValue() << "'s children\n";
    }
}
//TODO
//this is called in the draw function to reposition the children so they
//are indented and below the parent
void FileNode::reposition() const {
//get global bounds of data
//itereate through children

    sf::FloatRect bounds = data.getGlobalBounds();
    sf::Vector2f pos = data.getPosition();
    //pos.x =

    //int i=1;
    //TODO -- Which One?
    //1 //pos.y = data.getGlobalBounds().top + bounds.height;
    // or 2:
    if(data.getValue() !="")
    pos.y = getGlobalBounds().top + bounds.height;

    //children.begin()->second->setPosition(children.begin()->second->getPosition().x, pos.y);
    for(auto iter=children.begin();iter!=children.end();++iter)
    {
        iter->second->setPosition(iter->second->data.getPosition().x,pos.y);
        if((*iter).second->isLeaf())
        {
           (*iter).second->textInput->setPosition(iter->second->data.getPosition().x,
                                                  iter->second->data.getPosition().y+pos.y+iter->second->data.getGlobalBounds().height);
           pos.y += (*iter).second->textInput->getGlobalBounds().height;
        }
       // if(iter->second->data.getValue() !="")
            pos.y += iter->second->getGlobalBounds().height;
    }
}

//this draws the node. This is a recursive function to draw all the children nodes as well
// this will only draw the node's children when it is in the proper state
void FileNode::draw(sf::RenderTarget &window, sf::RenderStates states) const
{

//    if(data.getValue()!="")
//    {
//        reposition();
//        window.draw(data);
//    }

    reposition();
    window.draw(data);

    if(this->isLeaf())
    {
        window.draw(*textInput);
    }
    //reposition();
    //std::cout << "called draw\n";
    //if(data.isEnabled(SHOWCHILDREN))
    if(isEnabled(VISIBLE))
    {
        //std::cout << "dont draw\n";
        for(auto iter=children.begin();iter!=children.end();++iter)
        {
            //iter->second->reposition();
            iter->second->draw(window, states);
        }
    }

}
//This is not currently used
void FileNode::applySnapshot(const Snapshot &snapshot) {

}
//This calls the addEventHandler for all the children. It calls the toggleChildren function
// when the node's data (FileItem) is clicked on
void FileNode::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    data.addEventHandler(window,event);

    //TODO 1
    //
    if(this->isLeaf())//textInput!= nullptr)
    {
        textInput->addEventHandler(window,event);
    }
    //
    //TODO --> Need to call data's addEventHandler? -- will this check twice for mouse click?
    if(MouseEvents<FileItem>::mouseClicked(data, window))
    {
       // std::cout << data.getValue() << " clicked\n";
        //enableState(HIGHLIGHTED);

        //determine first if to show or hide children
        //toggleChildren();
        toggleSelf();
        //while(MouseEvents<FileItem>::mouseClicked(data, window));
    }

    //****
    else if(MouseEvents<FileItem>::mouseClicked(window, event))
    {
        //std::cout << "unhighlight " << data.getValue() << "\n";
        disableState(HIGHLIGHTED);
    }
}
//does nothing now
void FileNode::update()
{
//    if(isEnabled(HIGHLIGHTED))
//    {
//        //std::cout << "coloring: " << data.getValue() << "\n";
//        data.setFillColor(sf::Color::Blue);
//    }
//    else
//    {
//        //std::cout << "uncoloring: " << data.getValue() << "\n";
//        data.setFillColor(sf::Color::Transparent);
//    }
    data.update();
    //std::cout << "here\n";
    if(this->isLeaf()) //textInput!= nullptr
    {
        //std::cout << "here\n";
        //std::cout << textInput->tostring() << "\n";
        textInput->update();
    }
}

//does nothing now
Snapshot &FileNode::getSnapshot() {
    //return <#initializer#>;
}

sf::FloatRect FileNode::getGlobalBounds() const{

    float paddingBelowInput = 20;
    sf::FloatRect bounds;

    bounds =  data.getGlobalBounds();

    if(this->isEnabled(VISIBLE))
    {
        for(auto iter = children.begin();iter!=children.end(); ++iter)
        {
            bounds.height += iter->second->getGlobalBounds().height;
            if(iter->second->isLeaf())
            {
                bounds.height +=  iter->second->textInput->getGlobalBounds().height;
                //bounds.height +=  iter->second->textInput->getGlobalBounds().height+paddingBelowInput;
            }

        }
    }
    if(textInput!= nullptr && this->isLeaf())
    {
        //std::cout << "hegiht: " << textInput->getGlobalBounds().height << "\n";
        bounds.height += textInput->getGlobalBounds().height;
    }

    return bounds;
}

//returns true if the node has no children, otherwise false
bool FileNode::isLeaf() const {

    //textBox = new TextBox();
    return (children.size()==0);
}

FileItem &FileNode::getData() {
    return data;
}

void FileNode::setData(const FileItem &data)
{
    this->data = data;
}

std::map<std::string, FileNode *> &FileNode::getChildren()
{
    return this->children;
}

FileNode::iterator FileNode::begin() {
    return children.begin();
}

FileNode::iterator FileNode::end() {
    return children.end();
}

void FileNode::addChild(std::string nVal, FileNode *n)
{
    children[nVal] = n;
}

void FileNode::setPosition(float x, float y) {
    data.setPosition({x,y});
}

void FileNode::deletePtr()
{
    if(textInput!= nullptr)
    {
        delete textInput;
    }
}

std::string FileNode::getInputString() {
    if(textInput!= nullptr) {
        return textInput->tostring();
    }
    else
    {
        return "empty\n";
    }
}

void FileNode::setNightView()
{
    this->enableState(NIGHTVIEW);
    this->disableState(LIGHTVIEW);
    data.setNightView();
}

void FileNode::setLightView()
{
    this->enableState(LIGHTVIEW);
    this->disableState(NIGHTVIEW);
    data.setLightView();
}

//void FileNode::createTextBox()
//{
//}


