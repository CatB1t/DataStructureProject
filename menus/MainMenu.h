#pragma once
#include "IMenu.h"

class MainMenu : public IMenu
{
public:
	void Show() override;
	bool Handle() override;
};
