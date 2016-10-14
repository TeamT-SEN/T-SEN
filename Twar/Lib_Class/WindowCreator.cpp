/**
* @file WindowCreator.cpp
* @brief �E�B���h�E���쐬����N���X
* @author haga
*/
#include <windows.h>
#include"WindowCreator.h"

// �R���X�g���N�^
WindowCreator::WindowCreator(char* title, int width, int height) :
m_hWnd(NULL),
m_wTitle(title),
m_wWidth(width),
m_wHeight(height),
m_wType(true)
{
}

// �f�X�g���N�^
WindowCreator::~WindowCreator()
{
}

// �E�B���h�E���쐬����֐�
HRESULT WindowCreator::MakeWindow(HINSTANCE hInstance, LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp), bool windowType)
{
	// �E�B���h�E���̐ݒ�
	m_wndc.cbSize = sizeof(m_wndc);
	m_wndc.style = CS_HREDRAW | CS_VREDRAW;
	m_wndc.lpfnWndProc = WndProc;
	m_wndc.cbClsExtra = m_wndc.cbWndExtra = 0;
	m_wndc.hInstance = hInstance;
	m_wndc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	m_wndc.hCursor = LoadCursor(NULL, IDC_ARROW);
	m_wndc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	m_wndc.lpszMenuName = NULL;
	m_wndc.lpszClassName = m_wTitle;
	m_wndc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&m_wndc))
	{
		MessageBox(0, "�E�B���h�E�N���X�̐ݒ�Ɏ��s���܂����B", NULL, MB_OK);
		return E_FAIL;
	}

	m_wType = windowType;  // �E�B���h�E�^�C�v��ێ�����

	// �E�B���h�E�����	
	if (m_wType)			// �ʏ�E�B���h�E
	{
		m_hWnd = CreateWindow(
			m_wTitle,							// �E�B���h�E�̃N���X��
			m_wTitle, 							// �E�B���h�E�̃^�C�g��
			WS_OVERLAPPEDWINDOW | WS_VISIBLE,	// �E�B���h�E�X�^�C��
			CW_USEDEFAULT,						// �E�B���h�E�̉������̈ʒux
			CW_USEDEFAULT,						// �E�B���h�E�̏c�����̈ʒuy
			m_wWidth,							// Width�i���j�@
			m_wHeight,							// Height�i����)
			NULL,
			NULL,
			hInstance,							// �A�v���P�[�V�����C���X�^���X�̃n���h��
			NULL
			);

		SetProcessDPIAware();					// �E�B���h�E�T�C�Y�𒲐�����֐�
		HDC hdc = GetDC(m_hWnd);
		int aaa = GetDeviceCaps(hdc, LOGPIXELSX);

		// �N���C�A���g�̈�𒲐�����
		RECT client_rect;
		RECT widow_rect;
		GetWindowRect(m_hWnd, &widow_rect);
		GetClientRect(m_hWnd, &client_rect);

		// �������E�B���h�E�Ԋu�����߂�(��)
		widow_rect.right -= widow_rect.left;
		client_rect.right -= client_rect.left;

		// �������E�B���h�E�Ԋu�����߂�(����)
		widow_rect.bottom -= widow_rect.top;
		client_rect.bottom -= client_rect.top;

		SetWindowPos(m_hWnd, HWND_TOP, 0, 0, (m_wWidth + (widow_rect.right - client_rect.right)), (m_wHeight + (widow_rect.bottom - client_rect.bottom)), SWP_NOMOVE);

		GetWindowRect(m_hWnd, &m_wRect);		// ������E�B���h�E�T�C�Y��ێ����Ă���
	}
	else				// �t���X�N���[��
	{
		m_hWnd = CreateWindow(
			m_wTitle,							// �E�B���h�E�̃N���X��
			m_wTitle, 							// �E�B���h�E�̃^�C�g��
			WS_POPUP | WS_VISIBLE,				// �E�B���h�E�X�^�C��
			0,									// �E�B���h�E�̉������̈ʒux
			0,									// �E�B���h�E�̏c�����̈ʒuy
			m_wWidth,							// Width�i���j�@
			m_wHeight,							// Height�i����)
			NULL,
			NULL,
			hInstance,							// �A�v���P�[�V�����C���X�^���X�̃n���h��
			NULL
			);
	}
	if (!m_hWnd)
	{
		MessageBox(0, "�E�B���h�E�����Ɏ��s���܂����B", NULL, MB_OK);
		return E_FAIL;
	}

	ShowWindow(m_hWnd, SW_SHOW);

	return S_OK;
}


// �E�B���h�E�T�C�Y�����肷��
HRESULT WindowCreator::ChangeWindowSize()
{
	if (m_wType)
	{
		SetWindowLong(m_hWnd, GWL_STYLE, WS_POPUP | WS_VISIBLE);
		m_wType = false;
	}
	else
	{
		SetWindowLong(m_hWnd, GWL_STYLE, WS_OVERLAPPEDWINDOW | WS_VISIBLE);
		SetWindowPos(m_hWnd, HWND_TOP, 0, 0, m_wWidth, m_wHeight, SWP_NOMOVE);

		// �N���C�A���g�̈�𒲐�����
		RECT client_rect;
		RECT widow_rect;
		GetWindowRect(m_hWnd, &widow_rect);
		GetClientRect(m_hWnd, &client_rect);

		// �������E�B���h�E�Ԋu�����߂�(��)
		widow_rect.right -= widow_rect.left;
		client_rect.right -= client_rect.left;

		// �������E�B���h�E�Ԋu�����߂�(����)
		widow_rect.bottom -= widow_rect.top;
		client_rect.bottom -= client_rect.top;

		SetWindowPos(m_hWnd, HWND_TOP, 0, 0, (m_wWidth + (widow_rect.right - client_rect.right)), (m_wHeight + (widow_rect.bottom - client_rect.bottom)), SWP_NOMOVE);
		GetWindowRect(m_hWnd, &m_wRect);

		m_wType = true;
	}
	return S_OK;
}