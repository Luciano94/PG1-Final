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
	GameStates gS;

	GameManager();
	static GameManager * Instance;
public:
	static GameManager * GetInstance();
	~GameManager();
	void Update();
	void p1Win();
	void p2Win();
	float GetTime();
	GameStates getActualState();
};

#endif // !GAMEMANAGER_H
