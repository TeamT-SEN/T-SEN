/**
* @file		Pursuit.h
* @brief	Pursuit�N���X�w�b�_
* @author	haga
*/

#ifndef PURSUIT_H
#define PURSUIT_H

#include "State.h"

/**
* �ǐՍs���̏�ԃN���X
*/
class Pursuit : public State
{

public:

	Pursuit();

	~Pursuit();

	/**�R���g���[���֐�*/
	virtual State::STATE_ID Control(const Ship::STATUS& rStatus);

};

#endif	// PURSUIT_H
