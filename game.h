#pragma once
#include"food.h"
#include"snake.h"
class game
{
public:
	game();
	virtual ~game();
	void run();
public:
	food *m_pFood;
	snake *m_pSnake;
};

