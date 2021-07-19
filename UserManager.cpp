//
// Created by peter on 7/18/2021.
//
#include <iostream>
#include "UserManager.h"
#include <string>
#include <algorithm>

using namespace std;
UserManager* UserManager::UserManager_Instance;
UserManager::UserManager()
{
    if(!UserManager_Instance)
        UserManager_Instance = this;

    ifstream nameFileout;
    nameFileout.open(ALL_USERS_PATH);

    if(!nameFileout.is_open())
    {
        std::cout << "Couldn't open file ('all-users.in'), please check UserManager.h for the correct path" << std::endl;
    }
    else {
        while(!nameFileout.eof()){
            string userName;
            string name;
            string email;
            nameFileout >> userName;
            userName.erase(userName.end() - 1);
            getline(nameFileout, name, ',');
            name.erase(name.begin());
            nameFileout >> email;
            User user(userName, name, email);
            if(_userList.search(userName))
            {
                std::cout << "ERROR! user name already exists" << endl;
                continue;
            }
            _userList.insertAtHead(user);
        };
        nameFileout.close();
    }

    ReadInputForRelations();
}

void UserManager::ReadInputForRelations()
{
    ifstream tmp;
    tmp.open(ALL_USERS_RELATIONS_IN);

    if(!tmp.is_open())
    {
        std::cout << "Couldn't open file ('all-users-relations.in'), please check UserManager.h for the correct path" << std::endl;
    }
    else {
        while(!tmp.eof())
        {
            string tmpFirstUser,tmpSecondUser;

            tmp >> tmpFirstUser;
            tmpFirstUser.erase(tmpFirstUser.end() - 1);
            tmp >> tmpSecondUser;

            User* firstUser = _userList.search(tmpFirstUser);
            User* secondUser = _userList.search(tmpSecondUser);

            if(firstUser && secondUser)
            {
                firstUser->AddFriend(*secondUser);
                secondUser->AddFriend(*firstUser);
            }
        }
        tmp.close();
    }
}

User* UserManager::Login(const std::string& name)
{
    return _userList.search(name);
}

User* UserManager::Search(const std::string& name)
{
    return _userList.search(name);
}


