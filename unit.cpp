#include "unit.h"
#include <windows.h>
unit::unit(int x, int y, char pic)
{
	m_iX = x;
	m_iY = y;
	m_cPic = pic;
}

unit::~unit()
{
}

void unit::show()
{
	gotoxy(m_iX, m_iY);
	cout << m_cPic;
}

void unit::erase()
{
	gotoxy(m_iX, m_iY);
	cout << " ";
}

void unit::gotoxy(int x, int y)
{
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);//新建句柄 screen
	COORD position;    // position 是一个 COORD 结构
	position.X = x;//如果用户定义了 COORD postion，那么postion其实是一个结构体变量，
	position.Y = y;//其中X和Y是它的成员，通过修改postion.X和postion.Y的值就可以实现光标的位置控制。
	//隐藏光标
	CONSOLE_CURSOR_INFO cinfo;
	cinfo.bVisible = 0;
	cinfo.dwSize = 1;// 如果没赋值的话，隐藏光标无效
	SetConsoleCursorInfo(screen, &cinfo);
	//将光标放在那里，然后开始打印
	SetConsoleCursorPosition(screen, position);//SetConsoleCursorPosition是API中定位光标位置的函数
}