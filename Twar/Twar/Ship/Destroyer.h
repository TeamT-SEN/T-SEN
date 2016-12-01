/**
	@file ShipManager.h
	@brief ShipManager�N���X�w�b�_
	@author kawaguchi
*/

#ifndef	DESTROYER_H
#define DESTROYER_H

#include "Ship.h"

/**
	�쒀�̓N���X
*/
class Destroyer : public Ship
{
private:
	/**	case Control of "the player" */
	virtual void ControlPlayer();

	/**	case Control of "the ally" */
	virtual void ControlAlly();

	/**	case Control of "the enemy" */
	virtual void ControlEnemy();

public:
	/**	�R���X�g���N�^ */
	Destroyer(D3DXVECTOR3* pos);

	/**	�f�X�g���N�^ */
	~Destroyer();

	/**	�R���g���[���֐� */
	virtual void Control();

	/**	�`��֐� */
	virtual void Draw();
};

#endif	//	DESTROYER_H
