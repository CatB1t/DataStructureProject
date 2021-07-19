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
    const char* const ALL_USERS_PATH = "../all-users.in";
    const char* const ALL_USERS_RELATIONS_IN = "../all-users-relations.in";
    static UserManager* UserManager_Instance;
public:
    UserManager();
    User* Login(const std::string& name);
    User* Search(const std::string& name);

    UserLinkedList GetUserRecommendation(User& user)
    {
       return _userList.TraverseLinkedList(user);
    }
};


#endif //DATASTRUCTUREPROJECT_USERMANAGER_H
