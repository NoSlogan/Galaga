#include "GameManager.h"

GameManager::GameManager()
{ 
	SMALL_RECT r; 
	r.Left = r.Top = 0;
	r.Right = 81;
	r.Bottom = 41;
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &r);

	gs = GS_MENU;
	player = nullptr;
}

GameManager::~GameManager()
{
	delete player; 
	for (unsigned i = 0; i < bullets.size(); ++i)
	{
		delete bullets.at(i);
	}
	for (unsigned i = 0; i < enemies.size(); ++i)
	{
		delete enemies.at(i); 
	}
}

void GameManager::Input()
{
	if (gs == GS_PLAY) 
	{
		if (GetKeyState(VK_SPACE) & 0x8000) 
		{
			Bullet* tmpptr = new Bullet(player->x, player->y); 
			bullets.push_back(tmpptr); 
		}
		if (GetKeyState(VK_LEFT) & 0x8000)
		{
			player->dir = DIR_LEFT; 
		}
		if (GetKeyState(VK_RIGHT) & 0x8000)
		{
			player->dir = DIR_RIGHT;
		}
		if (GetKeyState(VK_LCONTROL) & 0x8000) 
		{
			enemies.push_back(new Enemy);
		}
	}
}

void GameManager::Render()
{
	int choice = 0;
	unsigned tmpPlace = 11; 
	std::string tmpName = ""; 
	switch (gs)
	{
	case GS_MENU:
		while (!((choice == 1) || (choice == 2) || (choice == 3))) 
		{
			system("cls");
			std::cout << "Wcisnij 1 Nowa gra" << std::endl;
			std::cout << "Wcisnij 2 Highscore" << std::endl;
			std::cout << "Wcisnij 3 Exit" << std::endl;
			std::cin >> choice;
		}
		if (choice == 1) 
		{
			
			delete player;
			for (unsigned i = 0; i < bullets.size(); ++i)
			{
				delete bullets.at(i);
			}
			for (unsigned i = 0; i < enemies.size(); ++i)
			{
				delete enemies.at(i);
			}
			bullets.clear();
			enemies.clear();
			//
			player = new Ship;
			timeLeft = MAX_PLAY_TIME; 
			system("cls");
			gs = GS_PLAY; 
		}
		else if (choice == 2)
			gs = GS_SCORE; 
		else if (choice == 3)
			gs = GS_END; 
		break;
	case GS_PLAY:
		player->Render(); 
		for (unsigned i = 0; i < enemies.size(); ++i)
		{
			enemies.at(i)->Render(); 
		}
		for (unsigned i = 0; i < bullets.size(); ++i)
		{
			bullets.at(i)->Render(); 
		}
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0,36}); 
		std::cout << "Points: " << player->score << "\t" << std::fixed << " Time left: " << timeLeft / static_cast<float>(FPS); 
		break;
	case GS_PLAYEND:
		system("cls"); 
		std::cout << "Your score is: " << player->score << " points." << std::endl;
		std::cout << "Press enter to continue..." << std::endl; 
		while (!(GetKeyState(VK_RETURN) & 0x8000)) {} 
		
	case GS_SCORE:
		system("cls");
		std::cout << "Highscore List: " << std::endl;
		for (int i = 0; i < 10; ++i)
		{
			std::cout << tu beda wyniki;
		}
		std::cout << "Press space button to go back to main menu..." << std::endl;
		while (!(GetKeyState(VK_SPACE) & 0x8000)) {} 
		gs = GS_MENU; 
		break;
	}
}

void GameManager::Update()
{
	if (gs == GS_PLAY)
	{
		--timeLeft; 
		while (enemies.size()< MAX_AMOUNT_OF_ENEMIES)
		{
			enemies.push_back(new Enemy); 
		}
		player->Update(); 
		for (unsigned i = 0; i < bullets.size(); ++i)
		{
			bullets.at(i)->Update();
			if (bullets.at(i)->y < 0) 
			{
				delete bullets.at(i); 
				bullets.erase(bullets.begin() + i); 
			}
		}
		for (unsigned i = 0; i < enemies.size(); ++i)
		{
			for (unsigned j = 0; j < bullets.size(); ++j)
			{
				if (enemies.at(i)->x == bullets.at(j)->x && enemies.at(i)->y == bullets.at(j)->y) 
				{
					player->score++; 
					enemies.erase(enemies.begin() + i); 
					bullets.erase(bullets.begin() + j);
					i = 0; 
					j = 0; 
				}
			}
		}
		if (timeLeft <= 0)
		{
			gs = GS_PLAYEND; 
		}
	}
}

void GameManager::PreRender() 
{
	if (gs == GS_PLAY) 
	{
		player->PreRender();
		for (unsigned i = 0; i < enemies.size(); ++i)
		{
			enemies.at(i)->PreRender();
		}
		for (unsigned i = 0; i < bullets.size(); ++i)
		{
			bullets.at(i)->PreRender();
		}
	}
}

