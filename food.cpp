#include "food.h"
#include"wall.h"
#include"snake.h"
#include <cstdlib>
#include <ctime>
food::food(int x, int y, char pic)
{
	m_iX = x;
	m_iY = y;
	m_cPic = pic;
}
food::~food()
{
}
void food::createpos()
{
	srand((int)time(0));//srand()用来设置rand()产生随机数时的随机数种子。 
	//在调用rand()函数产生随机数前，必须先利用srand()设好随机数种子（seed）,
	//如果未设随机数种子,rand()所产生的随机数值都一样
	m_iX = wall::left + 1 + rand() % (wall::COL - 2);//在[3,73]之间的整数
	m_iY = wall::up + 1 + rand() % (wall::ROW - 2);//在[2,23]之间的整数
}
