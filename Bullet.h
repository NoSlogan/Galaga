#include <iostream>
#include <Windows.h>

class Bullet 
{
public:
	short x, y; 
	Bullet(short x, short y); 

	void Update();
	void Render();
	void PreRender();
};

