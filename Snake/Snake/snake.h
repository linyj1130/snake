#pragma once
#include <iostream>
#include "wall.h"
#include "food.h"

using namespace std;

class Snake
{
public:
	Snake(Wall& tempWall, Food & food);
	// �ڵ�

	enum 
	{
		UP = 'w',
		DOWN = 's',
		LEFT = 'a',
		RIGHT = 'd'
	};

	struct Point
	{
		// ������
		int x;
		int y;

		// ָ����
		Point* next;
	};

	void initSnake();

	// ���ٽڵ�
	void destroyPoint();

	// ��ӽڵ�
	void addPoint(int x, int y);

	// ɾ���ڵ�
	void delPoint();

	// �ߵ��ƶ�
	bool move(char key);

	// �趨�Ѷ�
	// ��ȡˢ��ʱ��
	int getSleepTime();

	// ��ȡ�ߵ����
	int countList();

	// ��ȡ����
	int getScore();

	Point * pHead;

	Wall & wall;

	Food& food;

	bool isRoll; // �ж�ѭ����ʾ
};