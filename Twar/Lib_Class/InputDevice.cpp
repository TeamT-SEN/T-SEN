/**
* @file   InputDevice.cpp
* @brief  DirectInput�֘A�N���X��cpp
* @author haga
*/
#include <dinput.h>
#include "InputDevice.h"

// �R���X�g���N�^
InputDevice::InputDevice() : m_pDInput(NULL),
m_pKeyDevice(NULL),
m_pMouseDevice(NULL),
m_hWnd(NULL)
{
}

// �f�X�g���N�^(�����Ńf�o�C�X�Ȃǂ��J�����Ă���)
InputDevice::~InputDevice()
{
	if (m_pKeyDevice)
	{
		m_pKeyDevice->Release();
		m_pKeyDevice = NULL;
	}

	if (m_pMouseDevice)
	{
		m_pMouseDevice->Release();
		m_pMouseDevice = NULL;
	}
	
	if (m_pDInput)
	{
		m_pDInput->Release();
		m_pDInput = NULL;
	}
}

// DirectInput����
HRESULT InputDevice::InitDinput()
{
	//	DirectInput �I�u�W�F�N�g�̍쐬
	if (FAILED(DirectInput8Create(GetModuleHandle(NULL),DIRECTINPUT_VERSION, IID_IDirectInput8, (VOID**)&m_pDInput, NULL)))
	{
		MessageBox(0, "DirectInput�I�u�W�F�N�g�����Ɏ��s���܂����B", NULL, MB_OK);
		return E_FAIL;
	}
	return S_OK;
}

// �L�[�{�[�h�f�o�C�X������
HRESULT InputDevice::InitDinputKey(HWND hWnd)
{
	// �����o�[�Ƀn���h�����i�[����
	m_hWnd = hWnd;

	//	�L�[�{�[�h�̏�����
	if (FAILED(m_pDInput->CreateDevice(GUID_SysKeyboard,
		&m_pKeyDevice, NULL)))
	{
		MessageBox(0, "DirectInput�L�[�{�[�h�������Ɏ��s���܂����B", NULL, MB_OK);
		return E_FAIL;
	}

	//	�f�[�^�t�H�[�}�b�g
	if (FAILED(m_pKeyDevice->SetDataFormat(&c_dfDIKeyboard)))
	{
		return E_FAIL;
	}

	//	�������x��
	if (FAILED(m_pKeyDevice->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND)))
	{
		return E_FAIL;
	}

	// �A�N�Z�X����
	m_pKeyDevice->Acquire();
	return S_OK;
}

// �}�E�X�f�o�C�X������
HRESULT InputDevice::InitDinputMouse(HWND hWnd)
{
	//	�L�[�{�[�h�̏�����
	if (FAILED(m_pDInput->CreateDevice(GUID_SysMouse,
		&m_pMouseDevice, NULL)))
	{
		MessageBox(0, "DirectInput�L�[�{�[�h�������Ɏ��s���܂����B", NULL, MB_OK);
		return E_FAIL;
	}

	//	�f�[�^�t�H�[�}�b�g
	if (FAILED(m_pMouseDevice->SetDataFormat(&c_dfDIMouse2)))
	{
		return E_FAIL;
	}

	// �����[�h��ݒ�i���Βl���[�h�ɐݒ�j
	DIPROPDWORD diprop;
	diprop.diph.dwSize = sizeof(diprop);					// ��܂���\���̂̃T�C�Y
	diprop.diph.dwHeaderSize = sizeof(diprop.diph);			// DIPROPHEADER �\���̂̃T�C�Y
	diprop.diph.dwObj = 0;									// �A�N�Z�X����v���p�e�B��������I�u�W�F�N�g
	diprop.diph.dwHow = DIPH_DEVICE;						// dwObj �����o�̉��ߕ��@���w�肷��l
	diprop.dwData = 1000;									// �ݒ�܂��͎擾�����v���p�e�B�l
	//	diprop.dwData		= DIPROPAXISMODE_ABS;	// ��Βl���[�h�̏ꍇ
	if (FAILED(m_pMouseDevice->SetProperty(DIPROP_BUFFERSIZE, &diprop.diph)))
	{
		MessageBox(0, "�����[�h�̐ݒ�Ɏ��s", NULL, MB_OK);
		return false;
	}

	//	�������x��
	if (FAILED(m_pMouseDevice->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND)))
	{
		return E_FAIL;
	}

	// �A�N�Z�X����
	m_pMouseDevice->Acquire();
	return S_OK;
}
