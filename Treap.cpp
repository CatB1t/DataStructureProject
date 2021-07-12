#include "Treap.h"
#include "User.h"
#include <iostream>
using namespace std;

int Treap::calibrateHeight(TreapNode *p)
{

    if (p->left && p->right)
    {
        if (p->left->height < p->right->height)
            return p->right->height + 1;
        else
            return p->left->height + 1;
    }
    else if (p->left && p->right == NULL)
    {
        return p->left->height + 1;
    }
    else if (p->left == NULL && p->right)
    {
        return p->right->height + 1;
    }
    return 0;
}

int Treap::getBalanceFactor(TreapNode *n)
{
    if (n->left && n->right)
    {
        return n->left->height - n->right->height;
    }
    else if (n->left && n->right == NULL)
    {
        return n->left->height;
    }
    else if (n->left == NULL && n->right)
    {
        return -n->right->height;
    }
}


TreapNode *Treap::insert(TreapNode *r, string username, User *user)
{
    if (r == NULL)
    {
        r = new TreapNode(username, user);
        r -> height = 1;
        return r;
    }
    else
    {
        if (username < r->username)
            r->left = insert(r->left, username, user);
        else
            r->right = insert(r->right, username, user);
    }

    r->height = calibrateHeight(r);

    if (getBalanceFactor(r) == 2 && getBalanceFactor(r->left) == 1)
        r = LLRotation(r);

    else if (getBalanceFactor(r) == -2 && getBalanceFactor(r->right) == -1)
        r = RRRotation(r);

    else if (getBalanceFactor(r) == -2 && getBalanceFactor(r->right) == 1)
        r = RLRotation(r);

    else if (getBalanceFactor(r) == 2 && getBalanceFactor(r->left) == -1)
        r = LRRotation(r);
    

    return r;
}

TreapNode *Treap::deleteNode(TreapNode *p, string username)
{

    if (p->left == NULL && p->right == NULL)
    {
        if (p == this->root)
            this->root = NULL;
        delete p;
        return NULL;
    }

    TreapNode *t;
    TreapNode *q;
    if (p->username < username)
        p->right = deleteNode(p->right, username);
    else if (p->username > username)
        p->left = deleteNode(p->left, username);
    else
    {
        if (p->left != NULL)
        {
            q = getPredecessor(p->left);
            p = q -> getCopy();
            p->left = deleteNode(p->left, q->username);
        }
        else
        {
            q = getSuccessor(p->right);
            p = q -> getCopy();
            p->right = deleteNode(p->right, q->username);
        }
    }

    if (getBalanceFactor(p) == 2 && getBalanceFactor(p->left) == 1)
        p = LLRotation(p);
    
    else if (getBalanceFactor(p) == 2 && getBalanceFactor(p->left) == -1)
        p = LRRotation(p);
    
    else if (getBalanceFactor(p) == 2 && getBalanceFactor(p->left) == 0)
        p = LLRotation(p);
    
    else if (getBalanceFactor(p) == -2 && getBalanceFactor(p->right) == -1)
        p = RRRotation(p);

    else if (getBalanceFactor(p) == -2 && getBalanceFactor(p->right) == 1)
        p = RLRotation(p);

    else if (getBalanceFactor(p) == -2 && getBalanceFactor(p->right) == 0)
        p = LLRotation(p);

    return p;
}

TreapNode *Treap::getPredecessor(TreapNode *p)
{
    while (p->right != NULL)
        p = p->right;
    return p;
}

TreapNode *Treap::getSuccessor(TreapNode *p)
{
    while (p->left != NULL)
        p = p->left;
    return p;
}

TreapNode *Treap::LLRotation(TreapNode *n) {
    struct TreapNode *tempNode, *rotNode;
    tempNode = n;
    rotNode = tempNode -> left;
    tempNode -> left = rotNode -> right;
    rotNode -> right = tempNode;
    return rotNode;
}

TreapNode *Treap::LRRotation(TreapNode *n) {
    struct TreapNode *tempNode, *rotNode2, *rotNode;
    tempNode = n;
    rotNode = tempNode -> left;
    rotNode2 = tempNode -> left -> right;
    tempNode -> left = rotNode2 -> right;
    rotNode -> right = rotNode2 -> left;
    rotNode2 -> right = tempNode;
    rotNode2 -> left = rotNode;
    return rotNode2;
}

TreapNode *Treap::RLRotation(TreapNode *n) {
    struct TreapNode *tempNode, *rotNode2, *rotNode;
    tempNode = n;
    rotNode = tempNode -> right;
    rotNode2 = tempNode -> right -> left;
    tempNode -> right = rotNode2 -> left;
    rotNode -> left = rotNode2 -> right;
    rotNode2 -> left = tempNode;
    rotNode2 -> right = rotNode;
    return rotNode2;
}

TreapNode *Treap::RRRotation(TreapNode *n) {
    struct TreapNode *tempNode, *rotNode;
    tempNode = n;
    rotNode = tempNode -> right;
    tempNode -> right = rotNode -> left;
    rotNode -> left = tempNode;
    return rotNode;
}

void Treap::inOrder(TreapNode *node) {
    if(node != 0){
        inOrder(node -> left);
        
        inOrder(node -> right);
    }
}
