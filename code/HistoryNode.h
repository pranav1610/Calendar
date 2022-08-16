//
// Created by hello on 10/10/2021.
//

#ifndef SFML_PROJECT_1_HISTORYNODE_H
#define SFML_PROJECT_1_HISTORYNODE_H

#include "GUIComponent.h"
#include "Snapshot.h"

struct HistoryNode
{
    Snapshot snapshot;
    GUIComponent* component;
};

#endif //SFML_PROJECT_1_HISTORYNODE_H
