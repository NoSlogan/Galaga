#include "Bullet.h"

Bullet::Bullet(short x, short y)
	: x(x), y(y)
}

void Bullet::Update()
{
	--y; 
}

void Bullet::Render()
{ // funkcja dzia³a tak: 
	COORD pos = { x, y }; 
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); 
	SetConsoleCursorPosition(handle, pos); 
	std::cout << "|" << std::endl;
}

void Bullet::PreRender()
{ 
	COORD pos = { x, y };
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, pos);
	std::cout << " " << std::endl;
}
