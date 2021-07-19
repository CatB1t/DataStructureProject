#include "UserMenu.h"
#include "User.h"
#include "MenuUtil.h"
#include "UserManager.h"
#include <iostream>

UserMenu::UserMenu(User* user) {
    if(user)
        _currentUser = user;
    std::cout << _currentUser->getUsername() << std::endl; // TODO Cleanup
}

void UserMenu::Show() {
	MenuUtil::Print("1. List all friends\n2. Search by username\n");
	MenuUtil::Print("3. Add Friend\n4. Remove friend\n");
	MenuUtil::Print("5. People you may know\n6. Logout\n");
}

bool UserMenu::Handle() {
	switch(MenuUtil::GetValidIntInput(1, 6))
	{
	case 1: // List all friends
	    ListAllFriends();
		return false;
	case 2: // Search by username
	    SearchByUsername();
		return false;
	case 3: // Add friend
	    AddFriend();
		return false;
	case 4: // Remove friend
	    RemoveFriend();
		return false;
	case 5: // People you may know
	    ShowPeopleYouMayKnow();
		return false;
	case 6:
		// Logout
		return true;
	default:
		MenuUtil::Print("Unknown error.");
		return true;
	}
}

void UserMenu::ListAllFriends() {
    _currentUser->ListFriends();
}

void UserMenu::SearchByUsername() {
    MenuUtil::Print("Enter username:\n");
    User* user = UserManager::UserManager_Instance->Search(MenuUtil::GetValidStringInput());

    if(!user)
    {
        MenuUtil::Print("Not a valid user.\n");
        return;
    }

    if(_currentUser->IsAFriend(*user))
        MenuUtil::Print(user->toString());
    else
        MenuUtil::Print("This user is not in your friend list.\n");
}

void UserMenu::AddFriend() {
    MenuUtil::Print("Enter username:\n");
    User* user = UserManager::UserManager_Instance->Search(MenuUtil::GetValidStringInput());

    if(user == _currentUser)
        MenuUtil::Print("You can't add yourself.\n");

    if(!user)
    {
        MenuUtil::Print("Not a valid user.\n");
        return;
    }

    if(_currentUser->IsAFriend(*user))
    {
        MenuUtil::Print("This user is already a friend.\n");
        return;
    }

    _currentUser->AddFriend(*user);
}

void UserMenu::RemoveFriend() {
    MenuUtil::Print("Enter username:\n");
    User* user = UserManager::UserManager_Instance->Search(MenuUtil::GetValidStringInput());

    if(!user)
    {
        MenuUtil::Print("Not a valid user.\n");
        return;
    }

    if(!_currentUser->IsAFriend(*user))
    {
        MenuUtil::Print("This user is not a friend.\n");
        return;
    }

    _currentUser->RemoveFriend(*user);
    MenuUtil::Print("Friend removed successfully.\n");
}


void UserMenu::ShowPeopleYouMayKnow()
{
    bool flag=false;
    MenuUtil::Print("Recommended Users:\n");
    ifstream nameFileout;
    nameFileout.open("../all-users.in");
    while(!nameFileout.eof())
    {
        string userName;
        string name;
        string email;
        nameFileout >> userName;
        userName.erase(userName.end() - 1);
        getline(nameFileout, name, ',');
        name.erase(name.begin());
        nameFileout >> email;
        User* user=UserManager::UserManager_Instance->Search(userName);
        if(user->IsAFriend(*_currentUser)||_currentUser->IsAFriend(*user))
        {
            while(!nameFileout.eof())
            {
                nameFileout >> userName;
                userName.erase(userName.end() - 1);
                getline(nameFileout, name, ',');
                name.erase(name.begin());
                nameFileout >> email;
                User* user2=UserManager::UserManager_Instance->Search(userName);
                if(user2->IsAFriend(*user)||user->IsAFriend(*user2)&&!user2->IsAFriend(*_currentUser)&&userName!=_currentUser->getUsername())
                {
                    flag=true;
                    cout<<userName<<","<<name<<endl;
                }
            }
            if(flag==false)
            {
                MenuUtil::Print("None\n");
            }
        }

    }
    nameFileout.close();

}
