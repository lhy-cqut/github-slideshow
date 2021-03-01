#pragma once

class wall
{
public:
	enum
	{
		ROW = 25, //行数，y坐标
		COL = 75,//列数，x坐标
		up = 1,//上边界
		left = 2//左边界
	};
	//画出墙壁
public:
	void drawWall();
};