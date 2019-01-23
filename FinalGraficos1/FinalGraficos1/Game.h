#pragma once
#include <SFML/Graphics.hpp>

class Game{

private:
	sf::RenderWindow window;
public:
	Game();
	~Game();
	void Update();
	void Start();
	void Stop();
	void Draw();
};

