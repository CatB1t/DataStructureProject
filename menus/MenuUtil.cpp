#include "MenuUtil.h"
#include <iostream>

namespace MenuUtil
{
	int GetValidIntInput(int min, int max)
	{
		std::cout << "\nPlease enter your choice:";
		int tmp;
		std::cin >> tmp;
		while (tmp > max && tmp < min)
		{
			std::cout << "Not a valid input, please try again: ";
			std::cin >> tmp;
		}
		return tmp;
	}

	void Print(const char* output)
	{
		std::cout << output;
	}
}