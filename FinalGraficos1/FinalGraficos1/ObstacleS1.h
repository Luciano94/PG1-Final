#ifndef OBSTACLES1_H
#define OBSTACLES1_H
#include "Obstacle.h"

using namespace std;
using namespace Constants;

class ObstacleS1 :public Obstacle{
public:
	ObstacleS1(string texturePath);
	~ObstacleS1();
	void Init() override;
};

#endif

