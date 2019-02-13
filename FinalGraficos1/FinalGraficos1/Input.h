#ifndef INPUT_H
#define INPUT_H
#include "GlobalDefinitions.h"
#include "GameManager.h"
#include "DeltaTime.h"
#include "InterfaceManager.h"
#include "SoundManager.h"
#include "ObstacleManager.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace Constants;

class Input
{
private:
	GameManager * gm;
	InterfaceManager * UI;
	DeltaTime * dT;
	ObstacleManager * oM;
	SoundManager * sM;
	
	float inputDelay;
	float actInputDelay;

	Input();
	static Input * Instance;
public:
	static Input * GetInstance();
	~Input();
	void Update(float dt);
};

#endif // !INPUT_H
