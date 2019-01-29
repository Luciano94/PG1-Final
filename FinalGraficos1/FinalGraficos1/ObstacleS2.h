#ifndef OBSTACLES2_H
#define OBSTACLES2_H
#include "Obstacle.h"

using namespace std;
using namespace Constants;

class ObstacleS2 :public Obstacle{
public:
	ObstacleS2(string texturePath);
	~ObstacleS2();
	void Init() override;
};
#endif

