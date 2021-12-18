/**
 * N-Ary Tree Node Definition
 *
 * Copyright (c) 2021, Pranav Patel.
*/

#ifndef N_ARY_TREE_NODE_H
#define N_ARY_TREE_NODE_H

#include <iostream>
#include <string>
#include <vector>

struct Node
{
    std::string data;
    std::vector<Node *> children;

    bool isLeaf()
    {
        return (this)->children.size() == 0;
    }
};

#endif //N_ARY_TREE_NODE_H