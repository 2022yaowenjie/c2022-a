#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<Windows.h>
int map[8][8] = {
	{2, 2, 2, 2, 2, 2, 2, 2},
	{2, 1, 1, 2, 1, 1, 1, 2},
	{2, 1, 3, 4, 4, 3, 1, 2},
	{2, 5, 3, 4, 7, 1, 2, 2},
	{2, 1, 3, 4, 4, 3, 1, 2},
	{2, 1, 1, 2, 1, 1, 1, 2},
	{2, 1, 1, 1, 1, 1, 2, 2},
	{2, 2, 2, 2, 2, 2, 2, 2},
};
//空地=1 墙=2 箱子=3 障碍=4 人=5  人+障碍=9  箱子+障碍=7
int x=3, y=1;//记录虫子的坐标位置
void setmap();
void move();
int judge();
int main() 
{
	//解决闪屏
	HANDLE hOutput;
	COORD coord = { 0,0 };
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	while (1) 
	{
		setmap();
		move();
		SetConsoleCursorPosition(hOutput, coord);
		if (judge())//获得胜利判断
		{
			system("cls");
			printf("you win");
			break;
		}
	}
	return 0;
}
void setmap() 
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			switch (map[i][j]) {
			case 1:printf(" ");
				break;
			case 2:printf("*");
				break;
			case 3:printf("M");
				break;
			case 4:printf("O");
				break;
			case 5:printf("&");
				break;
			case 7:printf("M");
				break;
			case 9:printf("&");
				break;

			}
		}
		printf("\n");
	}
}
void move() 
{
	char ch;
	ch= _getch();
		switch (ch) 
		{
			case 75:
			if (map[x][y] != 9) //现在位置不是人+障碍
			{
				if (map[x][y - 1] == 1) //为空地
				{  
					map[x][y] = 1;
					map[x][y - 1] = 5;
					y--;
				}
				else if (map[x][y - 1] == 3) //移动方向为箱子
				{
					if (map[x][y - 2] == 1) //移动方向的下下一个为空地
					{  
						map[x][y] = 1;
						map[x][y - 1] = 5;
						map[x][y - 2] = 3;
						y--;
					}
					else if (map[x][y - 2] == 4) //移动方向的下下一个为障碍
					{
						map[x][y] = 1;
						map[x][y - 1] = 5;
						map[x][y - 2] = 7;
						y--;
					}

				}
				else if (map[x][y - 1] == 4) //移动的方向为障碍
				{
					map[x][y] = 1;
					map[x][y - 1] = 9;
					y--;
				}
				else if (map[x][y - 1] == 7) //移动方向为箱子+障碍
				{
					if (map[x][y - 2] != 3 && map[x][y - 2] != 7 && map[x][y - 2] != 2) 
					{
						if (map[x][y - 2] == 4) //下下位置为障碍
						{
							map[x][y] = 1;
							map[x][y - 1] = 9;
							map[x][y - 2] = 7;
							y--;
						}
						else //则为空地
						{  
							map[x][y] = 1;
							map[x][y - 1] = 9;
							map[x][y - 2] = 3;
							y--;
						}
					}
				}
			}          
			else //现在位置是为人+障碍
			{
				if (map[x][y - 1] == 1) //为空地
				{  
					map[x][y] = 4;
					map[x][y - 1] = 5;
					y--;
				}
				else if (map[x][y - 1] == 3) //移动方向为箱子
				{
					if (map[x][y - 2] == 1) //移动方向的下下一个为空地
					{  
						map[x][y] = 4;
						map[x][y - 1] = 5;
						map[x][y - 2] = 3;
						y--;
					}
					else if (map[x][y - 2] == 4) //移动方向的下下一个为障碍
					{
						map[x][y] = 4;
						map[x][y - 1] = 5;
						map[x][y - 2] = 7;
						y--;
					}
				}
				else if (map[x][y - 1] == 4) //移动的方向为障碍
				{
					map[x][y] = 4;
					map[x][y - 1] = 9;
					y--;
				}
				else if (map[x][y - 1] == 7) //移动方向为箱子+障碍
				{
					if (map[x][y - 2] == 4) //下下位置为障碍
					{
						map[x][y] = 4;
						map[x][y - 1] = 9;
						map[x][y - 2] = 7;
						y--;
					}
					else if (map[x][y - 2] == 1) //下下位置为空地
					{            
						map[x][y] = 4;
						map[x][y - 1] = 9;
						map[x][y - 2] = 3;
						y--;
					}
					else;
				}
			}
			break;
		case 80: 
			if (map[x][y] != 9) //现在位置不是为人+障碍
			{
				if (map[x + 1][y] == 1) //为空地
				{  
					map[x][y] = 1;
					map[x + 1][y] = 5;
					x++;
				}
				else if (map[x + 1][y] == 3) //移动方向为箱子
				{
					if (map[x + 2][y] == 1) //移动方向的下下一个为空地
					{
						map[x][y] = 1;
						map[x + 1][y] = 5;
						map[x + 2][y] = 3;
						x++;
					}
					else if (map[x + 2][y] == 4) //移动方向的下下一个为障碍
					{
						map[x][y] = 1;
						map[x + 1][y] = 5;
						map[x + 2][y] = 7;
						x++;
					}

				}
				else if (map[x + 1][y] == 4) //移动的方向为障碍
				{
					map[x][y] = 1;
					map[x + 1][y] = 9;
					x++;
				}
				else if (map[x + 1][y] == 7) //移动方向为箱子+障碍
				{

					if (map[x + 2][y] == 4) //下下位置为障碍
					{
						map[x][y] = 1;
						map[x + 1][y] = 9;
						map[x + 2][y] = 7;
						x++;
					}
					else if (map[x + 2][y] == 1)//为空地 
					{ 
						map[x][y] = 1;
						map[x + 1][y] = 9;
						map[x + 2][y] = 3;
						x++;
					}
				}
			}
			else   //现在位置是为人+障碍
			{
			if (map[x + 1][y] == 1) //为空地
			{  
				map[x][y] = 4;
				map[x + 1][y] = 5;
				x++;
			}
			else if (map[x + 1][y] == 3)//移动方向为箱子
			{
				if (map[x + 2][y] == 1)  //移动方向的下下一个为空地
				{  
					map[x][y] = 4;
					map[x + 1][y] = 5;
					map[x + 2][y] = 3;
					x++;
				}
				else if (map[x + 2][y] == 4) //移动方向的下下一个为障碍
				{
					map[x][y] = 4;
					map[x + 1][y] = 5;
					map[x + 2][y] = 7;
					x++;
				}
			}
			else if (map[x + 1][y] == 4) //移动的方向为障碍
			{
				map[x][y] = 4;
				map[x + 1][y] = 9;
				x++;
			}
			else if (map[x + 1][y] == 7) //移动方向为箱子+障碍
			{
				if (map[x + 2][y] != 3 && map[x + 2][y] != 7 && map[x + 2][y] != 2) 
				{
					if (map[x + 2][y] == 4) //下下位置为障碍
					{
						map[x][y] = 4;
						map[x + 1][y] = 9;
						map[x + 2][y] = 7;
						x++;
					}
					else //则下下位置为空地
					{          
						map[x][y] = 4;
						map[x + 1][y] = 9;
						map[x + 2][y] = 3;
						x++;
					}
				}
			}
		}
			   break;

		case 77:
			if (map[x][y] != 9) //现在位置不是为人+障碍
			{
				if (map[x][y + 1] == 1)  //为空地
				{  
					map[x][y] = 1;
					map[x][y + 1] = 5;
					y++;
				}
				else if (map[x][y + 1] == 3) //移动方向为箱子
				{ 
					if (map[x][y + 2] == 1)  //移动方向的下下一个为空地
					{  
						map[x][y] = 1;
						map[x][y + 1] = 5;
						map[x][y + 2] = 3;
						y++;
					}
					else if (map[x][y + 2] == 4) //移动方向的下下一个为障碍
					{ 
						map[x][y] = 1;
						map[x][y + 1] = 5;
						map[x][y + 2] = 7;
						y++;
					}

				}
				else if (map[x][y + 1] == 4) //移动的方向为障碍
				{ 
					map[x][y] = 1;
					map[x][y + 1] = 9;
					y++;
				}
				else if (map[x][y + 1] == 7) //移动方向为箱子+障碍
				{ 
					if (map[x][y + 2] != 3 && map[x][y + 2] != 7 && map[x][y + 2] != 2) {
						if (map[x][y + 2] == 4)//下下位置为障碍
						{ 
							map[x][y] = 1;
							map[x][y + 1] = 9;
							map[x][y + 2] = 7;
							y++;
						}
						else //则为空地
						{   
							map[x][y] = 1;
							map[x][y + 1] = 9;
							map[x][y + 2] = 3;
							y++;
						}
					}


				}
			}           
			else  //现在位置是为人+障碍
			{
				if (map[x][y + 1] == 1) //为空地
				{   
					map[x][y] = 4;
					map[x][y + 1] = 5;
					y++;
				}
				else if (map[x][y + 1] == 3) //移动方向为箱子
				{ 
					if (map[x][y + 2] == 1)  //移动方向的下下一个为空地
					{  
						map[x][y] = 4;
						map[x][y + 1] = 5;
						map[x][y + 2] = 3;
						y++;
					}
					else if (map[x][y + 2] == 4) //移动方向的下下一个为障碍
					{ 
						map[x][y] = 4;
						map[x][y + 1] = 5;
						map[x][y + 2] = 7;
						y++;
					}

				}
				else if (map[x][y + 1] == 4) //移动的方向为障碍
				{ 
					map[x][y] = 4;
					map[x][y + 1] = 9;
					y++;
				}
				else if (map[x][y + 1] == 7) //移动方向为箱子+障碍
				{

					if (map[x][y + 2] == 4) //下下位置为障碍
					{ 
						map[x][y] = 4;
						map[x][y + 1] = 9;
						map[x][y + 2] = 7;
						y++;
					}
					else if (map[x][y + 2] == 1)  //则下下位置为空地
					{             
						map[x][y] = 4;
						map[x][y + 1] = 9;
						map[x][y + 2] = 3;
						y++;
					}
				}
			}
			break;

		case 72:
			if (map[x][y] != 9) //现在位置不是为人+障碍
			{ 
				if (map[x - 1][y] == 1) 
				{  //为空地
					map[x][y] = 1;
					map[x - 1][y] = 5;
					x--;
				}
				else if (map[x - 1][y] == 3)//移动方向为箱子
				{ 
					if (map[x - 2][y] == 1) //移动方向的下下一个为空地
					{   
						map[x][y] = 1;
						map[x - 1][y] = 5;
						map[x - 2][y] = 3;
						x--;
					}
					else if (map[x - 2][y] == 4) //移动方向的下下一个为障碍
					{ 
						map[x][y] = 1;
						map[x - 1][y] = 5;
						map[x - 2][y] = 7;
						x--;
					}
				}
				else if (map[x - 1][y] == 4) //移动的方向为障碍
				{ 
					map[x][y] = 1;
					map[x - 1][y] = 9;
					x--;
				}
				else if (map[x - 1][y] == 7) //移动方向为箱子+障碍
				{ 
					if (map[x - 2][y] != 3 && map[x - 2][y] != 7 && map[x - 2][y] != 2) 
					{
						if (map[x - 2][y] == 4)//下下位置为障碍
						{ 
							map[x][y] = 1;
							map[x - 1][y] = 9;
							map[x - 2][y] = 7;
							x--;
						}
						else //则为空地
						{   
							map[x][y] = 1;
							map[x - 1][y] = 9;
							map[x - 2][y] = 3;
							x--;
						}
					}
				}
			}           
			else  //现在位置是为人+障碍
			{
				if (map[x - 1][y] == 1)//为空地
				{   
					map[x][y] = 4;
					map[x - 1][y] = 5;
					x--;
				}
				else if (map[x - 1][y] == 3)//移动方向为箱子
				{ 
					if (map[x - 2][y] == 1)//移动方向的下下一个为空地
					{   
						map[x][y] = 4;
						map[x - 1][y] = 5;
						map[x - 2][y] = 3;
						x--;
					}
					else if (map[x - 2][y] == 4)//移动方向的下下一个为障碍
					{ 
						map[x][y] = 4;
						map[x - 1][y] = 5;
						map[x - 2][y] = 7;
						x--;
					}
				}
				else if (map[x - 1][y] == 4) //移动的方向为障碍
				{
					map[x][y] = 4;
					map[x - 1][y] = 9;
					x--;
				}
				else if (map[x - 1][y] == 7) //移动方向为箱子+障碍
				{ 
					if (map[x - 2][y] == 4)//下下位置为障碍
					{
						map[x][y] = 4;
						map[x - 1][y] = 9;
						map[x - 2][y] = 7;
						x--;
					}
					else if (map[x - 2][y] == 1)  //下下位置为空地
					{           
						map[x][y] = 4;
						map[x - 1][y] = 9;
						map[x - 2][y] = 3;
						x--;
					}
				}
			}
			break;
		}
}
int judge()
{
	if (map[2][3] == 7 && map[2][4] == 7 &&
		map[3][3] == 7 && map[3][4] == 7 &&
		map[4][3] == 7 && map[4][4] == 7)
		return 1;
	else
		return 0;
}
