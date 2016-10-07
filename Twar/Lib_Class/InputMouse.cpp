/**
* @file   InputMouse.cpp
* @brief  �}�E�X����Ɋւ���N���X.
* @author haga
*/
#include "InputDevice.h"
#include "InputMouse.h"

// �R���X�g���N�^
InputMouse::InputMouse() :
m_pMouseDevice(InputDevice::GetInstance().GetMouseDevice()),
m_hWnd(InputDevice::GetInstance().GethWnd())
{
	// �N���C�A���g�T�C�Y���擾
	RECT rec;		
	GetClientRect(m_hWnd,&rec);
	m_wndWid = rec.right - rec.left;
	m_wndHgt = rec.bottom - rec.top;
	m_posX = m_wndWid / 2;
	m_posY = m_wndHgt / 2;
	m_wheel = 0;
	m_LDown = false;
	m_RDown = false;
	m_MDown = false;
	m_LAction = false;
	m_MAction = false;
	m_RAction = false;
}

// �f�X�g���N�^
InputMouse::~InputMouse()
{
}

// �}�E�X�̃f�[�^�X�V
void InputMouse::UpdateMouse()
{
	DIDEVICEOBJECTDATA od;			// �f�o�C�X�I�u�W�F�N�g�f�[�^���i�[����ϐ�
	DWORD dwItems = 1;
	HRESULT hr;

	// �N���C�A���g�T�C�Y���擾
	RECT rec;
	GetWindowRect(m_hWnd, &rec);

	while (true)
	{
		hr = m_pMouseDevice->GetDeviceData(sizeof(DIDEVICEOBJECTDATA), &od, &dwItems, 0);
		if (hr == DIERR_INPUTLOST)
		{
			m_pMouseDevice->Acquire();
		}
		else if (FAILED(hr) || dwItems == 0)
		{
			if (hr == DIERR_NOTACQUIRED)
			{
				m_pMouseDevice->Acquire();
			}
			break;
		}
		else
		{
			POINT pos;				// ���肵���}�E�X���W���ꎞ�I�Ɋi�[����ϐ�
			
			switch (od.dwOfs)
			{
			case DIMOFS_X:							// �}�E�X�̐����ړ�
				GetCursorPos(&pos);					// �}�E�X���W���擾����
				ScreenToClient(m_hWnd, &pos);		// �X�N���[�����W����N���C�A���g���W�ւƕύX����
				m_posX = pos.x;
				break;

			case DIMOFS_Y:							// �}�E�X�̐����ړ�
				GetCursorPos(&pos);
				ScreenToClient(m_hWnd, &pos);
				m_posY = pos.y;
				break;

			case DIMOFS_Z:							// �}�E�X��Z(�z�C�[��)����
				m_wheel = od.dwData;
				if (m_wheel > 0)
				{
					m_wheel = 1;
				}
				else if (m_wheel < 0)
				{
					m_wheel = -1;
				}
				break;

			case DIMOFS_BUTTON0:					// ���{�^���̏��
				m_LDown = (od.dwData & 0x80) ? true : false;
				if (m_LDown)
				{
					m_LAction = true;
				}
				else
				{
					m_LAction = false;
				}
				break;

			case DIMOFS_BUTTON1:					// �E�{�^���̏��
				m_RDown = (od.dwData & 0x80) ? true : false;
				if (m_RDown)
				{
					m_RAction = true;
				}
				else
				{
					m_RAction = false;
				}
				break;

			case DIMOFS_BUTTON2:					// ���{�^���̏��
				m_MDown = (od.dwData & 0x80) ? true : false;
				if (m_MDown)
				{
					m_MAction = true;
				}
				else
				{
					m_RAction = false;
				}
				break;

			}
		}

	}
}

