#ifndef PLAYER1_H
#define PLAYER1_H
#include "Player.h"
class Player1 : public Player{
private:
	void Input(float dt) override;
	void BoundingCheck() override;
public:
	Player1(string texturePath);
	~Player1();
	void Update(float dt) override;
};
#endif

