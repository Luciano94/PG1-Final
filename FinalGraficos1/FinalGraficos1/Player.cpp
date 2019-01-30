#include "Player.h"



Player::Player(string texturePath): speed(P_SPEED){
	texture = new sf::Texture();
	texture->loadFromFile(texturePath);
	character.setSize(sf::Vector2f(P_WIDTH, P_HEIGHT));
	character.setTexture(texture);
}


Player::~Player(){
	delete texture;
}

void Player::Draw(sf::RenderWindow &win){
	win.draw(character);
}

