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
public:
	/**	�R���X�g���N�^ */
	Cruiser(D3DXVECTOR3* pos, BulletManager* pBulletManager);

	/**	�f�X�g���N�^ */
	~Cruiser();

	/**	�R���g���[���֐� */
	virtual void Control();

	/**	�`��֐� */
	virtual void Draw();

private:
	/**	case Control of "the player" */
	virtual void ControlPlayer();

	/**	case Control of "the ally" */
	virtual void ControlAlly();

	/**	case Control of "the enemy" */
	virtual void ControlEnemy();
};

#endif	//	CRUISER_H
