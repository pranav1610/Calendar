/**
 * N-Ary Tree Definition
 *
 * Copyright (c) 2021, Pranav Patel.
*/

#ifndef N_ARY_TREE_NARY_CPP
#define N_ARY_TREE_NARY_CPP

#include "NAry.h"

//helper functions
void NAryTree::push(Node *&root, std::string parent, std::string item)
{
    //if (root->isLeaf() && root->data != parent)
    // if (root == nullptr)
    // {
    //     std::cerr << "Error: Directory " << parent << " doesnt exist!\n";
    // }
    //if (root.)

    //else
    if (root->data != parent)
    {
        //push(root->children., parent, item);
        for (int i = 0; i < root->children.size(); i++)
        {
            push(root->children.at(i), parent, item);
        }
    }
    else if (root->data == parent)
    {
        Node *n = new Node;
        n->data = item;
        root->children.push_back(n);
    }
}
//helper functions
// void NAryTree::push(Node *&root, std::string parent, std::string item)
// {
//     //bool found = false;
//     Node *tempPar = root;
//     Node *file = new Node;
//     file->data = item;
//     std::vector<std::string> directories = split(parent);

//     if (directories.size() == 0)
//     {
//         std::cout << "\nError: No such file or directory found!\n";
//     }

//     if (root == nullptr)
//     {
//         root = new Node;
//         root->data = directories[0];

//         if (directories.size() == 1)
//         {
//             root->children.push_back(file);
//             return;
//         }

//         tempPar = root;

//         for (int i = 1; i < directories.size(); i++)
//         {
//             //Add new directory
//             Node *dir = new Node;
//             dir->data = directories[i];

//             tempPar->children.push_back(dir);

//             if (i == directories.size() - 1)
//             {
//                 dir->children.push_back(file);
//             }
//             tempPar = dir;
//         }
//     }
//     else
//     {
//         Node *prevPar;
//         //indicates if___ is found
//         bool found = false;
//         for (int j = 1; j < directories.size(); j++)
//         {
//             prevPar = tempPar;
//             tempPar = findItem(tempPar, directories[j], found);

//             //eg. c/dir1 --> root has d/dir1
//             if (tempPar == nullptr)
//             {
//                 break;
//             }
//             found = false;
//         }
//         if (!found)
//         {
//                 }
//     }
// }
void NAryTree::traverse(Node *root, void f(std::string &item))
{
    if (root == nullptr)
    {
        return;
    }
    f(root->data);

    for (int i = 0; i < root->children.size(); i++)
    {
        //std::cout << " child: " << root->children.at(i)->data;
        traverse(root->children.at(i), f);
    }
}

//public interface
void NAryTree::push(std::string parent, std::string item)
{
    if (root == nullptr)
    {
        //std::cout << "first node\n";
        root = new Node;
        root->data = parent;

        Node *n = new Node;
        n->data = item;
        root->children.push_back(n);
    }
    else
    {
        push(root, parent, item);
    }
}

Node *NAryTree::findItem(Node *root, std::string item, bool &found)
{
    if (root->data == item)
    {
        found = true;
        return root;
    }
    else // if (root->data != item)
    {
        //push(root->children., item, item);
        for (int i = 0; i < root->children.size(); i++)
        {
            //std::cout << "at: " << root->children.at(i)->data << "\n";
            return findItem(root->children.at(i), item, found);
        }
    }
}

void NAryTree::traverse(void f(std::string &item))
{
    traverse(root, f);
}

std::vector<std::string> NAryTree::split(std::string basicString)
{
    // c/dir3/dir2, "hello" "c", "dir1", "dir2"
    std::vector<std::string> strs;
    int idx = 0;
    while (basicString.length() > 0 && idx != std::string::npos)
    {
        //std::cout << "s is " << basicString << std::endl;
        idx = basicString.find('/');
        if (idx != std::string::npos)
        {
            std::string t = basicString.substr(0, idx);
            strs.push_back(t);
            basicString = basicString.substr(idx + 1);
        }
    }
    strs.push_back(basicString);
    return strs;
}

#endif //N_ARY_TREE_NARY_CPP