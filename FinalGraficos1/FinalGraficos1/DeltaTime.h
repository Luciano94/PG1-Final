#ifndef DELTATIME_H
#define DELTATIME_H
#include <SFML/Graphics.hpp>

class DeltaTime
{
private:
	sf::Clock deltaclock;
	float deltaTime;

	DeltaTime();
	static DeltaTime * Instance;
public:
	static DeltaTime * GetInstance();
	void Update();
	float Get();
	~DeltaTime();
};
#endif
