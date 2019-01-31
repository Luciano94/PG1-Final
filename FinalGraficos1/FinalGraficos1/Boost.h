#ifndef BOOST_H
#define BOOST_H
#include<SFML/Graphics.hpp>
#include "GlobalDefinitions.h"
#include "ObstacleManager.h"
class Boost{
private:
	float speed;
	float respawn;
	float actTime;
	bool isActive;
	int win;
	sf::RectangleShape boost;
	sf::Texture * texture;
	ObstacleManager * obsM;

	void Init();
	void Move(float dt);
public:
	Boost(int win);
	~Boost();
	void Update(float dt);
	void Draw(sf::RenderWindow &win);
};
#endif

