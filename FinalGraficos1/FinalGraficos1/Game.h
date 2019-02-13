#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include "Player1.h"
#include "Player2.h"
#include "ObstacleManager.h"
#include "InterfaceManager.h"
#include "GameManager.h"
#include "CollisionManager.h"
#include "GlobalDefinitions.h"
#include "SoundManager.h"
#include "DeltaTime.h"
#include "Boost.h"
#include "Input.h"

using namespace std;
using namespace Constants;

class Game{

private:
//attribute
	sf::RenderWindow window;

	Player1 * p1;
	Player2 * p2;

	Boost * b1;
	Boost * b2;

	SoundManager * sM;
	Input * iM;
	InterfaceManager * UI;
	ObstacleManager * ObsManager;
	DeltaTime * dt;
	GameManager * gm;
	CollisionManager * cM;
//methods	
	void Draw();
	void CallUpdates();
	void CheckCollisions();
public:
	Game();
	~Game();
	void Update();
	void Start();
	void Stop();
};

