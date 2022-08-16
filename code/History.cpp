//
// Created by hello on 10/10/2021.
//

#include "History.h"

std::stack<HistoryNode> History::stack;


void History::pushHistory(const HistoryNode &snapshot)
{
    History::stack.push(snapshot);
}

HistoryNode &History::topHistory() {
    return History::stack.top();
}

void History::popHistory() {
    if(!History::stack.empty()) {
        //std::cout << "popping";
        History::stack.top().component->applySnapshot(History::stack.top().snapshot);
        History::stack.pop();

    }
}

void History::addEventHandler(sf::RenderWindow &window, sf::Event event)
{
    if(KeyShortcuts::isUndo())
    {
        //std::cout << "\nundo action\n";
        popHistory();
        while(KeyShortcuts::isUndo());
    }
}
