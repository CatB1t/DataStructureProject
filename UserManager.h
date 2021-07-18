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
    UserLinkedList _userList;
    void ReadInputForRelations();
public:
    static UserManager* UserManager_Instance;
public:
    UserManager();
    User* Login(const std::string& name);
};


#endif //DATASTRUCTUREPROJECT_USERMANAGER_H
