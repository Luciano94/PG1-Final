#include "Game.h"



Game::Game()
{
}


Game::~Game()
{
}

void Game::Update(){
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.display();
	}
}

void Game::Start()
{
	window.create(sf::VideoMode(800, 600), "SFML works!");
}

void Game::Stop(){
	
}

void Game::Draw()
{
}
