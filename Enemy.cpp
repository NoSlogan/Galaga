#include "Enemy.h"

Enemy::Enemy()
{
	std::random_device rd; 
	x = rd() % 81;
	y = rd() % 21; 
}

void Enemy::Render()
{
	COORD pos = { x, y };
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, pos);
	std::cout << "x" << std::endl;
}

void Enemy::PreRender()
{
	COORD pos = { x, y };
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, pos);
	std::cout << " " << std::endl;
}
