/**
	@file ShipManager.h
	@brief ShipManager�N���X�w�b�_
	@author kawaguchi
*/
#ifndef	CRUISER_H
#define CRUISER_H

#include "Ship.h"

/**
	���m�̓N���X
*/
class Cruiser : public Ship
{
private:
	/**	case Control of "the player" */
	virtual void ControlPlayer();

	/**	case Control of "the ally" */
	virtual void ControlAlly();

	/**	case Control of "the enemy" */
	virtual void ControlEnemy();

	const float m_SpeedLimit = 1.5f;		//!<	���E���x

public:
	/**	�R���X�g���N�^ */
	Cruiser(D3DXVECTOR3* pos);

	/**	�f�X�g���N�^ */
	~Cruiser();

	/**	�R���g���[���֐� */
	virtual void Control();

	/**	�`��֐� */
	virtual void Draw();
};

#endif	//	CRUISER_H