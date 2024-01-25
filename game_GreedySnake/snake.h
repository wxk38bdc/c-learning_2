#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <stdbool.h>
#include <wchar.h>

#define KEY_PRESS(vk) ((GetAsyncKeyState(vk)&0x1)?1:0) //��������
#define WALL L'�I' 
enum GAME_STATUS
{
	OK,
	ESC,
	KILL_BY_WALL,
	KILL_BY_SELF
};
enum DIRECTION
{
	UP=1,
	DOWN,
	LEFT,
	RIGHT
};
//��������ڵ�
typedef struct SnakeNode
{
	int x;
	int y;
	struct SnakeNode* next;
}SnakeNode, * pSnakeNode;
//������
typedef struct Snake
{
	pSnakeNode pSnake;//ά�������ߵ�ָ��
	pSnakeNode pFood;//ά��ʳ���ָ��
	int Score;//����
	int FoodWeight;//һ��ʳ��ķ���
	int SleepTime;//�����ߵ�ʱ��
	enum GAME_STATUS Status;//��Ϸ״̬
	enum DIRECTION Dir;//�ߵķ���
}Snake, * pSnake;
void SetPos(int x, int y); //���ù��λ��
void GameStart(pSnake ps); //��Ϸ��ʼ
void WelcomeToGame(); //��ӭ����
void CreateMap(); //������ͼ