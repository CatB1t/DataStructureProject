#include "MenuManager.h"
#include "MainMenu.h"
#include "IMenu.h"

MenuManager* MenuManager::MenuManager_Instance;
std::stack<IMenu*> MenuManager::_currentMenus;

// Create a default MainMenu and execute it 
MenuManager::MenuManager()
{
	if(!MenuManager_Instance)
		MenuManager_Instance = this;
	ExecuteMenu(new MainMenu());
}

// Start displaying the current menus
bool MenuManager::Run()
{
	while(!_currentMenus.empty())
	{
		// Get the top menu
		IMenu* top = _currentMenus.top();

		// Show it
		top->Show();
		
		// wait for input
		if (top->Handle())
		{
			_currentMenus.pop(); // TODO Not a proper way to pop the current menu
		}
	}
	return true;
}

// Add a menu to the stack to be executed
void MenuManager::ExecuteMenu(IMenu* menu) 
{
	_currentMenus.push(menu);
}