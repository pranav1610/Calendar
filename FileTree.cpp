//
// Created by hello on 11/6/2021.
//

#include "FileTree.h"

FileTree::FileTree() {
    indent = 30;
}

//HELPER FUNCTIONS

//finds the parent and add the item to the parent.
// If the parent isn't found, a new parent is created
void FileTree::push(FileNode *&root, std::string parent, std::string item, bool& found)
{
    if(root->getData().getValue()!=parent)
    {
        FileNode::iterator iter;
        for(iter = root->begin(); iter!=root->end();++iter)
        {
            push((*iter).second, parent, item, found);
        }
    }
    else if(root->getData().getValue()==parent)
    {
        //root->deletePtr();
        root->getData().setIcon(Image::FOLDER);
        root->getData().setIconSize(Image::FOLDER);

        found = true;
        //30 is just the indent
        root->getChildren()[item] = new FileNode(Image::FILE, item, {200,30}, {root->getGlobalBounds().left+indent, 0});
        //FileItem childN;
        //FileNode *n = new FileNode();
        //n->setData(childN);
        //root->addChild(item, );

    }
}

void FileTree::traverse(FileNode *root)
{
    if(root== nullptr || root->isLeaf())
    {
        return;
    }
    else
    {
        auto iter = root->begin();
        for(;iter!=root->end();++iter)
        {
            traverse(iter->second);
        }
    }
}

//traverses the tree ad adds the evenhandlers for each of the nodes
void FileTree::traverse(FileNode *&root, sf::RenderWindow &window, sf::Event event)
{
    if(root== nullptr)
    {
        return;
    }
    else if(root->isLeaf())
    {
        //if(root->isEnabled(VISIBLE))
        {
            root->addEventHandler(window, event);
        }
        return;
    }
    else
    {
        root->addEventHandler(window, event);
        auto iter = root->begin();
        for(;iter!=root->end();++iter)
        {
            traverse(iter->second, window, event);
        }
    }
//    if(MouseEvents<FileItem>::mouseClicked(root->getData(), window))
//    {
//        root->getData().setFillColor(sf::Color::Blue);
//    }
//    else if(MouseEvents<FileItem>::mouseClicked(window, event))
//    {
//        root->getData().setFillColor(sf::Color::Transparent);
//    }
//
//    if(root!= nullptr && !root->isLeaf())
//    {
//        root->addEventHandler(window, event);
//        for(auto iter = root->begin();iter!=root->end();++iter)
//        {
//            traverse(iter->second, window, event);
//        }
//    }
}

//PUBLIC INTERFACE

//this is the public version of push
void FileTree::push(std::string parent, std::string item)
{
    //false indicates parent not found yet
    bool found = false;
    if (root == nullptr)
    {
        //std::cout << "first node\n";
        root = new FileNode(Image::FOLDER, parent, {200,30}, initPosition);

        //30 is just the indent
        //TODO - determine image enum type as not sure if always FILE
        //FileItem childN(Image::FILE, item, {200,30}, {root->getGlobalBounds().left+indent, root->getGlobalBounds().top});
        FileNode *n = new FileNode(Image::FILE, item, {200,30}, {root->getGlobalBounds().left+indent, root->getGlobalBounds().top});
        //n->setData(childN);
        //n->data = item;
        root->addChild(item, n);
    }
    else
    {
        push(root, parent, item, found);

        if(found==false)
        {
            std::cout << "\nError: Parent directory not found!\n";
        }

    }
}
//draws the root node of the tree
void FileTree::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    root->draw(window, states);
}
//does nothing now
void FileTree::applySnapshot(const Snapshot &snapshot) {

}
//calls the traverse function to add the event handlers to each node
void FileTree::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    //std::cout << "in tree\n";
    this->traverse(root, window, event);
}
void FileTree::update(FileNode *&root)
{
    if(root== nullptr)
    {
        return;
    }
    else if(root->isLeaf())
    {
        if(root->isEnabled(VISIBLE))
            root->update();
        return;
    }
    else
    {
        //if(root->isEnabled(VISIBLE))
        root->update();
        auto iter = root->begin();
        for(;iter!=root->end();++iter)
        {
            update(iter->second);
        }
    }
}

//does nothing now
void FileTree::update() {
    this->update(root);
}
//does nothing now
Snapshot &FileTree::getSnapshot() {
    //return <#initializer#>;
}
//does nothing now
sf::FloatRect FileTree::getGlobalBounds() {
    return {0,0,0,0};
    //TODO RETURN GLOBALBOUNDS
//    if(root== nullptr)
//    {
//        return {initPosition.x,initPosition.y,0,0};
//    }
////    else if(root->isLeaf()){
////
////        return {root->getData().getGlobalBounds().left+indent,
////                root->getData().getGlobalBounds().top+root->getData().getGlobalBounds().height,
////                (root->getData().getGlobalBounds().width+indent - initPosition.x),
////                (root->getData().getGlobalBounds().top+root->getData().getGlobalBounds().height - initPosition.y)};
////    }
//    //recursive call
//    else{
//        sf::FloatRect par = root->getGlobalBounds();
//        for(auto iter=root->begin();iter!=root->end();++iter)
//        {
//            if(!(iter->second->isEnabled(HIDDEN)))
//            {
//                //return {initPosition.x, initPosition.y,
//                //        iter->second->getGlobalBounds().width+}
//            }
//        }
//    }
}

void FileTree::setPosition(float x, float y) {
    initPosition = {x,y};
}

void FileTree::setRootBoxSize(float x, float y)
{
    root->getData().setBoxSize(30,30);
}

std::string FileTree::findInput(FileNode *n, std::string child) {

    if(n== nullptr)
    {
        return "Doesnt exist\n";
    }
    for(auto iter = n->begin(); iter!=n->end(); ++iter)
    {
        if((*iter).second->getData().getValue()==child)
        {
            return (*iter).second->getInputString();
        }
    }
}

FileNode *FileTree::search(FileNode* &rt, std::string parent)
{
    if(rt==nullptr)
    {
        return nullptr;
    }
    //root->isLeaf() &&
//    else if(rt->getData().getValue()==parent)
//    {
//        return rt;
//    }
//    else
//    {
//        for(auto iter = rt->begin(); iter!=rt->end(); ++iter)
//        {
//            return search(iter->second, parent);
//        }
//    }

//TODO THIS IS TEMPORARY, USE ABOVE RECURSION
    else
    {
        for(auto iter = rt->begin();iter!=rt->end();++iter)
        {
            if(iter->second->getData().getValue()==parent)
            {
                return iter->second;
            }
        }
        return nullptr;
    }

}

//returns "empty" if input is

// findInput("Birthday", "add"), findInput("Birthday", "remove"), findInput("Task", "add"), findInput("Task", "remove")
std::string FileTree::findInput(std::string parent, std::string child) {
    return findInput(search(root, parent), child);
}

void FileTree::setNightView()
{
    setNightView(root);
}

void FileTree::setLightView()
{
    setLightView(root);
}

void FileTree::setNightView(FileNode *&rt)
{
    if(rt== nullptr)
    {
        return;
    }
    else if(rt->isLeaf())
    {
        //if(root->isEnabled(VISIBLE))
        {
            rt->setNightView();
        }
        return;
    }
    else
    {
        rt->setNightView();
        auto iter = rt->begin();
        for(;iter!=rt->end();++iter)
        {
            setNightView(iter->second);
        }
    }
}

void FileTree::setLightView(FileNode *&rt)
{
    if(rt== nullptr)
    {
        return;
    }
    else if(rt->isLeaf())
    {
        //if(root->isEnabled(VISIBLE))
        {
            rt->setLightView();
        }
        return;
    }
    else
    {
        rt->setLightView();
        auto iter = rt->begin();
        for(;iter!=rt->end();++iter)
        {
            setLightView(iter->second);
        }
    }
}

FileTree::~FileTree()
{

}

void FileTree::clear(FileNode *&rt)
{
    if(rt== nullptr)
    {
        return;
    }
    else if(rt->isLeaf())
    {
        delete rt;
    }
    else
    {
        auto iter = rt->begin();
        for(;iter!=rt->end();++iter)
        {
            clear(iter->second);
        }
    }
}


