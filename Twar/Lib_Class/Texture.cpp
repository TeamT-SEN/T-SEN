/**
* @file Texture.cpp
* @brief �e�N�X�`���[�Ɋ֘A����N���X.cpp
* @author haga
*/
#include <d3dx9.h>
#include <d3d9.h>
#include "GraphicsDevice.h"
#include "Texture.h"

// �R���X�g���N�^
Texture::Texture() :m_pTexture(NULL), m_pD3Device(GraphicsDevice::GetInstance().GetDevice())
{
}

// �f�X�g���N�^
Texture::~Texture()
{
	SAFE_RELEASE(m_pTexture);
}

// �摜�ǂݍ��݊ȈՔ�
HRESULT Texture::LoadTex(char* text)
{
	if (FAILED(D3DXCreateTextureFromFile(m_pD3Device, text, &m_pTexture)))
	{
		// �ǂݍ��ݎ��s������G���[
		MessageBox(0, "�摜�̓ǂݍ��݂Ɏ��s���܂����B", NULL, MB_OK);
		return E_FAIL;
	}
	return S_OK;
}

// �摜�ǂݍ��ݏڍאݒ��
HRESULT Texture::LoadTexEx(char* text, int a, int r, int g, int b, bool size)
{
	if (size)
	{
		if (FAILED(D3DXCreateTextureFromFileEx(
			m_pD3Device,			//	�C���^�[�t�F�C�X�ւ̃|�C���^
			text,					//	�摜�t�@�C����
			D3DX_DEFAULT,
			D3DX_DEFAULT,
			D3DX_DEFAULT,
			0,
			D3DFMT_UNKNOWN,
			D3DPOOL_DEFAULT,
			D3DX_FILTER_NONE,
			D3DX_DEFAULT,
			D3DCOLOR_ARGB(a, r, g, b),
			NULL,
			NULL,
			&m_pTexture
			)))
		{
			MessageBox(0, "�摜�̓ǂݍ��݂Ɏ��s���܂����B", NULL, MB_OK);
			return E_FAIL;
		}
	}
	else			//�Q�ׂ̂��悶��Ȃ��̂Ȃ�
	{
		if (FAILED(D3DXCreateTextureFromFileEx(
			m_pD3Device,
			text,
			D3DX_DEFAULT_NONPOW2,
			D3DX_DEFAULT_NONPOW2,
			D3DX_DEFAULT,
			0,
			D3DFMT_UNKNOWN,
			D3DPOOL_MANAGED,
			D3DX_FILTER_NONE,
			D3DX_FILTER_NONE,
			D3DCOLOR_ARGB(a, r, g, b),
			NULL, NULL,
			&m_pTexture)))
		{
			MessageBox(0, "�摜�̓ǂݍ��݂Ɏ��s���܂����B", NULL, MB_OK);
			return E_FAIL;
		}

	}
	return S_OK;
}

// �`��
void Texture::RenderTex(CUSTOMVERTEX* setdraw)
{
	m_pD3Device->SetTexture(0, m_pTexture);
	m_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN,2,setdraw,sizeof(CUSTOMVERTEX));
}

// �f�o�C�X���擾����֐�
void Texture::GetDevice()
{
	m_pD3Device = GraphicsDevice::GetInstance().GetDevice();
}

// �������J������֐�
void Texture::Release()
{
	if (m_pTexture != NULL)
	{
		m_pTexture->Release();
	}
}