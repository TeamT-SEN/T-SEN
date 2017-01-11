/**
* @file		Pursuit.cpp
* @brief	Pursuit�N���X����
* @author	haga
*/

//--------------------------------------------------------------------------------------------------------------------------------------//
//Includes
//--------------------------------------------------------------------------------------------------------------------------------------//

#include <d3dx9.h>
#include <math.h>
#include "Pursuit.h"
#include "../../Battle/Radar.h"

//--------------------------------------------------------------------------------------------------------------------------------------//
//Public functions
//--------------------------------------------------------------------------------------------------------------------------------------//

Pursuit::Pursuit()
{
}

Pursuit::~Pursuit()
{
}

State::STATE_ID Pursuit::Control(const Ship::STATUS& rStatus)
{
	m_Status = rStatus;

	D3DXVECTOR3 targetPos = Radar::Instance().GetMonsterPos();

	float targetRadian;
	if((targetPos.z - m_Pos.z) >= 0.0f)			// �^�[�Q�b�g��Z���W�̈ʒu�ɂ���Čv�Z���@��������
	{
		targetRadian = atan2f((targetPos.x - m_Pos.x), (targetPos.z - m_Pos.z));
	
	}
	else
	{
		targetRadian = atan2f((targetPos.z - m_Pos.z), (targetPos.x - m_Pos.x));
		targetRadian = D3DXToRadian(m_CorrectionAngle) - targetRadian;
	}

	m_Angle = targetRadian / (3.141592f / 180.f);

	D3DXVECTOR3 vecLength = (m_Pos - targetPos);
	float length = D3DXVec3Length(&vecLength);

	if(length > m_FiringRange)
	{
		// �O�i����
		//m_Pos.x += sin(targetRadian) * m_Status.m_Speed;
		m_Pos.x += static_cast<float>(sin(targetRadian) * m_SpeedLimit);
		//m_Pos.z += cos(targetRadian) * m_Status.m_Speed;
		m_Pos.z += static_cast<float>(cos(targetRadian) * m_SpeedLimit);
	}
	else
	{
		// �U���Ɉڍs����
		return State::ATTACK;
	}

	return State::PURSUIT;
}
