#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<Windows.h>
int x = 1, y = 1;//人物坐标
int ex = 4, ey = 5;//迷宫出口
int map[6][6] = {
   {2,2,2,2,2,2},
   {2,1,1,2,1,2},
   {2,1,2,2,1,2},
   {2,1,1,2,1,2},
   {2,2,1,1,1,6},
   {2,2,2,2,2,2},
};
void setmap() {
	for (int i = 0; i < 6; i++) 
	{
		for (int j = 0; j < 6; j++) 
		{
			if (map[i][j] == 1) 
				printf(" ");
			if (map[i][j] == 2) 
				printf("*");
			if (map[i][j] == 5) 
				printf("&");
			if (map[i][j] == 6) 
				printf("0");
		}
		printf("\n");
	}
}//生成地图的函数
void move() 
{
	char ch;
	ch = _getch();
	switch (ch) 
	{
	case 75:
		if ((y - 1) >= 0 && map[x][y - 1] != 2) 
		{
			map[x][y] = 1;
			y -= 1;
		}
		break;
	case 80:
		if ((x + 1) <= 6 && map[x + 1][y] != 2) 
		{
			map[x][y] = 1;
			x += 1;
		}
		break;

	case 77:
		if ((y + 1) <= 6 && map[x][y + 1] != 2)
		{
			map[x][y] = 1;
			y += 1;
		}
		break;
	case 72:
		if ((x - 1) >= 0 && map[x - 1][y] != 2) 
		{
			map[x][y] = 1;
			x -= 1;
		}
		break;
	}
}
int main() {
	//解决闪屏
	HANDLE hOutput;
	COORD coord = { 0,0 };
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	while (1) 
	{
		map[x][y] = 5;  //设置人物坐标
		setmap();
		move();
		SetConsoleCursorPosition(hOutput, coord);
		if (x == ex && y == ey) 
		{
			system("cls");
			printf("you win");
			break;
		}
	}
	return 0;
}