#ifndef _PLAYERPADDLE_H__
#define _PLAYERPADDLE_H__
#include "VisibleGameObject.h"

class PlayerPaddle : public VisibleGameObject
{
public:
	PlayerPaddle();
	~PlayerPaddle();

	void Update(float elapsedTime);
	void Draw(sf::RenderWindow &rw);

	float GetVelocity() const;

private:
	float _velocity;
	float _maxVelocity;
};

#endif