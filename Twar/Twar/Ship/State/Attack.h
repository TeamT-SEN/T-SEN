/**
* @file		Attack.h
* @brief	Attack�N���X�w�b�_
* @author	haga
*/

#ifndef ATTACK_H
#define ATTACK_H

#include "State.h"

class Attack : public State
{

public:
	Attack();
	~Attack();

	/**�R���g���[���֐�*/
	virtual STATE_ID Control(const Ship::STATUS& rStatus);

private:
	int			m_AttackInterValCount;

};

#endif	// ATTACK_H
