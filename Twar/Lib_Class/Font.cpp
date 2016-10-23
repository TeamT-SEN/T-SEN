/**
* @file Font.cpp
* @brief �t�H���g�������N���X��cpp
* @author haga
*/
#include "Font.h"

// �R���X�g���N�^
Font::Font(IDirect3DDevice9*	pD3Device) :
m_pD3Device(pD3Device),
m_pFont(NULL),
m_height(20),
m_width(10)
{
	if (FAILED(D3DXCreateFont(m_pD3Device,
		m_height,
		m_width,
		FW_REGULAR,
		NULL,
		FALSE,
		SHIFTJIS_CHARSET,
		OUT_DEFAULT_PRECIS,
		PROOF_QUALITY,
		FIXED_PITCH | FF_MODERN,
		TEXT("�l�r�@�o�S�V�b�N"),
		&m_pFont)))
	{
		MessageBox(NULL,"�t�H���g�N���X���쐬�ł��܂���","Error",MB_OK);
	}
}

// �R���X�g���N�^ �����̑傫�����w�肷��ꍇ�Ɏg�p
Font::Font(IDirect3DDevice9*	pD3Device,INT height, UINT	width) :
m_pD3Device(pD3Device),
m_pFont(NULL),
m_height(height),
m_width(width)
{
	if (FAILED(D3DXCreateFont(m_pD3Device,
		m_height,
		m_width,
		FW_REGULAR,
		NULL,
		FALSE,
		SHIFTJIS_CHARSET,
		OUT_DEFAULT_PRECIS,
		PROOF_QUALITY,
		FIXED_PITCH | FF_MODERN,
		TEXT("�l�r�@�o�S�V�b�N"),
		&m_pFont)))
	{
		MessageBox(NULL, "�t�H���g�N���X���쐬�ł��܂���", "Error", MB_OK);
	}
}

// �f�X�g���N�^
Font::~Font()
{
	if (m_pFont != NULL)m_pFont->Release();
}

// �e�L�X�g��\������֐�
void Font::Draw(LPCTSTR pString, D3DXVECTOR2 pos)
{
	RECT rc;
	D3DXFONT_DESC desc;
	m_pFont->GetDesc(&desc);

	rc.left = (LONG)pos.x;
	rc.top = (LONG)pos.y;
	rc.right = (LONG)pos.x + desc.Width * strlen(pString);
	rc.bottom = (LONG)pos.y + desc.Height * strlen(pString);
	m_pFont->DrawTextA(
		NULL,							// NULL
		pString,						// �`��e�L�X�g
		-1,								// �S�ĕ\��
		&rc,							// �\���͈�
		DT_LEFT,						// ����
		D3DCOLOR_XRGB(255, 255, 255));	// ���F
}

// �e�L�X�g��\������֐�(�F�ƕ����񂹂�ς����)
void Font::Draw(LPCSTR pString, D3DXVECTOR2 pos, DWORD format, D3DCOLOR color)
{
	RECT rc;
	D3DXFONT_DESC desc;
	m_pFont->GetDesc(&desc);

	rc.left = (LONG)pos.x;
	rc.top = (LONG)pos.y;
	rc.right = (LONG)pos.x + desc.Width * strlen(pString);
	rc.bottom = (LONG)pos.y + desc.Height * strlen(pString);

	m_pFont->DrawTextA(
		NULL,		// NULL 
		pString,	// �`��e�L�X�g
		-1,			// �S�ĕ\��
		&rc,		// �\���͈�
		format,		// ������
		color);		// �����̐F
}

// �����̃t�H���g�Ȃǂ��Đݒ肷��֐�
void Font::ReCreateFont(LPCTSTR pFacename, UINT weight, BOOL italic)
{
	// �t�H���g����x�J������
	if (m_pFont != NULL)
	{
		m_pFont->Release();
		m_pFont = NULL;
	}

	if (FAILED(D3DXCreateFont(m_pD3Device,
		m_height,
		m_width,
		weight,
		NULL,
		italic,
		SHIFTJIS_CHARSET,
		OUT_DEFAULT_PRECIS,
		PROOF_QUALITY,
		FIXED_PITCH | FF_MODERN,
		pFacename,
		&m_pFont)))
	{
		MessageBox(NULL, "�t�H���g�N���X���쐬�ł��܂���", "Error", MB_OK);
	}
}