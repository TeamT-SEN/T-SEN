/**
* @file		State.h
* @brief	State�N���X�w�b�_
* @author	haga
*/ 

#ifndef STATE_H
#define STATE_H

#include <d3dx9.h>
#include "../Ship.h"

/**
* �D�̏�Ԃ̊��N���X
*/
class State
{
public:
	enum STATE_ID
	{
		PURSUIT,	//!< �ǐՍs��
		EVADE,		//!< �����s��
		ATTACK,		//!< �U���s��
	};

	State();

	virtual ~State();

	/**�R���g���[���֐�*/
	virtual State::STATE_ID Control(const Ship::STATUS& rStatus) = 0;

	/**
	* �D�̃f�[�^���Z�b�g����֐�
	*/
	void SetShipData(const D3DXVECTOR3& rPos, float angle, float slant, float speedLimit);

	/**�f�[�^�擾�֐��Q*/
	const D3DXVECTOR3&	GetPos() { return m_Pos; }
	float				GetAngle(){ return m_Angle; }
	float				GetSlant(){ return m_Slant; }
	const Ship::STATUS&	GetStatus(){ return m_Status; }

protected:
	D3DXVECTOR3			m_Pos;					//!< �ʒu���
	float				m_Angle;				//!< �p�x
	float				m_Slant;				//!< �D�̌X��
	Ship::STATUS		m_Status;				//!< �X�e�[�^�X
	float				m_SpeedLimit;			//!< �X�s�[�h���E�l

	static const float	m_FiringRange;			//!< �˒� 
	static const float	m_CorrectionAngle;		//!< �␳�p�x

};

#endif	// STATE_H

