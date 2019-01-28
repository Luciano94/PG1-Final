#include "Player1.h"



Player1::Player1(string texturePath) :Player(texturePath) {
	character.setPosition(sf::Vector2f(P1_SPAWN_X, P1_SPAWN_Y));
}


Player1::~Player1()
{
}
