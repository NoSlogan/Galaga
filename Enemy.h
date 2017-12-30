#include <iostream>
#include <Windows.h>
#include <random>

class Enemy
{
public:
	short x, y;
	Enemy();

	void Render();
	void PreRender();
};

