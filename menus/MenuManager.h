#pragma once

#include "stack"

class IMenu;
class MenuManager
{
private:
	std::stack<IMenu*> _currentMenus;
public:
	MenuManager(); 
	bool Run();
	void ExecuteMenu(IMenu* menu);
	bool SkipMenu(IMenu* menu);
	bool SkipCurrentMenu();
};