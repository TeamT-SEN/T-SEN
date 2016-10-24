/**
* @file InputKey.cpp
* @brief  ����L�[�Ɋւ���N���X��cpp
* @author haga
*/
#include <dinput.h>

#include "InputKey.h"

// �R���X�g���N�^
InputKey::InputKey() : m_pKeyDevice(InputDevice::GetInstance().GetKeyDevice())
{
	for (int i = 0; i < KEYMAX;i++)
	{
		m_PreKey[i] = BTN_OFF;
	} 
}

// �f�X�g���N�^
InputKey::~InputKey()
{
}

// �L�[�̍X�V
void InputKey::UpdateKey()
{
	HRESULT hr = m_pKeyDevice->Acquire();
	if ((hr == DI_OK) || (hr == S_FALSE))
	{
		m_pKeyDevice->GetDeviceState(sizeof(m_diks), &m_diks);
	}
}

// �L�[�`�F�b�N�֐�
BTN_STATE InputKey::CheckKey(int DIK, KEYKIND st)
{
	CheckState(&m_diks[DIK], st);

	return m_Key[st];
}

// ��Ԋm�F�֐�
void InputKey::CheckState(BYTE* DIK, KEYKIND st)
{
	if ((*DIK) & 0x80)
	{
		if (m_PreKey[st] == BTN_OFF)
		{
			m_Key[st] = BTN_PUSH;
		
		}
		else
		{
			m_Key[st] = BTN_ON;
		}
		m_PreKey[st] = BTN_ON;
	}
	else
	{
		if (m_PreKey[st] == BTN_ON)
		{
			m_Key[st] = BTN_RELEASE;
		}
		else
		{
			m_Key[st] = BTN_OFF;
		}
		m_PreKey[st] = BTN_OFF;
	}
}
