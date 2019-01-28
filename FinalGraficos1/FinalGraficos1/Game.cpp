#include "Game.h"



Game::Game(){

}

void Game::Start(){
	window.create(sf::VideoMode(W_WIDTH, W_HEIGHT), W_TITTLE);
	p1 = new Player1(P1_TEXTURE);
	p2 = new Player2(P2_TEXTURE);
	GM = new GameManager(DIV_TEXTURE);
	dt = DeltaTime::GetInstance();
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

		CallUpdates();
		Draw();

		window.display();
	}
}

void Game::Stop(){
	
}

void Game::Draw(){
	p1->Draw(window);
	p2->Draw(window);
	GM->Draw(window);
}

void Game::CallUpdates(){
	dt->Update();
	p1->Update(dt->Get());
	p2->Update(dt->Get());
}
