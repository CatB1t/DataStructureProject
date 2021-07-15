#include "UserMenu.h"
#include "User.h"
#include "MenuUtil.h"
#include <iostream>

UserMenu::UserMenu(User* user) {
    if(user)
        _currentUser = user;
    std::cout << _currentUser->getusername() << std::endl; // TODO Cleanup
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

}

void UserMenu::SearchByUsername() {

}

void UserMenu::AddFriend() {

}

void UserMenu::RemoveFriend() {

}

void UserMenu::ShowPeopleYouMayKnow() {

}

