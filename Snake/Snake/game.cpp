#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<ctime>
#include<conio.h>
#include<Windows.h>
#include "wall.h"
#include "snake.h"
#include "food.h"

using namespace std;


void gotoxy(HANDLE hOut, int x, int y)
{
	COORD pos;
	pos.X = x;             //������
	pos.Y = y;            //������
	SetConsoleCursorPosition(hOut, pos);
}
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//������ʾ���������


int main() {

	// ����������
	srand((unsigned int)time(NULL));

	// �Ƿ������ı�ʶ
	bool isDead = false;

	char preKey = NULL;

	Wall wall;
	wall.initWall();
	wall.drawWall();

	Food food(wall);
	food.setFood();

	Snake snake(wall, food);
	snake.initSnake();

	//snake.move('w');
	//snake.move('w');
	//snake.move('a');

	// snake.delPoint();

	gotoxy(hOut, 0, Wall::ROW);
	cout << "Score : " << snake.getScore() << "��" << endl;
	gotoxy(hOut, 10, 5); //y*2 x

	while (!isDead)
	{
		// �����û�������
		char key = _getch();

		// �ж�����ǵ�һ�ΰ���������Ų��ܼ�����Ϸ
		// ��һ�ε��ƶ�����
		if (preKey == NULL && key == snake.LEFT) 
		{
			continue;
		}
		do
		{
			if (key == snake.UP || key == snake.DOWN || key == snake.LEFT || key == snake.RIGHT)
			{
				// �жϱ��ΰ������Ƿ�����һ�γ�ͻ
				if( (key == snake.LEFT  && preKey == snake.RIGHT) ||
					(key == snake.RIGHT && preKey == snake.LEFT) || 
					(key == snake.UP && preKey == snake.DOWN) ||
					(key == snake.DOWN && preKey == snake.UP) )
				{
					key = preKey;
				}
				else
				{
					preKey = key;  //���ǳ�ͻ���������Ը��°���
				}

				if (snake.move(key) == true)
				{
					// �ƶ��ɹ���
					//system("cls");
					//wall.drawWall();
					gotoxy(hOut, 0,Wall::ROW);
					cout << "Score : "<< snake.getScore() << "��" << endl;
					Sleep(snake.getSleepTime());
				}
				else
				{
					isDead = true;
					break;
				}
			}
			else
			{
				key = preKey; // ǿ�ƽ����󰴼���Ϊ��һ�ΰ���
			}
			
			
		} while (!_kbhit()); // ��û�м��������ʱ�򣬷���0

	}

	//wall.setWall(5, 4, '=');
	//wall.setWall(5, 5, '=');
	//wall.setWall(5, 6, 'p');

	//cout << wall.getWall(0, 0) <<endl;
	//cout << wall.getWall(5, 6) <<endl;
	//cout << wall.getWall(5, 5) <<endl;

	system("pause");
	return EXIT_SUCCESS;

}