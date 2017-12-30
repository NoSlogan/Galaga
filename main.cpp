#include "GameManager.h"

int main()
{
	GameManager manager;
	clock_t start = clock();
	while (manager.gs != GS_END)
	{
		if ((clock() - start) > CLOCKS_PER_SEC/manager.FPS)
		{
			start = clock(); 
			manager.Input();
			manager.Update(); 
			manager.Render(); 
	}
	return 0;
}