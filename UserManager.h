//
// Created by peter on 7/18/2021.
//

#ifndef DATASTRUCTUREPROJECT_USERMANAGER_H
#define DATASTRUCTUREPROJECT_USERMANAGER_H


#include <iostream>
#include <fstream>
#include <string>
#include "UserLinkedList.h"
class UserManager {
private:
    ifstream nameFileout;
    string user_info;
    UserLinkedList UserList;
public:
    UserManager();
};


#endif //DATASTRUCTUREPROJECT_USERMANAGER_H
