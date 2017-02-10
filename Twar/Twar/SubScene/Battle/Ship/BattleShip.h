/**
	@file ShipManager.h
	@brief ShipManager�N���X�w�b�_
	@author kawaguchi
*/

#ifndef	BATTLESHIP_H
#define BATTLESHIP_H

#include "Ship.h"

/**
	��̓N���X
*/
class BattleShip : public Ship
{
public:
	/**	�R���X�g���N�^ */
	BattleShip(D3DXVECTOR3* pos, BulletManager* pBulletManager);

	/**	�f�X�g���N�^ */
	~BattleShip();

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

	void debugControl();
};

#endif	//	BATTLESHIP_H
