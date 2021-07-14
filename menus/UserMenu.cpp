#include "UserMenu.h"
#include "MenuUtil.h"

void UserMenu::Show()
{
	MenuUtil::Print("1. List all friends\n2. Search by username\n");
	MenuUtil::Print("3. Add Friend\n4. Remove friend\n");
	MenuUtil::Print("5. People you may know\n6. Logout\n");
}

bool UserMenu::Handle()
{
	switch(MenuUtil::GetValidIntInput(1, 6))
	{
	case 1: // List all friends
		return false;
	case 2: // Search by username
		return false;
	case 3: // Add friend
		return false;
	case 4: // Remove friend
		return false;
	case 5: // People you may know 
		return false;
	case 6:
		// Logout
		return true;
	default:
		MenuUtil::Print("Unknown error.");
		return true;
	}
}

