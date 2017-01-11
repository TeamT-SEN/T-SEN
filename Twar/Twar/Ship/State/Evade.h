/**
* @file		Evade.h
* @brief    Evade�N���X�w�b�_
* @author	haga
*/

#ifndef EVADE_H
#define EVADE_H

#include "State.h"

/**
* �����s����ԃN���X
*/
class Evade : public State
{
public:

	Evade();
	~Evade();

	/**�R���g���[���֐�*/
	virtual State::STATE_ID Control(const Ship::STATUS& rStatus);
};

#endif	// EVADE_H
