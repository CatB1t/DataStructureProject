#ifndef TREAP_H
#define TREAP_H

#include "User.h"
#include <iostream>
using namespace std;

class User; //forward definition

struct TreapNode
{
    string username;
    User *user;
    TreapNode *left, *right;
    int height;

    TreapNode(string username, User *user, TreapNode *left = 0, TreapNode *right = 0)
    {
        this->username = username;
        this->user = user;
        this->left = left;
        this->right = right;
    }

    TreapNode *getCopy(){ return new TreapNode(this -> username, this -> user); }
};

class Treap
{
    private:
        TreapNode *root = 0;
        void inOrder(TreapNode *node);
        int calibrateHeight(TreapNode *n);
        int getBalanceFactor(TreapNode *n);
        TreapNode *LLRotation(TreapNode *n);
        TreapNode *RRRotation(TreapNode *n);
        TreapNode *RLRotation(TreapNode *n);
        TreapNode *LRRotation(TreapNode *n);
        TreapNode *insert(TreapNode *node, string username, User *user);
        TreapNode *deleteNode(TreapNode *node, string username);
        TreapNode *getPredecessor(TreapNode *node);
        TreapNode *getSuccessor(TreapNode *node);


    public:
        void add(string username, User *user){ root = insert(root, username, user); };
        void remove(string username){ root = deleteNode(root, username); };
        User *find(string);
        void printInOrder() {inOrder(root); };

};

#endif