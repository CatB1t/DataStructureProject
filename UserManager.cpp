//
// Created by peter on 7/18/2021.
//
#include <iostream>
#include <fstream>
#include "UserManager.h"
#include <string>
#include "User.h"
#include <algorithm>


using namespace std;
UserManager::UserManager(){
    nameFileout.open(R"(E:\college\data structure\New folder\DataStructureProject-main\all-users.in)");
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
        if(UserList.search(userName))
        {
            std::cout << "ERROR! user name already exists" << endl;
            continue;
        }
        UserList.insertAtHead(user);
    };
    UserList.printList();
    nameFileout.close();
}



