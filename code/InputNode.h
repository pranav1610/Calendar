//
// Created by hello on 11/22/2021.
//

#ifndef CALENDAR_GUI_INPUTNODE_H
#define CALENDAR_GUI_INPUTNODE_H

#include "FileNode.h"
#include "TextBox.h"

class InputNode : public FileNode{
private:
    TextBox textBox;
public:
    //from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    // from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();

    //from SnapshotInterface
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);

};


#endif //CALENDAR_GUI_INPUTNODE_H
