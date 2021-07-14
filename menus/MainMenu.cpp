#include <iostream>
#include "MainMenu.h"

void MainMenu::Show()
{
	std::cout << "Choose an option: \n1. Login\n2.Exit";
}

bool MainMenu::Handle()
{
	/*
	switch (MenuUtil::GetValidIntInput(1, 2))
	{
		case 1: // Login
			return false;
		case 2: // Exit
			return true;
		default:
			std::cout << "Unknown error.";
			return false;
	}
	*/
	return true;
}