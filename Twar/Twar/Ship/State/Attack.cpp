/**
* @file		Attack.cpp
* @brief	Attack�N���X����
* @author	haga
*/

//--------------------------------------------------------------------------------------------------------------------------------------//
//Includes
//--------------------------------------------------------------------------------------------------------------------------------------//

#include "Attack.h"
#include "../../Battle/Radar.h"

//---------------------------------------------------------------------------------------------------------------------------------------//
//Namespace
//---------------------------------------------------------------------------------------------------------------------------------------//

namespace
{

const int		AttackInterVal = 300;						// �U���Ԋu
const float		CorrectionRange = 500.f;

}

//--------------------------------------------------------------------------------------------------------------------------------------//
//public functions
//--------------------------------------------------------------------------------------------------------------------------------------//

Attack::Attack()
	: m_AttackInterValCount(0)
{
}

Attack::~Attack()
{
}

State::STATE_ID Attack::Control(const Ship::STATUS& rStatus)
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

	if(length <= m_FiringRange + CorrectionRange)
	{
		if(m_AttackInterValCount == 0)
		{
			// �e������

			m_AttackInterValCount = AttackInterVal;
		}
		else
		{
			--m_AttackInterValCount;
		}

		m_Pos.x -= static_cast<float>(sin(targetRadian) * m_SpeedLimit) / 4.f;
		m_Pos.z -= static_cast<float>(cos(targetRadian) * m_SpeedLimit) / 4.f;
	}
	else
	{
		// �ǐՍs���Ɉڂ�
		return State::PURSUIT;
	}

	return State::ATTACK;
}
