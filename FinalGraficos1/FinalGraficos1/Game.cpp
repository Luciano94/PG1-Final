#include "Game.h"



Game::Game(){

}

void Game::Start(){
	window.create(sf::VideoMode(800, 600), "SFML works!");
	p1 = new Player1("../Assets/Sprites/Player.png");
	p2 = new Player2("../Assets/Sprites/Player.png");
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
		Draw();
		window.display();
	}
}

void Game::Stop(){
	
}

void Game::Draw(){
	p1->Draw(window);
	p2->Draw(window);
}
