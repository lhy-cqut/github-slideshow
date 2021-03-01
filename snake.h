#pragma once
#include"vector"
#include "unit.h"
#include "food.h"
typedef enum {
	Up, Down, Left, Right
}Dir;
class snake
{
public:
	int Slenth;
	int SheadX;
	int SheadY;
	Dir dir;
	int Speed;
	char pic;
	int grade;
	vector<unit> mybody;
public:
	snake(int headx = 20, int heady = 10, int length =3, Dir dir = Right, int speed =300, char pic = '*', int gra = 0);
	~snake();
	void createSnake();
	void showSnake();
	void eraseSnake();
	void move();
	void changedir(int key);
	bool eatfood(food *p);
	void growup();
	int speedup();
	bool die();
};

