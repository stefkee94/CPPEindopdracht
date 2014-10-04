#pragma once
#include <vector>

class Chamber
{
public:
	Chamber(int maxNumberOfExits, std::vector<std::string> directions);
	~Chamber();
};

