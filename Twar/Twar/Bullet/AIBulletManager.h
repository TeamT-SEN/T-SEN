/**
* @file		AIBulletManager.h
* @brief	AIBulletManager�N���X�w�b�_
* @author	haga
*/

#ifndef AI_BULLET_MANAGER_H
#define AI_BULLET_MANAGER_H

#include <d3dx9.h>
#include <vector>

class ApBullet;
class Bullet;
class FbxRelated;

/**
* AI��BulletManager�N���X
*/
class AIBulletManager
{
public:
	static  AIBulletManager&	Instance()
	{
		static AIBulletManager bulletManager;
		return bulletManager;
	}

	/**�R���g���[���֐�*/
	void Control();

	/**�`��֐�*/
	void Draw();

	/**�e�쐬�֐�*/
	void Create(const D3DXVECTOR3& pos);

	~AIBulletManager();

private:
	FbxRelated*					m_BulletModel;			//!< �e�̃��f��
	std::vector<Bullet*>		m_pBullets;

	AIBulletManager();

};

#endif	// AI_BULLET_MANAGER_H
