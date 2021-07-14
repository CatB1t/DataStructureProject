#pragma once
#include "IMenu.h"

class UserMenu : public IMenu
{
public:
    void Show() override;
    bool Handle() override;
};
