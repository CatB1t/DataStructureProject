//
// Created by david on 7/12/2021.
//

#include "UserLinkedList.h"

UserLinkedList::UserLinkedList() {
    head = tail = nullptr;
    length = 0;
}
void UserLinkedList::insertAtHead(User data) {
    Node* newNode = new Node(data);
    newNode->info = data;
    newNode->next = head;
    head = newNode;
}

void UserLinkedList::insertAtTail(User data) { 
    Node* newNode = new Node(data);
    newNode->info = data;

    if (tail)
        tail->next = newNode;
    tail = newNode;
    if (!head)
        head = newNode;

    length++;

}
bool UserLinkedList::search(string data) {
    Node* current = head;
    while (current != NULL)
    {
        if (current->info.getusername() == data)
            return true;
        current = current->next;
    }
    return false;
}

void UserLinkedList::printList() {
    Node* temp;
    temp=head;

    while (temp!= nullptr){
        cout<<temp->info<<" ";
        temp=temp->next;
    }

}