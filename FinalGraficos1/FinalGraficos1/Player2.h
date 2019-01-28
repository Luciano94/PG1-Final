#ifndef PLAYER2_H
#define PLAYER2_H
#include "Player.h"

using namespace std;

class Player2 : public Player
{
private:
	void Input(float dt) override;
	void BoundingCheck() override;
public:
	Player2(string texturePath);
	~Player2();

	void Update(float dt) override;
};

#endif // !PLAYER2_H
