#include "Enemy.h"
#include "Ship.h"

#include <iostream>
#include <vector>
#include <Windows.h>
#include <ctime>
#include <utility>
#include <fstream>
#include <string>
#include <iomanip>

enum GAMESTATE
{
	GS_MENU = 0,
	GS_PLAY = 1,
	GS_SCORE = 2,
	GS_PLAYEND = 3,
	GS_END = 4
};

class GameManager
{
public:
	GameManager();
	~GameManager(); 

	GAMESTATE gs; 

	Ship* player; 
	std::vector<Bullet*> bullets; 
	std::vector<Enemy*> enemies; 

	const unsigned MAX_AMOUNT_OF_ENEMIES = 5; 
	const unsigned PLAY_SECONDS = 60; 
	const unsigned MAX_PLAY_TIME = FPS * PLAY_SECONDS;

	unsigned timeLeft; 

	void Input();
	void Render();
	void Update();
	void PreRender();

	void UpdateScoreFile(); 

};