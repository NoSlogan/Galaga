#include "Ship.h"

Ship::Ship()
	: x(20), y(30)
{
	dir = DIR_NONE; 
	score = 0; 
}


void Ship::Render()
{
	COORD pos = { x, y };
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, pos);
	std::cout << "O" << std::endl;
}

void Ship::PreRender()
{
	COORD pos = { x, y };
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, pos);
	std::cout << " " << std::endl;
}
