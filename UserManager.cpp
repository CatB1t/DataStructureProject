//
// Created by peter on 7/18/2021.
//
#include <iostream>
#include "UserManager.h"
#include <string>
#include <algorithm>
#include <queue>

using namespace std;
UserManager* UserManager::UserManager_Instance;
UserManager::UserManager()
{
    if(!UserManager_Instance)
        UserManager_Instance = this;
    ifstream nameFileout;
    nameFileout.open(R"(../all-users.in)"); // TODO handle if file is not found
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
    //_userList.printList();
    nameFileout.close();

    ifstream tmp;
    tmp.open("../all-users-relations.in");
    std::queue<std::string> users;

    while(!tmp.eof())
    {
        // Get each line
        string line;
        string tmpFirstUser,tmpSecondUser;

        tmp >> tmpFirstUser;
        getline(tmp, tmpSecondUser, ',');

        users.push(tmpFirstUser);
        users.push(tmpSecondUser);
    }


    while(!users.empty()) // we are assuming there's always pair of users
    {
        // add each user to the other
        // Search both users
        User* firstUser = _userList.search(users.front());
        users.pop();
        User* secondUser = _userList.search(users.front());
        users.pop();

        if(firstUser && secondUser)
        {
            firstUser->AddFriend(*secondUser);
            secondUser->AddFriend(*firstUser);
        }
    }
}

User* UserManager::Login(const std::string& name)
{
    return _userList.search(name);
}



