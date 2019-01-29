#include "Game.h"



Game::Game(){

}

void Game::Start(){
	window.create(sf::VideoMode(W_WIDTH, W_HEIGHT), W_TITTLE);
	dt = DeltaTime::GetInstance();
	p1 = new Player1(P1_TEXTURE);
	p2 = new Player2(P2_TEXTURE);
	UI = new InterfaceManager();
	obs = new Obstacle(O_TEXTURE, 1);
	obs->Init();
}

Game::~Game(){

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
	delete p1;
	delete p2;
	delete UI;
	delete obs;
}

void Game::Draw(){
	p1->Draw(window);
	p2->Draw(window);
	UI->Draw(window);
	obs->Draw(window);
}

void Game::CallUpdates(){
	dt->Update();
	obs->Update(dt->Get());
	p1->Update(dt->Get());
	p2->Update(dt->Get());
}
