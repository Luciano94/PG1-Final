#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include "Player1.h"
#include "Player2.h"
#include "ObstacleS1.h"
#include "ObstacleS2.h"
#include "InterfaceManager.h"
#include "GlobalDefinitions.h"
#include "DeltaTime.h"

using namespace std;
using namespace Constants;

class Game{

private:
//attribute
	sf::RenderWindow window;
	Player1 * p1;
	Player2 * p2;
	ObstacleS1 * obs1;
	ObstacleS2 * obs2;
	InterfaceManager * UI;
	DeltaTime * dt;
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

