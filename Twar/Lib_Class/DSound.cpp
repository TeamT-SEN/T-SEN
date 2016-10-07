/**
* @file DSound.cpp
* @brief DirectSound�Ɋւ���N���X��cpp
* @author haga
*/
#include <dSound.h>
#include "DSound.h"

// �R���X�g���N�^
DSound::DSound() :m_pDSound8(NULL)
{
}

// �f�X�g���N�^
DSound::~DSound()
{
	if (m_pDSound8)
	{
		m_pDSound8->Release();
		m_pDSound8 = NULL;
	}
}

// �C���^�[�t�F�C�X�̏�����
void DSound::InitDSound(HWND hWnd)
{
	DirectSoundCreate8(NULL, &m_pDSound8,NULL);
	// �������x���ݒ�
	m_pDSound8->SetCooperativeLevel(hWnd, DSSCL_NORMAL);

}
