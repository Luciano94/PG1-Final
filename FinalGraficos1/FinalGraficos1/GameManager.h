#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include <SFML/Graphics.hpp>
#include "DeltaTime.h"
#include "GlobalDefinitions.h"
#include "SoundManager.h"

using namespace std;
using namespace Constants;

class GameManager{
private:
	float timer;
	DeltaTime * dt;
	SoundManager * sM;
	GameStates gS;
	bool beClose;

	GameManager();
	static GameManager * Instance;
public:
	static GameManager * GetInstance();
	~GameManager();
	void Update();
	void p1Win();
	void p2Win();
	float GetTime();
	void InitGame();
	void GoToMenu();
	void GoToCredits();
	void GoToHowTo();
	void Exit();
	GameStates getActualState();
	bool BeClose();
};

#endif // !GAMEMANAGER_H
