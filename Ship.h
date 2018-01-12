#pragma once

#include "Bullet.h"

enum DIR
{
	DIR_NONE = 0,
	DIR_LEFT = 1,
	DIR_RIGHT =2
}; 

class Ship
{
public:
	short score; 
	short x, y;
	DIR dir;

	Ship();

	void Update();
	void Render();
	void PreRender();
};

