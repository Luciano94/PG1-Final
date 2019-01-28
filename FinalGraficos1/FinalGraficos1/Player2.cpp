#include "Player2.h"



Player2::Player2(string texturePath) :Player(texturePath){
	character.setPosition(sf::Vector2f(P2_SPAWN_X, P2_SPAWN_Y));
}


Player2::~Player2()
{
}
