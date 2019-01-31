#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include "Player1.h"
#include "Player2.h"
#include "ObstacleManager.h"
#include "InterfaceManager.h"
#include "GameManager.h"
#include "GlobalDefinitions.h"
#include "DeltaTime.h"
#include "Boost.h"

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

	InterfaceManager * UI;
	ObstacleManager * ObsManager;
	DeltaTime * dt;
	GameManager * gm;
//methods	
	void Draw();
	void CallUpdates();
public:
	Game();
	~Game();
	void Update();
	void Start();
	void Stop();
};

