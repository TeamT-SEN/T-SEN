/**
* @file		StateMachine.h
* @brief	StateMachine�N���X�w�b�_
* @author	haga
*/

#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include "State.h"

class StateMachine
{

public:

	StateMachine(const D3DXVECTOR3& rPos, float angle, float slant, float speedLimit);

	~StateMachine();

	/**�X�V�֐�*/
	void Update();

	/**�f�[�^�Z�b�g�֐�*/
	void SetStatus(const Ship::STATUS& rStatus);

	/**�f�[�^�擾�֐��Q*/
	const D3DXVECTOR3&	GetPos() { return m_Pos; }
	float				GetAngle(){ return m_Angle; }
	float				GetSlant(){ return m_Slant; }
	const Ship::STATUS&	GetStatus(){ return m_Status; }

private: 

	// �J�ڃX�e�b�v
	enum STEP
	{
		ENTER,		//!< �I��ł���X�e�C�g�ɂȂ� 
		EXECUTE,	//!< �I�񂾃X�e�C�g�����s����
		EXIT,		//!< �I��ł���X�e�C�g����߂�
		
	};

	State*				m_pState;			//!< State�N���X�̌p���N���X�̃C���X�^���X�ւ̃|�C���^
	STEP				m_Step;				//!< State�N���X�̑J�ڃX�e�b�v
	State::STATE_ID		m_CurrentStateID;	//!< ���݂�StateID
	State::STATE_ID		m_NextStateID;		//!< ����StateID

	D3DXVECTOR3			m_Pos;				//!< �ʒu���
	float				m_Angle;			//!< �p�x
	float				m_Slant;			//!< �D�̌X��
	Ship::STATUS		m_Status;			//!< �X�e�[�^�X
	const float			m_SpeedLimit;		//!< �X�s�[�h�̌��E�l

};

#endif	// STATE_MACHINE_H
