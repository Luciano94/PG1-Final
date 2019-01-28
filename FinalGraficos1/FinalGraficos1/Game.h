#pragma once
#include <SFML/Graphics.hpp>
#include "Player1.h"
#include "Player2.h"
#include "GlobalDefinitions.h"

using namespace Constants;

class Game{

private:
	sf::RenderWindow window;
	Player1 * p1;
	Player2 * p2;

	void Draw();
public:
	Game();
	~Game();
	void Update();
	void Start();
	void Stop();
};

