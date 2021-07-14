#pragma once

class IMenu
{
public:
	virtual void Show() = 0;
	virtual bool Handle() = 0;
};