#include "InterfaceManager.h"



InterfaceManager::InterfaceManager(){
	division.setSize(sf::Vector2f(DIV_WIDTH, DIV_HEIGHT));
	division.setFillColor(sf::Color::Magenta);
	division.setPosition(DIV_SPAWN_X, DIV_SPAWN_Y);
}


InterfaceManager::~InterfaceManager(){
}

void InterfaceManager::Draw(sf::RenderWindow & win){
	win.draw(division);
}
