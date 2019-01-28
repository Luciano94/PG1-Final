#include "GameManager.h"



GameManager::GameManager(string texturePath){
	//texture = new sf::Texture();
	//texture->loadFromFile(texturePath);
	division.setSize(sf::Vector2f(DIV_WIDTH, DIV_HEIGHT));
	//division.setTexture(texture);
	division.setFillColor(sf::Color::Magenta);
	division.setPosition(DIV_SPAWN_X, DIV_SPAWN_Y);
}


GameManager::~GameManager()
{
}

void GameManager::Draw(sf::RenderWindow & win){
	win.draw(division);
}
