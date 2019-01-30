#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include <SFML/Graphics.hpp>
#include "DeltaTime.h"
#include "GlobalDefinitions.h"

using namespace std;
using namespace Constants;

class GameManager{
private:
	float timer;
	DeltaTime * dt;

	GameManager();
	static GameManager * Instance;
public:
	static GameManager * GetInstance();
	~GameManager();
	void Update();
	float GetTime();

};

#endif // !GAMEMANAGER_H
