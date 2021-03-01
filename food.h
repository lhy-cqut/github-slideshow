#pragma once
#include"unit.h"
class food : public unit
{
public:
	food(int x = 0, int y = 0, char pic = '$');
	~food();
	void createpos();
};
