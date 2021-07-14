#include <iostream>
#include "MainMenu.h"
#include "MenuManager.h"
#include "MenuUtil.h"
#include "UserMenu.h"

void MainMenu::Show()
{
	std::cout << "Choose an option:\n1. Login\n2. Exit";
}

bool MainMenu::Handle()
{
	switch (MenuUtil::GetValidIntInput(1, 2))
	{
		case 1: // Login
			MenuManager::MenuManager_Instance->ExecuteMenu(new UserMenu());
			return false;
		case 2: // Exit
			return true;
		default:
			std::cout << "Unknown error.";
			return false;
	}
}