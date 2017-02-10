/**
* @file BulletManager.h
* @brief BulletManager�N���X�w�b�_
* @author Matsuda
*/
#ifndef BULLETMANAGER_H
#define BULLETMANAGER_H

#include <vector>
#include "Bullet.h"

class ApBullet;
class Bullet;
class FbxRelated;
/**
*BulletManager�N���X
*/
class BulletManager
{
	friend class Bullet;

public:
	enum BULLET_ID
	{
		APBULLET,
		HEBULLET,
		TORPEDO,
	};

	typedef struct
	{
		float m_MaxX, m_MaxY, m_MaxZ;
		float m_MinX, m_MinY, m_MinZ;
		float m_MaxR;
	}BulletSize;

	/**�R���X�g���N�^*/
	BulletManager();

	/**�f�X�g���N�^*/
	~BulletManager();

	/**�R���g���[���֐�*/
	void Control(D3DXVECTOR3 Pos, float Rotate);

	/**�`��֐�*/
	void Draw();

	/**Bullet�����֐�*/
	void Create(const D3DXVECTOR3& rPos, float angle, D3DXVECTOR3* vec);

	BulletSize GetBulletSize(){ return m_BulletSize; };
	int GetBulletCount(){ return static_cast<int>(m_pBullet.size()); }
	D3DXVECTOR3 GetBulletPos(int i){ return m_pBullet[i]->GetPos(); }
	D3DXVECTOR3 GetBulletOldPos(int i){ return m_pBullet[i]->GetOldPos(); }
	float GetBulletRotate(int i){ return m_pBullet[i]->GetRotate(); }

	void SetHit(int i, bool is){ m_pBullet[i]->m_IsHit = is; };

private:
	ApBullet*		m_pAPBullet;
	FbxRelated*		m_pAPBulletModel;
	std::vector<Bullet*> m_pBullet;
	char m_BulletCount;
	int m_BulletNumber;
	BulletSize		m_BulletSize;
};
#endif //BULLETMANAGER_H

