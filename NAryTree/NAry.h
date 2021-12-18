/**
 * N-Ary Tree Declaration
 *
 * Copyright (c) 2021, Pranav Patel.
*/

#ifndef N_ARY_TREE_NARY_H
#define N_ARY_TREE_NARY_H

#include "Node.h"
#include <string>

class NAryTree
{
private:
    Node *root = nullptr;
    void push(Node *&root, std::string parent, std::string item);
    Node *findItem(Node *parent, std::string item, bool &found);
    void traverse(Node *root, void f(std::string &item));
    std::vector<std::string> split(std::string basicString);

public:
    void push(std::string parent, std::string item);
    void traverse(void f(std::string &item));
};

#endif //N_ARY_TREE_NARY_H