//
// Created by hello on 10/10/2021.
//

#ifndef SFML_PROJECT_1_HISTORY_H
#define SFML_PROJECT_1_HISTORY_H

#include <stack>
#include <SFML/Graphics.hpp>
#include "KeyShortcuts.h"
#include "HistoryNode.h"



class History  {


private:
    static std::stack<HistoryNode> stack;
public:
    static void pushHistory(const HistoryNode& snapshot);
    static HistoryNode& topHistory();
    static void popHistory();
    static void addEventHandler(sf::RenderWindow& window, sf::Event event);

};


#endif //SFML_PROJECT_1_HISTORY_H
