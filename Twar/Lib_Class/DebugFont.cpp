#include "DebugFont.h"


DebugFont::DebugFont(INT height, UINT width, D3DCOLOR color):
m_pD3Device(GraphicsDevice::GetInstance().GetDevice()),
m_pFont(NULL),
m_height(height),
m_width(width),
m_color(color)
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


DebugFont::~DebugFont()
{
	if (m_pFont != NULL)
	{
		Release();
	}
}

// �����`��֐�
void DebugFont::Draw(LPCSTR pString, D3DXVECTOR2 pos)
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
		m_color);						// �F
}

// �������J���֐�
void DebugFont::Release()
{
	m_pFont->Release();
	m_pFont = NULL;
}