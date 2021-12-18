//
// Created by hello on 11/6/2021.
//

#ifndef FILETREE_FILETREE_H
#define FILETREE_FILETREE_H

#include <SFML/Graphics.hpp>
#include "GUIComponent.h"
#include "FileNode.h"

class FileTree : public GUIComponent
{
private:
    //the root node of the tree
    float indent;
    FileNode* root = nullptr;
    sf::Vector2f initPosition = {0, 0};

    //finds the parent and add the item to the parent.
    // If the parent isn't found, a new parent is created
    void push(FileNode*& root, std::string parent, std::string item, bool& found);

    void traverse(FileNode *root);

    //traverses the tree ad adds the evenhandlers for each of the nodes
    void traverse(FileNode* &root, sf::RenderWindow& window, sf::Event event);

    //traverses the tree ad adds the update for each of the nodes
    void update(FileNode* &root);

    //findInput(FileNode ptr for "Birthday" -- from search(), "add")
    std::string findInput(FileNode* n, std::string child);

    //FileNode ptr for "Birthday" starting from rt for recursion
    FileNode* search(FileNode* &rt, std::string parent);

    void setNightView(FileNode* &rt);

    void setLightView(FileNode* &rt);

public:
    //constructors
    FileTree();
    ~FileTree();
    void clear(FileNode* &rt);

    void setPosition(float x, float y);

    void setRootBoxSize(float x, float y);

    //go and call return findInput(search())
    // findInput("Birthday", "add"), findInput("Birthday", "remove"), findInput("Task", "add"), findInput("Task", "remove")
    std::string findInput(std::string parent, std::string child);

    //this is the public version of push
    void push(std::string parent, std::string item = "NULL");

    //draws the root node of the tree
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    //does nothing now
    virtual void applySnapshot(const Snapshot& snapshot);

    //calls the traverse function to add the event handlers to each node
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);

    //FileTree update - does nothing now
    virtual void update();
    //does nothing now
    virtual Snapshot& getSnapshot();
    //does nothing now
    virtual sf::FloatRect getGlobalBounds();

    void setNightView();

    void setLightView();


};


#endif //FILETREE_FILETREE_H
