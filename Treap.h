#ifndef TREAP_H
#define TREAP_H


#include "TreapNode.h"
#include "User.h"
#include <iostream>
using namespace std;

class User; //forward definition

class Treap
{
    private:
        TreapNode *root;
        void inOrder(TreapNode *node);
    public:
        void add(string, User *);
        TreapNode *find(string);
        void printInOrder();
        void remove(string);
        
};

#endif