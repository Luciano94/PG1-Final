#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include "Player1.h"
#include "Player2.h"
#include "GameManager.h"
#include "GlobalDefinitions.h"
#include "DeltaTime.h"

using namespace std;
using namespace Constants;

class Game{

private:
	sf::RenderWindow window;
	Player1 * p1;
	Player2 * p2;
	GameManager * GM;
	DeltaTime * dt;
	void Draw();
	void CallUpdates();
public:
	Game();
	~Game();
	void Update();
	void Start();
	void Stop();
};

