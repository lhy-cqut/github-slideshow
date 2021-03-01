#include "snake.h"
#include "wall.h"
snake::snake(int x, int y, int l, Dir d, int s, char p,int g)
{
	SheadX = x;
	SheadY = y;
	Slenth = l;
	dir = d;
	Speed = s;
	pic = p;
	grade = g;

	for (int i = 0; i < Slenth; i++)
	{
		unit myunit(0, 0,'*');
		mybody.push_back(myunit);
		switch (dir)
		{
		case Up:
			mybody[i].m_iX = SheadX;
			mybody[i].m_iY = SheadY + i;
			break;
		case Down:
			mybody[i].m_iX = SheadX;
			mybody[i].m_iY = SheadY - i;
			break;
		case Left:
			mybody[i].m_iX = SheadX + i;
			mybody[i].m_iY = SheadY;
			break;
		case Right:
			mybody[i].m_iX = SheadX - i;
			mybody[i].m_iY = SheadY;
			break;
		default:
			break;
		}
	}
}
snake::~snake()
{

}

void snake::showSnake()
{
	
	for (int i = 0; i < Slenth; i++)
	{
		mybody[i].show();
	}
}
void snake::eraseSnake()
{
	for (int i = 0; i < Slenth; i++)
	{
		mybody[i].erase();
	}
}
void snake::move()
{
	eraseSnake();
	//蛇身体的移动
	for (int i = Slenth - 1; i > 0; i--)
	{
		mybody[i].m_iX = mybody[i - 1].m_iX;
		mybody[i].m_iY = mybody[i - 1].m_iY;
	}
	//蛇头移动
	switch (dir)
	{
	case Up:
		mybody[0].m_iY--;
		break;
	case Down:
		mybody[0].m_iY++;
		break;
	case Left:
		mybody[0].m_iX--;
		break;
	case Right:
		mybody[0].m_iX++;
		break;
	default:
		break;
	}
	showSnake();
	Sleep(Speed);
	//eraseSnake();
}
void snake::changedir(int keyvaule)
{
	switch (keyvaule)
	{
	case 72:
		if (dir==Left||dir==Right)
		{
			dir = Up;
		}
		break;
	case 80:
		if (dir == Left || dir == Right)
		{
			dir = Down;
		}
		break;
	case 75:
		if (dir == Up || dir == Down)
		{
			dir = Left;
		}
		break;
	case 77:
		if (dir == Up || dir == Down)
		{
			dir = Right;
		}
		break;
	default:
		break;
	}
}

bool snake::eatfood(food *p)
{
	if (mybody[0].m_iX == p->m_iX&&mybody[0].m_iY == p->m_iY)
	{
		return true;
	}
	return false;
}

void snake::growup()
{
	unit myunit(0, 0, '*');
	mybody.push_back(myunit);
	Slenth++;
	grade++;
}

bool snake::die()
{
	/*unit head= mybody[0];*/
	for (int i = 1; i < Slenth; i++)
	{
		if(mybody[0].m_iX == mybody[i].m_iX&& mybody[0].m_iY == mybody[i].m_iY)
		{
			return true;
		}
		/*else
			return false;*/
	}
	//if(mybody[0].m_iX<= 2 || mybody[0].m_iY>= wall::COL-1|| head.m_iY <= 0|| head.m_iY >= wall::ROW)
	if (mybody[0].m_iX <= wall::left || mybody[0].m_iY <= wall::up || mybody[0].m_iY >=wall::ROW+1 || mybody[0].m_iX >= wall::COL+1)
	{
		return true;
	}
	//else
		return false;
}
int snake::speedup()
{
	if (Slenth < 5)
	{
		Speed = 300;
	}
	else if (Slenth >= 5 && Slenth <= 10)
	{
		Speed = 200;
	}
	else
	{
		Speed = 100;
	}
	return Speed;
}