//
// Created by hello on 11/22/2021.
//

#include "InputNode.h"


void InputNode::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    FileNode::draw(window, states);
    if(this->isLeaf())
    {
        window.draw(textBox);
    }
}

void InputNode::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    FileNode::addEventHandler(window, event);
}

void InputNode::update() {
    FileNode::update();
}

Snapshot &InputNode::getSnapshot() {
    return FileNode::getSnapshot();
}

void InputNode::applySnapshot(const Snapshot &snapshot) {
    FileNode::applySnapshot(snapshot);
}
